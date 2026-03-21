#pragma once
#include <vector>

namespace game
{
    typedef enum game { CHESS, CHECKERS } GameType;
    typedef enum color { WHITE, BLACK, RED, LIGHTRED, NONE } GameColor;
    typedef enum piece { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, EMPTY, CHECKER, CKING } pieceType;

    struct coordinates {
        int x, y;
    };

    // A pure data representation of a piece
    struct PieceData {
        pieceType type = EMPTY;
        GameColor color = NONE;
        bool hasMoved = false;
        bool isJumping = false;
    };

    struct Move {
        pieceType type;
        coordinates from;
        coordinates to;
    };

    // The pure C++ Brain
    class GameEngine
    {
    public:
        GameEngine(GameType startingGame = CHESS);

        // Core Game Loop
        void resetBoard(GameType type);
        bool attemptMove(int fromX, int fromY, int toX, int toY);
        std::vector<coordinates> getValidMoves(int startX, int startY);

        // Getters for the UI to read the state
        PieceData getPieceAt(int x, int y) const;
        GameColor getTurn() const;
        GameType getGameType() const;
        std::vector<Move> getPlayedMoves() const;

    private:
        // A simple 2D array
        PieceData board[8][8];
        GameColor currentTurn;
        GameType currentGameType;
        std::vector<Move> playedMoves;
        bool isCheckersJumping;

        // Internal Setup
        void setupChess();
        void setupCheckers();
        void switchTurn();
    };
}