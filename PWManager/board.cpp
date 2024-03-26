#include "board.h"

namespace chess
{
	coordinates Square::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}

	Piece Square::getPiece()
	{
		Piece p = this->piece;
		return p;
	}

	void Square::setPiece(Piece piece)
	{
		this->piece = piece;
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

namespace checkers
{
	coordinates Square::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}

	Piece Square::getPiece()
	{
		Piece p = this->piece;
		return p;
	}

	void Square::setPiece(Piece piece)
	{
		this->piece = piece;
	}

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