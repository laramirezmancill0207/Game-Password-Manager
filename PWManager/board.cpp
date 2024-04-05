#include "board.h"
#include "gameLogic.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QCursor>
#include <QApplication>
#include <QBitmap>
#include <QCursor>
#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>

namespace chess
{
	Board* Board::instancePtr = NULL;

	baseChess::baseChess(QGraphicsItem* parent)
		: QGraphicsObject(parent)
	{	
	}

	void Square::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
	{
		event->setAccepted(true);
		dragOver = true;
		update();
	}
	//! [1]

	//! [2]
	void Square::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
	{
		Q_UNUSED(event);
		dragOver = false;
		update();
	}
	//! [2]

	//! [3]
	void Square::dropEvent(QGraphicsSceneDragDropEvent* event)
	{
		dragOver = false;
		
		update();
	}
	//! [3]
	

	
	Square::Square(QGraphicsItem* parent)
		: baseChess(parent)
	{
		setAcceptDrops(true);
		Piece* p = new Piece(this);
		this->setPiece(p);
	}
	
	QRectF Square::boundingRect() const
	{
		return QRectF(0, 0, 50, 50);
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
			painter->setBrush(Qt::blue);
			break;
		case (RED):
			painter->setBrush(Qt::red);
			break;
		default:
			painter->setBrush(Qt::white);
		}


		painter->drawRect(0, 0, 50, 50);
	}

	Board* Board::getInstance()
	{
		if (instancePtr == NULL)
		{
			instancePtr = new Board();

			return instancePtr;
		}
		else
		{
			return instancePtr;
		}
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
				squares[i][j]->setCoordinates(i, j);			
			}
		}

		//place all pieces
		squares[0][0]->changePiece(WHITE, ROOK);
		squares[1][0]->changePiece(WHITE, KNIGHT);
		squares[2][0]->changePiece(WHITE, BISHOP);
		squares[3][0]->changePiece(WHITE, QUEEN);
		squares[4][0]->changePiece(WHITE, KING);
		squares[5][0]->changePiece(WHITE, BISHOP);
		squares[6][0]->changePiece(WHITE, KNIGHT);
		squares[7][0]->changePiece(WHITE, ROOK);

		squares[0][1]->changePiece(WHITE, PAWN);
		squares[1][1]->changePiece(WHITE, PAWN);
		squares[2][1]->changePiece(WHITE, PAWN);
		squares[3][1]->changePiece(WHITE, PAWN);
		squares[4][1]->changePiece(WHITE, PAWN);
		squares[5][1]->changePiece(WHITE, PAWN);
		squares[6][1]->changePiece(WHITE, PAWN);
		squares[7][1]->changePiece(WHITE, PAWN);


		squares[0][7]->changePiece(BLACK, ROOK);
		squares[1][7]->changePiece(BLACK, KNIGHT);
		squares[2][7]->changePiece(BLACK, BISHOP);
		squares[3][7]->changePiece(BLACK, QUEEN);
		squares[4][7]->changePiece(BLACK, KING);
		squares[5][7]->changePiece(BLACK, BISHOP);
		squares[6][7]->changePiece(BLACK, KNIGHT);
		squares[7][7]->changePiece(BLACK, ROOK);

		squares[0][6]->changePiece(BLACK, PAWN);
		squares[1][6]->changePiece(BLACK, PAWN);
		squares[2][6]->changePiece(BLACK, PAWN);
		squares[3][6]->changePiece(BLACK, PAWN);
		squares[4][6]->changePiece(BLACK, PAWN);
		squares[5][6]->changePiece(BLACK, PAWN);
		squares[6][6]->changePiece(BLACK, PAWN);
		squares[7][6]->changePiece(BLACK, PAWN);


		bool sw = true;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (sw) { squares[j][i]->setColor(WHITE); }

				else { squares[j][i]->setColor(BLACK); }
				sw = !sw;

				//draw squares and pieces
				QGraphicsObject* square = squares[i][j];
				square->setPos(50 * i, 50 * j);

				if (squares[i][j]->getPiece()->getType() == EMPTY) {
					delete squares[i][j]->getPiece();
					squares[i][j]->setPiece(NULL);
				}

				if (squares[i][j]->getPiece() != NULL) {
					QGraphicsObject* piece = squares[i][j]->getPiece();
					piece->setPos(0, 0);
				}
			}
			sw = !sw;
		}

	}

	Piece::Piece(QGraphicsItem* parent, GameColor c, pieceType t)
		: baseChess(parent)
	{
		color = c;
		type = t;
		setCursor(Qt::OpenHandCursor);
		setAcceptedMouseButtons(Qt::LeftButton);
	}
	QRectF Piece::boundingRect() const
	{
		return QRectF(0, 0, 50, 50);
	}

	void Piece::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		Q_UNUSED(option);
		Q_UNUSED(widget);

		QPixmap wp("icons/chess/Chess_plt60.png");
		QPixmap wb("icons/chess/Chess_blt60.png");
		QPixmap wkn("icons/chess/Chess_nlt60.png");
		QPixmap wr("icons/chess/Chess_rlt60.png");
		QPixmap wq("icons/chess/Chess_qlt60.png");
		QPixmap wki("icons/chess/Chess_klt60.png");

		QPixmap bp("icons/chess/Chess_pdt60.png");
		QPixmap bb("icons/chess/Chess_bdt60.png");
		QPixmap bkn("icons/chess/Chess_ndt60.png");
		QPixmap br("icons/chess/Chess_rdt60.png");
		QPixmap bq("icons/chess/Chess_qdt60.png");
		QPixmap bki("icons/chess/Chess_kdt60.png");

		if (this->getColor() == WHITE)
		{
			switch (this->getType())
			{
			case PAWN:
				painter->drawPixmap(0, 0, 50, 50, wp);
				break;
			case BISHOP:
				painter->drawPixmap(0, 0, 50, 50, wb);
				break;
			case KNIGHT:
				painter->drawPixmap(0, 0, 50, 50, wkn);
				break;
			case ROOK:
				painter->drawPixmap(0, 0, 50, 50, wr);
				break;
			case QUEEN:
				painter->drawPixmap(0, 0, 50, 50, wq);
				break;
			case KING:
				painter->drawPixmap(0, 0, 50, 50, wki);
				break;
			default:
				break;
			}
		}

		else if (this->getColor() == BLACK)
		{
			switch (this->getType())
			{
			case PAWN:
				painter->drawPixmap(0, 0, 50, 50, bp);
				break;
			case BISHOP:
				painter->drawPixmap(0, 0, 50, 50, bb);
				break;
			case KNIGHT:
				painter->drawPixmap(0, 0, 50, 50, bkn);
				break;
			case ROOK:
				painter->drawPixmap(0, 0, 50, 50, br);
				break;
			case QUEEN:
				painter->drawPixmap(0, 0, 50, 50, bq);
				break;
			case KING:
				painter->drawPixmap(0, 0, 50, 50, bki);
				break;
			default:
				break;
			}
		}

	}

	void Piece::mousePressEvent(QGraphicsSceneMouseEvent*)
	{
		setCursor(Qt::ClosedHandCursor);
		Square*** squares = Board::getInstance()->getSquares();


		update();
	}

	void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent*)
	{
		setCursor(Qt::OpenHandCursor);
	}

	void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
			.length() < QApplication::startDragDistance()) {
			return;
		}

		QDrag* drag = new QDrag(event->widget());
		QMimeData* mime = new QMimeData;
		drag->setMimeData(mime);
		drag->exec(Qt::MoveAction);
		setCursor(Qt::OpenHandCursor);
	}

	coordinates Square::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}
	void Square::setCoordinates(int x, int y)
	{
		this->c = { x, y };
	}

	Piece* Square::getPiece()
	{
		Piece* p = this->piece;
		return p;
	}

	void Square::setPiece(Piece* p)
	{
		this->piece = p;
	}

	void Square::changePiece(GameColor c, pieceType t, QGraphicsItem* parent)
	{
		this->piece->setType(t);
		this->piece->setColor(c);
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
	void Piece::setColor(GameColor c)
	{
		this->color = c;
	}
	void Piece::setType(pieceType t)
	{
		this->type = t;
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