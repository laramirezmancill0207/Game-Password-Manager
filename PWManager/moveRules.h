#pragma once

#include "board.h"

namespace game
{
	/*
	* strategy design pattern
	* calls isValid x Move based on piece
	* return bool of whether move is valid
	*/
	bool isValidChessMove(Square* from, Square* to, Square*** board);

	/*
	* strategy design pattern
	* calls isValid x Move based on piece
	* returns a vector of squares correspoinding to which squares on the board the parameter "square" could move to
	*/
	std::vector<Square*> validChessMoves(Square* square, Square*** board);

	/*
	* check to see if a piece makes a valid move based on specific piece rules
	* takes squares from and to to check these rules
	* may also take board depending on if need to check rest if board pieces, states etc.
	*/
	bool isValidPawnMove(Square* from, Square* to, Square*** board);
	bool isValidKnightMove(Square* from, Square* to);
	bool isValidBishopMove(Square* from, Square* to, Square*** board);
	bool isValidRookMove(Square* from, Square* to, Square*** board);
	bool isValidQueenMove(Square* from, Square* to, Square*** board);
	bool isValidKingMove(Square* from, Square* to);

	//check square to see if it contains a pawn promotion. return true if so
	bool isChessPromotion(Square* square);

	//check if some piece on the board is attacking a square
	bool isChessSquareAttacked(Square* square, Square*** board);

	//check if squares from, to is a valid move for a checkers piece
	bool isValidCheckersMove(Square* from, Square* to);

	//returns all valid moves for a checkers piece in the form of a vector of squares
	std::vector<Square*> validCheckersMoves(Square* square, Square*** board);

	//check if a square corresponds to a checkers promotion
	bool isCheckersPromotion(Square* square);
}