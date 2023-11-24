#include "ArrayOutput.h"

ArrayOutput::~ArrayOutput()
{
	file.close();
}

void ArrayOutput::OpenFile()
{
	string name{};

	do {
		name = ReadLink("\nEnter the name of file where array will be stored.\nExample: array.txt\n\n");

		if (_access(name.c_str(), 0) == 0) {

			if (filesystem::exists(name)) {
				if (SaveResults("\nFile exists. Do you want to overwrite current data in the file") == 'n') continue;
			}

			file.open(name.c_str(), ios::out);
		}
		else {
			if (errno == ENOENT) {
				file.open(name.c_str(), ios::out);
			}
			else {
				cout << "\nAdress contains forbidden value!\n";
				continue;
			}
		}

		return;
	} while (true);
}

const void ArrayOutput::WriteArrayInFile(vector<int>& array)
{
	OpenFile();

	for (auto element : array) file << element << ' ';
	
	file.close();
}
