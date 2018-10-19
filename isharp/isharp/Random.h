#pragma once
#ifndef MOUSEHAX_RANDOM
#define MOUSEHAX_RANDOM
#include "standard.h"

class Random { // simple (not random) random class made by ya boi ( uses some random math i made to "make" a random
private:
	int seed_temp1 = 1934;
	int seed_temp2 = 92;
	int seed_temp3 = 124;

	bool used1 = false;
	bool used2 = false;

	int count_seed = 1;

	int getRandom();

public:
	int seed1 = 1934;
	int seed2 = 295;
	int seed3 = 900; // 

	int multiplyer = 123;

	string random_int(int min, int max);
	string rand_here(int min, int max);
};
#endif

