#pragma once
#include <algorithm>
#include <random>
#include <chrono>

/*
Shuffle `arr` of `len` randomly
*/
static void shuffle_array(int* arr, int len)
{
	uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(arr, arr + len, std::default_random_engine(seed));
}