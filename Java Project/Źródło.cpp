#include "AllHeaders.h"
#include <ctime>
#include <iostream>
#include <conio.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
	string menu = "\n\nMovement: Arrow Keys\nSpecial ability: R\nNext Turn: X\nLoad Game: V\nSave game:C\nQuit Game:Q\n";
	char input = 0;
	std::srand(std::time(NULL));


	World swiat(31,21);
	//adding organisms
	Human man(15, 10, swiat);
	swiat.setHuman(&man); //setting man as controllable human instance (other instances of man will not be controllable)
	Guarana gu(3, 3, swiat);
	Belladona be(27, 17, swiat);
	Grass gr(27, 3, swiat);
	Sow_Thistle so(3, 17, swiat);
	Sosnowsky_Hogweed weed(24, 14, swiat);
	Wolf wo(15, 5, swiat);
	Sheep sh(10, 9, swiat);
	Turtle tu(3, 19, swiat);
	Fox fo(20, 10, swiat);
	Fox fo2(21, 11, swiat);
	Fox fo3(22, 12, swiat);
	Antelope an(4, 14, swiat);


	swiat.drawWorld();
	cout << endl << menu;


	while (1)
	{
		while (input != 'x' && input != 'X')
		{
			switch ((input = _getch())) {
			case KEY_UP:
				if (swiat.man() != NULL)
				swiat.man()->setSide(UP);
				break;
			case KEY_DOWN:
				if (swiat.man() != NULL)
				swiat.man()->setSide(DOWN);
				break;
			case KEY_LEFT:
				if (swiat.man() != NULL)
				swiat.man()->setSide(LEFT);
				break;
			case KEY_RIGHT:
				if (swiat.man() != NULL)
				swiat.man()->setSide(RIGHT);
				break;
			case 'r':
			case 'R':
				swiat.man()->usepower();
				break;
			case 'c':
			case 'C':
				swiat.savegame();
				break;
			case 'v':
			case 'V':
				swiat.loadgame();
				break;
			case 'x':
			case'X':
				break;
			case 'q':
			case 'Q':
				return 1;
			default:
				break;
			}
		}
		input = 0;
		system("CLS");
		swiat.makeTurn();
		swiat.drawWorld();
		cout << endl<<menu;
	}
}