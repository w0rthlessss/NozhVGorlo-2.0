#pragma once
#include <fstream>
#include "ConsoleInput.h"
#include <vector>
#include <io.h>
#include <cerrno>
#include <filesystem>

class WorkWithArray {
protected:
	fstream file;
public:
	WorkWithArray();
	virtual ~WorkWithArray();
	char SaveResults(string message);
	virtual void OpenFile() = 0;
};
