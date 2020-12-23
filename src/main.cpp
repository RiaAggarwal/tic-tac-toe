#include <iostream>

void DrawBoard();
void GetInput();
int CheckWinner();

const int X = 1;		// Player 1
const int O = 2;		// Player 2
const int DRAW = -1;
const int NO_WINNER = 0;

char board[9] = { '1','2','3','4','5','6','7','8','9' };	// The board!
int player = X; //We start with player 1

int main()
{
	int winner = NO_WINNER;
	int turns = 0;

	while (winner==NO_WINNER) //run the loop till a draw or a winner is declared
	{
		DrawBoard();
		GetInput();
		turns++;
		winner = CheckWinner();
		if(winner==NO_WINNER && turns==9) winner=DRAW;
		if(player==X) player=O; else player=X;	// change the player
	}
	DrawBoard();
	if (winner == DRAW)
		std::cout << "It's a DRAW!\n";
	else
		std::cout << "CONGRATULATIONS Player " << winner << "!\nYou win!\n";
}

void DrawBoard()
{
	std::cout
		<< " " << board[0] << " | " << board[1] << " | " << board[2] << " \n"
		<< "-----------\n"
		<< " " << board[3] << " | " << board[4] << " | " << board[5] << " \n"
		<< "-----------\n"
		<< " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

void GetInput()
{
	int position;

	while (true)
	{
		std::cout << "Player " << player<<" it is your turn."<< "\n" << "Enter a position between 1 to 9:\n";
		std::cin >> position;
		position--;
		if (position < 0 || position > 8)
		{
			DrawBoard();
			std::cout << "This position is INVALID. TRY again...\n";
			continue;
		}
		else if (board[position] == 'X' || board[position] == 'O')
		{
			DrawBoard();
			std::cout << "This position is NOT AVAILABLE. TRY again...\n";
			continue;
		}
		break;
	}
	// Updates Board Value //
	if (player != X) board[position] = 'O';
	else board[position] = 'X';
}

int CheckWinner()
{
	// Check all the Row//
	if (board[0] == board[1] && board[1] == board[2]) return player;
	else if (board[3] == board[4] && board[4] == board[5]) return player;
	else if (board[6] == board[7] && board[7] == board[8]) return player;

	// Check all the Columns//
	else if (board[0] == board[3] && board[3] == board[6]) return player;
	else if (board[1] == board[4] && board[4] == board[7]) return player;
	else if (board[2] == board[5] && board[5] == board[8]) return player;

	// Check all the Diagonals //
	else if (board[0] == board[4] && board[4] == board[8]) return player;
	else if (board[2] == board[4] && board[4] == board[6]) return player;

	else return NO_WINNER;
}
