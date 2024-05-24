#include "PieceLLeft.h"

PieceLLeft::PieceLLeft()
{
	shape =
	{
		{
			{'.', 'X', '.', '.'},
			{'.', 'X', '.', '.'},
			{'X', 'X', '.', '.'},
			{'.', '.', '.', '.'}
		},
		{
			{'X', '.', '.', '.'},
			{'X', 'X', 'X', '.'},
			{'.', '.', '.', '.'},
			{'.', '.', '.', '.'}
		},
		{
			{'X', 'X', '.', '.'},
			{'X', '.', '.', '.'},
			{'X', '.', '.', '.'},
			{'.', '.', '.', '.'}
		},
		{
			{'X', 'X', 'X', '.'},
			{'.', '.', 'X', '.'},
			{'.', '.', '.', '.'},
			{'.', '.', '.', '.'}
		}
	};
}