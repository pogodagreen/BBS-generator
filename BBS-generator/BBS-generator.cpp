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
	uint64_t value = (x*x) % N;
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

bool singleBitsTest(string sequence)
{
	int count=0;
	for (int i = 0; i < sequence.length(); i++)
	{
		if (sequence[i] == '1')
			count++;
	}
	cout << "Single Bits Test: Count 1 " << count << endl;
	if (count > 9725 && count < 10275)
	{
		cout << "Single Bits Test is passed" << endl;
		return true;
	}
	else
	{
		cout << "Single Bits Test is not passed" << endl;
		return false;
	}
}

bool pokerTest(string sequence)
{
	int array[16] = { 0 };
	int i = 0;
	int value = 0;
	double x=0, temp=0;
	do
	{
		value =	(sequence[i++]-48) * 8 + (sequence[i++]-48) * 4 + (sequence[i++]-48) * 2 + (sequence[i++]-48);
		switch (value)
		{
		case 0: 
			array[value]++;
			break;
		case 1:
			array[value]++;
			break;
		case 2:
			array[value]++;
			break;
		case 3:
			array[value]++;
			break;
		case 4:
			array[value]++;
			break;
		case 5:
			array[value]++;
			break;
		case 6:
			array[value]++;
			break;
		case 7:
			array[value]++;
			break;
		case 8:
			array[value]++;
			break;
		case 9:
			array[value]++;
			break;
		case 10:
			array[value]++;
			break;
		case 11:
			array[value]++;
			break;
		case 12:
			array[value]++;
			break;
		case 13:
			array[value]++;
			break;
		case 14:
			array[value]++;
			break;
		case 15:
			array[value]++;
			break;
		}
	} while (i < sequence.length());
	for (int i = 0; i < 16; i++)
	{
		temp += (array[i] * array[i]);
	}
	x = (16/5000) *temp - 5000;
	if (x > 2,16 && x < 46,17)
	{
		cout << "Poker Test is passed" << endl;
		return true;
	}
	else
	{
		cout << "Poker Test is not passed" << endl;
		return false;
	}
}

bool longRunsTest(string sequence)
{
	int count = 0;
	for (int i = 1; i <= sequence.length(); i++)
	{
		if (sequence[i] == sequence[i-1])
		{
			count++;
			if (count > 25)
			{
				cout << "Long Runs Test is not passed" << endl;
				return false;
				break;
			}
		}
		else
		{
			count = 1;
		}
	}
	cout << "Long Runs Test is passed" << endl;
	return true;
}

bool runsTest(string sequence)
{
	int array[6] = { 0 };
	int count = 0;
	for (int i = 1; i < sequence.length(); i++)
	{
		if (sequence[i] == sequence[i - 1])
		{
			count++;
		}
		else
		{
			switch (count)
			{
			case 1: 
				array[count - 1]++;
				break;
			case 2:
				array[count - 1]++;
				break;
			case 3:
				array[count - 1]++;
				break;
			case 4:
				array[count - 1]++;
				break;
			case 5:
				array[count - 1]++;
				break;
			default:
				array[5]++;
				break;
			}
			count = 1;
		}
	}
	if (array[0] > 2267 && array[0] < 2733 && array[1]>1079 && array[1] < 1421 && array[2]>502 && array[2] < 748 && array[3] > 223 && array[3] < 402 && array[4]>90 && array[4] < 223 && array[5]>90 && array[5] < 223)
	{
		cout << "Runs Test is passed" << endl;
		return true;
	}
	else
	{
		cout << "Runs Test is not passed" << endl;
		return false;
	}
	
	
}

int main()
{
	uint64_t p=11699, q=7219, x=3;
	int length=20000;
	int sbt = 0;
	string sequence = BBS(p, q, x, length);
	singleBitsTest(sequence);
	pokerTest(sequence);
	longRunsTest(sequence);
	runsTest(sequence);
	getchar;
}

