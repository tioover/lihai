#pragma once

#include "base.h"

// 模板化的快速排序在 generic.h。
void quick_sort(i32 *arr, usize len);

void heap_sort(i32 *arr, usize len);

void insert_sort(i32 *arr, usize len);
