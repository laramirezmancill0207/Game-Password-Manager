#include "pieces.h"

namespace chess
{
	Color Piece::getColor() {
		Color c = this->color;
		return c;
	}
	pieceType Piece::getType() {
		pieceType t = this->type;
		return t;
	}
}

namespace checkers
{
	void Piece::setType(pieceType type)
	{
		this->type = type;
	}
	Color Piece::getColor() {
		Color c = this->color;
		return c;
	}
	pieceType Piece::getType() {
		pieceType t = this->type;
		return t;
	}
}