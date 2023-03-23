#ifndef AI_MODULE // include guard
#define AI_MODULE

// Ai = Minimax

// C++ Ai to find the next optimal move depends on
// Hard , intermediate and easy

#include <bits/stdc++.h>
using namespace std;

string mode = "default";
struct Move
{
	int row, col;
};
struct win_pos
{
	int row, col;
};
struct Players
{
	const char Bot = 'x';
	const char opponent = 'o';
};
int player_won[] = {0, 0};

Players symbol;

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == '_')
				return true;
	return false;
}

bool isMovesSame(char board[3][3], int chose_index)
{

	switch (chose_index)
	{
	case 7:
		if (board[0][0] != '_')
			return true;
		break;

	case 8:
		if (board[0][1] != '_')
			return true;
		break;

	case 9:
		if (board[0][2] != '_')
			return true;
		break;

	case 4:
		if (board[1][0] != '_')
			return true;
		break;

	case 5:
		if (board[1][1] != '_')
			return true;
		break;

	case 6:
		if (board[1][2] != '_')
			return true;
		break;

	case 1:
		if (board[2][0] != '_')
			return true;
		break;

	case 2:
		if (board[2][1] != '_')
			return true;
		break;

	case 3:
		if (board[2][2] != '_')
			return true;
		break;

	default:
		cout << "\nNumber invalid !!\n\n";
		break;
	}
	return false;
}

// This is the evaluation function as discussed
int evaluate(char b[3][3])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == symbol.Bot)
			{
				if (mode == "hard")
					return +10;
				else
					return -10;
			}

			else if (b[row][0] == symbol.opponent)
			{
				if (mode == "hard")
					return -10;
				else
					return +10;
			}
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == symbol.Bot)
			{
				if (mode == "hard")
					return +10;
				else
					return -10;
			}

			else if (b[0][col] == symbol.opponent)
			{
				if (mode == "hard")
					return -10;
				else
					return +10;
			}
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == symbol.Bot)
		{
			if (mode == "hard")
				return +10;
			else
				return -10;
		}
		else if (b[0][0] == symbol.opponent)
		{
			if (mode == "hard")
				return -10;
			else
				return +10;
		}
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == symbol.Bot)
		{
			if (mode == "hard")
				return +10;
			else
				return -10;
		}
		else if (b[0][2] == symbol.opponent)
		{
			if (mode == "hard")
				return -10;
			else
				return +10;
		}
	}

	// Else if none of them have won then return 0
	return 0;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(board) == false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = symbol.Bot;

					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
							   minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty
				if (board[i][j] == '_')
				{
					// Make the move
					board[i][j] = symbol.opponent;

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
							   minimax(board, depth + 1, !isMax));

					// Undo the move
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

// This will return the best possible move for the symbol.Bot
Move findBestMove(char board[3][3])
{

	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if cell is empty
			if (board[i][j] == '_')
			{
				// Make the move
				board[i][j] = symbol.Bot;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(board, 0, false);

				// Undo the move
				board[i][j] = '_';

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}

#endif /* AI_MODULE */