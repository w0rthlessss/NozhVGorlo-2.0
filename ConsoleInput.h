#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;

/*
	Файл необходимый для ввода значений с консоли, таких как:
	пункты меню, значения массива, ответы пользователя в формате (y / n),
	путь к файлу.
*/

enum InputMenu{consoleInput = 1, fileInput, randomInput, exitApp};

void IgnoreLine();

int ReadInt(string message);

int ReadMenuOption(string message);

string ReadLink(string message);

char ReadAnswer(string message);
