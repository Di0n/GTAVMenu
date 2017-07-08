#pragma once
#include "..\inc\natives.h"
#include "..\inc\types.h"
#include "..\inc\enums.h"
#include "..\inc\main.h"
#include <string>

using std::string;

struct RGBA {
	int r, g, b, a;
};

struct Point2D {
	float x, y;
};

//extern float menux;
//extern RGBA titleText;
//extern RGBA titleRect;
//extern RGBA scroller;
//extern RGBA options;
//extern RGBA optionsrect;

class Menu {
public:
	Menu() {};
	Menu(RGBA titleText, RGBA titleRect, RGBA scroller, RGBA options, RGBA optionsRect) : titleText(titleText), titleRect(titleRect), scroller(scroller), options(options), optionsRect(optionsRect)
	{
		tickDelay = GetTickCount();
	};
	~Menu() {};

	char* GetCurrentMenuName() const;

	void _ChangeMenu(char* menuName);
	void MenuBack();

	void SetTitle(char* title);

	bool Option(char* option);
	bool MenuOption(char* option, char* menu);
	bool BoolOption(char* option);
	bool IntOption(char* option, int *var, int min, int max, int step = 1);
	bool FloatOption(char* option, float *var, float min, float max, float step = 0.1);
	bool BoolSpriteOption(char* option, bool b00l, char* category, char* spriteOn, char* spriteOff);
	bool IntArray(char* option, int display[], int *PlaceHolderInt);
	bool FloatArray(char* option, float display[], int *PlaceHolderInt);
	bool CharArray(char* option, char* display[], int *PlaceHolderInt);

	void EndMenu();
	void ProcessMenuInteraction();
	/*static bool currentMenu(char* menuname);
	static void changeMenu(char* menuname);
	static void backMenu();

	static void drawText(char* text, int font, float x, float y, float scalex, float scaley, RGBA RGBA, bool center);
	static void drawRect(float x, float y, float width, float height, RGBA RGBA);
	static void drawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA RGBA);

	static void Title(char* title);
	static bool Option(char* option);
	static bool MenuOption(char* option, char* menu);
	static bool IntOption(char* option, int *var, int min, int max, int step = 1);
	static bool FloatOption(char* option, float *var, float min, float max, float step = 0.1);
	static bool BoolOption(char* option, bool *b00l);
	static bool BoolSpriteOption(char* option, bool b00l, char* category, char* spriteOn, char* spriteOff);
	static bool IntArray(char* option, int display[], int *PlaceHolderInt);
	static bool FloatArray(char* option, float display[], int *PlaceHolderInt);
	static bool CharArray(char* option, char* display[], int *PlaceHolderInt);*/

	/*static void Load();

	static void endMenu();
	static void checkKeys();*/
private:
	void _DrawText(string text, int fontType, Point2D textPos, Point2D textScale, RGBA colour, BOOL centered) const;
	void DrawRect(Point2D rectPos, float width, float height, RGBA colour) const;
	void DrawSprite(char* streamedTexture, char* textureName, Point2D pos, float width, float height, float rotation, RGBA colour) const;

	void PlayMenuBeep() const;

	float menuX;
	RGBA titleText;
	RGBA titleRect;
	RGBA scroller;
	RGBA options;
	RGBA optionsRect;

	DWORD tickDelay;
	int menuLevel;
	bool optionPressed;
	int selectedOption;
	int optionCount;

	bool leftPressed, rightPressed;

	char* currentMenu;
};