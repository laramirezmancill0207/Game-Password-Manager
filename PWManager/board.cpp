#include "board.h"
#include "moveRules.h"
#include "gamePassword.h"

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
#include <QMenu>


#include <string>
#include <map>
#include <vector>



namespace game
{
	baseGame::baseGame(QGraphicsItem* parent)
		: QGraphicsObject(parent)
	{	
	}


	//square functions
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

		// get mime data and convert to x y coordinates
		std::string s = event->mimeData()->text().toStdString();
		int x = std::stoi(s.substr(0, s.find('\n')));
		int y = std::stoi(s.substr(s.find('\n'), s.length()));

		//get original square and piece from mime data coordinates
		Board* b = Board::getInstance();
		Square*** squares = b->getSquares();
		Square* square = squares[x][y];
		Piece* p = square->getPiece();

		Game gameType = b->getGame();

		//if not colors turn, dont allow move
		if (p->getColor() != b->getTurn())
		{
			return;
		}

		bool isValidMove = (gameType == CHESS) ? isValidChessMove(square, this, squares) : isValidCheckersMove(square, this);;

		//if from and to square arent same. Also use isValidMove to check if allowable chess move
		if (square != this && isValidMove) {
			
			//highlight square red to indicate movement
			this->setColor(RED);
			(x + y) % 2 == 0 ? square->setColor(WHITE) : square->setColor(BLACK);

			//move piece and set new coordinates
			coordinates c = this->getCoordinates();
			p->setCoordinates(c.x, c.y);

			if (this->getPiece() != NULL) delete this->getPiece();

			this->setPiece(p);
			square->setPiece(NULL);
			

			//graphicsscene move piece by setting parent and updating
			p->setParentItem(this);
			square->update();
			update();

			//add move to move vector
			b->addMove(Move::Move(p->getType(), square->getCoordinates(), c));

			if (gameType == CHESS)
			{
				//pawn promotion at end ranks
				if (isChessPromotion(this))
				{

					//this->changePiece(this->getPiece()->getColor(), QUEEN, this);
				}
			}

			else if (gameType == CHECKERS)
			{
				//if checkers promotion change piece to king
				if (isCheckersPromotion(this))
				{
					this->changePiece(this->getPiece()->getColor(), CKING, this);
				}
			}

			//specific piece is no longer on first turn. also switch board turn
			p->setMoved();

			if (gameType == CHECKER && this->getPiece()->checkIfJumping())
			{
				return;
			}

			b->switchTurn();
		}
	}
	
	Square::Square(QGraphicsItem* parent)
		: baseGame(parent)
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

		//paint square based on color
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
		case (LIGHTRED):
			painter->setBrush(QColor(Qt::red).lighter(120));
			break;
		default:
			painter->setBrush(Qt::white);
		}

		painter->drawRect(0, 0, 50, 50);
	}


	//board functions
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
		: baseGame(parent)
	{
		setFlag(ItemHasNoContents);
		turn = WHITE;
		type = CHESS;

		//create squares pointer array
		squares = new Square ** [8]();

		for (int i = 0; i < 8; ++i) {
			squares[i] = new Square * [8]();

			for (int j = 0; j < 8; j++)
			{
				squares[i][j] = new Square(this);
				squares[i][j]->setCoordinates(i, j);			
			}
		}

		//start by setting up chess
		setupChessBoard();

		//iterate through all squares
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				(i + j) % 2 == 0 ? squares[i][j]->setColor(WHITE) : squares[i][j]->setColor(BLACK);

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

	void Board::resetBoard()
	{
		playedMoves.clear();

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; j++)
			{
				//reset square colors
				(i + j) % 2 == 0 ? squares[i][j]->setColor(WHITE) : squares[i][j]->setColor(BLACK);

				//delete all pieces
				if (squares[i][j]->getPiece() != NULL)
				{
					delete squares[i][j]->getPiece();
					squares[i][j]->setPiece(NULL);
				}
			}
		}

		//set turn to white
		if (getTurn() != WHITE) switchTurn();

		//setup board based on which game being played
		if (type == CHESS)
		{
			setupChessBoard();
		}
		else if (type == CHECKERS)
		{
			setupCheckersBoard();
		}

	}

	void Board::setupChessBoard()
	{
		//create all pieces
		Piece* whiteRook1 = new Piece(squares[0][7], WHITE, ROOK);
		whiteRook1->setCoordinates(0, 7);

		Piece* whiteRook2 = new Piece(squares[7][7], WHITE, ROOK);
		whiteRook2->setCoordinates(7, 7);

		Piece* whiteKnight1 = new Piece(squares[1][7], WHITE, KNIGHT);
		whiteKnight1->setCoordinates(1, 7);

		Piece* whiteKnight2 = new Piece(squares[6][7], WHITE, KNIGHT);
		whiteKnight2->setCoordinates(6, 7);

		Piece* whiteBishop1 = new Piece(squares[2][7], WHITE, BISHOP);
		whiteBishop1->setCoordinates(2, 7);

		Piece* whiteBishop2 = new Piece(squares[5][7], WHITE, BISHOP);
		whiteBishop2->setCoordinates(5, 7);

		Piece* whiteQueen = new Piece(squares[3][7], WHITE, QUEEN);
		whiteQueen->setCoordinates(3, 7);

		Piece* whiteKing = new Piece(squares[4][7], WHITE, KING);
		whiteKing->setCoordinates(4, 7);

		squares[0][7]->setPiece(whiteRook1);
		squares[1][7]->setPiece(whiteKnight1);
		squares[2][7]->setPiece(whiteBishop1);
		squares[3][7]->setPiece(whiteQueen);
		squares[4][7]->setPiece(whiteKing);
		squares[5][7]->setPiece(whiteBishop2);
		squares[6][7]->setPiece(whiteKnight2);
		squares[7][7]->setPiece(whiteRook2);

		//create white pawns
		for (int i = 0; i < 8; i++)
		{
			Piece* p = new Piece(squares[i][6], WHITE, PAWN);
			p->setCoordinates(i, 6);
			squares[i][6]->setPiece(p);
		}

		//create all pieces
		Piece* blackRook1 = new Piece(squares[0][0], BLACK, ROOK);
		blackRook1->setCoordinates(0, 0);

		Piece* blackRook2 = new Piece(squares[7][0], BLACK, ROOK);
		blackRook2->setCoordinates(7, 0);

		Piece* blackKnight1 = new Piece(squares[1][0], BLACK, KNIGHT);
		blackKnight1->setCoordinates(1, 0);

		Piece* blackKnight2 = new Piece(squares[6][0], BLACK, KNIGHT);
		blackKnight2->setCoordinates(6, 0);

		Piece* blackBishop1 = new Piece(squares[2][0], BLACK, BISHOP);
		blackBishop1->setCoordinates(2, 0);

		Piece* blackBishop2 = new Piece(squares[5][0], BLACK, BISHOP);
		blackBishop2->setCoordinates(5, 0);

		Piece* blackQueen = new Piece(squares[3][0], BLACK, QUEEN);
		blackQueen->setCoordinates(3, 0);

		Piece* blackKing = new Piece(squares[4][0], BLACK, KING);
		blackKing->setCoordinates(4, 0);

		squares[0][0]->setPiece(blackRook1);
		squares[1][0]->setPiece(blackKnight1);
		squares[2][0]->setPiece(blackBishop1);
		squares[3][0]->setPiece(blackQueen);
		squares[4][0]->setPiece(blackKing);
		squares[5][0]->setPiece(blackBishop2);
		squares[6][0]->setPiece(blackKnight2);
		squares[7][0]->setPiece(blackRook2);

		//create black pawns
		for (int i = 0; i < 8; i++)
		{
			Piece* p = new Piece(squares[i][1], BLACK, PAWN);
			p->setCoordinates(i, 1);
			squares[i][1]->setPiece(p);
		}
	}

	

	void Board::setupCheckersBoard()
	{
		//add pieces
		for (int i = 0; i < 8; i++)
		{
			for (int j = (i % 2) ? 0 : 1; j < 8; j += 2)
			{
				//black checkers pieces from y == 0 to 2
				if (i < 3)
				{
					Piece* p = new Piece(squares[j][i], BLACK, CHECKER);
					p->setCoordinates(j, i);
					squares[j][i]->setPiece(p);
				}

				//black checkers pieces from y == 5 to 7
				else if (i > 4)
				{
					Piece* p = new Piece(squares[j][i], WHITE, CHECKER);
					p->setCoordinates(j, i);
					squares[j][i]->setPiece(p);
				}

			}
		}
	}

	//piece functions
	Piece::Piece(QGraphicsItem* parent, GameColor c, pieceType t)
		: baseGame(parent)
	{
		color = c;
		type = t;
		moved = false;
		isJumping = false;
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

		//draw pieces from image map
		std::map<GameColor, std::map<pieceType, QPixmap>> pieceImageMap = getPieceImageMap();

		painter->drawPixmap(0, 0, 50, 50, pieceImageMap[this->getColor()][this->getType()]);
	}


	void Piece::mousePressEvent(QGraphicsSceneMouseEvent*)
	{
		setCursor(Qt::ClosedHandCursor);

		Board* b = Board::getInstance();
		Square*** squares = b->getSquares();

		//reset square colors to proper white and black
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (squares[i][j]->getColor() == (WHITE | BLACK))
				{
					continue;					
				}

				(i + j) % 2 == 0 ? squares[i][j]->setColor(WHITE) : squares[i][j]->setColor(BLACK);
				squares[i][j]->update();
			}
		}

		//set selected square to red
		coordinates c;
		c = this->getCoordinates();
		squares[c.x][c.y]->setColor(RED);
		squares[c.x][c.y]->update();

		//if not colors turn, return
		if (b->getTurn() != this->getColor())
		{
			return;
		}

		//based on game type, return valid move vector

		std::vector<Square*> moves;

		if (b->getGame() == CHESS)
		{
			moves = validChessMoves(squares[c.x][c.y], squares);
		}
		else if (b->getGame() == CHECKERS)
		{
			moves = validCheckersMoves(squares[c.x][c.y], squares);
		}

		for (auto& it : moves)
		{
			it->setColor(LIGHTRED);
			it->update();
		}
	}

	void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent*)
	{
		setCursor(Qt::OpenHandCursor);
	}

	void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		//draw properly
		if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
			.length() < QApplication::startDragDistance()) {
			return;
		}

		//drag even to send mime data to dropevent
		QDrag* drag = new QDrag(event->widget());
		QMimeData* mime = new QMimeData;
		QString s = QString::number(c.x) + "\n" + QString::number(c.y);
		drag->setMimeData(mime);

		//send text mimedata to Square::dropevent
		mime->setText(s);
		drag->exec(Qt::MoveAction);
		setCursor(Qt::OpenHandCursor);
	}

	//getters and setters / destructors
	Square::~Square()
	{
		delete this->getPiece();
	}

	coordinates Square::getCoordinates() 
	{ 
		return c; 
	};

	void Square::setCoordinates(int x, int y)
	{
		c = { x, y };
	}

	Piece* Square::getPiece()
	{
		return piece;
	}

	void Square::setPiece(Piece* p)
	{
		piece = p;
	}

	void Square::changePiece(GameColor c, pieceType t, QGraphicsItem* parent)
	{
		piece->setType(t);
		piece->setColor(c);
	}

	void Square::setColor(GameColor col)
	{
		color = col;
	}

	GameColor Square::getColor()
	{
		return color;
	}

	GameColor Piece::getColor() {
		return color;
	}

	pieceType Piece::getType() {
		return type;
	}

	void Piece::setColor(GameColor c)
	{
		color = c;
	}

	void Piece::setType(pieceType t)
	{
		type = t;
	}

	coordinates Piece::getCoordinates()
	{
		return c;
	}

	void Piece::setCoordinates(int x, int y)
	{
		c = { x, y };
	}

	bool Piece::checkIfMoved()
	{
		return moved;
	}

	void Piece::setMoved()
	{
		moved = true;
	}

	bool Piece::checkIfJumping()
	{
		return isJumping;
	}
	void Piece::setJumping(bool j)
	{
		isJumping = j;
	}

	Square*** Board::getSquares()
	{
		return squares;
	}

	GameColor Board::getTurn()
	{
		return turn;
	}
	void Board::switchTurn()
	{
		(turn == WHITE) ? turn = BLACK : turn = WHITE;
	}

	Board::~Board()
	{
		Square*** squares = this->getSquares();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				delete squares[i][j];
			}
			delete[] squares[i];
		}
		delete squares;

		instancePtr = NULL;
	}

	void Board::addMove(Move m)
	{
		playedMoves.push_back(m);
	}

	Game Board::getGame()
	{
		return type;
	}

	void Board::setGame(Game g)
	{
		type = g;
	}

	std::vector<Move> Board::getPlayedMoves()
	{
		return playedMoves;
	}

	Move::Move(pieceType ty, coordinates f, coordinates t)
	{
		type = ty;
		from = f;
		to = t;
	}

	pieceType Move::getType()
	{
		return type;
	}

	coordinates Move::getFromCoord()
	{
		return from;
	}

	coordinates Move::getToCoord()
	{
		return to;
	}
}