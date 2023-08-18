#include<iostream>
using namespace std;
int main()
{
	enum Status
	{
		WIN, TIE, UNDECIDED
	};
	Status Game = UNDECIDED;
	char Board[6][6];
	char num[2] = "1";
	int player_counter = 1;
	for (int rows = 0; rows < 6; rows++)
	{
		for (int cols = 0; cols < 6; cols++)
		{
			Board[rows][cols] = ' ';
		}
	}
	for (int loop2 = 1; loop2 < 5; loop2 = loop2 + 2)
	{
		for (int loop = 0; loop < 6; loop++)
		{
			Board[loop][loop2] = '|';
			Board[loop2][loop] = '_';
			if (loop == loop2)
			{
				Board[loop][loop2] = '|';
			}
		}
	}
	for (int loop3 = 0; loop3 < 6; loop3 = loop3 + 2)
	{
		for (int loop4 = 0; loop4 < 6; loop4 = loop4 + 2)
		{
			Board[loop3][loop4] = num[0];
			num[0] ++;
		}
	}
	Board[3][1] = '|';
	for (int rows = 0; rows < 6; rows++)
	{
		for (int cols = 0; cols < 6; cols++)
		{
			cout << Board[rows][cols];
		}
		cout << endl;
	}
	while (Game == UNDECIDED)
	{
		char place;
		int checker = 0;
		if (player_counter % 2 != 0)
		{
			while (checker == 0)
			{
				cout << "Player 1's Turn, choose a corresponding number to place X: ";
				cin >> place;
				for (int rows = 0; rows < 5; rows = rows + 2)
				{
					for (int cols = 0; cols < 5; cols = cols + 2)
					{
						if (Board[rows][cols] == place)
						{
							Board[rows][cols] = 'X';
							checker++;
						}
					}
				}
				if (checker == 0)
				{
					cout << "You have not entered a valid place, enter again" << endl;
				}
			}
			system("clear");
			for (int rows = 0; rows < 6; rows++)
			{
				for (int cols = 0; cols < 6; cols++)
				{
					cout << Board[rows][cols];
				}
				cout << endl;
			}
		}
		else
		{
			while (checker == 0)
			{
				cout << "Player 2's Turn, choose a corresponding number to place O: ";
				cin >> place;
				for (int rows = 0; rows < 5; rows = rows + 2)
				{
					for (int cols = 0; cols < 5; cols = cols + 2)
					{
						if (Board[rows][cols] == place)
						{
							Board[rows][cols] = 'O';
							checker++;
						}
					}
				}
				if (checker == 0)
				{
					cout << "You have not entered a valid place, enter again" << endl;
				}
			}
			system("clear");
			for (int rows = 0; rows < 6; rows++)
			{
				for (int cols = 0; cols < 6; cols++)
				{
					cout << Board[rows][cols];
				}
				cout << endl;
			}
		}
		for (int rows = 0; rows < 5; rows = rows + 2)
		{
			for (int cols = 0; cols < 5; cols = cols + 2)
			{
				if (Board[rows][cols] == 'X')
				{
					if (Board[rows + 2][cols + 2] == 'X' && Board[rows + 4][cols + 4] == 'X' || Board[rows + 2][cols] == 'X' && Board[rows + 4][cols] == 'X' || Board[rows][cols + 2] == 'X' && Board[rows][cols + 4] == 'X' || Board[2][2] == 'X' && Board[4][0] == 'X')
					{
						cout << "Player 1 wins" << endl;
						Game = WIN;
						break;
					}
				}
			}
		}
		for (int rows = 0; rows < 5; rows = rows + 2)
		{
			for (int cols = 0; cols < 5; cols = cols + 2)
			{
				if (Board[rows][cols] == 'O')
				{
					if (Board[rows + 2][cols + 2] == 'O' && Board[rows + 4][cols + 4] == 'O' || Board[rows + 2][cols] == 'O' && Board[rows + 4][cols] == 'O' || Board[rows][cols + 2] == 'O' && Board[rows][cols + 4] == 'O' || Board[2][2] == 'O' && Board[4][0] == 'O')
					{
						cout << "Player 2 wins" << endl;
						Game = WIN;
						break;
					}
				}
			}
		}
		if (player_counter == 9 && Game != WIN)
		{
			cout << "It's a tie" << endl;
			Game = TIE;
		}
		player_counter++;
	}
	return 0;
}
