#pragma once
#include<utility>
#include<cassert>
#include<cstddef>
#include<type_traits>
// Type redefine
using i32   = std::int32_t;
using i64   = std::int64_t;
using u32   = std::uint32_t;
using u64   = std::uint64_t;
using isize = std::make_signed_t<std::size_t>;
using usize = std::size_t;
using f32   = float;
using f64   = double;

// Common macro


// Common help class
template <typename T>
class Maybe
{
public:
    Maybe()
    {
        this->none = true;
    };
    Maybe(T data)
        : data(data)
    {
        this->none = false;
    };
    T get()
    {
        assert(!this->none);
        T data = std::move(this->data);
        this->none = true;
        this->data = T();
        return data;
    };
    bool is_none() {
        return this->none;
    };
private:
    bool none;
    T data;
};
