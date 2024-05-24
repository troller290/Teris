#include "Piece.h"

Piece::Piece() : current_shape(0)
{}

Piece::~Piece()
{}

void Piece::rotate()
{
	current_shape = (current_shape + 1) % shape.size();
}

void Piece::display()
{
	for (auto row : shape[current_shape])
	{
		for (char cell : row)
		{
			cout << cell << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<vector<char>>> Piece::getShape()
{
	return shape;
}

int Piece::getCurrent()
{
	return current_shape;
}