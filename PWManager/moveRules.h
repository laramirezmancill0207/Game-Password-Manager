#pragma once

#include "board.h"

namespace chess
{
	bool isValidMove(Square* from, Square* to, Square*** board);
	std::vector<Square*> validMoves(Square* square, Square*** board);

	bool isValidPawnMove(Square* from, Square* to, Square*** board);
	bool isValidKnightMove(Square* from, Square* to);
	bool isValidBishopMove(Square* from, Square* to, Square*** board);
	bool isValidRookMove(Square* from, Square* to, Square*** board);
	bool isValidQueenMove(Square* from, Square* to, Square*** board);
	bool isValidKingMove(Square* from, Square* to);
}