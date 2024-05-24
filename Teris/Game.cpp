#include "Game.h"
#include "PieceI.h"
#include "PieceLLeft.h"
#include "PieceLRight.h"
#include "PieceSquare.h"
#include "PieceZLeft.h"
#include "PieceZRight.h"
#include "PieceT.h"
Game::Game() : brick(0), current_piece(nullptr)
{
	gameboard = GameBoard();
}

Game::~Game()
{
	delete current_piece;
}

void Game::start_game()
{
	gameboard.display();
	while (brick < 25)
	{
		generate_piece();
		brick++;
		cout << "Da tao " << brick << " vien gach!" << endl;
		while (!play());
	}
	end_game();
}

bool Game::play()
{
	int option;
	cout << "Chon hanh dong (1.Place 2. Rotate 3. Discard): ";
	cin >> option;

	if (option == 1)
	{
		int x, y;
		cout << "Nhap toa do x: "; cin >> x;
		cout << "Nhap toa do y: "; cin >> y;
		if (gameboard.is_valid_place(*current_piece, x, y))
		{
			gameboard.update_board(*current_piece, x, y);
			gameboard.display();
			return true; //tao manh tiep theo
		}
		else
		{
			cout << "Vi tri khong hop le" << endl;
			return false; //khong dat dc, chon action khac
		}
	}
	else if (option == 2)
	{
		current_piece->rotate();
		current_piece->display();
		return false; //nguoi choi chon action tiep
	}
	else if (option == 3)
	{
		return true; //tao manh tiep theo
	}
	else
	{
		cout << "Khong co action" << endl;
		return false; //chon action lai
	}
}

void Game::end_game()
{
	gameboard.display();
	int score = gameboard.calculate_score();
	cout << "Game Over! Tong so diem cua ban: " << score << endl;
}

void Game::generate_piece()
{
	vector<Piece*> piece = { new PieceI, new PieceLRight, new PieceLLeft, new PieceSquare, new PieceZLeft, new PieceZRight, new PieceT };
	current_piece = piece[rand() % piece.size()];
	cout << "Dang tao manh moi: " << endl;
	current_piece->display();
}