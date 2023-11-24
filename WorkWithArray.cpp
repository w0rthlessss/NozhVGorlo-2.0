#include "WorkWithArray.h"

/*
	Конструктор класса по умолчанию.
	Создания объекта для работы с файлами
*/
WorkWithArray::WorkWithArray()
{
	this->file = fstream{};
}

/*
	Деструктор класса.
	Закрывает файл.
*/
WorkWithArray::~WorkWithArray()
{
	file.close();
}

/*
	Обработка пользовательского ответа в формате (y / n)
*/
char WorkWithArray::SaveResults(string message)
{
	cout << "\n" << message << " (y / n)\n\n";
	char answer = ReadAnswer(">>");
	if (answer == char(0)) cout << "Array was not saved\n\n";
	return answer;
}
