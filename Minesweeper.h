#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include <vector>

#ifndef MINESWEEPER
#define MINESWEEPER


class Minesweeper
{

public:
	Minesweeper(char, int);
	
	void displayBoard();
	void displayPosition(int, int);
	int gameStatus();//note medium is uncomplete
	bool unFlagEligibility(int,int);
	bool clickEligibility(int,int);
	void initializeMines(int,int);
	void initializeSurroundingMinesValues();//note medium is uncomplete
	void play();
	void reveal(int,int);//note medium is uncomplete


private:
	//easy or medium; easy is 9*9, 15*15
	static const int easyDimension = 9;
	static const int mediumDimension = 15;
	int dimension;
	struct box
	{
		bool containsMine;
		int surroundingMineQuantity;
		bool revealedYet;
		bool flagPlanted;
	};
	
	struct boardPosition
	{
		int row;
		int column;
	};

	char boardType;
	int mineQuantity;
	box easyBoard[easyDimension+1][easyDimension+1];
	box mediumBoard[mediumDimension+1][mediumDimension+1];
	int remainingFlags;

};



#endif