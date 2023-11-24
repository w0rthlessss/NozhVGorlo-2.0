#include "pch.h"
#include "CppUnitTest.h"

#include "../ConsoleInput.h"
#include "../ConsoleInput.cpp"
#include "../InsertionSort.h"
#include "../InsertionSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(OneElementArrayTest) {
			InsertionSort method{};
			vector<int> testArray{ 1 };
			const int expectedPermutations = 0;
			const int expectedComparisons = 0;

			method.Sort(testArray);
			int actualPermutations = method.GetPermutations();
			int actualComparisons = method.GetComparisons();

			Assert::AreEqual(expectedComparisons, actualComparisons);
			Assert::AreEqual(expectedPermutations, actualPermutations);
		}

		TEST_METHOD(EqualElementArrayTest) {
			InsertionSort method{};
			vector<int> testArray{ 5,5,5,5,5 };
			const int expectedPermutations = 0;

			method.Sort(testArray);
			int actualPermutations = method.GetPermutations();

			Assert::AreEqual(expectedPermutations, actualPermutations);

		}

		TEST_METHOD(LettersAreNotAllowedTest) {
			istringstream testStream("576dead%\n\n");
			streambuf* cinbuf = cin.rdbuf(testStream.rdbuf());

			const int expected = 576;
			int actual = ReadInt("");

			cin.rdbuf(cinbuf);

			Assert::AreEqual(expected, actual);
		}
	};
}
