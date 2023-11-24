#include "ArrayOutput.h"

/*
	����������, ����������� ����
*/
ArrayOutput::~ArrayOutput()
{
	file.close();
}

/*
	�������� ����� ��� ������
*/
void ArrayOutput::OpenFile()
{
	string name{};

	for(int counter = 0; counter < 10; counter++){
		name = ReadLink("\nEnter the name of file where array will be stored.\nExample: array.txt\n\n");

		/*�����, ����������� ������ � �����. ���������� 0, ���� ������ �������*/
		if (_access(name.c_str(), 0) == 0) {

			/*���� ���� ��� ����������, ���������� ������������ ������������ ���*/
			if (filesystem::exists(name)) {
				if (SaveResults("\nFile exists. Do you want to overwrite current data in the file") == 'n') continue;
			}

			file.open(name.c_str(), ios::out);
		}
		else {
			/*���� ������� � ����� ���, ��������� �� ���� ������. ENOENT - ���� �� ����������*/
			if (errno == ENOENT) {
				file.open(name.c_str(), ios::out);
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
