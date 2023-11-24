#pragma once
#include "WorkWithArray.h"

/*
	Класс-наследник от WorkWithArray
	Содержит в себе метод для открытия файла для записи
	и метод для записи массива в файл
*/
class ArrayOutput : public WorkWithArray
{
public:
	virtual ~ArrayOutput();
	virtual void OpenFile() override;
	const void WriteArrayInFile(vector<int>& array);
};

