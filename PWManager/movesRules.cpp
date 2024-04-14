#include "moveRules.h"
#include <cmath>
#include <algorithm>

namespace chess
{
	//check if a move of a piece from a square to another square is valid
	bool isValidMove(Square* from, Square* to, Square*** board)
	{
		Piece* fromPiece = from->getPiece();

		//based on square piece type switch to appropriate function
		switch (fromPiece->getType()) {
		case KING:
			return isValidKingMove(from, to);
		case QUEEN:
			return isValidQueenMove(from, to, board);
		case ROOK:
			return isValidRookMove(from, to, board);
		case BISHOP:
			return isValidBishopMove(from, to, board);
		case KNIGHT:
			return isValidKnightMove(from, to);
		case PAWN:
			return isValidPawnMove(from, to, board);
		}

		return false;
	}

	//get all valid moves from a specific square/piece on the board
	std::vector<Square*> validMoves(Square* square, Square*** board) {
		std::vector<Square*> squares;
		Piece* squarePiece = square->getPiece();

		//iterate across all squares on the board
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				//based on piece type check if move from "square" to board[i][j] is valid
				switch (squarePiece->getType()) {
				case KING:
					if (isValidKingMove(square, board[i][j]))
					{
						squares.push_back(board[i][j]);
					}
					break;
				case QUEEN:
					if (isValidQueenMove(square, board[i][j], board))
					{
						squares.push_back(board[i][j]);
					}
					break;
				case ROOK:
					if (isValidRookMove(square, board[i][j], board))
					{
						squares.push_back(board[i][j]);
					}
					break;
				case BISHOP:
					if (isValidBishopMove(square, board[i][j], board))
					{
						squares.push_back(board[i][j]);
					}
					break;
				case KNIGHT:
					if (isValidKnightMove(square, board[i][j]))
					{
						squares.push_back(board[i][j]);
					}
					break;
				case PAWN:
					if (isValidPawnMove(square, board[i][j], board))
					{
						squares.push_back(board[i][j]);
					}
					break;
				}
			}
		}

		return squares;
	}

	bool isValidPawnMove(Square* from, Square* to, Square*** board)
	{
		//rules

		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		GameColor col = from->getPiece()->getColor();

		//handle normal pawn movement
		if (to->getPiece() == NULL)
		{
			if (fromCoord.x == toCoord.x && (toCoord.y - fromCoord.y == ((col == WHITE) ? -1 : 1))) return true;

			//handle 2 square movement on first move
			else if (!from->getPiece()->checkIfMoved() && fromCoord.x == toCoord.x && (toCoord.y - fromCoord.y == ((col == WHITE) ? -2 : 2)))
			{
				//if there is no piece between from square and to square
				if (board[fromCoord.x][(col == WHITE) ? fromCoord.y - 1 : fromCoord.y + 1]->getPiece() == NULL)
				{
					return true;
				}
			}
			
			//en passant
			else if (std::abs(toCoord.x - fromCoord.x) == 1 && (toCoord.y - fromCoord.y == ((col == WHITE) ? -1 : 1)))
			{

			}
		}

		//handle pawn attacks
		else if (to->getPiece() != NULL && to->getPiece()->getColor() != col)
		{
			if (toCoord.y - fromCoord.y == ((col == WHITE) ? -1 : 1) && std::abs(toCoord.x - fromCoord.x) == 1)
			{
				return true;
			}
		}
		
		return false;
	}

	bool isValidKnightMove(Square* from, Square* to)
	{
		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		// 2 by 1 movement in any direction
		if ((std::abs(toCoord.y - fromCoord.y) == 2 && std::abs(toCoord.x - fromCoord.x) == 1) || (std::abs(toCoord.y - fromCoord.y) == 1 && std::abs(toCoord.x - fromCoord.x) == 2))
		{
			if (to->getPiece() == NULL)
			{
				return true;
			}

			//if piece on "to" square
			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}

		return false;
	}

	bool isValidBishopMove(Square* from, Square* to, Square*** board)
	{
		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		//handle bishop diagonal movement
		if (std::abs(toCoord.x - fromCoord.x) == std::abs(toCoord.y - fromCoord.y))
		{
			//get start points based on which direction the bishop moves
			int i = (fromCoord.x > toCoord.x) ? fromCoord.x - 1 : fromCoord.x + 1;
			int j = (fromCoord.y > toCoord.y) ? fromCoord.y - 1 : fromCoord.y + 1;

			//iterate through all pieces between from and to square
			for (i; (fromCoord.x > toCoord.x) ? i > toCoord.x : i < toCoord.x; (fromCoord.x > toCoord.x) ? i-- : i++)
			{
				//check if there are pieces between to and from
				if (board[i][j]->getPiece() != NULL)
				{
					return false;
				}

				(fromCoord.y > toCoord.y) ? j-- : j++;
			}

			//if piece on to square and from and to square pieces are of the same color, not a valid move
			if (to->getPiece() != NULL && to->getPiece()->getColor() == from->getPiece()->getColor())
			{
				return false;
			}

			return true;
		}

		return false;
	}

	bool isValidRookMove(Square* from, Square* to, Square*** board)
	{
		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		//handle straight single direction y movement of rook
		if (toCoord.x == fromCoord.x)
		{
			//iterate through all pieces between to and from
			for (int i = std::min(toCoord.y, fromCoord.y) + 1; i < (std::max(toCoord.y, fromCoord.y)); i++)
			{
				//if there is a piece between from and to not valid
				if (board[toCoord.x][i]->getPiece() != NULL)
				{
					return false;
				}
			}

			//if piece on to square and from and to square pieces are of the same color, not a valid move
			if (to->getPiece() != NULL && to->getPiece()->getColor() == from->getPiece()->getColor())
			{
				return false;
			}

			return true;
		}

		//handle straight single direction x movement of rook

		else if (toCoord.y == fromCoord.y)
		{
			//iterate through all pieces between to and from
			for (int i = std::min(toCoord.x, fromCoord.x) + 1; i < (std::max(toCoord.x, fromCoord.x)); i++)
			{
				//if there is a piece between from and to not valid
				if (board[i][toCoord.y]->getPiece() != NULL)
				{
					return false;
				}
			}

			//if piece on to square and from and to square pieces are of the same color, not a valid move
			if (to->getPiece() != NULL && to->getPiece()->getColor() == from->getPiece()->getColor())
			{
				return false;
			}

			return true;
		}


		return false;
	}
	bool isValidQueenMove(Square* from, Square* to, Square*** board)
	{
		//queen is the same as bishop and rook combined
		if (isValidBishopMove(from, to, board) || isValidRookMove(from, to, board))
		{
			return true;
		}
		return false;
	}

	bool isValidKingMove(Square* from, Square* to)
	{
		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		//horizontal/vertical 1 square movement
		if (((std::abs(toCoord.x - fromCoord.x) == 1) && (std::abs(toCoord.y - fromCoord.y) == 0)) || (std::abs(toCoord.x - fromCoord.x) == 0) && (std::abs(toCoord.y - fromCoord.y) == 1))
		{
			//if piece on to square and from and to square pieces are of the same color, not a valid move
			if (to->getPiece() != NULL && to->getPiece()->getColor() == from->getPiece()->getColor())
			{
				return false;
			}

			return true;
		}

		//diagonal 1 square movement
		else if (std::abs(toCoord.x - fromCoord.x) == 1 && std::abs(toCoord.y - fromCoord.y) == 1)
		{
			//if piece on to square and from and to square pieces are of the same color, not a valid move
			if (to->getPiece() != NULL && to->getPiece()->getColor() == from->getPiece()->getColor())
			{
				return false;
			}

			return true;
		}
		return false;
	}

	//if pawn reaches last rank
	bool isPromotion(Square* square)
	{
		if (square->getPiece()->getType() == PAWN && (square->getCoordinates().y == 0 || square->getCoordinates().y == 7))
		{
			return true;
		}
		return false;
	}

	//for use with king
	bool isSquareAttacked(Square* square, Square*** board)
	{
		Piece* squarePiece = square->getPiece();

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				std::vector<Square*> values = validMoves(board[i][j], board);

				int cnt = count(values.begin(), values.end(), square);
				if (cnt > 0)
				{
					return true;
				}
			}
		}

		return false;
	}
}

