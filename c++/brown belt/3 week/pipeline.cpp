#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <deque>

using namespace std;

struct Email {
    std::string from;
    std::string to;
    std::string body;
};

class Worker {
public:
    virtual ~Worker() = default;
    virtual void Process(std::unique_ptr<Email> email) = 0;
    virtual void Run() {
        throw logic_error("Unimplemented");
    }

    void SetNext(std::unique_ptr<Worker> next) {
        _next = std::move(next);
    }
protected:
    void PassOn(std::unique_ptr<Email> email) const {
        if (_next != nullptr) {
            _next->Process(std::move(email));
        }
    }
private:
    std::unique_ptr<Worker> _next = nullptr;
};


class Reader : public Worker {
public:
    Reader(std::istream& is)
        : _is(is) { }

    void Process(std::unique_ptr<Email> email) override {

    };

    void Run() override {
        while (!_is.eof()) {
            std::string from;
            std::string to;
            std::string body;
            std::getline(_is, from);
            if (_is.eof()) {
                return;
            }
            std::getline(_is, to);
            if (_is.eof()) {
                return;
            }
            std::getline(_is, body);
            if (_is.eof()) {
                return;
            }
            PassOn(std::make_unique<Email>(Email{std::move(from), std::move(to), std::move(body)}));
        }
    }
private:
    std::istream& _is;
};


class Filter : public Worker {
public:
    using Function = function<bool(const Email&)>;

    Filter(Function func)
        : _func(std::move(func)) { }

    void Process(std::unique_ptr<Email> email) override {
        if (_func(*email)) {
            PassOn(std::move(email));
        }
    }
private:
    Function _func;
};


class Copier : public Worker {
public:
    Copier(std::string recipient)
        : _recipient(std::move(recipient)) { }

    void Process(std::unique_ptr<Email> email) override {
        bool needToCopy = email->to != _recipient;
        auto from = email->from;
        auto body = email->body;
        PassOn(std::move(email));
        if (needToCopy) {
            PassOn(std::make_unique<Email>(Email{ std::move(from), _recipient, std::move(body) }));
        }
    }
private:
    std::string _recipient;
};


class Sender : public Worker {
public:
    Sender(std::ostream& out)
        : _out(out) { }

    void Process(std::unique_ptr<Email> email) override {
        _out << email->from << "\n";
        _out << email->to << "\n";
        _out << email->body << "\n";
        PassOn(std::move(email));
    }
private:
    std::ostream& _out;
};

class PipelineBuilder {
public:
    explicit PipelineBuilder(std::istream& in) {
        addWorker(std::make_unique<Reader>(in));
    }

    PipelineBuilder& FilterBy(Filter::Function filter) {
        return addWorker(std::make_unique<Filter>(filter));
    }

    PipelineBuilder& CopyTo(std::string recipient) {
        return addWorker(std::make_unique<Copier>(recipient));
    }

    PipelineBuilder& Send(std::ostream& out) {
        return addWorker(std::make_unique<Sender>(out));
    }

    std::unique_ptr<Worker> Build() {
        while (_workers.size() > 1) {
            auto back = std::move(_workers.back());
            _workers.pop_back();
            _workers.back()->SetNext(std::move(back));
        }
        return std::move(_workers.front());
    }

private:
    std::deque<std::unique_ptr<Worker>> _workers;

    PipelineBuilder& addWorker(std::unique_ptr<Worker> worker) {
        _workers.push_back(std::move(worker));
        return *this;
    }
};


void TestSanity() {
    string input = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "ralph@example.com\n"
            "erich@example.com\n"
            "I do not make mistakes of that kind\n"

            "erich@example.com\n"
            "shit\n"
    );
    istringstream inStream(input);
    ostringstream outStream;

    PipelineBuilder builder(inStream);
    builder.FilterBy([](const Email& email) {
        return email.from == "erich@example.com";
    });
    builder.CopyTo("richard@example.com");
    builder.Send(outStream);
    auto pipeline = builder.Build();

    pipeline->Run();

    string expectedOutput = (
            "erich@example.com\n"
            "richard@example.com\n"
            "Hello there\n"

            "erich@example.com\n"
            "ralph@example.com\n"
            "Are you sure you pressed the right button?\n"

            "erich@example.com\n"
            "richard@example.com\n"
            "Are you sure you pressed the right button?\n"
    );

    ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSanity);
    return 0;
}
