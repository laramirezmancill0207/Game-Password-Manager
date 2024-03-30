#include "moves.h"
#include <cmath>

namespace chess
{
	bool isValidPawnMove(Square from, Square to)
	{
		//rules

		//handle pawn attacks
		if (to.getPiece().getType() != NONE)
		{
			if (std::abs(to.getCoordinates().x - from.getCoordinates().x) == 1)
			{
				return true;
			}
		}

		if (from.getCoordinates().x == to.getCoordinates().x && to.getCoordinates().y - from.getCoordinates().y == 1)
		{
			return true;
		}

		return false;
	}
	bool isValidKnightMove(Square from, Square to)
	{
		if (std::abs(to.getCoordinates().y - from.getCoordinates().y) == 2 && std::abs(to.getCoordinates().x - from.getCoordinates().x) == 1)
		{
			return true;
		}

		else if (std::abs(to.getCoordinates().y - from.getCoordinates().y) == 1 && std::abs(to.getCoordinates().x - from.getCoordinates().x) == 2)
		{
			return true;
		}

		return false;
	}
	bool isValidBishopMove(Square from, Square to)
	{
		if (std::abs(to.getCoordinates().x - from.getCoordinates().x) == std::abs(to.getCoordinates().y - from.getCoordinates().y))
		{
			return true;
		}

		return false;
	}
	bool isValidRookMove(Square from, Square to)
	{
		if (to.getCoordinates().x == from.getCoordinates().x || to.getCoordinates().y == from.getCoordinates().y)
		{
			return true;
		}


		return false;
	}
	bool isValidQueenMove(Square from, Square to)
	{
		if (isValidBishopMove(from, to) && isValidRookMove(from, to))
		{
			return true;
		}
	}
	bool isValidKingMove(Square from, Square to)
	{
		if (std::abs(to.getCoordinates().x - from.getCoordinates().x) == 1 || std::abs(to.getCoordinates().y - from.getCoordinates().y) == 1)
		{
			return true;
		}

		else if (std::abs(to.getCoordinates().x - from.getCoordinates().x) == 1 && std::abs(to.getCoordinates().y - from.getCoordinates().y) == 1)
		{
			return true;
		}
		return false;
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

