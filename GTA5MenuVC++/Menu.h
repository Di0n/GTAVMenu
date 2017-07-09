#pragma once
#include <string>

using std::string;
struct RGBA {
	int r, g, b, a;
};

#define MAIN_MENU_NAME "main_menu"
class Menu {
public:
	static string GetCurrentMenu();
	static void _ChangeMenu(const string& menuname);
	static void MenuBack();

	static void Title(const string& title);
	static bool Option(const string& option);
	static bool MenuOption(const string& option, const string& menu);
	static bool IntOption(const string& option, int *var, int min, int max, int stepSize = 1);
	static bool FloatOption(const string& option, float *var, float min, float max, float stepSize = 0.1f);
	static bool BoolOption(const string& option, bool *var);

	static void DrawMenu();
	static void UpdateInput();

	static void SetColours(RGBA titleTextClr, RGBA titleRectClr, RGBA selectionClr, RGBA optionClr, RGBA optionsRectClr);
private:
	static enum MenuSounds
	{
		BACK,
		SELECT,
		QUIT,
		NAV_UP_DOWN,
		YES,
		NO,
		CONTINUE
	};

	static void _DrawText(string text, int font, float x, float y, float scaleX, float scaleY, RGBA colour, bool centered);
	static void DrawRect(float x, float y, float width, float height, RGBA colour);
	static void DrawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA colour);
	static void PlayMenuSound(const MenuSounds sound);
};