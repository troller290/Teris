#pragma once
#include "Piece.h"
class GameBoard
{
private:
	vector<vector<char>> board;
	int dong, cot;
public:
	GameBoard();
	void init_board();
	void display();
	void update_board(Piece&, int, int);
	bool is_valid_place(Piece&, int, int);
	int calculate_score();
};

