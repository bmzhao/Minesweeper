#include "Minesweeper.h"

using namespace std;


int main()
{
	
	char boardType = 'n';

	do
	{
		cout << "Play on 9x9 board (enter 'x') or a 15x15 board (enter 'y')?" << endl;
		cin >> boardType;
		if (!(boardType == 'x' || boardType == 'y'))
		{
			cout << "Please enter a proper board letter.\n";
		}
	}while (!(boardType == 'x' || boardType == 'y'));

	int mineQuantity = -1;
	bool continueCondition = false;
	do
	{
		if (boardType == 'x')
			cout << "\nA 9x9 board typically has 10 mines and supports a maximum of 64 mines.";
		else
			cout << "\nA 15x15 board typically has 40 mines and supports a maximum of 196 mines.";

		cout << "\nHow many mines would you like on this board? ";
		cin >> mineQuantity;
		if (boardType == 'x' && (mineQuantity <=64 && mineQuantity >= 0))
		{
			continueCondition = true;
		}
		else if (boardType == 'y' && (mineQuantity <=196 && mineQuantity >= 0))
		{
			continueCondition = true;
		}
		else 
		{
			cout << "Please enter an appropriate number of mines between 0 and the board's maxiumum.\n";
			continueCondition = false;
		}
		
	}while (continueCondition == false);



	Minesweeper game(boardType,mineQuantity);
	game.play();

	system("PAUSE");

}