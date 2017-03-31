#pragma once

#include <utility>
#include <stdexcept>

template<typename T>
class Option {
public:
    Option() {
        none = true;
    }

    Option(T data)
            : data(data) {
        none = false;
    }

    T &&unwrap() noexcept {
        if (none) {
            throw std::runtime_error("Unwrap a empty \"Maybe\"");
        }
        none = false;
        return std::move(data);
    }

    bool is_none() {
        return none;
    }

private:
    T data;
    bool none;
};
