#pragma once
#include "board.h"
#include "moves.h"

#include <vector>


namespace chess
{
	bool isValidMove(Square from, Square to);
	std::vector<Square> validMoves(Square square);
}

namespace checkers
{
	bool isValidMove(Square from, Square to);
	std::vector<Square> validMoves(Square square);
}