#pragma once

class Random
{
private:
	Random() { }

public:
	~Random() { }

	// Return a number between [a, b]
	static int RandomRange(int a, int b);
	// Return a number between [0, 1]
	static double Rand();
};