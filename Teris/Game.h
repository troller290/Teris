#pragma once
#include "GameBoard.h"
#include "Piece.h"
class Game
{
private:
	GameBoard gameboard;
	Piece* current_piece;
	int brick;
public:
	Game();
	~Game();
	void generate_piece();
	void start_game();
	void end_game();
	bool play();
};

