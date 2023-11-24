#pragma once
#include "WorkWithArray.h"
class ArrayOutput : public WorkWithArray
{
public:
	virtual ~ArrayOutput();
	virtual void OpenFile() override;
	const void WriteArrayInFile(vector<int>& array);
};

