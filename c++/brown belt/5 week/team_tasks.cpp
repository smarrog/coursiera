#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>

TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const std::string& person) const;
    void AddNewTask(const std::string& person);
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int tasksCount);

private:
    std::map<std::string, TasksInfo> _tasks;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) const {
    return _tasks.at(person);
}

void TeamTasks::AddNewTask(const std::string& person) {
    ++_tasks[person][TaskStatus::NEW];
}

void RemoveZeros(TasksInfo& tasks_info) {
    std::vector<TaskStatus> toRemove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            toRemove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : toRemove) {
        tasks_info.erase(status);
    }
}


std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const std::string& person, int tasksCount) {
    TasksInfo updatedTasks;
    TasksInfo untouchedTasks;
    TasksInfo& tasks = _tasks[person];
    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = Next(status)) {
        updatedTasks[Next(status)] = std::min(tasksCount, tasks[status]);
        tasksCount -= updatedTasks[Next(status)];
    }

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = Next(status)) {
        untouchedTasks[status] = tasks[status] - updatedTasks[Next(status)];
        tasks[status] += updatedTasks[status] - updatedTasks[Next(status)];
    }
    tasks[TaskStatus::DONE] += updatedTasks[TaskStatus::DONE];
    RemoveZeros(updatedTasks);
    RemoveZeros(untouchedTasks);

    return {updatedTasks, untouchedTasks};
}
