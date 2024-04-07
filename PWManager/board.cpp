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

#include <string>

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

	void Square::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
	{
		Q_UNUSED(event);
		dragOver = false;
		update();
	}

	void Square::dropEvent(QGraphicsSceneDragDropEvent* event)
	{
		dragOver = false;
		
		std::string s = event->mimeData()->text().toStdString();

		int x = std::stoi(s.substr(0, s.find('\n')));
		int y = std::stoi(s.substr(s.find('\n'), s.length()));

		Board* b = Board::getInstance();

		Square*** squares = b->getSquares();
		
		Square* square = squares[x][y];
		Piece* p = square->getPiece();

		square->setPiece(NULL);
		this->setPiece(p);

		p->setParentItem(this);

		squares[x][y] = square;
		squares[x][y]->update();
		update();
	}
	

	
	Square::Square(QGraphicsItem* parent)
		: baseChess(parent)
	{
		setAcceptDrops(true);
		this->setPiece(NULL);
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

			for (int j = 0; j < 8; j++)
			{
				squares[i][j] = new Square(this);
				squares[i][j]->setCoordinates(i, j);			
			}
		}

		//create all pieces
		Piece* whiteRook1 = new Piece(squares[0][0], WHITE, ROOK);
		whiteRook1->setCoordinates(0, 0);

		Piece* whiteRook2 = new Piece(squares[7][0], WHITE, ROOK);
		whiteRook2->setCoordinates(7, 0);

		Piece* whiteKnight1 = new Piece(squares[1][0], WHITE, KNIGHT);
		whiteKnight1->setCoordinates(1, 0);

		Piece* whiteKnight2 = new Piece(squares[6][0], WHITE, KNIGHT);
		whiteKnight2->setCoordinates(6, 0);

		Piece* whiteBishop1 = new Piece(squares[2][0], WHITE, BISHOP);
		whiteBishop1->setCoordinates(2, 0);

		Piece* whiteBishop2 = new Piece(squares[5][0], WHITE, BISHOP);
		whiteBishop2->setCoordinates(5, 0);

		Piece* whiteQueen = new Piece(squares[3][0], WHITE, QUEEN);
		whiteQueen->setCoordinates(3, 0);

		Piece* whiteKing = new Piece(squares[4][0], WHITE, KING);
		whiteKing->setCoordinates(4, 0);

		squares[0][0]->setPiece(whiteRook1);
		squares[1][0]->setPiece(whiteKnight1);
		squares[2][0]->setPiece(whiteBishop1);
		squares[3][0]->setPiece(whiteQueen);
		squares[4][0]->setPiece(whiteKing);
		squares[5][0]->setPiece(whiteBishop2);
		squares[6][0]->setPiece(whiteKnight2);
		squares[7][0]->setPiece(whiteRook2);

		//create white pawns
		for (int i = 0; i < 8; i++)
		{
			Piece* p = new Piece(squares[i][1], WHITE, PAWN);
			p->setCoordinates(i, 1);
			squares[i][1]->setPiece(p);
		}

		//create all pieces
		Piece* blackRook1 = new Piece(squares[0][7], BLACK, ROOK);
		blackRook1->setCoordinates(0, 7);

		Piece* blackRook2 = new Piece(squares[7][7], BLACK, ROOK);
		blackRook2->setCoordinates(7, 7);

		Piece* blackKnight1 = new Piece(squares[1][7], BLACK, KNIGHT);
		blackKnight1->setCoordinates(1, 7);

		Piece* blackKnight2 = new Piece(squares[6][7], BLACK, KNIGHT);
		blackKnight2->setCoordinates(6, 7);

		Piece* blackBishop1 = new Piece(squares[2][7], BLACK, BISHOP);
		blackBishop1->setCoordinates(2, 7);

		Piece* blackBishop2 = new Piece(squares[5][7], BLACK, BISHOP);
		blackBishop2->setCoordinates(5, 7);

		Piece* blackQueen = new Piece(squares[3][7], BLACK, QUEEN);
		blackQueen->setCoordinates(3, 7);

		Piece* blackKing = new Piece(squares[4][7], BLACK, KING);
		blackKing->setCoordinates(4, 7);

		squares[0][0]->setPiece(blackRook1);
		squares[1][0]->setPiece(blackKnight1);
		squares[2][0]->setPiece(blackBishop1);
		squares[3][0]->setPiece(blackQueen);
		squares[4][0]->setPiece(blackKing);
		squares[5][0]->setPiece(blackBishop2);
		squares[6][0]->setPiece(blackKnight2);
		squares[7][0]->setPiece(blackRook2);

		//create white pawns
		for (int i = 0; i < 8; i++)
		{
			Piece* p = new Piece(squares[i][6], BLACK, PAWN);
			p->setCoordinates(i, 6);
			squares[i][1]->setPiece(p);
		}


		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0)
				{
					squares[i][j]->setColor(BLACK);
				}
				else
				{
					squares[i][j]->setColor(WHITE);
				}

				//draw squares and pieces
				QGraphicsObject* square = squares[i][j];
				square->setPos(50 * i, 50 * j);

				if (squares[i][j]->getPiece() != NULL) {
					QGraphicsObject* piece = squares[i][j]->getPiece();
					piece->setPos(0, 0);
				}
			}
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

		Board* b = Board::getInstance();
		Square*** squares = b->getSquares();

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (squares[i][j]->getColor() != RED)
				{
					continue;					
				}

				if ((i + j) % 2 == 0) 
				{
					squares[i][j]->setColor(BLACK);
				}
				else
				{
					squares[i][j]->setColor(WHITE);
				}
				squares[i][j]->update();
			}
		}

		coordinates c;
		c = this->getCoordinates();
		squares[c.x][c.y]->setColor(RED);
		squares[c.x][c.y]->setPiece(this);

		squares[c.x][c.y]->update();
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
		QString s = QString::number(c.x) + "\n" + QString::number(c.y);
		drag->setMimeData(mime);

		mime->setText(s);
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
		Piece* p = piece;
		return p;
	}

	void Square::setPiece(Piece* p)
	{
		piece = p;
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

	coordinates Piece::getCoordinates()
	{
		coordinates c = this->c;
		return c;
	}
	void Piece::setCoordinates(int x, int y)
	{
		this->c = { x, y };
	}


	Square*** Board::getSquares()
	{
		return this->squares;
	}

	void Board::setView(QGraphicsView* v)
	{
		view = v;
	}

	QGraphicsView* Board::getView()
	{
		return this->view;
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