#pragma once
#include "WorkWithArray.h"

/*
	�����-��������� �� WorkWithArray
	�������� � ���� ����� ��� �������� ����� ��� ������
	� ����� ��� ������ ������� � ����
*/
class ArrayOutput : public WorkWithArray
{
public:
	virtual ~ArrayOutput();
	virtual void OpenFile() override;
	const void WriteArrayInFile(vector<int>& array);
};

