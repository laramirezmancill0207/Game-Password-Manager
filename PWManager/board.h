#pragma once
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsView>

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
	};

	class Piece : public baseChess
	{
	private:
		GameColor color;
		pieceType type;
		coordinates c;
		bool moved;


	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
		void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

	public:
		Piece(QGraphicsItem* parent = nullptr, GameColor c = NONE, pieceType t = EMPTY);

		GameColor getColor();
		pieceType getType();
		void setColor(GameColor c);
		void setType(pieceType t);
		void setCoordinates(int x, int y);
		coordinates getCoordinates();

		bool checkIfMoved();
		void setMoved();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	};

	class Square : public baseChess
	{
	private:
		GameColor color;
		Piece *piece;
		coordinates c;

	protected:
		void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
		void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;
		void dropEvent(QGraphicsSceneDragDropEvent* event) override;

		//QColor color = Qt::lightGray;
		bool dragOver = false;
	public:
		Square(QGraphicsItem *parent = nullptr);

		coordinates getCoordinates();
		void setCoordinates(int x, int y);
		Piece* getPiece();
		void setPiece(Piece* p);
		void changePiece(GameColor c = NONE, pieceType t = EMPTY, QGraphicsItem* parent = nullptr);
		void setColor(GameColor col);
		GameColor getColor();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

	};

	//singleton design pattern
	class Board : public baseChess
	{
	private:
		Square*** squares;
		static Board* instancePtr;
		GameColor turn;

		Board(QGraphicsItem* parent = nullptr);
		

	public:
		
		static Board* getInstance();
		
		GameColor getTurn();
		void switchTurn();

		Square*** getSquares();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

		Board(const Board&) = delete;
		Board(Board&&) = delete;
		Board& operator=(const Board&) = delete;
		Board& operator=(Board&&) = delete;
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
