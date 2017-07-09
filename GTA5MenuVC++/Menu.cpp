#include "Menu.h"
#include "..\inc\natives.h"
#include "..\inc\types.h"
#include "..\inc\enums.h"
#include "..\inc\main.h"
#include "keyboard.h"
#include <array>

#define MAX_MENU_COUNT 100
#define MAX_OPTION_COUNT 100

const float menuX = 0.2f;
RGBA titleTextColour = { 0, 0, 0, 255 };
RGBA titleRectColour = { 81, 200, 188, 255 }; //{ 191, 63, 63, 255 };  // orig: { 255, 200, 0, 255 };
RGBA selectionColour = { 80, 80, 80, 200 };
RGBA optionColour = { 255, 255, 255, 255 };
RGBA optionsRectColour = { 81, 172, 200, 60 }; // orig { 255, 220, 30, 60 };

int optionCount;
int currentOption;
bool optionPressed;
bool leftPressed;
bool rightPressed;
bool downPressed;
bool upPressed;

std::array<string, MAX_MENU_COUNT> menuList;
string currentMenu = "";

std::array<int, MAX_OPTION_COUNT> optionList;
int menuLevel = 0;

int tickDelay = GetTickCount();


string Menu::GetCurrentMenu()
{
	return currentMenu;
}

void Menu::_ChangeMenu(const string& menuname)
{
	menuList[menuLevel] = currentMenu;
	optionList[menuLevel] = currentOption;
	menuLevel++;
	currentMenu = menuname;
	currentOption = 1;
}

void Menu::MenuBack()
{
	menuLevel--;
	currentMenu = menuList[menuLevel];
	currentOption = optionList[menuLevel];
}
void Menu::Title(const string& title)
{
	optionCount = 0;
	_DrawText(title, 7, menuX, 0.095f, 0.85f, 0.85f, titleTextColour, true);
	DrawRect(menuX, 0.1175f, 0.23f, 0.085f, titleRectColour);
}

bool Menu::Option(const string& option)
{
	optionCount++;

	bool _option = false;
	if (currentOption == optionCount) _option = true;

	if (currentOption <= 16 && optionCount <= 16)
	{
		_DrawText(option, 6, menuX - 0.1f, (optionCount * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, false);
		DrawRect(menuX, ((optionCount * 0.035f) + 0.1415f), 0.23f, 0.035f, optionsRectColour);
		if (_option) DrawRect(menuX, ((optionCount * 0.035f) + 0.1415f), 0.23f, 0.035f, selectionColour);
	}

	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
	{
		_DrawText(option, 6, menuX - 0.1f, ((optionCount - (currentOption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, false);
		DrawRect(menuX, ((optionCount - (currentOption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, optionsRectColour);
		if (_option) DrawRect(menuX, ((optionCount - (currentOption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, selectionColour);
	}

	if (optionPressed && currentOption == optionCount) return true;
	else return false;
}

bool Menu::MenuOption(const string& option, const string& menu) {
	Option(option);

	if (currentOption <= 16 && optionCount <= 16)
		_DrawText(">>", 6, menuX + 0.068f, (optionCount * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);
	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
		_DrawText(">>", 6, menuX + 0.068f, ((optionCount - (currentOption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);

	if (optionPressed && currentOption == optionCount) {
		optionPressed = false;
		_ChangeMenu(menu);
		return true;
	}
	else return false;
}

bool Menu::IntOption(const string& option, int *var, int min, int max, int stepSize)
{
	Option(option);

	if (currentOption <= 16 && optionCount <= 16)
		_DrawText("<" + std::to_string(*var) + ">", 6, menuX + 0.068f, (optionCount * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);
	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
		_DrawText("<" + std::to_string(*var) + ">", 6, menuX + 0.068f, ((optionCount - (currentOption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);

	if (currentOption == optionCount) {
		if (leftPressed) {
			if (*var <= min) *var = max;
			else *var -= stepSize;
			leftPressed = false;
			return true;
		}
		if (*var < min) *var = max;
		if (rightPressed) {
			if (*var >= max) *var = min;
			else *var += stepSize;
			rightPressed = false;
			return true;
		}
		if (*var > max) *var = min;
	}

	if (optionPressed && currentOption == optionCount)
		return true;
	else return false;
}

bool Menu::FloatOption(const string& option, float *var, float min, float max, float stepSize)
{
	Option(option);
	
	char buf[100];
	_snprintf_s(buf, sizeof(buf), "%.2f", *var);

	if (currentOption <= 16 && optionCount <= 16)
		_DrawText("<" + static_cast<string>(buf) + ">", 6, menuX + 0.068f, (optionCount * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);
	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
		_DrawText("<" + static_cast<string>(buf) + ">", 6, menuX + 0.068f, ((optionCount - (currentOption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, optionColour, true);

	if (currentOption == optionCount) {
		if (leftPressed) {
			if (*var <= min) *var = max;
			else *var -= stepSize;
			leftPressed = false;
			return true;
		}
		if (*var < min) *var = max;

		if (rightPressed) {
			if (*var >= max) *var = min;
			else *var += stepSize;
			rightPressed = false;
			return true;
		}
		if (*var > max) *var = min;
	}
	
	if (optionPressed && currentOption == optionCount)
		return true;
	else return false;
}

bool Menu::BoolOption(const string& option, bool *var)
{
	Option(option);
	if (currentOption <= 16 && optionCount <= 16)
		DrawSprite("commonmenu", *var ? "shop_box_tick" : "shop_box_blank",
		menuX + 0.068f, (optionCount * 0.035f + 0.141f), 0.03f, 0.05f, 0, optionColour);
	else if ((optionCount > (currentOption - 16)) && optionCount <= currentOption)
		DrawSprite("commonmenu", *var ? "shop_box_tick" : "shop_box_blank",
		menuX + 0.068f, ((optionCount - (currentOption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, optionColour);
	if (optionPressed && currentOption == optionCount) {
		*var = !*var; //^= 1;
		return true;
	}
	else return false;
}

void Menu::DrawMenu()
{
	if (menuLevel > 0)
	{
		if (optionCount > 16)
		{
			const float defYPos = 17 * 0.035f;
			const float rectY = defYPos + 0.1415f;
			const float arrowDownPos = defYPos + 0.148f;
			const float arrowUpPos = defYPos + 0.137f;

			_DrawText(std::to_string(currentOption) + "/" + std::to_string(optionCount),
				6, menuX - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleTextColour, false);
			DrawRect(menuX, rectY, 0.23f, 0.035f, titleRectColour);

			if (currentOption == 1) {
				DrawSprite("commonmenu", "arrowright", menuX, arrowDownPos, 0.02f, 0.02f, 90, titleTextColour);
			}
			else if (currentOption == optionCount) {
				DrawSprite("commonmenu", "arrowright", menuX, arrowUpPos, 0.02f, 0.02f, 270, titleTextColour);
			}
			else {
				DrawSprite("commonmenu", "arrowright", menuX, arrowUpPos, 0.02f, 0.02f, 270, titleTextColour);
				DrawSprite("commonmenu", "arrowright", menuX, arrowDownPos, 0.02f, 0.02f, 90, titleTextColour);
			}
		}
		else
		{
			const float defYPos = (optionCount + 1) * 0.035f;
			const float rectY = defYPos + 0.1415f;
			const float arrowDownPos = defYPos + 0.148f;
			const float arrowUpPos = defYPos + 0.137f;

			_DrawText(std::to_string(currentOption) + "/" + std::to_string(optionCount),
				6, menuX - 0.1f, ((optionCount + 1) * 0.035f + 0.125f), 0.5f, 0.5f, titleTextColour, false);
			DrawRect(menuX, rectY, 0.23f, 0.035f, titleRectColour);

			if (currentOption == 1 && optionCount > 1) {
				DrawSprite("commonmenu", "arrowright", menuX, arrowDownPos, 0.02f, 0.02f, 90, titleTextColour);
			}
			else if (currentOption == optionCount && optionCount > 1) {
				DrawSprite("commonmenu", "arrowright", menuX, arrowUpPos, 0.02f, 0.02f, 270, titleTextColour);
			}
			else if (optionCount > 1) {
				DrawSprite("commonmenu", "arrowright", menuX, arrowUpPos, 0.02f, 0.02f, 270, titleTextColour);
				DrawSprite("commonmenu", "arrowright", menuX, arrowDownPos, 0.02f, 0.02f, 90, titleTextColour);
			}
		}


		UI::HIDE_HELP_TEXT_THIS_FRAME();
		CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlNextCamera, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleCinCam, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMichael, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterFranklin, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterTrevor, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMultiplayer, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlCharacterWheel, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackLight, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackHeavy, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackAlternate, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMultiplayerInfo, true);
		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMapPointOfInterest, true);

		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlWhistle, true);

		if (currentOption > optionCount) currentOption = optionCount;
		if (currentOption < 1) currentOption = 1;
	}
}

void Menu::UpdateInput()
{
	optionPressed = false;
	if (GetTickCount() - tickDelay > 150)
	{
		if (IsKeyDown(VK_MULTIPLY) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLb) &&
			CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRb))
		{
			if (menuLevel == 0)
			{
				PlayMenuSound(MenuSounds::CONTINUE);
				_ChangeMenu(MAIN_MENU_NAME);
			}
			else if (menuLevel == 1)
			{
				PlayMenuSound(MenuSounds::QUIT);
				MenuBack();
			}
			else if (menuLevel > 1)
			{
				PlayMenuSound(MenuSounds::BACK);
				MenuBack();
			}
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel)))
		{
			if (menuLevel > 0)
			{
				PlayMenuSound(MenuSounds::BACK);
				MenuBack();
			}
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)))
		{
			PlayMenuSound(MenuSounds::SELECT);
			optionPressed = true;
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown)))
		{
			PlayMenuSound(MenuSounds::NAV_UP_DOWN);
			currentOption = currentOption < optionCount ? currentOption + 1 : 1;
			downPressed = true;
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp)))
		{
			PlayMenuSound(MenuSounds::NAV_UP_DOWN);
			currentOption = currentOption > 1 ? currentOption - 1 : optionCount;
			upPressed = true;
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft)))
		{
			PlayMenuSound(MenuSounds::NAV_UP_DOWN);
			leftPressed = true;
			tickDelay = GetTickCount();
		}
		else if (menuLevel != 0 && (IsKeyDown(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)))
		{
			PlayMenuSound(MenuSounds::NAV_UP_DOWN);
			rightPressed = true;
			tickDelay = GetTickCount();
		}
	}
}

void Menu::_DrawText(string text, int font, float x, float y, float scaleX, float scaleY, RGBA colour, bool centered)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_COLOUR(colour.r, colour.g, colour.b, colour.a);
	UI::SET_TEXT_CENTRE(centered);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(const_cast<char*>(text.c_str()));
	UI::_DRAW_TEXT(x, y);
}

void Menu::DrawRect(float x, float y, float width, float height, RGBA colour)
{
	GRAPHICS::DRAW_RECT(x, y, width, height, colour.r, colour.g, colour.b, colour.a);
}

void Menu::DrawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA RGBA)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	else GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, RGBA.r, RGBA.g, RGBA.b, RGBA.a);
}

void Menu::PlayMenuSound(const MenuSounds sound)
{
	switch (sound)
	{
	case MenuSounds::BACK:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::SELECT:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::NAV_UP_DOWN:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::QUIT:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "QUIT", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::YES:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "YES", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::NO:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "NO", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	case MenuSounds::CONTINUE:
		AUDIO::PLAY_SOUND_FRONTEND(-1, "CONTINUE", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
		break;
	default:
		break;
	}
}

void Menu::SetColours(RGBA titleTextClr, RGBA titleRectClr, RGBA selectionClr, RGBA optionClr, RGBA optionsRectClr)
{
	titleTextColour = titleTextClr;
	titleRectColour = titleRectClr;
	selectionColour = selectionClr;
	optionColour = optionClr;
	optionsRectColour = optionsRectClr;
}