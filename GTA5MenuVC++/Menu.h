#pragma once
#include "..\inc\natives.h"
#include "..\inc\types.h"
#include "..\inc\enums.h"
#include "..\inc\main.h"

#include <string>
#include <array>

using std::string;

struct RGBA {
	int r, g, b, a;
};

#define MAIN_MENU_NAME "main_menu"
#define MAX_MENU_COUNT 100
#define MAX_OPTION_COUNT 100

class Menu
{
public:
	Menu();
	Menu(const RGBA& titleTextColour, const RGBA& titleRectColour, const RGBA& selectionColour, const RGBA& optionColour, const RGBA& optionsRectColour);

	string GetCurrentMenu() const;

	void _ChangeMenu(const string& menuname);
	void MenuBack();

	void Title(const string& title, const eFont font = FontPricedown);
	bool Option(const string& option);
	bool MenuOption(const string& option, const string& menu);
	bool IntOption(const string& option, int *var, int min, int max, int stepSize = 1);
	bool FloatOption(const string& option, float *var, float min, float max, float stepSize = 0.1f);
	bool BoolOption(const string& option, bool *var);

	void DrawMenu();
	void UpdateInput();

	void SetTitleTextColour(const RGBA& titleTextClr);
	void SetTitleRectColour(const RGBA& titleRectClr);
	void SetSelectionColour(const RGBA& selectionClr);
	void SetOptionsColour(const RGBA& optionsClr);
	void SetOptionsRectColour(const RGBA& optionsRectClr);
private:
	enum MenuSounds
	{
		BACK,
		SELECT,
		QUIT,
		NAV_UP_DOWN,
		YES,
		NO,
		CONTINUE
	};

	const float menuX = 0.2f;

	RGBA titleTextColour;
	RGBA titleRectColour;
	RGBA selectionColour;
	RGBA optionColour;
	RGBA optionsRectColour;

	int optionCount;
	int currentOption;
	int menuLevel;

	DWORD tickDelay;

	bool optionPressed;
	bool leftPressed;
	bool rightPressed;
	bool downPressed;
	bool upPressed;

	string currentMenu = "";

	std::array<string, MAX_MENU_COUNT> menuList;
	std::array<int, MAX_OPTION_COUNT> optionList;
	

	void _DrawText(string text, int font, float x, float y, float scaleX, float scaleY, RGBA colour, bool centered) const;
	void DrawRect(float x, float y, float width, float height, RGBA colour) const;
	void DrawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA colour) const;
	void PlayMenuSound(const MenuSounds sound) const;
};