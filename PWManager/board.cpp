#include "board.h"
#include "gamePassword.h"

#include <QMimeData>
#include <QPainter>
#include <QCursor>
#include <QApplication>
#include <QDrag>
#include <QWidget>
#include <string>
#include <map>

namespace game
{
	// SQUARE LOGIC

	Square::Square(QGraphicsItem* parent, int x, int y)
		: QGraphicsObject(parent), gridX(x), gridY(y)
	{
		setAcceptDrops(true);
	}

	void Square::dragEnterEvent(QGraphicsSceneDragDropEvent* event) {
		event->setAccepted(true);
		dragOver = true;
		update();
	}

	void Square::dragLeaveEvent(QGraphicsSceneDragDropEvent* event) {
		Q_UNUSED(event);
		dragOver = false;
		update();
	}

	void Square::dropEvent(QGraphicsSceneDragDropEvent* event)
	{
		dragOver = false;

		// Get where the piece came from
		std::string s = event->mimeData()->text().toStdString();
		int fromX = std::stoi(s.substr(0, s.find('\n')));
		int fromY = std::stoi(s.substr(s.find('\n') + 1, s.length()));

		Board* b = Board::getInstance();

		// Engine handles move
		bool success = b->getEngine()->attemptMove(fromX, fromY, gridX, gridY);

		// Resync the UI to the engine state
		b->syncVisuals();
	}

	void Square::setColor(GameColor col) { color = col; update(); }
	GameColor Square::getColor() { return color; }
	QRectF Square::boundingRect() const { return QRectF(0, 0, 50, 50); }

	void Square::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
	{
		switch (color) {
		case WHITE: painter->setBrush(Qt::white); break;
		case BLACK: painter->setBrush(Qt::blue); break;
		case RED: painter->setBrush(Qt::red); break;
		case LIGHTRED: painter->setBrush(QColor(Qt::red).lighter(120)); break;
		default: painter->setBrush(Qt::white);
		}
		painter->drawRect(0, 0, 50, 50);
	}

	// PIECE LOGIC

	Piece::Piece(QGraphicsItem* parent, GameColor c, pieceType t, int x, int y)
		: QGraphicsObject(parent), color(c), type(t), gridX(x), gridY(y)
	{
		setCursor(Qt::OpenHandCursor);
		setAcceptedMouseButtons(Qt::LeftButton);
	}

	void Piece::mousePressEvent(QGraphicsSceneMouseEvent*) {
		setCursor(Qt::ClosedHandCursor);
		Board* b = Board::getInstance();

		// Reset all colors to clear old highlights
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				(i + j) % 2 == 0 ? b->getSquare(i, j)->setColor(WHITE) : b->getSquare(i, j)->setColor(BLACK);
			}
		}

		// Highlight the clicked piece RED
		b->getSquare(gridX, gridY)->setColor(RED);

		// Ask the Engine for valid moves, highlight them LIGHTRED
		std::vector<coordinates> validMoves = b->getEngine()->getValidMoves(gridX, gridY);
		for (const auto& move : validMoves) {
			b->getSquare(move.x, move.y)->setColor(LIGHTRED);
		}
	}

	void Piece::mouseReleaseEvent(QGraphicsSceneMouseEvent*) {
		setCursor(Qt::OpenHandCursor);
	}

	void Piece::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance()) {
			return;
		}

		QDrag* drag = new QDrag(event->widget());
		QMimeData* mime = new QMimeData;

		// Package original coordinates
		QString s = QString::number(gridX) + "\n" + QString::number(gridY);
		mime->setText(s);
		drag->setMimeData(mime);

		drag->exec(Qt::MoveAction);
		setCursor(Qt::OpenHandCursor);
	}

	GameColor Piece::getColor() { return color; }
	pieceType Piece::getType() { return type; }
	QRectF Piece::boundingRect() const { return QRectF(0, 0, 50, 50); }

	void Piece::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
	{
		std::map<GameColor, std::map<pieceType, QPixmap>> pieceImageMap = getPieceImageMap();
		painter->drawPixmap(0, 0, 50, 50, pieceImageMap[color][type]);
	}

	// BOARD RENDERER LOGIC

	Board* Board::instancePtr = NULL;

	Board* Board::getInstance() {
		if (instancePtr == NULL) instancePtr = new Board();
		return instancePtr;
	}

	Board::Board(QGraphicsItem* parent) : QGraphicsObject(parent)
	{
		setFlag(ItemHasNoContents);

		// Initialize visual grids
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; j++) {
				squares[i][j] = new Square(this, i, j);
				squares[i][j]->setPos(50 * i, 50 * j);
				pieces[i][j] = nullptr;
			}
		}

		resetBoard(); // Populates engine and syncs visuals
	}

	Board::~Board() {
		instancePtr = NULL;
	}

	void Board::resetBoard() {
		engine.resetBoard(engine.getGameType());
		syncVisuals();
	}

	// Reads the engine and updates the screen
	void Board::syncVisuals()
	{
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				// Reset Checkerboard Colors
				(i + j) % 2 == 0 ? squares[i][j]->setColor(WHITE) : squares[i][j]->setColor(BLACK);

				// Clear old visual piece
				if (pieces[i][j] != nullptr) {
					pieces[i][j]->deleteLater();
					pieces[i][j] = nullptr;
				}

				// Read the Engine's Brain
				PieceData pd = engine.getPieceAt(i, j);

				// Draw a new visual piece if a piece exists in the engine
				if (pd.type != EMPTY) {
					pieces[i][j] = new Piece(this, pd.color, pd.type, i, j);
					pieces[i][j]->setPos(50 * i, 50 * j);
				}
			}
		}
		update();
	}

	GameEngine* Board::getEngine() { return &engine; }
	std::vector<Move> Board::getPlayedMoves() { return engine.getPlayedMoves(); }
	GameType Board::getGame() { return engine.getGameType(); }

	void Board::setGame(GameType g) {
		engine.resetBoard(g);
		syncVisuals();
	}

	QRectF Board::boundingRect() const { return QRectF(); }
	void Board::paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {}
}