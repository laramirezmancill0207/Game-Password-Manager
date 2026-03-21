#include "GameEngine.h"
#include "moveRules.h"

namespace game
{
    GameEngine::GameEngine(GameType startingGame) {
        resetBoard(startingGame);
    }

    void GameEngine::resetBoard(GameType type) {
        currentGameType = type;
        currentTurn = WHITE;
        playedMoves.clear();
        isCheckersJumping = false;

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                board[x][y] = { EMPTY, NONE, false, false };
            }
        }

        if (type == CHESS) setupChess();
        else setupCheckers();
    }

    void GameEngine::setupChess() {
        for (int i = 0; i < 8; i++) {
            board[i][6] = { PAWN, WHITE, false, false };
            board[i][1] = { PAWN, BLACK, false, false };
        }
        board[0][7] = { ROOK, WHITE, false, false };   board[7][7] = { ROOK, WHITE, false, false };
        board[1][7] = { KNIGHT, WHITE, false, false }; board[6][7] = { KNIGHT, WHITE, false, false };
        board[2][7] = { BISHOP, WHITE, false, false }; board[5][7] = { BISHOP, WHITE, false, false };
        board[3][7] = { QUEEN, WHITE, false, false };  board[4][7] = { KING, WHITE, false, false };

        board[0][0] = { ROOK, BLACK, false, false };   board[7][0] = { ROOK, BLACK, false, false };
        board[1][0] = { KNIGHT, BLACK, false, false }; board[6][0] = { KNIGHT, BLACK, false, false };
        board[2][0] = { BISHOP, BLACK, false, false }; board[5][0] = { BISHOP, BLACK, false, false };
        board[3][0] = { QUEEN, BLACK, false, false };  board[4][0] = { KING, BLACK, false, false };
    }

    void GameEngine::setupCheckers() {
        for (int i = 0; i < 8; i++) {
            for (int j = (i % 2) ? 0 : 1; j < 8; j += 2) {
                if (i < 3) board[j][i] = { CHECKER, BLACK, false, false };
                else if (i > 4) board[j][i] = { CHECKER, WHITE, false, false };
            }
        }
    }

    bool GameEngine::attemptMove(int fromX, int fromY, int toX, int toY) {
        if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 ||
            toX < 0 || toX > 7 || toY < 0 || toY > 7) return false;

        PieceData movingPiece = board[fromX][fromY];

        if (movingPiece.type == EMPTY || movingPiece.color != currentTurn) return false;
        bool isValid = false;
        if (currentGameType == CHESS) {
            isValid = isValidChessMove(fromX, fromY, toX, toY, board);
        }
        else {
            isValid = isValidCheckersMove(fromX, fromY, toX, toY, board);
        }

        if (!isValid) return false;

        board[toX][toY] = movingPiece;
        board[toX][toY].hasMoved = true;
        board[fromX][fromY] = { EMPTY, NONE, false, false };

        playedMoves.push_back({ movingPiece.type, {fromX, fromY}, {toX, toY} });
        switchTurn();

        return true;
    }

    // The UI calls this to find out what squares to paint Red
    std::vector<coordinates> GameEngine::getValidMoves(int startX, int startY) {
        std::vector<coordinates> validMoves;
        PieceData p = board[startX][startY];

        if (p.type == EMPTY || p.color != currentTurn) return validMoves;

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                bool isValid = false;
                if (currentGameType == CHESS) isValid = isValidChessMove(startX, startY, x, y, board);
                else isValid = isValidCheckersMove(startX, startY, x, y, board);

                if (isValid) validMoves.push_back({ x, y });
            }
        }
        return validMoves;
    }

    void GameEngine::switchTurn() { currentTurn = (currentTurn == WHITE) ? BLACK : WHITE; }
    PieceData GameEngine::getPieceAt(int x, int y) const { return board[x][y]; }
    GameColor GameEngine::getTurn() const { return currentTurn; }
    GameType GameEngine::getGameType() const { return currentGameType; }
    std::vector<Move> GameEngine::getPlayedMoves() const { return playedMoves; }
}