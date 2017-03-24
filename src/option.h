#pragma once

#include <utility>
#include "panic.h"

template<typename T>
class Option {
public:
    Option() {
        this->none = true;
    }

    Option(T data)
            : data(data) {
        this->none = false;
    }

    T &&unwrap() noexcept {
        if (this->none) {
            PANIC("Unwrap a empty \"Maybe\"");
        }
        this->none = false;
        return std::move(this->data);
    }

    bool is_none() {
        return this->none;
    }

private:
    bool none;
    T data;
};
