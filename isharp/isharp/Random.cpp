#include "stdafx.h"
#include "Random.h"

int Random::getRandom() {
	srand((unsigned int)time(NULL));
	return rand() % 129;
}

string Random::random_int(int min, int max) {
	int random = (((seed_temp1 * seed_temp2 * count_seed) - seed_temp3 * getRandom()) / count_seed) * max / 999999 + 1 + min;

	if (random % 2 == 0) { // is an even number...
		if (random * 2 > max) {
			if ((random + (random / 3) * 2) < max) {
				random += (random / 3) * 2;
			}
		}
		else {
			random *= 2;
		}
	}
	else {
		if (random / 2 < min) {

		}
		else {
			random = random / 2;
		}
	}

	if (random > max) {
		random -= max / 10;

		// if the random won't shrink..
		while (random > max) {
			random -= max / 10;
		}
	}

	if (!used2)
		seed_temp1 -= seed2;
	else
		seed_temp1 += seed2;

	seed_temp2 += 3;

	seed_temp3 -= 5;

	if (seed_temp1 > 3000) {
		seed_temp1 = seed1;
		seed_temp2 = seed2;
		seed_temp3 = seed3;
		used1 = false;
		used2 = false;
		count_seed++;
		if (count_seed == 5) {
			count_seed = 1;
		}
	}


	if (seed_temp1 <= 1000 && !used1) {
		seed_temp1 += seed1;
		used1 = true;
	}
	else if (seed_temp1 <= 900 && !used2) {
		used2 = true;
	}

	return to_string(random);
}

string Random::rand_here(int min, int max) {
	return to_string(rand() % max + min);
}
