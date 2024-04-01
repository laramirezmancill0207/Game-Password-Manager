#include "gameLogic.h"

namespace chess
{
	bool isValidMove(Square from, Square to)
	{
		Piece* fromPiece = from.getPiece();

		switch (fromPiece->getType()) {
		case KING:
			break;
		case QUEEN:
			break;
		case ROOK:
			break;
		case BISHOP:
			break;
		case KNIGHT:
			break;
		case PAWN:
			break;
		}
		
		return false;
	}

	std::vector<Square> validMoves(Square square) {
		std::vector<Square> squares;
		Piece* squarePiece = square.getPiece();

		switch (squarePiece->getType()) {
		case KING:
			break;
		case QUEEN:
			break;
		case ROOK:
			break;
		case BISHOP:
			break;
		case KNIGHT:
			break;
		case PAWN:
			break;
		}

		return squares;
	}
}

namespace checkers
{

}