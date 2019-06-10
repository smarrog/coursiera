#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace PhoneBookSerialize {
    class Date {
    public:
        uint32_t year() const { return _year; }
        uint32_t month() const { return _month; }
        uint32_t day() const { return _day; }

        void set_year(uint32_t value) { _year = value; }
        void set_month(uint32_t value) { _month = value; }
        void set_day(uint32_t value) { _day = value; }

        void clear_year() {}
        void clear_month() {}
        void clear_day() {}

    private:
        uint32_t _year;
        uint32_t _month;
        uint32_t _day;
    };

    class Contact {
    public:
        const std::string& name() const { return _name; }
        void set_name(const std::string& value) { _name = value; }
        void clear_name() {}
        std::string* mutable_street() { return &_name; }

        bool has_birthday() const { return true; }
        Date* mutable_birthday() { return &_birthday; }
        const Date& birthday() const { return _birthday; }

        int phone_number_size() const { return _phone_number.size(); }
        void add_phone_number(std::string number = std::string()) { _phone_number.emplace_back(std::move(number)); }
        const std::vector<std::string>& phone_number() const { return _phone_number; }
        const std::string& phone_number(uint32_t index) const { return _phone_number[index]; }

        void Clear() {
            _name = "";
            _phone_number.clear();
        }

    private:
        std::string _name;
        Date _birthday;
        std::vector<std::string> _phone_number;
    };

    class ContactList {
    public:
        int contact_size() const { return _contact.size(); }
        Contact* add_contact(Contact contact = {}) {  _contact.emplace_back(std::move(contact)); return &_contact[_contact.size() - 1]; }
        const std::vector<Contact>& contact() const { return _contact; }
        const Contact& contact(uint32_t index) const { return _contact[index]; }

        bool ParseFromIstream(std::istream*) { return true; }
        void SerializeToOstream(std::ostream*) {}
    private:
        std::vector<Contact> _contact;
    };
}