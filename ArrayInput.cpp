#include "ArrayInput.h"

/*
	Границы для генерации случайных значений массива
	(Можно менять на любые другие)
*/
const int lowerRandomRange = -999;
const int upperRandomRange = 999;

/*
	Деструктор класса
*/
ArrayInput::~ArrayInput()
{
	file.close();
}

/*
	Метод, открывающий файл для чтения.
*/
void ArrayInput::OpenFile()
{
	string name{};
	for(int counter =0; counter < 10; counter++) {
		name = ReadLink("\nEnter the name of file with data. Example: ArrayValues.txt\n");

		/*Метод, проверяющий доступ к файлу. Возвращает 0, если доступ имеется*/
		if (_access(name.c_str(), 0) == 0) {
			file.open(name.c_str(), ios::in);
		}
		else {
			/*Если доступа к файлу нет, проверяем по коду ошибки. ENOENT - файл не существует*/
			if (errno == ENOENT) {
				cout << "\nError opening file. Make sure, that file exists!\n";
				continue;
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

/*
	Заполнение массива рандомными значениями
*/
void ArrayInput::RandomInput(vector<int>& array)
{
	/*Привязка генерации чисел ко времени*/
	srand(static_cast<unsigned int>(time(NULL)));
	int arraySize = ReadInt("\nEnter number of elements in array\n\n>>");
	array.resize(arraySize);
	
	for (auto index = 0; index < arraySize; index++)
		array[index] = lowerRandomRange + rand() %
		(upperRandomRange + 1 - lowerRandomRange);

	PrintCurrentArray(array);
}

/*
	Заполнение массива данными из файла
*/
bool ArrayInput::FileInput(vector<int>& array)
{
	int tmpValue{};

	OpenFile();

	/*Если пользователь исчерпал все попытки*/
	if (!file.is_open()) return false;

	do {
		file >> tmpValue;

		if (file.eof()) break;

		if (file.fail()) {
			cout << "\nError! Invalid data in the file! Check array values!\n";
			array.clear();
			file.close();
			return false;
		}

		array.push_back(tmpValue);

	} while (!file.eof());

	file.close();

	return true;
}

/*
	Заполнение массива данными с консоли
*/
void ArrayInput::ConsoleInput(vector<int>& array)
{
	int arraySize = ReadMenuOption("\nEnter number of elements in array\n\n>>");
	array.resize(arraySize);

	cout << "\nEnter " << arraySize << "elements:\n";
	for (auto index = 0; index < arraySize; index++) {
		array[index] = ReadInt(">>");
		if (array[index] == INT_MIN) {
			index--;
		}
	}
	PrintCurrentArray(array);
}

/*
	Вывод текущего массива в консоль
*/
const void ArrayInput::PrintCurrentArray(vector<int>& array)
{
	cout << "\nCurrent array is:\n\n";
	for (auto element : array) cout << element << ' ';
	cout << "\n\n";
}
