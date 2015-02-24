#include "PrimeGenerator.h"
#include <iostream>


PrimeGenerator::PrimeGenerator()
{
	primeList.push_back(2);
}


PrimeGenerator::~PrimeGenerator()
{
}

std::vector<int> PrimeGenerator::GetPrimeLessThan(int upperBound){
	int initialTestCase = 5;
	for (int testCase = initialTestCase; testCase < upperBound; testCase++){
		bool isPrime = true;
		int divider = testCase - 1;
		while (isPrime && divider > 1){
			if (testCase % divider == 0)
				isPrime = false;
			divider = divider - 1;
		}

		if (isPrime)
			primeList.push_back(testCase);
	}

	return primeList;
}

void printPrimeList(std::vector<int> primeList){
	for (int i = 0; i < primeList.size(); i++){
		std::cout << primeList[i] << " ";
	}

	std::cout << std::endl; 
} 


int main(void){
	int upperBound;
	std::cin >> upperBound;
	PrimeGenerator* prime = new PrimeGenerator();
	std::vector<int> primeList = prime->GetPrimeLessThan(upperBound);
	printPrimeList(primeList);
	system("pause"); 
	return 0;
}
