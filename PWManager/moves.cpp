#include "moves.h"
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

	std::vector<Square*> validMoves(Square* square) {
		std::vector<Square*> squares;
		Piece* squarePiece = square->getPiece();

		switch (squarePiece->getType()) {
		case KING:
			return kingMoves(square);
		case QUEEN:
			return queenMoves(square);
		case ROOK:
			return rookMoves(square);
		case BISHOP:
			return bishopMoves(square);
		case KNIGHT:
			return knightMoves(square);
		case PAWN:
			return pawnMoves(square);
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

			else if (board[fromCoord.x][(col == WHITE) ? fromCoord.y - 1 : fromCoord.y + 1]->getPiece() == NULL)
			{
				if (!from->getPiece()->checkIfMoved() && fromCoord.x == toCoord.x && (toCoord.y - fromCoord.y == ((col == WHITE) ? -2 : 2)))
				{
					return true;
				}
			}
		}

		//handle pawn attacks
		else if (to->getPiece() != NULL && to->getPiece()->getColor() != col)
		{
			if (toCoord.y - fromCoord.y == ((col == WHITE) ? -1 : 1) && std::abs(toCoord.x - fromCoord.x) == 1)
			{
				delete to->getPiece();
				to->setPiece(NULL);
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
				delete to->getPiece();
				to->setPiece(NULL);
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
			int j = std::min(toCoord.y, fromCoord.y) + 1;

			for (int i = std::min(toCoord.x, fromCoord.x) + 1; i < (std::max(toCoord.x, fromCoord.x)); i++)
			{
				if (board[i][j]->getPiece() != NULL)
				{
					return false;
				}
				j++;
			}

			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				delete to->getPiece();
				to->setPiece(NULL);
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
				delete to->getPiece();
				to->setPiece(NULL);
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
				delete to->getPiece();
				to->setPiece(NULL);
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
		if (std::abs(toCoord.x - fromCoord.x) == 1 || std::abs(toCoord.y - fromCoord.y) == 1)
		{
			if (to->getPiece() == NULL)
			{
				return true;
			}

			else if (to->getPiece() != NULL && to->getPiece()->getColor() != from->getPiece()->getColor())
			{
				delete to->getPiece();
				to->setPiece(NULL);
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
				delete to->getPiece();
				to->setPiece(NULL);
				return true;
			}
		}


		return false;
	}
	


	std::vector<Square*> pawnMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
	std::vector<Square*> knightMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
	std::vector<Square*> bishopMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
	std::vector<Square*> rookMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
	std::vector<Square*> queenMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
	std::vector<Square*> kingMoves(Square* square)
	{
		std::vector<Square*> squares;
		return squares;
	}
}

