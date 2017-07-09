#include "script.h"
#include "keyboard.h"
#include "Menu.h"
#include "utils.h"

void update();
void handleKeyboardInput();
void processMenu();

void scriptMain()
{

	showNotification("Loaded menu");
	while (true)
	{
		update();
		WAIT(0);
	}
}

void update()
{
	processMenu();
	handleKeyboardInput();
}

bool toggle = false;
void handleKeyboardInput()
{
	if (IsKeyJustUp(0x39))
	{
		toggle = !toggle;
		showSubtitle("Pressed", 2000);
	}
}


void processMenu()
{

}