#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isPrime(uint64_t x)
{
	for (int i = 2; i < (double)sqrt(x); i++)
	{
		if (x%i == 0)
		{
			return false;
			break;
		}
	}
	return true;
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
	if (NWD(N, x) == 1)
		return true;
	else
		return false;
}

string generateSequence(uint64_t x, uint64_t N, int length)
{
	string klucz;
	string pom = "0";
	int value = (x*x) % N;
	for (int i = 0; i < length; i++)
	{
		pom=to_string(value & 1);
		klucz.append(pom);
		value = (value*value) % N;
		
	}
	return klucz;
}

string BBS(uint64_t p, uint64_t q, uint64_t x, int length)
{
	uint64_t N;
	if (isPrime(p) && isPrime(q))
	{
		if (p % 4 == 3 && q % 4 == 3)
		{
			N = p * q;
			if (isCoPrime(N, x))
			{
				return generateSequence(x, N, length);

			}
		}
	}
	else
		return "Blad";
}

int main()
{
	uint64_t p=11, q=19, x=281;
	int length=20000;
	string sequence = BBS(p, q, x, length);
	cout << sequence;
	getchar;
}

