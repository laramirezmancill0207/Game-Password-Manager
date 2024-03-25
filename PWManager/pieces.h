#pragma once
#include "board.h"

namespace chess
{
	typedef enum piece { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE } pieceType;

	class Piece
	{
	private:
		Color color;
		pieceType type;
	public:
		Color getColor();
		pieceType getType();
	};
}

namespace checkers
{
	typedef enum piece { KING, NORMAL, NONE } pieceType;

	class Piece
	{
	private:
		Color color;
		pieceType type;
	public:
		void setType(pieceType type);
		Color getColor();
		pieceType getType();
	};
}