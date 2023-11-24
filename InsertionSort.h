#pragma once
#include <vector>
class InsertionSort
{
private:
	int comparisons;
	int permutations;
public:
	InsertionSort();
	~InsertionSort() = default;
	void Sort(std::vector<int> &array);
	int GetPermutations();
	int GetComparisons();
	bool Compare(int first, int second);
	void Permutate(std::vector<int> &array, int posFirst, int posSecond);

};

