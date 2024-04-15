#pragma once
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

typedef enum color { WHITE, BLACK, RED, LIGHTRED, NONE } GameColor;

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
		~Square();

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

	class Move
	{
	private:
		pieceType type;
		coordinates from;
		coordinates to;
	public:
		Move(pieceType ty, coordinates f, coordinates t);

		pieceType getType();
		coordinates getFromCoord();
		coordinates getToCoord();
	};

	//singleton design pattern
	class Board : public baseChess
	{
	private:
		static Board* instancePtr;
		Square*** squares;
		GameColor turn;
		std::vector<Move> playedMoves;

		Board(QGraphicsItem* parent = nullptr);

	public:
		~Board();

		static Board* getInstance();

		void resetBoard();
		void setupBoard();
		GameColor getTurn();
		void switchTurn();
		void addMove(Move m);
		std::vector<Move> getPlayedMoves();

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
	typedef enum piece { KING, NORMAL, EMPTY } pieceType;

	class baseCheckers : public QGraphicsObject
	{
	public:
		baseCheckers(QGraphicsItem* parent = nullptr);
	};

	class Piece : public baseCheckers
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

	class Square : public baseCheckers
	{
	private:
		GameColor color;
		Piece* piece;
		coordinates c;

	protected:
		void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
		void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;
		void dropEvent(QGraphicsSceneDragDropEvent* event) override;

		//QColor color = Qt::lightGray;
		bool dragOver = false;
	public:
		Square(QGraphicsItem* parent = nullptr);
		~Square();

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

	class Move
	{
	private:
		pieceType type;
		coordinates from;
		coordinates to;
	public:
		Move(pieceType ty, coordinates f, coordinates t);

		pieceType getType();
		coordinates getFromCoord();
		coordinates getToCoord();
	};

	//singleton design pattern
	class Board : public baseCheckers
	{
	private:
		static Board* instancePtr;
		Square*** squares;
		GameColor turn;
		std::vector<Move> playedMoves;

		Board(QGraphicsItem* parent = nullptr);

	public:
		~Board();

		static Board* getInstance();

		void resetBoard();
		void setupBoard();
		GameColor getTurn();
		void switchTurn();
		void addMove(Move m);
		std::vector<Move> getPlayedMoves();

		Square*** getSquares();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

		Board(const Board&) = delete;
		Board(Board&&) = delete;
		Board& operator=(const Board&) = delete;
		Board& operator=(Board&&) = delete;
	};
}
