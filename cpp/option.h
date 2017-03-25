#pragma once

#include <utility>
#include <stdexcept>

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
            throw std::runtime_error("Unwrap a empty \"Maybe\"");
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
