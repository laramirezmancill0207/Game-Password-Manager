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

namespace game
{
	typedef enum game { CHESS, CHECKERS } Game;

	typedef enum color { WHITE, BLACK, RED, LIGHTRED, NONE } GameColor;

	typedef enum piece { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY, CHECKER, CKING } pieceType;

	struct coordinates
	{
		int x, y;
	};

	//base class for game
	class baseGame : public QGraphicsObject
	{
	public:
		baseGame(QGraphicsItem* parent = nullptr);
	};

	/*
	* piece class inherits from base game
	*/
	class Piece : public baseGame
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

	class Square : public baseGame
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
	class Board : public baseGame
	{
	private:
		static Board* instancePtr;
		Square*** squares;
		GameColor turn;
		std::vector<Move> playedMoves;
		Game type;

		Board(QGraphicsItem* parent = nullptr);

	public:
		~Board();

		static Board* getInstance();

		GameColor getTurn();
		void switchTurn();
		void addMove(Move m);
		std::vector<Move> getPlayedMoves();
		Game getGame();
		void setGame(Game g);

		Square*** getSquares();

		void setupChessBoard();
		void setupCheckersBoard();
		void resetBoard();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

		Board(const Board&) = delete;
		Board(Board&&) = delete;
		Board& operator=(const Board&) = delete;
		Board& operator=(Board&&) = delete;
	};
}