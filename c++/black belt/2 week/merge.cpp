#include "yellow_pages.h"

#include <algorithm>
#include <tuple>
#include <map>
#include <algorithm>

using namespace google::protobuf;

namespace YellowPages {
	template <typename T>
	struct MaxPriority {
		const T* data = nullptr;
		int priority = -1;
	};

	template <typename T>
	struct MaxPriorityList {
		std::vector<const T*> data;
		int priority = -1;
	};

	using AddressData = MaxPriority<Address>;
	using NameData = MaxPriorityList<Name>;
	using PhoneData = MaxPriorityList<Phone>;
	using UrlData = MaxPriorityList<Url>;
	using WorkingTimeData = MaxPriority<WorkingTime>;

    void FillAddress(const AddressData& data, Company& company) {
    	if (data.priority == -1) {
    		return;
    	}
    	const auto& address = *data.data;
	    company.mutable_address()->set_formatted(address.formatted());
	    company.mutable_address()->mutable_coords()->set_lat(address.coords().lat());
	    company.mutable_address()->mutable_coords()->set_lon(address.coords().lon());
    }

    void FillName(const NameData& data, Company& company) {
        if (data.priority == -1) {
            return;
        }
        const auto& names = data.data;
        for (const auto& name : names) {
            auto newName = company.add_names();
            newName->set_type(name->type());
            newName->set_value(name->value());
        }
    }

    void FillPhone(const PhoneData& data, Company& company) {
	    if (data.priority == -1) {
		    return;
	    }
	    const auto& phones = data.data;
        for (const auto& phone : phones) {
            auto newPhone = company.add_phones();
            newPhone->set_formatted(phone->formatted());
            newPhone->set_type(phone->type());
            newPhone->set_country_code(phone->country_code());
            newPhone->set_local_code(phone->local_code());
            newPhone->set_number(phone->number());
            newPhone->set_extension(phone->extension());
            newPhone->set_description(phone->description());
        }
    }

    void FillUrl(const UrlData& data, Company& company) {
	    if (data.priority == -1) {
		    return;
	    }
	    const auto& urls = data.data;
        for (const auto& url : urls) {
            auto newUrl = company.add_urls();
            newUrl->set_value(url->value());
        }
    }

    void FillWorkingTime(const WorkingTimeData& data, Company& company) {
	    if (data.priority == -1) {
		    return;
	    }
	    const auto& workingTime = *data.data;
	    company.mutable_working_time()->set_formatted(workingTime.formatted());
        for (const auto& interval : workingTime.intervals()) {
            auto newInterval = company.mutable_working_time()->add_intervals();
            newInterval->set_day(interval.day());
            newInterval->set_minutes_from(interval.minutes_from());
            newInterval->set_minutes_to(interval.minutes_to());
        }
    }

    template <typename T>
    void checkIfMaxPriority(MaxPriority<T>& maxPriority, const T& data, int priority) {
    	if (maxPriority.priority >= priority) {
    		return;
    	}
    	maxPriority.priority = priority;
    	maxPriority.data = &data;
    }

	template <typename T>
	void checkIfMaxPriority(MaxPriorityList<T>& maxPriority, const RepeatedPtrField<T>& data, int priority) {
		if (maxPriority.priority > priority) {
			return;
		}
		if (maxPriority.priority < priority) {
			maxPriority.priority = priority;
			maxPriority.data.clear();
		}
		for (auto it = data.pointer_begin(); it != data.pointer_end(); it++) {
			const auto& elem = *it;
			if (std::all_of(maxPriority.data.begin(), maxPriority.data.end(), [&elem](const T* value) -> bool {
				return elem->SerializeAsString() != value->SerializeAsString();
			})) {
				maxPriority.data.push_back(elem);
			}
		}
	}

    Company Merge(const Signals& signals, const Providers& providers) {
        Company company;
	    AddressData addressData{};
	    NameData nameData{};
	    PhoneData phoneData{};
	    UrlData urlData{};
	    WorkingTimeData workingTimeData{};

        for (const auto& signal : signals) {
            auto it = providers.find(signal.provider_id());
            if (it == providers.end()) {
                continue;
            }
            auto priority = it->second.priority();
            if (signal.company().has_address()) {
	            checkIfMaxPriority(addressData, signal.company().address(), priority);
            }
            if (!signal.company().names().empty()) {
                checkIfMaxPriority(nameData, signal.company().names(), priority);
            }
            if (!signal.company().phones().empty()) {
	            checkIfMaxPriority(phoneData, signal.company().phones(), priority);
            }
            if (!signal.company().urls().empty()) {
	            checkIfMaxPriority(urlData, signal.company().urls(), priority);
            }
	        if (signal.company().has_working_time()) {
		        checkIfMaxPriority(workingTimeData, signal.company().working_time(), priority);
	        }
        }

        FillAddress(addressData, company);
        FillName(nameData, company);
        FillPhone(phoneData, company);
        FillUrl(urlData, company);
        FillWorkingTime(workingTimeData, company);

        // Наивная неправильная реализация: берём все данные из самого первого сигнала, никак не учитываем приоритеты
        return std::move(company);
    }
}
