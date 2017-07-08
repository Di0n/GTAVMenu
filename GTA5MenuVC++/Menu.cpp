//#include "Menu.h"
//#include "keyboard.h"
//#include "utils.h"
//
//float menux = 0.2f;
//RGBA titleText = { 0, 0, 0, 255 };
//RGBA titleRect = { 255, 200, 0, 255 };
//RGBA scroller = { 80, 80, 80, 200 };
//RGBA options = { 0, 0, 0, 255 };
//RGBA optionsrect = { 255, 220, 30, 60 };
//
//int optioncount;
//int currentoption;
//bool optionpress = false;
//bool leftpress = false;
//bool rightpress = false;
//bool uppress = false;
//bool downpress = false;
//
//char* currentmenu[100];
//char* actualmenu = "";
//int lastoption[100];
//int menulevel = 0;
//int infocount;
//int Delay = GetTickCount();
//
//
//bool Menu::currentMenu(char* menuname) {
//	if (menuname == actualmenu) return true;
//	else return false;
//}
//
//void Menu::changeMenu(char* menuname) {
//	currentmenu[menulevel] = actualmenu;
//	lastoption[menulevel] = currentoption;
//	menulevel++;
//	actualmenu = menuname;
//	currentoption = 1;
//}
//
//void Menu::backMenu() {
//	menulevel--;
//	actualmenu = currentmenu[menulevel];
//	currentoption = lastoption[menulevel];
//}
//
//void Menu::drawText(char* text, int font, float x, float y, float scalex, float scaley, RGBA RGBA, bool center) {
//	UI::SET_TEXT_FONT(font);
//	UI::SET_TEXT_SCALE(scalex, scaley);
//	UI::SET_TEXT_COLOUR(RGBA.r, RGBA.g, RGBA.b, RGBA.a);
//	UI::SET_TEXT_CENTRE(center);
//	UI::_SET_TEXT_ENTRY("STRING");
//	//UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
//	UI::_ADD_TEXT_COMPONENT_STRING(text);
//	UI::_DRAW_TEXT(x, y);
//};
//
//void Menu::drawRect(float x, float y, float width, float height, RGBA RGBA) {
//	GRAPHICS::DRAW_RECT(x, y, width, height, RGBA.r, RGBA.g, RGBA.b, RGBA.a);
//};
//
//void Menu::drawSprite(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, RGBA RGBA)
//{
//	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture)) GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
//	else GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, RGBA.r, RGBA.g, RGBA.b, RGBA.a);
//};
//
//void Menu::Title(char* title) {
//	optioncount = 0;
//	drawText(title, 7, menux, 0.095f, 0.85f, 0.85f, titleText, true);
//	drawRect(menux, 0.1175f, 0.23f, 0.085f, titleRect);
//};
//
//bool Menu::Option(char* option) {
//	optioncount++;
//
//	bool thisOption = false;
//	if (currentoption == optioncount) thisOption = true;
//
//	if (currentoption <= 16 && optioncount <= 16)
//	{
//		drawText(option, 6, menux - 0.1f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, false);
//		drawRect(menux, ((optioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, optionsrect);
//		if (thisOption) drawRect(menux, ((optioncount * 0.035f) + 0.1415f), 0.23f, 0.035f, scroller);
//	}
//
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//	{
//		drawText(option, 6, menux - 0.1f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, false);
//		drawRect(menux, ((optioncount - (currentoption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, optionsrect);
//		if (thisOption) drawRect(menux, ((optioncount - (currentoption - 16)) * 0.035f + 0.1415f), 0.23f, 0.035f, scroller);
//	}
//
//	if (optionpress && currentoption == optioncount) return true;
//	else return false;
//};
//
//bool Menu::MenuOption(char* option, char* menu) {
//	Option(option);
//
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(">>", 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(">>", 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (optionpress && currentoption == optioncount) {
//		optionpress = false;
//		changeMenu(menu);
//		return true;
//	}
//	else return false;
//}
//
//bool Menu::IntOption(char* option, int *var, int min, int max, int step) {
//	Option(option);
//
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(stringToCharPtr("<" + std::to_string(*var) + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(stringToCharPtr("<" + std::to_string(*var) + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (currentoption == optioncount) {
//		if (leftpress) {
//			if (*var <= min) *var = max;
//			else *var -= step;
//			leftpress = false;
//			return true;
//		}
//		if (*var < min) *var = max;
//		if (rightpress) {
//			if (*var >= max) *var = min;
//			else *var += step;
//			rightpress = false;
//			return true;
//		}
//		if (*var > max) *var = min;
//	}
//
//	if (optionpress && currentoption == optioncount)
//		return true;
//	else return false;
//}
//
//bool Menu::FloatOption(char* option, float *var, float min, float max, float step) {
//	Option(option);
//
//
//
//	char buf[100];
//	_snprintf_s(buf, sizeof(buf), "%.2f", *var);
//
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(stringToCharPtr("<" + (std::string)buf + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(stringToCharPtr("<" + (std::string)buf + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (currentoption == optioncount) {
//		if (leftpress) {
//			if (*var <= min) *var = max;
//			else *var -= step;
//			leftpress = false;
//			return true;
//		}
//		if (*var < min) *var = max;
//
//		if (rightpress) {
//			if (*var >= max) *var = min;
//			else *var += step;
//			rightpress = false;
//			return true;
//		}
//		if (*var > max) *var = min;
//	}
//
//	if (optionpress && currentoption == optioncount)
//		return true;
//	else return false;
//}
//
//bool Menu::BoolOption(char* option, bool *b00l) {
//	Option(option);
//	if (currentoption <= 16 && optioncount <= 16)
//		drawSprite("commonmenu", *b00l ? "shop_box_tick" : "shop_box_blank",
//		menux + 0.068f, (optioncount * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawSprite("commonmenu", *b00l ? "shop_box_tick" : "shop_box_blank",
//		menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);
//	if (optionpress && currentoption == optioncount) {
//		*b00l ^= 1;
//		return true;
//	}
//	else return false;
//}
//
//bool Menu::BoolSpriteOption(char* option, bool b00l, char* category, char* spriteOn, char* spriteOff) {
//	Option(option);
//
//	if (currentoption <= 16 && optioncount <= 16)
//		drawSprite(category, b00l ? spriteOn : spriteOff,
//		menux + 0.068f, (optioncount * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawSprite(category, b00l ? spriteOn : spriteOff,
//		menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.141f), 0.03f, 0.05f, 0, options);
//
//	if (optionpress && currentoption == optioncount) return true;
//	else return false;
//}
//
//bool Menu::IntArray(char* option, int display[], int *PlaceHolderInt) {
//	Option(option);
//
//	int min = 0;
//	int max = sizeof(display) / sizeof(*display);
//
//	if (currentoption == optioncount) {
//		if (leftpress) {
//			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
//			else PlaceHolderInt -= 1;
//			leftpress = false;
//			return true;
//		}
//		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
//		if (rightpress) {
//			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
//			else *PlaceHolderInt += 1;
//			rightpress = false;
//			return true;
//		}
//		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
//	}
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(stringToCharPtr("<" + std::to_string(display[*PlaceHolderInt]) + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(stringToCharPtr("<" + std::to_string(display[*PlaceHolderInt]) + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (optionpress && currentoption == optioncount)
//		return true;
//	else return false;
//}
//
//bool Menu::FloatArray(char* option, float display[], int *PlaceHolderInt) {
//	Option(option);
//
//	int min = 0;
//	int max = sizeof(display) / sizeof(*display);
//
//	if (currentoption == optioncount) {
//		if (leftpress) {
//			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
//			else *PlaceHolderInt -= 1;
//			leftpress = false;
//			return true;
//		}
//		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
//		if (rightpress) {
//			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
//			else *PlaceHolderInt += 1;
//			rightpress = false;
//			return true;
//		}
//		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
//	}
//
//	char buf[30];
//	_snprintf_s(buf, sizeof(buf), "%.2f", display[*PlaceHolderInt]);
//
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(stringToCharPtr("<" + (std::string)buf + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(stringToCharPtr("<" + (std::string)buf + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (optionpress && currentoption == optioncount)
//		return true;
//	else return false;
//}
//
//bool Menu::CharArray(char* option, char* display[], int *PlaceHolderInt) {
//	Option(option);
//
//	int min = 0;
//	int max = sizeof(display) / sizeof(*display) + 1;
//
//	if (currentoption == optioncount) {
//		if (leftpress) {
//			if (*PlaceHolderInt <= min) *PlaceHolderInt = max;
//			else *PlaceHolderInt -= 1;
//			leftpress = false;
//		}
//		if (*PlaceHolderInt < min) *PlaceHolderInt = max;
//		if (rightpress) {
//			if (*PlaceHolderInt >= max) *PlaceHolderInt = min;
//			else *PlaceHolderInt += 1;
//			rightpress = false;
//		}
//		if (*PlaceHolderInt > max) *PlaceHolderInt = min;
//	}
//	if (currentoption <= 16 && optioncount <= 16)
//		drawText(stringToCharPtr("<" + (std::string)display[*PlaceHolderInt] + ">"), 6, menux + 0.068f, (optioncount * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//	else if ((optioncount > (currentoption - 16)) && optioncount <= currentoption)
//		drawText(stringToCharPtr("<" + (std::string)display[*PlaceHolderInt] + ">"), 6, menux + 0.068f, ((optioncount - (currentoption - 16)) * 0.035f + 0.125f), 0.5f, 0.5f, options, true);
//
//	if (optionpress && currentoption == optioncount)
//		return true;
//	else return false;
//}
//
//void Menu::Load()
//{
//	titleText.r = 0;
//	titleText.g = 0;
//	titleText.b = 0;
//	titleText.a = 255;
//
//
//	// Title Rect
//	titleRect.r = 108;
//	titleRect.g = 171;
//	titleRect.b = 243;
//	titleRect.a = 255;
//
//	// Scroller
//	scroller.r = 255;
//	scroller.g = 255;
//	scroller.b = 255;
//	scroller.a = 200;
//
//	// Option Text
//	options.r = 243;
//	options.g = 162;
//	options.b = 108;
//	options.a = 225;
//
//	// Option Rect
//	optionsrect.r = 0;
//	optionsrect.g = 0;
//	optionsrect.b = 0;
//	optionsrect.a = 60;
//}
//
//
//void Menu::endMenu() {
//	if (menulevel > 0)
//	{
//		if (optioncount > 16)
//		{
//			drawText(stringToCharPtr(std::to_string(currentoption) + "/" + std::to_string(optioncount)),
//				6, menux - 0.1f, (17 * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
//			drawRect(menux, (17 * 0.035f + 0.1415f), 0.23f, 0.035f, titleRect);
//
//			if (currentoption == 1) {
//				drawSprite("commonmenu", "arrowright", menux, ((16 + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 90, titleText);
//			}
//			else if (currentoption == optioncount) {
//				drawSprite("commonmenu", "arrowright", menux, ((16 + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 270, titleText);
//			}
//			else {
//				drawSprite("commonmenu", "arrowright", menux, ((16 + 1) * 0.035f + 0.14f), 0.02f, 0.02f, 270, titleText);
//				drawSprite("commonmenu", "arrowright", menux, ((16 + 1) * 0.035f + 0.15f), 0.02f, 0.02f, 90, titleText);
//			}
//		}
//		else
//		{
//			drawText(stringToCharPtr(std::to_string(currentoption) + "/" + std::to_string(optioncount)),
//				6, menux - 0.1f, ((optioncount + 1) * 0.035f + 0.125f), 0.5f, 0.5f, titleText, false);
//			drawRect(menux, ((optioncount + 1) * 0.035f + 0.1415f), 0.23f, 0.035f, titleRect);
//
//			if (currentoption == 1 && optioncount > 1) {
//				drawSprite("commonmenu", "arrowright", menux, ((optioncount + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 90, titleText);
//			}
//			else if (currentoption == optioncount && optioncount > 1) {
//				drawSprite("commonmenu", "arrowright", menux, ((optioncount + 1) * 0.035f + 0.145f), 0.02f, 0.02f, 270, titleText);
//			}
//			else if (optioncount > 1) {
//				drawSprite("commonmenu", "arrowright", menux, ((optioncount + 1) * 0.035f + 0.14f), 0.02f, 0.02f, 270, titleText);
//				drawSprite("commonmenu", "arrowright", menux, ((optioncount + 1) * 0.035f + 0.15f), 0.02f, 0.02f, 90, titleText);
//			}
//		}
//
//
//		UI::HIDE_HELP_TEXT_THIS_FRAME();
//		CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
//		UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
//		UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
//		UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
//		UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
//		UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
//
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlNextCamera, true);
//
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlPhone, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlVehicleCinCam, true);
//
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMichael, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterFranklin, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterTrevor, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlSelectCharacterMultiplayer, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlCharacterWheel, true);
//
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackLight, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackHeavy, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMeleeAttackAlternate, true);
//
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMultiplayerInfo, true);
//		CONTROLS::DISABLE_CONTROL_ACTION(2, ControlMapPointOfInterest, true);
//
//		if (currentoption > optioncount) currentoption = optioncount;
//		if (currentoption < 1) currentoption = 1;
//	}
//}
//
//void Menu::checkKeys() {
//	optionpress = false;
//	if (GetTickCount() - Delay > 150) {
//		if (IsKeyJustUp(VK_MULTIPLY) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLb) &&
//			CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRb)) {
//			
//			if (menulevel == 0) changeMenu("mainmenu");
//			else if (menulevel == 1) backMenu();
//			Delay = GetTickCount();
//		}
//		if ( /*getKeyPressed(VK_NUMPAD0)*/IsKeyJustUp(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel)) {
//			if (menulevel > 0)
//				backMenu();
//			Delay = GetTickCount();
//		}
//		if (IsKeyJustUp(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
//			optionpress = true;
//			Delay = GetTickCount();
//		}
//		if (IsKeyJustUp(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown)) {
//			if (currentoption < optioncount)
//				currentoption++;
//			else
//				currentoption = 1;
//			Delay = GetTickCount();
//			downpress = true;
//		}
//		if (IsKeyJustUp(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp)) {
//			if (currentoption > 1)
//				currentoption--;
//			else
//				currentoption = optioncount;
//			Delay = GetTickCount();
//			uppress = true;
//		}
//		if (IsKeyJustUp(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft)) {
//			leftpress = true;
//			Delay = GetTickCount();
//		}
//		if (IsKeyJustUp(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) {
//			rightpress = true;
//			Delay = GetTickCount();
//		}
//	}
//}

#include "Menu.h"
#include "keyboard.h"

void Menu::PlayMenuBeep() const
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", FALSE);
}

void Menu::_DrawText(string text, int fontType, Point2D textPos, Point2D textScale, RGBA colour, BOOL centered) const
{
		UI::SET_TEXT_FONT(fontType);
		UI::SET_TEXT_SCALE(textScale.x, textScale.y);
		UI::SET_TEXT_COLOUR(colour.r,colour.g, colour.b, colour.a);
		UI::SET_TEXT_CENTRE(centered);
		UI::_SET_TEXT_ENTRY("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING((char*)text.c_str());
		UI::_DRAW_TEXT(textPos.x, textPos.y);
}

void Menu::DrawRect(Point2D rectPos, float width, float height, RGBA colour) const
{
	GRAPHICS::DRAW_RECT(rectPos.x, rectPos.y, width, height, colour.g,  colour.g, colour.b, colour.a);
}

void Menu::DrawSprite(char* streamedTexture, char* textureName, Point2D pos, float width, float height, float rotation, RGBA colour) const
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(streamedTexture))
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(streamedTexture, FALSE);
	else GRAPHICS::DRAW_SPRITE(streamedTexture, textureName, pos.x, pos.y, width, height, rotation, colour.r, colour.g, colour.b, colour.a);
}

void Menu::ProcessMenuInteraction()
{
	if (GetTickCount() - tickDelay > 150) // native trainer menu defines this
	{
		if (IsKeyJustUp(VK_F7) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRb) && CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, ControlPhoneRight))
		{
			if (menuLevel == 0) _ChangeMenu("main_menu");
			else if (menuLevel == 1) MenuBack(); // TODO check this >= 1
			
		}
		if (IsKeyJustUp(VK_NUMPAD0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel))
		{
			if (menuLevel > 0)
				MenuBack();
		}
		if (IsKeyJustUp(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept))
		{
			optionPressed = true;
		}
		if (IsKeyJustUp(VK_NUMPAD2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown))
		{
			selectedOption = selectedOption < optionCount ? selectedOption + 1 : 1;
			// downpress = true ??
		}
		if (IsKeyJustUp(VK_NUMPAD8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp))
		{
			selectedOption = selectedOption > 1 ? selectedOption - 1 : optionCount;
			// uppress = true
		}
		if (IsKeyJustUp(VK_NUMPAD4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft))
		{
			leftPressed = true;
		}
		if (IsKeyJustUp(VK_NUMPAD6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight))
		{
			rightPressed = true;
		}
		tickDelay = GetTickCount();
	}
}

char* Menu::GetCurrentMenuName() const
{
	return currentMenu;
}
void Menu::MenuBack()
{
	menuLevel--;
	//currentMenu = 
}

void Menu::_ChangeMenu(char* menuName)
{

}

void Menu::SetTitle(char* title)
{
	optionCount = 0;

	Point2D textPos;
	textPos.x = menuX;
	textPos.y = 0.095f;
	Point2D textScale;
	textScale.x = 0.85f;
	textScale.y = 0.85f;
	Point2D rectPos;
	rectPos.x = menuX;
	rectPos.y = 0.1175f;

	_DrawText(title, 7, textPos, textScale, titleText, TRUE);
	DrawRect(rectPos, 0.23f, 0.085f, titleRect);
}

bool Menu::Option(char* option)
{
	optionCount++;

	bool _option = false;
	if (selectedOption == optionCount) _option = true;

	if (selectedOption <= 16 && optionCount <= 16)
	{
		Point2D textPos;
		textPos.x = menuX - 0.1f;
		textPos.y = (optionCount * 0.035f + 0.125f);
		Point2D textScale;
		textScale.x = 0.5f;
		textScale.y = 0.5f;
		_DrawText(option, 6, textPos, textScale, options, FALSE);
		Point2D rectPos;
		rectPos.x = menuX;
		rectPos.y = ((optionCount * 0.035f) + 0.1415f);
		DrawRect(rectPos, 0.23f, 0.035f, optionsRect);

		if (_option) DrawRect(rectPos, 0.23f, 0.035f, scroller);
	}
	else if ((optionCount > (selectedOption - 16)) && optionCount <= selectedOption)
	{
		Point2D textPos;
		textPos.x = menuX - 0.1f;
		textPos.y = ((optionCount - (selectedOption - 16)) * 0.035f + 0.125f);
		Point2D textScale;
		textScale.x = 0.5f;
		textScale.y = 0.5f;
		_DrawText(option, 6, textPos, textScale, options, FALSE);
		
		Point2D rectPos;
		rectPos.x = menuX;
		rectPos.y = ((optionCount * 0.035f) + 0.1415f);
		DrawRect(rectPos, 0.23f, 0.035f, optionsRect);

		if (_option) DrawRect(rectPos, 0.23f, 0.035f, scroller);
	}
	return (optionPressed && selectedOption == optionCount) ? true : false;
}

bool Menu::MenuOption(char* option, char* menu)
{
	Option(option);

	if (selectedOption <= 16 && optionCount <= 16)
	{
		Point2D textPos;
		textPos.x = menuX + 0.068f;
		textPos.y = (optionCount * 0.035f + 0.125f);
		Point2D textScale;
		textScale.x = 0.5f;
		textScale.y = 0.5f;
		_DrawText(">>", 6, textPos, textScale, options, TRUE);
	}
	else if ((optionCount > (selectedOption - 16)) && optionCount <= selectedOption)
	{
		Point2D textPos;
		textPos.x = menuX + 0.068f;
		textPos.y = ((optionCount - (selectedOption - 16)) * 0.035f + 0.125f);
		Point2D textScale;
		textScale.x = 0.5f;
		textScale.y = 0.5f;
		_DrawText(">>", 6, textPos, textScale, options, TRUE);
	}

	if (optionPressed && selectedOption == optionCount)
	{
		optionPressed = false;
		_ChangeMenu(menu);
		return true;
	}
	return false;
}