#pragma once
#pragma once
#include <vector>

class PrimeGenerator
{
private:
	std::vector<int> primeList;
	static const int primeBound = 1000; 

public:
	PrimeGenerator();
	~PrimeGenerator();

	std::vector<int> GetPrimeLessThan(int);
};

