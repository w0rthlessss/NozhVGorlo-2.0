#include "ConsoleInput.h"

void IgnoreLine()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int ReadInt(string message)
{
	cout << message;
	int tmp = 0;
	for(int counter = 0; counter < 10; counter++){
		cin >> tmp;
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
	cout << "\nLimit of attempts exceeded!\n\n";
	return INT_MIN;
}

int ReadMenuOption(string message)
{
	int tmp = 0;
	for (int counter = 0; counter < 10; counter++) {
		cout << message;
		cin >> tmp;
		if (cin.fail()) {
			cin.clear();
			IgnoreLine();
			cout << "\nUse correct values!\n\n";
		}
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
	cout << "\nLimit of attempts exceeded!\n\n";
	return INT_MIN;
}

string ReadLink(string message)
{
	string b = "";
	cout << message;
	cout << "Path must not contain cyrillic symbols!\n\n>>";
	getline(cin, b);
	return b;
}

char ReadAnswer(string message)
{
	string tmp{};
	for (int counter = 0; counter < 10; counter++) {
		cout << message;
		cin >> tmp;
		if (tmp == "\n") {
			cout << "You must type y or n!\n\n";
			cin.clear();
			IgnoreLine();
		}
		else if (tmp != "y" && tmp != "n") {
			cout << "Incorrect input! Type only y or n!\n\n";
			cin.clear();
			IgnoreLine();
		}
		else {
			if (tmp.length() > 1) {
				cout << "Incorrect input! Type only y or n!\n\n";

				cin.clear();
				IgnoreLine();
			}
			return tmp[0];
		}
	}
	cout << "\nLimit of attempts exceeded!\n";
	return char(0);
}


