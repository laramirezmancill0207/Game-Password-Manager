#include "moves.h"

namespace chess
{
	bool isValidPawnMove(Square from, Square to)
	{
		//rules

		//handle pawn attacks
		if (to.getPiece().getType() == NONE)
		{
			if (from.getCoordinates().x == to.getCoordinates().x-1 || from.getCoordinates().x == to.getCoordinates().x + 1)
			{

			}
		}

		if (from.getCoordinates().x != to.getCoordinates().x)
		{
			return false;
		}


	}
	bool isValidKnightMove(Square from, Square to)
	{

	}
	bool isValidBishopMove(Square from, Square to)
	{

	}
	bool isValidRookMove(Square from, Square to)
	{

	}
	bool isValidQueenMove(Square from, Square to)
	{

	}
	bool isValidKingMove(Square from, Square to)
	{

	}


	std::vector<Square> pawnMoves(Square square)
	{

	}
	std::vector<Square> knightMoves(Square square)
	{

	}
	std::vector<Square> bishopMoves(Square square)
	{

	}
	std::vector<Square> rookMoves(Square square)
	{

	}
	std::vector<Square> queenMoves(Square square)
	{

	}
	std::vector<Square> kingMoves(Square square)
	{

	}
}

