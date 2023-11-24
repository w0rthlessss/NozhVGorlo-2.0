#include "ArrayOutput.h"

/*
	Деструктор, закрывающий файл
*/
ArrayOutput::~ArrayOutput()
{
	file.close();
}

/*
	Открытие файла для записи
*/
void ArrayOutput::OpenFile()
{
	string name{};

	for(int counter = 0; counter < 10; counter++){
		name = ReadLink("\nEnter the name of file where array will be stored.\nExample: array.txt\n\n");

		/*Метод, проверяющий доступ к файлу. Возвращает 0, если доступ имеется*/
		if (_access(name.c_str(), 0) == 0) {

			/*Если файл уже существует, предложить пользователю перезаписать его*/
			if (filesystem::exists(name)) {
				if (SaveResults("\nFile exists. Do you want to overwrite current data in the file") == 'n') continue;
			}

			file.open(name.c_str(), ios::out);
		}
		else {
			/*Если доступа к файлу нет, проверяем по коду ошибки. ENOENT - файл не существует*/
			if (errno == ENOENT) {
				file.open(name.c_str(), ios::out);
			}
			/*Если файл существует, но доступа нет, то он иммет важное для системы значение и к нему нельзя обращаться*/
			else {
				cout << "\nAdress contains forbidden value!\n";
				continue;
			}
		}

		return;
	}

	//Если пользователь исчерпал все попытки ввода, то файл не откроется
	cout << "\nLimit of attempts exceeded!\n\n";
}

const void ArrayOutput::WriteArrayInFile(vector<int>& array)
{
	OpenFile();

	if (!file.is_open()) {
		cout << "\nUnable to open file!\n\n";
		return;
	}

	for (auto element : array) file << element << ' ';
	
	file.close();
}
