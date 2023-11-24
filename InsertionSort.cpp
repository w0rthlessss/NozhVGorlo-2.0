#include "InsertionSort.h"

/*
	����������� �� ���������
*/
InsertionSort::InsertionSort()
{
	comparisons = 0;
	permutations = 0;
}

/*
	�����, ����������� ���� ���������� ���������.
	������ ����������� �� ��� �����: ��������������� � �����������������
	��� ������� �������� ����������������� ����� ������ ����� � ���������������,
	� ������� ������������ ����, ������� ������ ��������
*/
void InsertionSort::Sort(std::vector<int>& array)
{
	/*����� ������� � ������� ��������*/
	for (int index = 1; index < array.size(); index++) {
		int elem = array[index];
		int tmpIndex = index - 1;

		/*���������� ������� �����, ���� �� ������ ��� �����*/
		while (tmpIndex >= 0 && Compare(elem, array[tmpIndex])) {
			Permutate(array, tmpIndex + 1, tmpIndex);
			tmpIndex--;
		}
		
	}

}

/*
	�����, ������������ ���������� ������������
*/
int InsertionSort::GetPermutations()
{
	return permutations;
}

/*
	�����, ������������ ���������� ���������
*/
int InsertionSort::GetComparisons()
{
	return comparisons;
}

/*
	����� ��� ����������� ���� ��������� �������
*/
bool InsertionSort::Compare(int first, int second)
{
	comparisons++;
	return second > first;
}

/*
	����� ��� ������������ ���� ��������� �������
*/
void InsertionSort::Permutate(std::vector<int>& array, int posFirst, int posSecond)
{
	permutations++;
	std::swap(array[posFirst], array[posSecond]);
}
