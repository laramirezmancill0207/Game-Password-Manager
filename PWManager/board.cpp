#include "board.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

namespace chess
{
	baseChess::baseChess(QGraphicsItem* parent)
		: QGraphicsObject(parent), color(Qt::lightGray)
	{
		setAcceptDrops(true);
	}
	//! [0]

	//! [1]
	void baseChess::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
	{
		if (event->mimeData()->hasColor()) {
			event->setAccepted(true);
			dragOver = true;
			update();
		}
		else {
			event->setAccepted(false);
		}
	}
	//! [1]

	//! [2]
	void baseChess::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
	{
		Q_UNUSED(event);
		dragOver = false;
		update();
	}
	//! [2]

	//! [3]
	void baseChess::dropEvent(QGraphicsSceneDragDropEvent* event)
	{
		dragOver = false;
		if (event->mimeData()->hasColor())
			color = qvariant_cast<QColor>(event->mimeData()->colorData());
		update();
	}
	//! [3]
	
	Square::Square(QGraphicsItem* parent)
		: baseChess(parent)
	{
	}
	
	QRectF Square::boundingRect() const
	{
		return QRectF(-30, -20, 60, 60);
	}

	void Square::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		Q_UNUSED(option);
		Q_UNUSED(widget);

		painter->setBrush(dragOver ? baseChess::color.lighter(130) : color);
		painter->drawRoundedRect(-20, -20, 40, 60, 25, 25, Qt::RelativeSize);
		painter->drawEllipse(-25, -20, 20, 20);
		painter->drawEllipse(5, -20, 20, 20);
		painter->drawEllipse(-20, 22, 20, 20);
		painter->drawEllipse(0, 22, 20, 20);
	}

	QRectF Board::boundingRect() const
	{
		return QRectF();
	}

	void Board::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		Q_UNUSED(painter);
		Q_UNUSED(option);
		Q_UNUSED(widget);
	}

	QRectF Piece::boundingRect() const
	{
		return QRectF(-30, -20, 60, 60);
	}

	void Piece::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		Q_UNUSED(option);
		Q_UNUSED(widget);

		painter->setBrush(dragOver ? baseChess::color.lighter(130) : color);
		painter->drawRoundedRect(-20, -20, 40, 60, 25, 25, Qt::RelativeSize);
		painter->drawEllipse(-25, -20, 20, 20);
		painter->drawEllipse(5, -20, 20, 20);
		painter->drawEllipse(-20, 22, 20, 20);
		painter->drawEllipse(0, 22, 20, 20);
	}
	
	Board::Board(QGraphicsItem* parent)
		: baseChess(parent)
	{
		setFlag(ItemHasNoContents);

		squares = new Square * [10];

		for (int i = 0; i < 10; ++i) {
			squares[i] = new Square[10];
			// each i-th pointer is now pointing to dynamic array (size 10) of actual int values
		}

		squares[0][0].setPiece(whiteRook);
		squares[0][0].setColor(BLACK);
		squares[1][0].setPiece(whiteKnight);
		squares[1][0].setColor(WHITE);
		squares[2][0].setPiece(whiteBishop);
		squares[2][0].setColor(BLACK);
		squares[3][0].setPiece(whiteQueen);
		squares[3][0].setColor(WHITE);
		squares[4][0].setPiece(whiteKing);
		squares[4][0].setColor(BLACK);
		squares[5][0].setPiece(whiteBishop);
		squares[5][0].setColor(WHITE);
		squares[6][0].setPiece(whiteKnight);
		squares[6][0].setColor(BLACK);
		squares[7][0].setPiece(whiteRook);
		squares[7][0].setColor(WHITE);

		squares[0][7].setPiece(whiteRook);
		squares[0][7].setColor(WHITE);
		squares[1][7].setPiece(whiteKnight);
		squares[1][7].setColor(BLACK);
		squares[2][7].setPiece(whiteBishop);
		squares[2][7].setColor(WHITE);
		squares[3][7].setPiece(whiteQueen);
		squares[3][7].setColor(BLACK);
		squares[4][7].setPiece(whiteKing);
		squares[4][7].setColor(WHITE);
		squares[5][7].setPiece(whiteBishop);
		squares[5][7].setColor(BLACK);
		squares[6][7].setPiece(whiteKnight);
		squares[6][7].setColor(WHITE);
		squares[7][7].setPiece(whiteRook);
		squares[7][7].setColor(BLACK);

		QGraphicsObject* square = new Square(this);

		square->setPos(0, 0);
		
	}


	coordinates Square::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}

	Piece* Square::getPiece()
	{
		Piece* p = this->piece;
		return p;
	}

	void Square::setPiece(Piece* piece)
	{
		this->piece = piece;
	}

	void Square::setColor(GameColor color)
	{
		this->color = color;
	}

	GameColor Piece::getColor() {
		GameColor c = this->color;
		return c;
	}
	pieceType Piece::getType() {
		pieceType t = this->type;
		return t;
	}

	Square** Board::getSquares()
	{
		return this->squares;
	}

}

namespace checkers
{
	coordinates Square::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}

	Piece Square::getPiece()
	{
		Piece p = this->piece;
		return p;
	}

	void Square::setPiece(Piece piece)
	{
		this->piece = piece;
	}

	void Piece::setType(pieceType type)
	{
		this->type = type;
	}
	GameColor Piece::getColor() {
		GameColor c = this->color;
		return c;
	}
	pieceType Piece::getType() {
		pieceType t = this->type;
		return t;
	}
}