#include "WorkWithArray.h"

WorkWithArray::WorkWithArray()
{
	this->file = fstream{};
}

WorkWithArray::~WorkWithArray()
{
	file.close();
}

char WorkWithArray::SaveResults(string message)
{
	cout << "\n" << message << " (y / n)\n\n";
	char answer = ReadAnswer(">>");
	if (answer == char(0)) cout << "Array was not saved\n\n";
	return answer;
}
