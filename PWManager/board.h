#pragma once
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

typedef enum color { WHITE, BLACK, RED, NONE } GameColor;

struct coordinates
{
	int x, y;
};

namespace chess
{
	typedef enum piece { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY } pieceType;

	class baseChess : public QGraphicsObject
	{
	public:
		baseChess(QGraphicsItem* parent = nullptr);

	protected:
		void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
		void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;
		void dropEvent(QGraphicsSceneDragDropEvent* event) override;

		QColor color = Qt::lightGray;
		bool dragOver = false;
	};

	class Piece : public baseChess
	{
	private:
		GameColor color;
		pieceType type;
	public:
		Piece(GameColor c, pieceType t)
		{
			color = c;
			type = t;
		}

		GameColor getColor();
		pieceType getType();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	};

	class Square : public baseChess
	{
	private:
		GameColor color;
		Piece *piece;
		coordinates c;
		
	public:
		Square(QGraphicsItem *parent = nullptr);

		coordinates getCoordinates();
		Piece* getPiece();
		void setPiece(Piece* piece);
		void setColor(GameColor color);
		GameColor getColor();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

	};

	class Board : public baseChess
	{
	private:
		Square*** squares;
		Piece* whiteRook = new Piece(WHITE, ROOK);
		Piece* whiteKnight = new Piece(WHITE, KNIGHT);
		Piece* whiteBishop = new Piece(WHITE, BISHOP);
		Piece* whiteQueen = new Piece(WHITE, QUEEN);
		Piece* whiteKing = new Piece(WHITE, KING);
		Piece* whitePawn = new Piece(WHITE, PAWN);

		Piece* blackRook = new Piece(WHITE, ROOK);
		Piece* blackKnight = new Piece(WHITE, KNIGHT);
		Piece* blackBishop = new Piece(WHITE, BISHOP);
		Piece* blackQueen = new Piece(WHITE, QUEEN);
		Piece* blackKing = new Piece(WHITE, KING);
		Piece* blackPawn = new Piece(WHITE, PAWN);

	public:
		Board(QGraphicsItem* parent = nullptr);

		Square*** getSquares();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	};
}

namespace checkers
{
	typedef enum piece { KING, NORMAL, NONE } pieceType;

	class Piece
	{
	private:
		GameColor color;
		pieceType type;
	public:
		void setType(pieceType type);
		GameColor getColor();
		pieceType getType();
	};

	class Square
	{
	private:
		GameColor color;
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
