#pragma once
#include<utility>
#include<cassert>
// typedef
typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;
// Macro
#define MAX(a,b) (a>b) ? a : b


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
