#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum InputMenu{consoleInput = 1, fileInput, randomInput, exitApp};

void IgnoreLine();

int ReadInt(string message);

int ReadMenuOption(string message);

string ReadLink(string message);

char ReadAnswer(string message);
