#pragma once
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <cstdio>

#define Assert(cond, format, ...) \
    do {\
        if (!(cond)) { \
            fprintf(stderr, format "\n", ## __VA_ARGS__); \
            exit(EXIT_FAILURE); \
        }\
    } while (0)

/*
Shuffle `arr` of `len` randomly
*/
static void shuffle_array(int* arr, int len)
{
	uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(arr, arr + len, std::default_random_engine(seed));
}