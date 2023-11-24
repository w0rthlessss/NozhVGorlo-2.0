#include "InsertionSort.h"

/*
	Конструктор по умолчанию
*/
InsertionSort::InsertionSort()
{
	comparisons = 0;
	permutations = 0;
}

/*
	Метод, реализующий саму сортировку вставками.
	Массив разделяется на две части: отсортированную и неотсортированную
	Для каждого элемента неотсортированной части ищется место в отсортированной,
	и элемент перемещается туда, сдвигая другие элементы
*/
void InsertionSort::Sort(std::vector<int>& array)
{
	/*Обход массива с первого элемента*/
	for (int index = 1; index < array.size(); index++) {
		int elem = array[index];
		int tmpIndex = index - 1;

		/*Перемещаем элемент назад, пока не найдем его место*/
		while (tmpIndex >= 0 && Compare(elem, array[tmpIndex])) {
			Permutate(array, tmpIndex + 1, tmpIndex);
			tmpIndex--;
		}
		
	}

}

/*
	Метод, возвращающий количество перестановок
*/
int InsertionSort::GetPermutations()
{
	return permutations;
}

/*
	Метод, возвращающий количество сравнений
*/
int InsertionSort::GetComparisons()
{
	return comparisons;
}

/*
	Метод для сравнивания двух элементов массива
*/
bool InsertionSort::Compare(int first, int second)
{
	comparisons++;
	return second > first;
}

/*
	Метод для перестановки двух элементов массива
*/
void InsertionSort::Permutate(std::vector<int>& array, int posFirst, int posSecond)
{
	permutations++;
	std::swap(array[posFirst], array[posSecond]);
}
