#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTest
{		
	TEST_CLASS(PrimeGeneratorTest){
	public:
		
		TEST_METHOD(ConstructorTest){
			PrimeGenerator prime;
			int totalPrime = 25;
			std::vector<int> actualList = prime.GetPrimeList();

			int hardCodedPrime[] = { 2, 3, 5, 7, 11, 
				                    13, 17, 19, 23, 29, 
									31, 37, 41, 43, 47,
									53, 59, 61, 67, 71, 
									73, 79, 83, 89, 97 };

			Assert::AreEqual(totalPrime, (int)actualList.size());

			for (int i = 0; i < totalPrime; i++){
				Assert::AreEqual(hardCodedPrime[i], actualList[i]);
			}
		}

		TEST_METHOD(GetPrimeLessThan_BasicTest){
			PrimeGenerator prime;

			int totalPrime = 25;
			int totalPrimeLessThan50 = 15;

			int hardCodedPrime[] = { 2, 3, 5, 7, 11,
									13, 17, 19, 23, 29,
									31, 37, 41, 43, 47,
									53, 59, 61, 67, 71,
									73, 79, 83, 89, 97 };
			prime.SetPrimeList(std::vector<int>(hardCodedPrime, hardCodedPrime + totalPrime));

		}
	};
}