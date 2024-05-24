#include "GameBoard.h"
#include "ctime"
GameBoard::GameBoard() : dong(8), cot(10)
{
	board = vector<vector<char>>(dong, vector<char>(cot, '.'));
	init_board();
}

void GameBoard::init_board()
{
	srand(time(0));
	int brick = rand() % 16 + 20;
	for (int i = 0; i < brick; i++)
	{
		int x = rand() % dong;
		int y = rand() % cot;
		board[x][y] = 'X';
	}
}

void GameBoard::display()
{
	for (auto row : board)
	{
		for (char cell : row)
		{
			cout << cell << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void GameBoard::update_board(Piece& piece, int x_pos, int y_pos)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.getShape()[piece.getCurrent()][i][j] == 'X')
			{
				board[x_pos + i][y_pos + j] = 'X';
			}
		}
	}
}

bool GameBoard::is_valid_place(Piece& piece, int x_pos, int y_pos)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (piece.getShape()[piece.getCurrent()][i][j] == 'X')
			{
				if (x_pos + i > dong || y_pos + j > cot || board[x_pos + i][y_pos + j] == 'X')
				{
					return false;
				}
			}
		}
	}
	return true;
}

int GameBoard::calculate_score()
{
	int filled_cell = 0, filled_column = 0;
	for (auto row : board)
	{
		filled_cell += count(row.begin(), row.end(), 'X');
	}

	for (int j = 0; j < cot; j++)
	{
		bool filled = true;
		for (int i = 0; i < dong; i++)
		{
			if (board[i][j] != 'X')
			{
				filled = false;
				break;
			}
		}
		if (filled) filled_column++;
	}

	return filled_cell + 4 * filled_column;
}