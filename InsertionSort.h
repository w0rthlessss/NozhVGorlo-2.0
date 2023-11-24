#pragma once
#include <vector>

/*
	Класс, содержащий реализацию сортировки вставками, а также методы,
	подсчитывающие количество сравнений и перестановок в массиве.
*/

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

