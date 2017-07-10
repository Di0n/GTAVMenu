#include "script.h"
#include "keyboard.h"
#include "utils.h"

#include "Menu.h"

void update();
void handleKeyboardInput();
void processMenu();

Menu menu;


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

void handleKeyboardInput()
{

}


int intVar = 0;
float floatVar = 0;
bool boolVar = false;
bool blackout = false;

void processMenu()
{
	menu.UpdateInput();

	if (menu.GetCurrentMenu() == MAIN_MENU_NAME)
	{
		menu.Title("Main Menu");
		const bool b = menu.Option("Test option");
		
		menu.IntOption("Int test", &intVar, 0, 10);
		menu.FloatOption("Float test", &floatVar, 0 , 15);
		const bool stabber = menu.Option("Spawn stabber");
		const bool emp = menu.BoolOption("EMP", &blackout);

		menu.MenuOption("Test Menu", "test_menu");
		menu.MenuOption("Another Menu", "another_menu");

		if (stabber)
		{
			Ped player = PLAYER::PLAYER_PED_ID();
			Vector3 pos = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(player, 0, 0, 0);
			Vector3 forwardVec = ENTITY::GET_ENTITY_FORWARD_VECTOR(player);

			Vector3 pedPos = vector3Add(pos, vector3Multiply(forwardVec, 3));
			Ped handle = PED::CREATE_RANDOM_PED(pedPos.x, pedPos.y, pedPos.z);

			WEAPON::GIVE_WEAPON_TO_PED(handle, 0x99B507EA, 1, false, true);


			const int num = 10;
			const int arrSize = num * 2 + 2;
			Ped peds[arrSize];
			peds[0] = num;

			const int count = PED::GET_PED_NEARBY_PEDS(player, peds, -1);
			showSubtitle(std::to_string(count), 2000);
			for (int i = 0; i < count; i++)
			{
				int pedID = i * 2 + 2;
				if (peds[pedID] != player && ENTITY::DOES_ENTITY_EXIST(peds[pedID]))
				{
					showSubtitle("found", 2000);
					AI::TASK_COMBAT_PED(handle, peds[pedID], 0, 16);
					break;
				}
			}
			//ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&handle);

		}

		if (emp)
		{
			GRAPHICS::_SET_BLACKOUT(blackout);
		}
	}
	else if (menu.GetCurrentMenu() == "test_menu")
	{
		menu.Title("Test Menu");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");
		menu.Option("Example option");

	}
	else if (menu.GetCurrentMenu() == "another_menu")
	{
		menu.Title("Another menu");
		menu.Option("Nothing");
	}

	menu.DrawMenu();
}