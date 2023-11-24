#include "ArrayInput.h"

/*
	������� ��� ��������� ��������� �������� �������
	(����� ������ �� ����� ������)
*/
const int lowerRandomRange = -999;
const int upperRandomRange = 999;

/*
	���������� ������
*/
ArrayInput::~ArrayInput()
{
	file.close();
}

/*
	�����, ����������� ���� ��� ������.
*/
void ArrayInput::OpenFile()
{
	string name{};
	for(int counter =0; counter < 10; counter++) {
		name = ReadLink("\nEnter the name of file with data. Example: ArrayValues.txt\n");

		/*�����, ����������� ������ � �����. ���������� 0, ���� ������ �������*/
		if (_access(name.c_str(), 0) == 0) {
			file.open(name.c_str(), ios::in);
		}
		else {
			/*���� ������� � ����� ���, ��������� �� ���� ������. ENOENT - ���� �� ����������*/
			if (errno == ENOENT) {
				cout << "\nError opening file. Make sure, that file exists!\n";
				continue;
			}
			/*���� ���� ����������, �� ������� ���, �� �� ����� ������ ��� ������� �������� � � ���� ������ ����������*/
			else {
				cout << "\nAdress contains forbidden value!\n";
				continue;
			}
		}
		return;
	}
	//���� ������������ �������� ��� ������� �����, �� ���� �� ���������
	cout << "\nLimit of attempts exceeded!\n\n";
}

/*
	���������� ������� ���������� ����������
*/
void ArrayInput::RandomInput(vector<int>& array)
{
	/*�������� ��������� ����� �� �������*/
	srand(static_cast<unsigned int>(time(NULL)));
	int arraySize = ReadInt("\nEnter number of elements in array\n\n>>");
	array.resize(arraySize);
	
	for (auto index = 0; index < arraySize; index++)
		array[index] = lowerRandomRange + rand() %
		(upperRandomRange + 1 - lowerRandomRange);

	PrintCurrentArray(array);
}

/*
	���������� ������� ������� �� �����
*/
bool ArrayInput::FileInput(vector<int>& array)
{
	int tmpValue{};

	OpenFile();

	/*���� ������������ �������� ��� �������*/
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
	���������� ������� ������� � �������
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
	����� �������� ������� � �������
*/
const void ArrayInput::PrintCurrentArray(vector<int>& array)
{
	cout << "\nCurrent array is:\n\n";
	for (auto element : array) cout << element << ' ';
	cout << "\n\n";
}
