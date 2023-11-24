#include "ConsoleInput.h"

/*
	Очистка потока ввода для корректного считывания с консоли
*/
void IgnoreLine()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
	Считывание целочисленного значения для заполнения массива
*/
int ReadInt(string message)
{
	cout << message;
	int tmp = 0;
	for(int counter = 0; counter < 10; counter++){
		cin >> tmp;
		//Если был введен недопустимый символ
		if (cin.fail()) {
			cin.clear();
			IgnoreLine();
			cout << "\nUse correct values!\n\n";
			cout << message;
		}
		else {
			IgnoreLine();
			return tmp;
		}
	}
	//Если пользователь исчерпал все попытки ввода, то вернется сигнализирующее значение
	cout << "\nLimit of attempts exceeded!\n\n";
	return INT_MIN;
}

/*
	Считывание положительного целочисленного значения для
	указания размера массива и выбора пункта меню
*/
int ReadMenuOption(string message)
{
	int tmp = 0;
	for (int counter = 0; counter < 10; counter++) {
		cout << message;
		cin >> tmp;
		//Если был введен недопустимый символ
		if (cin.fail()) {
			cin.clear();
			IgnoreLine();
			cout << "\nUse correct values!\n\n";
		}
		//Если введеное значение меньше нуля
		else if (tmp <= 0) {
			cout << "\nValue must be >0\n\n";
			cin.clear();
			IgnoreLine();
		}
		else {
			IgnoreLine();
			return tmp;
		}
	}
	//Если пользователь исчерпал все попытки ввода, то вернется сигнализирующее значение
	cout << "\nLimit of attempts exceeded!\n\n";
	return INT_MIN;
}

/*
	Считывание пути к файлу
*/
string ReadLink(string message)
{
	string b = "";
	cout << message;
	cout << "Path must not contain cyrillic symbols!\n\n>>";
	getline(cin, b);
	return b;
}

/*
	Считывание ответа в формате (y / n)
*/
char ReadAnswer(string message)
{
	string tmp{};
	for (int counter = 0; counter < 10; counter++) {
		cout << message;
		cin >> tmp;
		//Если не было ничего введено
		if (tmp == "\n") {
			cout << "You must type y or n!\n\n";
			cin.clear();
			IgnoreLine();
		}
		//Если введенный символ не соответствует формату
		else if (tmp != "y" && tmp != "n") {
			cout << "Incorrect input! Type only y or n!\n\n";
			cin.clear();
			IgnoreLine();
		}
		else {
			//Если было введено больше одного символа
			if (tmp.length() > 1) {
				cout << "Incorrect input! Type only y or n!\n\n";
				cin.clear();
				IgnoreLine();
			}
			return tmp[0];
		}
	}
	//Если пользователь исчерпал все попытки ввода, то вернется сигнализирующее значение
	cout << "\nLimit of attempts exceeded!\n";
	return char(0);
}


