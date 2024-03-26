#pragma once

#include "board.h"
#include <vector>

namespace chess
{
	bool isValidPawnMove(Square from, Square to);
	bool isValidKnightMove(Square from, Square to);
	bool isValidBishopMove(Square from, Square to);
	bool isValidRookMove(Square from, Square to);
	bool isValidQueenMove(Square from, Square to);
	bool isValidKingMove(Square from, Square to);

	std::vector<Square> pawnMoves(Square square);
	std::vector<Square> knightMoves(Square square);
	std::vector<Square> bishopMoves(Square square);
	std::vector<Square> rookMoves(Square square);
	std::vector<Square> queenMoves(Square square);
	std::vector<Square> kingMoves(Square square);
}