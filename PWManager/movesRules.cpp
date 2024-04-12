#include "moveRules.h"
#include <cmath>
#include <algorithm>

namespace chess
{
	bool isValidMove(Square* from, Square* to, Square*** board)
	{
		Piece* fromPiece = from->getPiece();

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

	std::vector<Square*> validMoves(Square* square, Square*** board) {
		std::vector<Square*> squares;
		Piece* squarePiece = square->getPiece();

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
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

		if (std::abs(toCoord.x - fromCoord.x) == std::abs(toCoord.y - fromCoord.y))
		{
			int i = (fromCoord.x > toCoord.x) ? fromCoord.x - 1 : fromCoord.x + 1;
			int j = (fromCoord.y > toCoord.y) ? fromCoord.y - 1 : fromCoord.y + 1;

			for (i; (fromCoord.x > toCoord.x) ? i > toCoord.x : i < toCoord.x; (fromCoord.x > toCoord.x) ? i-- : i++)
			{
				if (board[i][j]->getPiece() != NULL)
				{
					return false;
				}

				(fromCoord.y > toCoord.y) ? j-- : j++;
			}

			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}

		return false;
	}

	bool isValidRookMove(Square* from, Square* to, Square*** board)
	{
		coordinates fromCoord = from->getCoordinates();
		coordinates toCoord = to->getCoordinates();

		if (toCoord.x == fromCoord.x)
		{
			for (int i = std::min(toCoord.y, fromCoord.y) + 1; i < (std::max(toCoord.y, fromCoord.y)); i++)
			{
				if (board[toCoord.x][i]->getPiece() != NULL)
				{
					return false;
				}
			}

			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}

		else if (toCoord.y == fromCoord.y)
		{
			for (int i = std::min(toCoord.x, fromCoord.x) + 1; i < (std::max(toCoord.x, fromCoord.x)); i++)
			{
				if (board[i][toCoord.y]->getPiece() != NULL)
				{
					return false;
				}
			}

			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}


		return false;
	}
	bool isValidQueenMove(Square* from, Square* to, Square*** board)
	{
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

		//horizontal/vertical movement
		if (((std::abs(toCoord.x - fromCoord.x) == 1) && (std::abs(toCoord.y - fromCoord.y) == 0)) || (std::abs(toCoord.x - fromCoord.x) == 0) && (std::abs(toCoord.y - fromCoord.y) == 1))
		{
			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}

		//diagonal movement
		else if (std::abs(toCoord.x - fromCoord.x) == 1 && std::abs(toCoord.y - fromCoord.y) == 1)
		{
			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				return true;
			}
		}
		return false;
	}

	Move::Move(pieceType ty, coordinates f, coordinates t)
	{
		type = ty;
		from = f;
		to = t;
	}

	pieceType Move::getType()
	{
		return type;
	}

	coordinates Move::getFromCoord()
	{
		return from;
	}

	coordinates Move::getToCoord()
	{
		return to;
	}
}

