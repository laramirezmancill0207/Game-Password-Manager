#pragma once
#include <QGraphicsObject>
#include <QPixmap>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include "GameEngine.h"

namespace game
{
	class Piece : public QGraphicsObject
	{
	private:
		GameColor color;
		pieceType type;
		int gridX, gridY;

	protected:
		void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
		void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
		void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

	public:
		Piece(QGraphicsItem* parent = nullptr, GameColor c = NONE, pieceType t = EMPTY, int x = 0, int y = 0);

		GameColor getColor();
		pieceType getType();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	};

	// Visual Square
	class Square : public QGraphicsObject
	{
	private:
		int gridX, gridY;
		GameColor color;
		bool dragOver = false;

	protected:
		void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
		void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;
		void dropEvent(QGraphicsSceneDragDropEvent* event) override;

	public:
		Square(QGraphicsItem* parent = nullptr, int x = 0, int y = 0);

		void setColor(GameColor col);
		GameColor getColor();

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
	};

	// The Renderer
	class Board : public QGraphicsObject
	{
	private:
		static Board* instancePtr;
		Square* squares[8][8];
		Piece* pieces[8][8];

		GameEngine engine;

		Board(QGraphicsItem* parent = nullptr);

	public:
		~Board();
		static Board* getInstance();
		Square* getSquare(int x, int y) { return squares[x][y]; }

		GameEngine* getEngine();

		void resetBoard();
		void syncVisuals();
		std::vector<Move> getPlayedMoves();
		GameType getGame();
		void setGame(GameType g);

		QRectF boundingRect() const override;
		void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

		Board(const Board&) = delete;
		Board(Board&&) = delete;
		Board& operator=(const Board&) = delete;
		Board& operator=(Board&&) = delete;
	};
}