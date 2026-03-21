#pragma once
#include "GameEngine.h"
#include <vector>

namespace game
{
    // Strategy design pattern: routes to the correct piece logic
    bool isValidChessMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);

    // Specific Piece Rules
    bool isValidPawnMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool isValidKnightMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool isValidBishopMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool isValidRookMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool isValidQueenMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool isValidKingMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);

    // State Checks
    bool isChessPromotion(int x, int y, const PieceData board[8][8]);
    bool isChessSquareAttacked(int targetX, int targetY, const PieceData board[8][8], GameColor attackerColor);

    // Checkers Logic
    bool isValidCheckersMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8]);
    bool jumpAvailable(int x, int y, const PieceData board[8][8]);
    bool isCheckersPromotion(int x, int y, const PieceData board[8][8]);
}