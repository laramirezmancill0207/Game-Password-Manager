#pragma once

#include "board.h"
#include <vector>

namespace chess
{
	bool isValidMove(Square* from, Square* to, Square*** board);
	std::vector<Square*> validMoves(Square* square);

	bool isValidPawnMove(Square* from, Square* to, Square*** board);
	bool isValidKnightMove(Square* from, Square* to);
	bool isValidBishopMove(Square* from, Square* to, Square*** board);
	bool isValidRookMove(Square* from, Square* to, Square*** board);
	bool isValidQueenMove(Square* from, Square* to, Square*** board);
	bool isValidKingMove(Square* from, Square* to);

	std::vector<Square*> pawnMoves(Square* square);
	std::vector<Square*> knightMoves(Square* square);
	std::vector<Square*> bishopMoves(Square* square);
	std::vector<Square*> rookMoves(Square* square);
	std::vector<Square*> queenMoves(Square* square);
	std::vector<Square*> kingMoves(Square* square);
}