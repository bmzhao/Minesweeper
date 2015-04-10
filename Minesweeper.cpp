#include "Minesweeper.h"


using namespace std;

//to do list = flags, medium board, displaying flags
Minesweeper::Minesweeper(char board, int mine)
{
		srand(time(0));
		boardType = board;
		mineQuantity= mine;
		remainingFlags = mineQuantity;
		dimension = ((board == 'x') ? 9 :15);
		if (boardType == 'x')
		{
			for (int row = 0; row <= easyDimension; row++)
			{
				for (int column = 0; column <= easyDimension; column++)
				{
					easyBoard[row][column].revealedYet = false;
					easyBoard[row][column].containsMine= false;
					easyBoard[row][column].surroundingMineQuantity = 0;
					easyBoard[row][column].flagPlanted = false;

				}
			}

		}

		else if (boardType == 'y')
		{
			for (int row = 0; row <= mediumDimension; row++)
			{
				for (int column = 0; column <= mediumDimension; column++)
				{
					mediumBoard[row][column].revealedYet = false;
					mediumBoard[row][column].containsMine= false;
					mediumBoard[row][column].surroundingMineQuantity = 0;
					mediumBoard[row][column].flagPlanted = false;
				}
			}
		}
		
}
//returns 0 for game incomplete, -1 for loss, 1 for win
int Minesweeper::gameStatus()
{
	if (boardType == 'x')
	{
		int counter = 0;
		for (int row = 1; row <= dimension; row++)
		{
			for (int column = 1; column<=dimension; column++)
			{
				if (easyBoard[row][column].containsMine == true && easyBoard[row][column].revealedYet == true)
					return -1;
				if (easyBoard[row][column].containsMine == false && easyBoard[row][column].revealedYet == false)
					counter++;

			}
		}

		if (counter > 0)
			return 0;

		return 1;
	
	}

	else
	{
		int counter = 0;
		for (int row = 1; row <= dimension; row++)
		{
			for (int column = 1; column<=dimension; column++)
			{
				if (mediumBoard[row][column].containsMine == true && mediumBoard[row][column].revealedYet == true)
					return -1;
				if (mediumBoard[row][column].containsMine == false && mediumBoard[row][column].revealedYet == false)
					counter++;

			}
		}

		if (counter > 0)
			return 0;

		return 1;

	}
}

void Minesweeper::displayBoard()
{
	system("cls");
	
	if (boardType == 'x')
	{
		for (int row = easyDimension; row >=1; row--)
		{
			for (int subrow = 1; subrow <= 5; subrow++)
			{
				if (subrow == 1)
				{
					cout << string(3,' ') << string(73,'+') << endl;
				}
				
				else if (subrow == 2||subrow == 5)
				{
					for (int column = 1; column <= easyDimension; column ++)
					{
						if (column == 1)
						{
							cout <<  string(3,' ')<<  "+" << string(7,' ') << "+";
						}
						else 
						{
							cout << string(7,' ') << "+";
						}
						if (column == easyDimension)
							cout << endl;
					}
				}
				else if (subrow == 3)
				{
					for (int column = 1; column <= easyDimension; column ++)
					{
						if (column == 1)
						{
							if (easyBoard[row][column].revealedYet == false)
							{
								cout << " "<< row<<" " <<"+" << string(2,' ') << "..." <<  string(2,' ') << "+";
							}
							else if (easyBoard[row][column].revealedYet == true && easyBoard[row][column].containsMine == false) 
							{
								cout << " "<< row<<" " <<"+" << string(3,' '); 
								displayPosition(row,column);
								cout << string(3,' ')<< "+";
							}
							else if (easyBoard[row][column].revealedYet == true && easyBoard[row][column].containsMine == true)
							{
								cout << " "<< row<<" " <<"+ BOOM! +";
							}
						}
						else 
						{
							if (easyBoard[row][column].revealedYet == false)
							{
								cout << string(2,' ') << "..." <<  string(2,' ') << "+";
							}
							else if (easyBoard[row][column].revealedYet == true && easyBoard[row][column].containsMine == false) 
							{
								cout << string(3,' '); 
								displayPosition(row,column);
								cout << string(3,' ')<< "+";
							}
							else if (easyBoard[row][column].revealedYet == true && easyBoard[row][column].containsMine == true)
							{
								cout << " BOOM! +";
							}
						}
						if (column == easyDimension)
							cout << endl;
					}
				}
				else if (subrow == 4)
				{
					for (int column = 1; column <= easyDimension; column ++)
					{
						if (column == 1)
						{
							if (easyBoard[row][column].revealedYet == false && easyBoard[row][column].flagPlanted == true)
								cout << string(3,' ')<< "+" << " FLAG  " << "+";

							else if (easyBoard[row][column].revealedYet == false)
								cout << string(3,' ')<< "+" << string(2,' ') << "..." <<  string(2,' ') << "+";
						
							else
								cout << string(3,' ')<< "+" << string(2,' ') << "   " <<  string(2,' ') << "+";
						}
						else 
						{
							if (easyBoard[row][column].revealedYet == false && easyBoard[row][column].flagPlanted == true)
								cout << " FLAG  " << "+";
							else if (easyBoard[row][column].revealedYet == false)
								cout <<string(2,' ') << "..." <<  string(2,' ') << "+";
							else
								cout << string(7,' ') << "+";
						}
						if (column == easyDimension)
							cout << endl;
					}
				}
			}
		}
		cout << string(3,' ')<<string(73,'+') << endl;
		for (int column = 1; column <=easyDimension; column++)
		{
			if (column == 1)
			{
				cout << string(7, ' ') << column << string(4, ' ');
			}
			else
			{
				cout << string(3,' ') << column << string(4,' ');
			}
		}
		cout << endl<<endl;
		cout << string(58,' ') << remainingFlags << " Remaining Flags\n\n\n\n";
	}


	else if (boardType == 'y')
	{
		for (int row = mediumDimension; row>=1; row--)
		{
			for (int subrow = 1; subrow<=3; subrow++)
			{
				if (subrow == 1)
				{
					cout << string(4, ' ') << string(76,'+');
				}
				else if (subrow == 2)
				{
					for (int column = 1; column<= mediumDimension; column++)
					{
						if (column == 1)
						{
							if (mediumBoard[row][column].flagPlanted == true)
							{
								if (row <10)
									cout <<"  ";
								else
									cout << " ";
								cout << row<<" " <<"+" << "FLAG" <<  "+";
							}

							else if (mediumBoard[row][column].revealedYet == false)
							{
								if (row <10)
									cout <<"  ";
								else
									cout << " ";
								cout << row<<" " <<"+" << "...." <<  "+";
							}
							

							else if (mediumBoard[row][column].revealedYet == true && mediumBoard[row][column].containsMine == false) 
							{
								if (row <10)
									cout <<"  ";
								else
									cout << " ";
								cout << row<<" " <<"+" << string(1,' '); 
								displayPosition(row,column);
								cout << string(2,' ')<< "+";
							}
							else if (mediumBoard[row][column].revealedYet == true && mediumBoard[row][column].containsMine == true)
							{
								if (row <10)
									cout <<"  ";
								else
									cout << " ";
								cout << row<<" " <<"+BOOM+";
							}
						}
						else 
						{
							if (mediumBoard[row][column].flagPlanted == true)
							{
								cout << "FLAG" <<  "+";
							}
							else if (mediumBoard[row][column].revealedYet == false)
							{
								cout << "...." <<  "+";
							}
							

							else if (mediumBoard[row][column].revealedYet == true && mediumBoard[row][column].containsMine == false) 
							{
								cout << string(1,' '); 
								displayPosition(row,column);
								cout << string(2,' ')<< "+";
							}
							else if (mediumBoard[row][column].revealedYet == true && mediumBoard[row][column].containsMine == true)
							{
								cout << "BOOM+";
							}
						}
					
					}
				}
				else
				{
					for (int column = 1; column<= mediumDimension; column++)
					{
						if (column == 1)
							cout << string(4,' ') << "+" << string(4, ' ') << "+";
					
						else
							cout << string(4,' ') << "+";
					}
							
				}

			}

		}
		cout << string(4,' ')<<string(76,'+') << endl;
		for (int column = 1; column <=mediumDimension; column++)
		{
			if (column == 1)
			{
				cout << string(6, ' ') << column << string(2, ' ');
			}
			else if (column >10)
			{
				cout << string(1,' ') << column << string(2,' ');
			}

			else
			{
				cout << string(2,' ') << column << string(2,' ');
			}
		}
		cout << endl;
		cout << string(62,' ') << remainingFlags << " Remaining Flags\n\n\n";


	}

}




void Minesweeper::displayPosition(int row, int column)
{

	if (boardType == 'x')
	{
		if (easyBoard[row][column].surroundingMineQuantity == 0)
			cout << " ";
		else
			cout << easyBoard[row][column].surroundingMineQuantity;
	}
	else
	{
		if (mediumBoard[row][column].surroundingMineQuantity == 0)
			cout << " ";
		else
			cout << mediumBoard[row][column].surroundingMineQuantity;
	}
}


bool Minesweeper::clickEligibility(int row, int column)
{
	if (boardType == 'x')
	{
		if (!((row >=1  && row <=easyDimension) && (column >=1  && column <=easyDimension)))
		{	
			cout << "Please select a row and column between 1-9.\n";
			return false;
		}
		if (easyBoard[row][column].revealedYet == true)
		{
			cout << "Location is already revealed. Pick a different one.\n";
			return false;
		}
		if (easyBoard[row][column].flagPlanted == true)
		{
			cout << "Location has a flag planted. Pick a different one.\n";
			return false;
		}
		else 
			return true;
		
	}
	else
	{
		if (!((row >=1  && row <=mediumDimension) && (column >=1  && column <=mediumDimension)))
		{
			cout << "Please select a row and column between 1-15.\n";
			return false;
		}
		if (mediumBoard[row][column].revealedYet == true)
		{
			cout << "Location is already revealed. Pick a different one.\n";
			return false;
		}
		if (mediumBoard[row][column].flagPlanted == true)
		{
			cout << "Location has a flag planted. Pick a different one.\n";
			return false;
		}
		else 
			return true;
	}
	
	


}


bool Minesweeper::unFlagEligibility(int row, int column)
{
	if (boardType == 'x')
	{
		if (!((row >=1  && row <=easyDimension) && (column >=1  && column <=easyDimension)))
		{	
			cout << "Please select a row and column between 1-9.\n";
			return false;
		}
		if (easyBoard[row][column].flagPlanted == true)
		{
			return true;
		}
		else 
			return false;
		
	}
	else
	{
		if (!((row >=1  && row <=mediumDimension) && (column >=1  && column <=mediumDimension)))
		{
			cout << "Please select a row and column between 1-15.\n";
			return false;
		}
		if (mediumBoard[row][column].flagPlanted == true)
		{
			return true;
		}
		else 
			return false;
	}
	
	
}


void Minesweeper::play()
{
	displayBoard();
	int row, column;
	
	cout << "Please enter the row and column of the box you would like to click:\n" ;
	cout << "Row: ";
	cin >> row;
	cout << "Column: ";
	cin >> column;

	while (clickEligibility(row,column) == false)
	{
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;
	}

	initializeMines(row,column);
	reveal(row,column);
	displayBoard();

	while (gameStatus() == 0)
	{
		char response = 'z';
		do
		{
			cout << "Press 'c' to click another spot, 'f' to plant a flag, or 'u' to unflag a spot. ";
			cin >> response;
		}while (!(response== 'c' ||response == 'f' || response == 'u'));

		while (response == 'f'||response == 'u')
		{
			
			if (response == 'f')
			{
				cout << "Please enter the row and column of the box you would like to flag: \n" ;
				cout << "Row: ";
				cin >> row;
				cout << "Column: ";
				cin >> column;
				while (clickEligibility(row,column) == false)
				{
					cout << "Row: ";
					cin >> row;
					cout << "Column: ";
					cin >> column;
				}
				if (boardType == 'x')
					easyBoard[row][column].flagPlanted = true;
				
				else
					mediumBoard[row][column].flagPlanted = true;
				remainingFlags--;
				displayBoard();
			}

			else
			{
				cout << "Please enter the row and column of the box you would like to unflag:\n" ;
				cout << "Row: ";
				cin >> row;
				cout << "Column: ";
				cin >> column;
				while (unFlagEligibility(row,column) == false)
				{
					cout << "Row: ";
					cin >> row;
					cout << "Column: ";
					cin >> column;
				}
				if (boardType == 'x')
					easyBoard[row][column].flagPlanted = false;
				else
					mediumBoard[row][column].flagPlanted = false;
				remainingFlags++;
				displayBoard();
			}

			cout << "Press 'c' to click another spot, 'f' to plant a flag, or 'u' to unflag a spot. ";
			cin >> response;
			while (!(response== 'c' ||response == 'f' || response == 'u'))
			{
					cout << "Press 'c' to click another spot, 'f' to plant a flag, or 'u' to unflag a spot. ";
					cin >> response;
			}

		}


		cout << "Please enter the row and column of the box you would like to click:\n" ;
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> column;

		while (clickEligibility(row,column) == false)
		{
			cout << "Row: ";
			cin >> row;
			cout << "Column: ";
			cin >> column;
		}

		reveal(row,column);
		displayBoard();
	}
	
	if (gameStatus()== 1)
		cout << "\nCONGRATULATIONS!!!! YOU WON!!\n";
	else
		cout << "\nSorry, you detonated a mine. Good luck next time!\n";

}




void Minesweeper::reveal(int row, int column)
{
	static int callNumber = 0;
	
	vector<boardPosition> ripple;
	boardPosition individual;
	if (boardType == 'x')
	{
		
		
		if (easyBoard[row][column].flagPlanted == true)
		{
			return;
		}

		easyBoard[row][column].revealedYet = true;
		if (callNumber != 0)
		{	
			if(easyBoard[row][column].surroundingMineQuantity>0)
			{
				return;
			}
		}
		callNumber++;


		if(easyBoard[row][column].containsMine == false)
		{

		if (!(row == 1 || row == easyDimension) && !(column == 1 || column == easyDimension))
		{

			if (easyBoard[row][column-1].containsMine== false)
			{
				
				if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet== false)
				{
					individual.row = row;
					individual.column = column-1;
					ripple.push_back(individual);
				}
				easyBoard[row][column-1].revealedYet= true;
			}
					
			if (easyBoard[row][column+1].containsMine== false)
			{
				
				if (easyBoard[row][column+1].surroundingMineQuantity == 0 && easyBoard[row][column+1].revealedYet==false )
				{
					individual.row = row;
					individual.column = column+1;
					ripple.push_back(individual);
				}
				easyBoard[row][column+1].revealedYet= true;
			}		
					
			if (easyBoard[row+1][column].containsMine== false)
			{
				
				if (easyBoard[row+1][column].surroundingMineQuantity == 0 && easyBoard[row+1][column].revealedYet== false)
				{
					individual.row = row+1;
					individual.column = column;
					ripple.push_back(individual);
				}
				easyBoard[row+1][column].revealedYet= true;
			}

			if (easyBoard[row-1][column].containsMine== false)
			{
				
				if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet== false)
				{
					individual.row = row-1;
					individual.column = column;
					ripple.push_back(individual);
				}
				easyBoard[row-1][column].revealedYet= true;
			}


			if (easyBoard[row-1][column-1].containsMine== false)
			{
				
				if (easyBoard[row-1][column-1].surroundingMineQuantity == 0 && easyBoard[row-1][column-1].revealedYet== false)
				{
					individual.row = row-1;
					individual.column = column-1;
					ripple.push_back(individual);
				}
				easyBoard[row-1][column-1].revealedYet= true;
			}
					
			if (easyBoard[row-1][column+1].containsMine== false)
			{
			
				if (easyBoard[row-1][column+1].surroundingMineQuantity == 0 && easyBoard[row-1][column+1].revealedYet== false )
				{
					individual.row = row-1;
					individual.column = column+1;
					ripple.push_back(individual);
				}
				easyBoard[row-1][column+1].revealedYet= true;
			}

			if (easyBoard[row+1][column-1].containsMine== false)
			{
				
				if (easyBoard[row+1][column-1].surroundingMineQuantity == 0 && easyBoard[row+1][column-1].revealedYet== false )
				{
					individual.row = row+1;
					individual.column = column-1;
					ripple.push_back(individual);
				}
				easyBoard[row+1][column-1].revealedYet= true;
			}

			if (easyBoard[row+1][column+1].containsMine== false)
			{
				
				if (easyBoard[row+1][column+1].surroundingMineQuantity == 0 && easyBoard[row+1][column+1].revealedYet== false)
				{
					individual.row = row+1;
					individual.column = column+1;
					ripple.push_back(individual);
				}
				easyBoard[row+1][column+1].revealedYet= true;
			}
		}

		else
		{
			if (row == 1)
			{
				if (column == 1)
				{
					if (easyBoard[1][2].containsMine== false)
					{
						if (easyBoard[1][2].surroundingMineQuantity == 0 && easyBoard[1][2].revealedYet==false )
						{
							individual.row = 1;
							individual.column = 2;
							ripple.push_back(individual);
						}
						easyBoard[1][2].revealedYet= true;
					}

					if (easyBoard[2][1].containsMine == false)
					{
						if (easyBoard[2][1].surroundingMineQuantity == 0 && easyBoard[2][1].revealedYet==false )
						{
							individual.row = 2;
							individual.column = 1;
							ripple.push_back(individual);
						}
						easyBoard[2][1].revealedYet= true;
					}


					if(easyBoard[2][2].containsMine == false)
					{
						if (easyBoard[2][2].surroundingMineQuantity == 0 && easyBoard[2][2].revealedYet==false )
						{
							individual.row = 2;
							individual.column = 2;
							ripple.push_back(individual);
						}
						easyBoard[2][2].revealedYet= true;
					}

							
				}
				else if (column != easyDimension)
				{
							
					if (easyBoard[row][column-1].containsMine==false)
					{
						if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row][column-1].revealedYet= true;
					}
					
					if (easyBoard[row][column+1].containsMine== false)
					{
						if (easyBoard[row][column+1].surroundingMineQuantity == 0 && easyBoard[row][column+1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row][column+1].revealedYet= true;
					}
					
					
					if (easyBoard[row+1][column].containsMine== false)
					{
						if (easyBoard[row+1][column].surroundingMineQuantity == 0 && easyBoard[row+1][column].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row][column].revealedYet= true;
					}
					
																
					if (easyBoard[row+1][column-1].containsMine==false)
					{
						if (easyBoard[row+1][column-1].surroundingMineQuantity == 0 && easyBoard[row+1][column-1].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column-1].revealedYet= true;
					}
					

					if (easyBoard[row+1][column+1].containsMine== false)
					{
						if (easyBoard[row+1][column+1].surroundingMineQuantity == 0 && easyBoard[row+1][column+1].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column+1].revealedYet= true;
					}

				}

				else
				{
							
					if (easyBoard[row+1][column].containsMine ==false)
					{
						if (easyBoard[row+1][column].surroundingMineQuantity == 0 && easyBoard[row+1][column].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column].revealedYet= true;
					}
					
					if (easyBoard[row+1][column-1].containsMine == false)
					{
						if (easyBoard[row+1][column-1].surroundingMineQuantity == 0 && easyBoard[row+1][column-1].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column-1].revealedYet= true;
					}
					
					if (easyBoard[row][column-1].containsMine ==false)
					{
						if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row][column-1].revealedYet= true;
					}
					
				}
			}

			else if (row == easyDimension)
			{
				if (column == 1)
				{
					if (easyBoard[row][column+1].containsMine== false)
					{
						if (easyBoard[row][column+1].surroundingMineQuantity == 0 && easyBoard[row][column+1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row][column+1].revealedYet= true;
					}
					
					if (easyBoard[row-1][column].containsMine == false)
					{
						if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column].revealedYet= true;
					}
					
					if(easyBoard[row-1][column+1].containsMine == false)
					{
						if (easyBoard[row-1][column+1].surroundingMineQuantity == 0 && easyBoard[row-1][column+1].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column+1].revealedYet= true;
					}
					

							
				}
				else if (column != easyDimension)
				{
							

					if (easyBoard[row][column-1].containsMine== false)
					{
						if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row][column-1].revealedYet= true;
					}
					
					
					if (easyBoard[row][column+1].containsMine== false)
					{
						if (easyBoard[row][column+1].surroundingMineQuantity == 0 && easyBoard[row][column+1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row][column+1].revealedYet= true;
					}
					
					if (easyBoard[row-1][column].containsMine== false)
						{
						if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column].revealedYet= true;
					}
																
					if (easyBoard[row-1][column-1].containsMine== false)
					{
						if (easyBoard[row-1][column-1].surroundingMineQuantity == 0 && easyBoard[row-1][column-1].revealedYet== false)
						{
							individual.row = row-1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column-1].revealedYet= true;
					}
					

					if (easyBoard[row-1][column+1].containsMine==false)
					{
						if (easyBoard[row-1][column+1].surroundingMineQuantity == 0 && easyBoard[row-1][column+1].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column+1].revealedYet= true;
					}
												
				}

				else
				{
							
					if (easyBoard[row][column-1].containsMine == false)
					{
						if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row][column-1].revealedYet= true;
					}
					
					if (easyBoard[row-1][column-1].containsMine == false)
					{
						if (easyBoard[row-1][column-1].surroundingMineQuantity == 0 && easyBoard[row-1][column-1].revealedYet== false)
						{
							individual.row = row-1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column-1].revealedYet= true;
					}
					if (easyBoard[row-1][column].containsMine == false)
					{
						if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column].revealedYet= true;
					}
				}
			}

			else if (column == 1)
			{
					if (easyBoard[row][column+1].containsMine== false)
					{
						if (easyBoard[row][column+1].surroundingMineQuantity == 0 && easyBoard[row][column+1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row][column+1].revealedYet= true;
					}
					
					if (easyBoard[row+1][column+1].containsMine== false)
					{
						if (easyBoard[row+1][column+1].surroundingMineQuantity == 0 && easyBoard[row+1][column+1].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column+1].revealedYet= true;
					}
					
					if (easyBoard[row+1][column].containsMine== false)
					{
						if (easyBoard[row+1][column].surroundingMineQuantity == 0 && easyBoard[row+1][column].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column].revealedYet= true;
					}
																
					if (easyBoard[row-1][column+1].containsMine== false)
						{
						if (easyBoard[row-1][column+1].surroundingMineQuantity == 0 && easyBoard[row-1][column+1].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column+1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column+1].revealedYet= true;
					}

					if (easyBoard[row-1][column].containsMine== false)
					{
						if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column].revealedYet= true;
					}

			}
			else if (column == easyDimension)
			{
					if (easyBoard[row][column-1].containsMine== false)
					{
						if (easyBoard[row][column-1].surroundingMineQuantity == 0 && easyBoard[row][column-1].revealedYet==false )
						{
							individual.row = row;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row][column-1].revealedYet= true;
					}
					
					if (easyBoard[row+1][column-1].containsMine== false)
					{
						if (easyBoard[row+1][column-1].surroundingMineQuantity == 0 && easyBoard[row+1][column-1].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column-1].revealedYet= true;
					}
					
					if (easyBoard[row+1][column].containsMine== false)
					{
						if (easyBoard[row+1][column].surroundingMineQuantity == 0 && easyBoard[row+1][column].revealedYet==false )
						{
							individual.row = row+1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row+1][column].revealedYet= true;
					}
																
					if (easyBoard[row-1][column-1].containsMine== false)
					{
						if (easyBoard[row-1][column-1].surroundingMineQuantity == 0 && easyBoard[row-1][column-1].revealedYet== false)
						{
							individual.row = row-1;
							individual.column = column-1;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column-1].revealedYet= true;
					}

					if (easyBoard[row-1][column].containsMine== false)
					{
						if (easyBoard[row-1][column].surroundingMineQuantity == 0 && easyBoard[row-1][column].revealedYet==false )
						{
							individual.row = row-1;
							individual.column = column;
							ripple.push_back(individual);
						}
						easyBoard[row-1][column].revealedYet= true;
					}
				}
			}
			}
		}

		else
		{
		
			if (mediumBoard[row][column].flagPlanted == true)
			{
				return;
			}

			mediumBoard[row][column].revealedYet = true;
			if (callNumber != 0)
			{	
				if(mediumBoard[row][column].surroundingMineQuantity>0)
				{
					return;
				}
			}
			callNumber++;


			if(mediumBoard[row][column].containsMine == false)
			{

			if (!(row == 1 || row == mediumDimension) && !(column == 1 || column == mediumDimension))
			{

				if (mediumBoard[row][column-1].containsMine== false)
				{
				
					if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet== false)
					{
						individual.row = row;
						individual.column = column-1;
						ripple.push_back(individual);
					}
					mediumBoard[row][column-1].revealedYet= true;
				}
					
				if (mediumBoard[row][column+1].containsMine== false)
				{
				
					if (mediumBoard[row][column+1].surroundingMineQuantity == 0 && mediumBoard[row][column+1].revealedYet==false )
					{
						individual.row = row;
						individual.column = column+1;
						ripple.push_back(individual);
					}
					mediumBoard[row][column+1].revealedYet= true;
				}		
					
				if (mediumBoard[row+1][column].containsMine== false)
				{
				
					if (mediumBoard[row+1][column].surroundingMineQuantity == 0 && mediumBoard[row+1][column].revealedYet== false)
					{
						individual.row = row+1;
						individual.column = column;
						ripple.push_back(individual);
					}
					mediumBoard[row+1][column].revealedYet= true;
				}

				if (mediumBoard[row-1][column].containsMine== false)
				{
				
					if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet== false)
					{
						individual.row = row-1;
						individual.column = column;
						ripple.push_back(individual);
					}
					mediumBoard[row-1][column].revealedYet= true;
				}


				if (mediumBoard[row-1][column-1].containsMine== false)
				{
				
					if (mediumBoard[row-1][column-1].surroundingMineQuantity == 0 && mediumBoard[row-1][column-1].revealedYet== false)
					{
						individual.row = row-1;
						individual.column = column-1;
						ripple.push_back(individual);
					}
					mediumBoard[row-1][column-1].revealedYet= true;
				}
					
				if (mediumBoard[row-1][column+1].containsMine== false)
				{
			
					if (mediumBoard[row-1][column+1].surroundingMineQuantity == 0 && mediumBoard[row-1][column+1].revealedYet== false )
					{
						individual.row = row-1;
						individual.column = column+1;
						ripple.push_back(individual);
					}
					mediumBoard[row-1][column+1].revealedYet= true;
				}

				if (mediumBoard[row+1][column-1].containsMine== false)
				{
				
					if (mediumBoard[row+1][column-1].surroundingMineQuantity == 0 && mediumBoard[row+1][column-1].revealedYet== false )
					{
						individual.row = row+1;
						individual.column = column-1;
						ripple.push_back(individual);
					}
					mediumBoard[row+1][column-1].revealedYet= true;
				}

				if (mediumBoard[row+1][column+1].containsMine== false)
				{
				
					if (mediumBoard[row+1][column+1].surroundingMineQuantity == 0 && mediumBoard[row+1][column+1].revealedYet== false)
					{
						individual.row = row+1;
						individual.column = column+1;
						ripple.push_back(individual);
					}
					mediumBoard[row+1][column+1].revealedYet= true;
				}
			}

			else
			{
				if (row == 1)
				{
					if (column == 1)
					{
						if (mediumBoard[1][2].containsMine== false)
						{
							if (mediumBoard[1][2].surroundingMineQuantity == 0 && mediumBoard[1][2].revealedYet==false )
							{
								individual.row = 1;
								individual.column = 2;
								ripple.push_back(individual);
							}
							mediumBoard[1][2].revealedYet= true;
						}

						if (mediumBoard[2][1].containsMine == false)
						{
							if (mediumBoard[2][1].surroundingMineQuantity == 0 && mediumBoard[2][1].revealedYet==false )
							{
								individual.row = 2;
								individual.column = 1;
								ripple.push_back(individual);
							}
							mediumBoard[2][1].revealedYet= true;
						}


						if(mediumBoard[2][2].containsMine == false)
						{
							if (mediumBoard[2][2].surroundingMineQuantity == 0 && mediumBoard[2][2].revealedYet==false )
							{
								individual.row = 2;
								individual.column = 2;
								ripple.push_back(individual);
							}
							mediumBoard[2][2].revealedYet= true;
						}

							
					}
					else if (column != mediumDimension)
					{
							
						if (mediumBoard[row][column-1].containsMine==false)
						{
							if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column-1].revealedYet= true;
						}
					
						if (mediumBoard[row][column+1].containsMine== false)
						{
							if (mediumBoard[row][column+1].surroundingMineQuantity == 0 && mediumBoard[row][column+1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column+1].revealedYet= true;
						}
					
					
						if (mediumBoard[row+1][column].containsMine== false)
						{
							if (mediumBoard[row+1][column].surroundingMineQuantity == 0 && mediumBoard[row+1][column].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row][column].revealedYet= true;
						}
					
																
						if (mediumBoard[row+1][column-1].containsMine==false)
						{
							if (mediumBoard[row+1][column-1].surroundingMineQuantity == 0 && mediumBoard[row+1][column-1].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column-1].revealedYet= true;
						}
					

						if (mediumBoard[row+1][column+1].containsMine== false)
						{
							if (mediumBoard[row+1][column+1].surroundingMineQuantity == 0 && mediumBoard[row+1][column+1].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column+1].revealedYet= true;
						}

					}

					else
					{
							
						if (mediumBoard[row+1][column].containsMine ==false)
						{
							if (mediumBoard[row+1][column].surroundingMineQuantity == 0 && mediumBoard[row+1][column].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column].revealedYet= true;
						}
					
						if (mediumBoard[row+1][column-1].containsMine == false)
						{
							if (mediumBoard[row+1][column-1].surroundingMineQuantity == 0 && mediumBoard[row+1][column-1].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column-1].revealedYet= true;
						}
					
						if (mediumBoard[row][column-1].containsMine ==false)
						{
							if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column-1].revealedYet= true;
						}
					
					}
				}

				else if (row == mediumDimension)
				{
					if (column == 1)
					{
						if (mediumBoard[row][column+1].containsMine== false)
						{
							if (mediumBoard[row][column+1].surroundingMineQuantity == 0 && mediumBoard[row][column+1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column+1].revealedYet= true;
						}
					
						if (mediumBoard[row-1][column].containsMine == false)
						{
							if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column].revealedYet= true;
						}
					
						if(mediumBoard[row-1][column+1].containsMine == false)
						{
							if (mediumBoard[row-1][column+1].surroundingMineQuantity == 0 && mediumBoard[row-1][column+1].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column+1].revealedYet= true;
						}
					

							
					}
					else if (column != mediumDimension)
					{
							

						if (mediumBoard[row][column-1].containsMine== false)
						{
							if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column-1].revealedYet= true;
						}
					
					
						if (mediumBoard[row][column+1].containsMine== false)
						{
							if (mediumBoard[row][column+1].surroundingMineQuantity == 0 && mediumBoard[row][column+1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column+1].revealedYet= true;
						}
					
						if (mediumBoard[row-1][column].containsMine== false)
							{
							if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column].revealedYet= true;
						}
																
						if (mediumBoard[row-1][column-1].containsMine== false)
						{
							if (mediumBoard[row-1][column-1].surroundingMineQuantity == 0 && mediumBoard[row-1][column-1].revealedYet== false)
							{
								individual.row = row-1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column-1].revealedYet= true;
						}
					

						if (mediumBoard[row-1][column+1].containsMine==false)
						{
							if (mediumBoard[row-1][column+1].surroundingMineQuantity == 0 && mediumBoard[row-1][column+1].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column+1].revealedYet= true;
						}
												
					}

					else
					{
							
						if (mediumBoard[row][column-1].containsMine == false)
						{
							if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column-1].revealedYet= true;
						}
					
						if (mediumBoard[row-1][column-1].containsMine == false)
						{
							if (mediumBoard[row-1][column-1].surroundingMineQuantity == 0 && mediumBoard[row-1][column-1].revealedYet== false)
							{
								individual.row = row-1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column-1].revealedYet= true;
						}
						if (mediumBoard[row-1][column].containsMine == false)
						{
							if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column].revealedYet= true;
						}
					}
				}

				else if (column == 1)
				{
						if (mediumBoard[row][column+1].containsMine== false)
						{
							if (mediumBoard[row][column+1].surroundingMineQuantity == 0 && mediumBoard[row][column+1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column+1].revealedYet= true;
						}
					
						if (mediumBoard[row+1][column+1].containsMine== false)
						{
							if (mediumBoard[row+1][column+1].surroundingMineQuantity == 0 && mediumBoard[row+1][column+1].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column+1].revealedYet= true;
						}
					
						if (mediumBoard[row+1][column].containsMine== false)
						{
							if (mediumBoard[row+1][column].surroundingMineQuantity == 0 && mediumBoard[row+1][column].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column].revealedYet= true;
						}
																
						if (mediumBoard[row-1][column+1].containsMine== false)
							{
							if (mediumBoard[row-1][column+1].surroundingMineQuantity == 0 && mediumBoard[row-1][column+1].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column+1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column+1].revealedYet= true;
						}

						if (mediumBoard[row-1][column].containsMine== false)
						{
							if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column].revealedYet= true;
						}

				}
				else if (column == mediumDimension)
				{
						if (mediumBoard[row][column-1].containsMine== false)
						{
							if (mediumBoard[row][column-1].surroundingMineQuantity == 0 && mediumBoard[row][column-1].revealedYet==false )
							{
								individual.row = row;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row][column-1].revealedYet= true;
						}
					
						if (mediumBoard[row+1][column-1].containsMine== false)
						{
							if (mediumBoard[row+1][column-1].surroundingMineQuantity == 0 && mediumBoard[row+1][column-1].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column-1].revealedYet= true;
						}
					
						if (mediumBoard[row+1][column].containsMine== false)
						{
							if (mediumBoard[row+1][column].surroundingMineQuantity == 0 && mediumBoard[row+1][column].revealedYet==false )
							{
								individual.row = row+1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row+1][column].revealedYet= true;
						}
																
						if (mediumBoard[row-1][column-1].containsMine== false)
						{
							if (mediumBoard[row-1][column-1].surroundingMineQuantity == 0 && mediumBoard[row-1][column-1].revealedYet== false)
							{
								individual.row = row-1;
								individual.column = column-1;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column-1].revealedYet= true;
						}

						if (mediumBoard[row-1][column].containsMine== false)
						{
							if (mediumBoard[row-1][column].surroundingMineQuantity == 0 && mediumBoard[row-1][column].revealedYet==false )
							{
								individual.row = row-1;
								individual.column = column;
								ripple.push_back(individual);
							}
							mediumBoard[row-1][column].revealedYet= true;
						}
					}
				}
			}
		}


				for (vector<boardPosition>::size_type i = 0; i != ripple.size(); i++)
				{
					reveal(ripple[i].row,ripple[i].column);
				}
				return;
}










void Minesweeper::initializeMines(int row, int column)
{
	
	if (boardType == 'x')
	{
		
		int firstClicked;
		if (row <= 1) 
			firstClicked = column;
		else 
			firstClicked = (row-1)*easyDimension + column;

		bool positionisTaken[82] = {};
		for (int i = 1; i <=81; i++)
		{
			positionisTaken[i] = false;
		}
		positionisTaken[firstClicked] = true;

		int minesPlaced = 0;
		while (minesPlaced != mineQuantity)
		{
			int position = rand()%81 + 1;
			while (positionisTaken[position] == true)
			{
				position = rand()%81 + 1;
			}
			if (position%easyDimension== 0)
			{
				easyBoard[position/easyDimension][easyDimension].containsMine = true;
			}
			else
				easyBoard[int(ceil((position*1.0)/easyDimension))][position%easyDimension].containsMine = true;
			minesPlaced++;
			positionisTaken[position] = true;
		}
		easyBoard[row][column].revealedYet = true;
		initializeSurroundingMinesValues();

	}

	else 
	{
		int firstClicked;
		if (row <= 1) 
			firstClicked = column;
		else 
			firstClicked = (row-1)*mediumDimension + column;

		bool positionisTaken[226] = {};
		for (int i = 1; i <=225; i++)
		{
			positionisTaken[i] = false;
		}
		positionisTaken[firstClicked] = true;

		int minesPlaced = 0;
		while (minesPlaced != mineQuantity)
		{
			int position = rand()%225 + 1;
			while (positionisTaken[position] == true)
			{
				position = rand()%225 + 1;
			}
			if (position%mediumDimension== 0)
			{
				mediumBoard[position/mediumDimension][mediumDimension].containsMine = true;
			}
			else
				mediumBoard[int(ceil((position*1.0)/mediumDimension))][position%mediumDimension].containsMine = true;
			minesPlaced++;
			positionisTaken[position] = true;
		}
		mediumBoard[row][column].revealedYet = true;
		initializeSurroundingMinesValues();

	}


}

void Minesweeper::initializeSurroundingMinesValues()
{
	if(boardType == 'x')
	{
		for (int row = 1; row <= easyDimension; row++)
		{
			for (int column = 1; column <= easyDimension; column++)
			{
				if (!(row == 1 || row == easyDimension) && !(column == 1 || column == easyDimension))
				{
					int mineCounter = 0;

					if (easyBoard[row][column-1].containsMine== true)
						mineCounter++;
					
					if (easyBoard[row][column+1].containsMine== true)
						mineCounter++;
					
					if (easyBoard[row+1][column].containsMine== true)
						mineCounter++;

					if (easyBoard[row-1][column].containsMine== true)
						mineCounter++;

					if (easyBoard[row-1][column-1].containsMine== true)
						mineCounter++;

					if (easyBoard[row-1][column+1].containsMine== true)
						mineCounter++;

					if (easyBoard[row+1][column-1].containsMine== true)
						mineCounter++;

					if (easyBoard[row+1][column+1].containsMine== true)
						mineCounter++;

					easyBoard[row][column].surroundingMineQuantity = mineCounter;
				}

				else
				{
					if (row == 1)
					{
						if (column == 1)
						{
							int mineCounter = 0;

							if (easyBoard[1][2].containsMine== true)
								mineCounter++;
							if (easyBoard[2][1].containsMine == true)
								mineCounter++;
							if(easyBoard[2][2].containsMine == true)
								mineCounter++;

							easyBoard[1][1].surroundingMineQuantity = mineCounter;
						}
						else if (column != easyDimension)
						{
							int mineCounter = 0;

							if (easyBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (easyBoard[row+1][column-1].containsMine== true)
								mineCounter++;

							if (easyBoard[row+1][column+1].containsMine== true)
								mineCounter++;

							easyBoard[row][column].surroundingMineQuantity = mineCounter;

						}

						else
						{
							int mineCounter = 0;

							if (easyBoard[row+1][column].containsMine == true)
								mineCounter++;
							if (easyBoard[row+1][column-1].containsMine == true)
								mineCounter++;
							if (easyBoard[row][column-1].containsMine == true)
								mineCounter++;
							easyBoard[row][column].surroundingMineQuantity = mineCounter;
						
						}
					}

					else if (row == easyDimension)
					{
						if (column == 1)
						{
							int mineCounter = 0;

							if (easyBoard[row][column+1].containsMine== true)
								mineCounter++;
							if (easyBoard[row-1][column].containsMine == true)
								mineCounter++;
							if(easyBoard[row-1][column+1].containsMine == true)
								mineCounter++;

							easyBoard[row][column].surroundingMineQuantity = mineCounter;
						}
						else if (column != easyDimension)
						{
							int mineCounter = 0;

							if (easyBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row-1][column].containsMine== true)
								mineCounter++;
																
							if (easyBoard[row-1][column-1].containsMine== true)
								mineCounter++;

							if (easyBoard[row-1][column+1].containsMine== true)
								mineCounter++;

							easyBoard[row][column].surroundingMineQuantity = mineCounter;

						}

						else
						{
							int mineCounter = 0;

							if (easyBoard[row][column-1].containsMine == true)
								mineCounter++;
							if (easyBoard[row-1][column-1].containsMine == true)
								mineCounter++;
							if (easyBoard[row-1][column].containsMine == true)
								mineCounter++;
							easyBoard[row][column].surroundingMineQuantity = mineCounter;
						
						}


					}

					else if (column == 1)
					{
							int mineCounter = 0;

							if (easyBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row+1][column+1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (easyBoard[row-1][column+1].containsMine== true)
								mineCounter++;

							if (easyBoard[row-1][column].containsMine== true)
								mineCounter++;

							easyBoard[row][column].surroundingMineQuantity = mineCounter;

					}
					else if (column == easyDimension)
					{
							int mineCounter = 0;

							if (easyBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row+1][column-1].containsMine== true)
								mineCounter++;
					
							if (easyBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (easyBoard[row-1][column-1].containsMine== true)
								mineCounter++;

							if (easyBoard[row-1][column].containsMine== true)
								mineCounter++;

							easyBoard[row][column].surroundingMineQuantity = mineCounter;

					}
				
				}
			}
		}
	}

	else
	{
		for (int row = 1; row <= mediumDimension; row++)
		{
			for (int column = 1; column <= mediumDimension; column++)
			{
				if (!(row == 1 || row == mediumDimension) && !(column == 1 || column == mediumDimension))
				{
					int mineCounter = 0;

					if (mediumBoard[row][column-1].containsMine== true)
						mineCounter++;
					
					if (mediumBoard[row][column+1].containsMine== true)
						mineCounter++;
					
					if (mediumBoard[row+1][column].containsMine== true)
						mineCounter++;

					if (mediumBoard[row-1][column].containsMine== true)
						mineCounter++;

					if (mediumBoard[row-1][column-1].containsMine== true)
						mineCounter++;

					if (mediumBoard[row-1][column+1].containsMine== true)
						mineCounter++;

					if (mediumBoard[row+1][column-1].containsMine== true)
						mineCounter++;

					if (mediumBoard[row+1][column+1].containsMine== true)
						mineCounter++;

					mediumBoard[row][column].surroundingMineQuantity = mineCounter;
				}

				else
				{
					if (row == 1)
					{
						if (column == 1)
						{
							int mineCounter = 0;

							if (mediumBoard[1][2].containsMine== true)
								mineCounter++;
							if (mediumBoard[2][1].containsMine == true)
								mineCounter++;
							if(mediumBoard[2][2].containsMine == true)
								mineCounter++;

							mediumBoard[1][1].surroundingMineQuantity = mineCounter;
						}
						else if (column != mediumDimension)
						{
							int mineCounter = 0;

							if (mediumBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (mediumBoard[row+1][column-1].containsMine== true)
								mineCounter++;

							if (mediumBoard[row+1][column+1].containsMine== true)
								mineCounter++;

							mediumBoard[row][column].surroundingMineQuantity = mineCounter;

						}

						else
						{
							int mineCounter = 0;

							if (mediumBoard[row+1][column].containsMine == true)
								mineCounter++;
							if (mediumBoard[row+1][column-1].containsMine == true)
								mineCounter++;
							if (mediumBoard[row][column-1].containsMine == true)
								mineCounter++;
							mediumBoard[row][column].surroundingMineQuantity = mineCounter;
						
						}
					}

					else if (row == mediumDimension)
					{
						if (column == 1)
						{
							int mineCounter = 0;

							if (mediumBoard[row][column+1].containsMine== true)
								mineCounter++;
							if (mediumBoard[row-1][column].containsMine == true)
								mineCounter++;
							if(mediumBoard[row-1][column+1].containsMine == true)
								mineCounter++;

							mediumBoard[row][column].surroundingMineQuantity = mineCounter;
						}
						else if (column != mediumDimension)
						{
							int mineCounter = 0;

							if (mediumBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row-1][column].containsMine== true)
								mineCounter++;
																
							if (mediumBoard[row-1][column-1].containsMine== true)
								mineCounter++;

							if (mediumBoard[row-1][column+1].containsMine== true)
								mineCounter++;

							mediumBoard[row][column].surroundingMineQuantity = mineCounter;

						}

						else
						{
							int mineCounter = 0;

							if (mediumBoard[row][column-1].containsMine == true)
								mineCounter++;
							if (mediumBoard[row-1][column-1].containsMine == true)
								mineCounter++;
							if (mediumBoard[row-1][column].containsMine == true)
								mineCounter++;
							mediumBoard[row][column].surroundingMineQuantity = mineCounter;
						
						}


					}

					else if (column == 1)
					{
							int mineCounter = 0;

							if (mediumBoard[row][column+1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row+1][column+1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (mediumBoard[row-1][column+1].containsMine== true)
								mineCounter++;

							if (mediumBoard[row-1][column].containsMine== true)
								mineCounter++;

							mediumBoard[row][column].surroundingMineQuantity = mineCounter;

					}
					else if (column == mediumDimension)
					{
							int mineCounter = 0;

							if (mediumBoard[row][column-1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row+1][column-1].containsMine== true)
								mineCounter++;
					
							if (mediumBoard[row+1][column].containsMine== true)
								mineCounter++;
																
							if (mediumBoard[row-1][column-1].containsMine== true)
								mineCounter++;

							if (mediumBoard[row-1][column].containsMine== true)
								mineCounter++;

							mediumBoard[row][column].surroundingMineQuantity = mineCounter;

					}
				
				}
			}
		}

	}

	
}