#pragma once
#include "pieces.h"
#include <tuple>

typedef enum color { WHITE, BLACK, NONE } Color;
struct coordinates
{
	int x, y;
};

namespace chess
{
	class Square
	{
	private:
		Color color;
		Piece piece;
		coordinates c;
		
	public:
		coordinates getCoordinates();
		Piece getPiece();
		void setPiece(Piece piece);

	};

	class Board
	{
	private:
		Square board[8][8];
	};
}

namespace checkers
{
	class Square
	{
	private:
		Color color;
		Piece piece;
		coordinates c;

	public:
		coordinates getCoordinates();
		Piece getPiece();
		void setPiece(Piece piece);

	};

	class Board
	{
	private:
		Square board[8][8];
	};
}