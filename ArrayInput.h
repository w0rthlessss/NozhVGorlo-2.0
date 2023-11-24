#pragma once
#include "WorkWithArray.h"

/*
	Класс-наследник от WorkWithArray
	Содержит в себе метод для открытия файла для чтения,
	методы для заполнения массива и вывода его на экран
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

