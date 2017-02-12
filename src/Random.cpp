#include "Random.h"
#include <time.h>
#include <iostream>

// Static Methods
int Random::RandomRange(int a, int b)
{
	return (rand() % (b - a)) + a;
}

double Random::Rand()
{
	return ((double)rand() / (RAND_MAX))
}