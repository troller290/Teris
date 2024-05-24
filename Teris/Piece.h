#pragma once
#include "vector"
#include "iostream"
using namespace std;
class Piece
{
protected:
	vector<vector<vector<char>>> shape;
	int current_shape;
public:
	Piece();
	~Piece();
	void rotate();
	virtual void display();

	vector<vector<vector<char>>> getShape();
	int getCurrent();
};

