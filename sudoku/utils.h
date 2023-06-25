#pragma once
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <cstdio>

/*
Check condition.
If not satisfied, dump error message to stderr and exit.
*/
#define Assert(cond, format, ...) \
    do {\
        if (!(cond)) { \
            fprintf(stderr, format "\n", ## __VA_ARGS__); \
            exit(EXIT_FAILURE); \
        }\
    } while (0)

/*
Generate a number between a range[l, r]
*/
static int gen_rand_number(int l, int r) {
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(l, r);
    return distribution(engine);
}

/*
Shuffle `arr` of `len` randomly.
*/
template <class T>
static void shuffle_array(T* arr, int len)
{
	uint32_t seed = (uint32_t) std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(arr, arr + len, std::default_random_engine(seed));
}

/*
Allocate 2d array of size m * n
*/
template <class T>
static T** allocate_2d_array(int m, int n) {
    T** ptr = new T * [m];
    for (int i = 0; i < m; i++) {
        ptr[i] = new T[n];
    }
    return ptr;
}

/*
Free 2d array by giving the size of the highest dimension
*/
template <class T>
static void free_2d_array(T** ptr, int m) {
    for (int i = 0; i < m; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
    ptr = nullptr;
}

