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