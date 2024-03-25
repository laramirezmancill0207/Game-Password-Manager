#include "gameLogic.h"

namespace chess
{
	bool isValidMove(Square from, Square to)
	{
		Piece fromPiece = from.getPiece();

		switch (fromPiece.getType()) {
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
		
	}

	std::vector<Square> validMoves(Square square) {
		std::vector<Square> squares;

		return squares;
	}
}

namespace checkers
{

}