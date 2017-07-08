#pragma once
#include "..\inc\natives.h"
#include <string>

using std::string;

void showSubtitle(const string& text, const int duration);
void showNotification(const string& text);
char* stringToCharPtr(string str);
