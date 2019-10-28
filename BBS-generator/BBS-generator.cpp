#include "pch.h"
#include <iostream>
#include <math.h>

bool isPrime(uint64_t x)
{
	for (int i = 2; i < (double)sqrt(x); i++)
	{
		if (x%i == 0)
		{
			return true;
			break;
		}
	}
	return false;
}

uint64_t NWD(uint64_t x, uint64_t y)
{
	uint64_t pom;
	while (y != 0)
	{
		pom = y;
		y = x % y;
		x = pom;
	}
	return x;
}

bool isCoPrime(uint64_t N, uint64_t x)
{
	NWD(N, x) == 1;
}

int main()
{
	uint64_t p, q, N;
	if (isPrime(p) && isPrime(q))
	{
		if (p % 4 == 3 && q % 4 == 3)
		{
			N = p * q;
		}
	}
}

