#pragma once

#include <stddef.h>

namespace RAII {
    template <typename Provider>
    class Booking {
    public:
        Booking(Provider* provider, int counter)
            : _provider(provider) {
        }

        Booking(const Booking&) = delete;
        Booking(Booking&& other) noexcept
            : Booking(other._provider, 0) {
            _provider = other._provider;
            other._provider = nullptr;
        }

        Booking& operator=(const Booking&) = delete;
        Booking& operator=(Booking&& other) noexcept {
            free();
            _provider = other._provider;
            other._provider = nullptr;
            return *this;
        };
        Booking& operator=(nullptr_t) {
            free();
            return *this;
        }

        ~Booking() {
            free();
        }
    private:
        Provider* _provider;

        void free() {
            if (_provider != nullptr) {
                _provider->CancelOrComplete(*this);
                _provider = nullptr;
            }
        }
    };
}