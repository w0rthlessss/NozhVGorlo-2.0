#pragma once
#include "WorkWithArray.h"

/*
	�����-��������� �� WorkWithArray
	�������� � ���� ����� ��� �������� ����� ��� ������,
	������ ��� ���������� ������� � ������ ��� �� �����
*/
class ArrayInput : public WorkWithArray
{
public:
	virtual ~ArrayInput();
	virtual void OpenFile() override;
	void RandomInput(vector<int>& array);
	bool FileInput(vector<int>& array);
	void ConsoleInput(vector <int>& array);
	const void PrintCurrentArray(vector<int>& array);
	
};

