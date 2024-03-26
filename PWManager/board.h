#pragma once

typedef enum color { WHITE, BLACK, NONE } Color;

struct coordinates
{
	int x, y;
};

namespace chess
{
	typedef enum piece { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE } pieceType;

	class Piece
	{
	private:
		Color color;
		pieceType type;
	public:
		Color getColor();
		pieceType getType();
	};

	class Square
	{
	private:
		Color color;
		Piece piece;
		coordinates c;
		
	public:
		coordinates getCoordinates();
		Piece getPiece();
		void setPiece(Piece piece);

	};

	class Board
	{
	private:
		Square board[8][8];
	};
}

namespace checkers
{
	typedef enum piece { KING, NORMAL, NONE } pieceType;

	class Piece
	{
	private:
		Color color;
		pieceType type;
	public:
		void setType(pieceType type);
		Color getColor();
		pieceType getType();
	};

	class Square
	{
	private:
		Color color;
		Piece piece;
		coordinates c;

	public:
		coordinates getCoordinates();
		Piece getPiece();
		void setPiece(Piece piece);

	};

	class Board
	{
	private:
		Square board[8][8];
	};
}
