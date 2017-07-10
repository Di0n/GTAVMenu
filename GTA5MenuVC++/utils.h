#pragma once
#include "..\inc\natives.h"
#include <string>

using std::string;

void showSubtitle(const string& text, const int duration);
void showNotification(const string& text);
char* stringToCharPtr(string str);

Vector3 vector3Add(const Vector3& vec1, const Vector3& vec2);

Vector3 vector3Multiply(Vector3 vector, float val);