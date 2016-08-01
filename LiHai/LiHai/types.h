#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>


// Type redefinition
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using isize = std::make_signed_t<std::size_t>;
using usize = std::size_t;
using iptr = std::intptr_t;
using uptr = std::uintptr_t;
using f32 = float;
using f64 = double;