#pragma once

#include <string>

using std::string;
class TrainerMenu
{
public:
	struct RGBA
	{
		unsigned short int r, g, b, a;
	};
	TrainerMenu();
	~TrainerMenu();
	void Update();
private:
	string menuTitle;
	int currentLineIndex = 0;
	void Draw(string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);

};

