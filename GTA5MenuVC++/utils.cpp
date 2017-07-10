#include "utils.h"

void showSubtitle(const string& text, const int duration)
{
	UI::_SET_TEXT_ENTRY_2("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(const_cast<char*>(text.c_str()));
	UI::_DRAW_SUBTITLE_TIMED(duration, TRUE);
}

void showNotification(const string& text)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING3(const_cast<char*>(text.c_str()));
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}

char* stringToCharPtr(string str)
{
	return _strdup(str.c_str());
}

Vector3 vector3Add(const Vector3& vec1, const Vector3& vec2)
{
	Vector3 result;
	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return result;
}

Vector3 vector3Multiply(Vector3 vector, float val)
{
	vector.x *= val;
	vector.y *= val;
	vector.z *= val;
	return vector;
}