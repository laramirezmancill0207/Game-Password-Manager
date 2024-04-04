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
		c = { -1, -1 };

		piece = new Piece(NONE, EMPTY);

		color = NONE;
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

		switch (this->getColor())
		{
		case (WHITE):
			painter->setBrush(Qt::white);
			break;
		case (BLACK):
			painter->setBrush(Qt::black);
			break;
		case (RED):
			painter->setBrush(Qt::red);
			break;
		default:
			painter->setBrush(Qt::white);
		}


		painter->drawRect(0, 0, 50, 50);
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

		squares = new Square ** [8]();

		for (int i = 0; i < 8; ++i) {
			squares[i] = new Square * [8]();
			// each i-th pointer is now pointing to dynamic array (size 10) of actual int values

			for (int j = 0; j < 8; j++)
			{
				squares[i][j] = new Square(this);
			}
		}


		//place all pieces
		squares[0][0]->setPiece(whiteRook);
		squares[1][0]->setPiece(whiteKnight);
		squares[2][0]->setPiece(whiteBishop);
		squares[3][0]->setPiece(whiteQueen);
		squares[4][0]->setPiece(whiteKing);
		squares[5][0]->setPiece(whiteBishop);
		squares[6][0]->setPiece(whiteKnight);
		squares[7][0]->setPiece(whiteRook);

		squares[0][1]->setPiece(whitePawn);
		squares[1][1]->setPiece(whitePawn);
		squares[2][1]->setPiece(whitePawn);
		squares[3][1]->setPiece(whitePawn);
		squares[4][1]->setPiece(whitePawn);
		squares[5][1]->setPiece(whitePawn);
		squares[6][1]->setPiece(whitePawn);
		squares[7][1]->setPiece(whitePawn);

		squares[0][7]->setPiece(blackRook);
		squares[1][7]->setPiece(blackKnight);
		squares[2][7]->setPiece(blackBishop);
		squares[3][7]->setPiece(blackQueen);
		squares[4][7]->setPiece(blackKing);
		squares[5][7]->setPiece(blackBishop);
		squares[6][7]->setPiece(blackKnight);
		squares[7][7]->setPiece(blackRook);
		
		squares[0][6]->setPiece(blackPawn);
		squares[1][6]->setPiece(blackPawn);
		squares[2][6]->setPiece(blackPawn);
		squares[3][6]->setPiece(blackPawn);
		squares[4][6]->setPiece(blackPawn);
		squares[5][6]->setPiece(blackPawn);
		squares[6][6]->setPiece(blackPawn);
		squares[7][6]->setPiece(blackPawn);


		bool sw = true;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (sw) { squares[j][i]->setColor(WHITE); }

				else { squares[j][i]->setColor(BLACK); }
				sw = !sw;
			}
			sw = !sw;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				QGraphicsObject* square = squares[i][j];
				square->setPos(50*i, 50*j);
			}
		}

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

	GameColor Square::getColor()
	{
		GameColor c = this->color;
		return c;
	}

	GameColor Piece::getColor() {
		GameColor c = this->color;
		return c;
	}
	pieceType Piece::getType() {
		pieceType t = this->type;
		return t;
	}

	Square*** Board::getSquares()
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