#include "moveRules.h"
#include <cmath>
#include <algorithm>
#include <utility>

namespace game
{
    // CHESS LOGIC

    bool isValidChessMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        PieceData fromPiece = board[fromX][fromY];

        switch (fromPiece.type) {
        case KING:   return isValidKingMove(fromX, fromY, toX, toY, board);
        case QUEEN:  return isValidQueenMove(fromX, fromY, toX, toY, board);
        case ROOK:   return isValidRookMove(fromX, fromY, toX, toY, board);
        case BISHOP: return isValidBishopMove(fromX, fromY, toX, toY, board);
        case KNIGHT: return isValidKnightMove(fromX, fromY, toX, toY, board);
        case PAWN:   return isValidPawnMove(fromX, fromY, toX, toY, board);
        default:     return false;
        }
    }

    bool isValidPawnMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        GameColor col = board[fromX][fromY].color;
        int direction = (col == WHITE) ? -1 : 1;

        // Normal forward movement
        if (board[toX][toY].type == EMPTY) {
            if (fromX == toX && (toY - fromY == direction)) return true;

            // 2 squares forward on first move
            if (!board[fromX][fromY].hasMoved && fromX == toX && (toY - fromY == direction * 2)) {
                if (board[fromX][fromY + direction].type == EMPTY) {
                    return true;
                }
            }
        }
        // Attacking diagonally
        else if (board[toX][toY].color != col && board[toX][toY].type != EMPTY) {
            if (toY - fromY == direction && std::abs(toX - fromX) == 1) {
                return true;
            }
        }
        return false;
    }

    bool isValidKnightMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        if ((std::abs(toY - fromY) == 2 && std::abs(toX - fromX) == 1) ||
            (std::abs(toY - fromY) == 1 && std::abs(toX - fromX) == 2)) {

            if (board[toX][toY].type == EMPTY || board[toX][toY].color != board[fromX][fromY].color) {
                return true;
            }
        }
        return false;
    }

    bool isValidBishopMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        if (std::abs(toX - fromX) == std::abs(toY - fromY)) {
            int stepX = (toX > fromX) ? 1 : -1;
            int stepY = (toY > fromY) ? 1 : -1;

            int currX = fromX + stepX;
            int currY = fromY + stepY;

            while (currX != toX && currY != toY) {
                if (board[currX][currY].type != EMPTY) return false;
                currX += stepX;
                currY += stepY;
            }

            if (board[toX][toY].type == EMPTY || board[toX][toY].color != board[fromX][fromY].color) {
                return true;
            }
        }
        return false;
    }

    bool isValidRookMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        if (toX == fromX || toY == fromY) {
            int stepX = (toX == fromX) ? 0 : ((toX > fromX) ? 1 : -1);
            int stepY = (toY == fromY) ? 0 : ((toY > fromY) ? 1 : -1);

            int currX = fromX + stepX;
            int currY = fromY + stepY;

            while (currX != toX || currY != toY) {
                if (board[currX][currY].type != EMPTY) return false;
                currX += stepX;
                currY += stepY;
            }

            if (board[toX][toY].type == EMPTY || board[toX][toY].color != board[fromX][fromY].color) {
                return true;
            }
        }
        return false;
    }

    bool isValidQueenMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        return isValidBishopMove(fromX, fromY, toX, toY, board) ||
            isValidRookMove(fromX, fromY, toX, toY, board);
    }

    bool isValidKingMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        if (std::abs(toX - fromX) <= 1 && std::abs(toY - fromY) <= 1) {
            if (board[toX][toY].type == EMPTY || board[toX][toY].color != board[fromX][fromY].color) {
                return true;
            }
        }
        return false;
    }

    bool isChessPromotion(int x, int y, const PieceData board[8][8])
    {
        return board[x][y].type == PAWN && (y == 0 || y == 7);
    }

    // CHECKERS LOGIC

    bool isValidCheckersMove(int fromX, int fromY, int toX, int toY, const PieceData board[8][8])
    {
        PieceData piece = board[fromX][fromY];

        // Target square must always be empty in Checkers
        if (board[toX][toY].type != EMPTY) return false;

        int dx = std::abs(toX - fromX);
        int dy = toY - fromY;
        int absDy = std::abs(dy);

        // White moves UP (-1), Black moves DOWN (+1)
        int forwardDir = (piece.color == WHITE) ? -1 : 1;

        if (piece.type == CHECKER) {
            // Normal 1-square diagonal move
            if (!piece.isJumping && dx == 1 && dy == forwardDir) {
                return true;
            }
            // 2-square Jump Move
            if (dx == 2 && dy == forwardDir * 2) {
                int midX = (fromX + toX) / 2;
                int midY = (fromY + toY) / 2;
                PieceData midPiece = board[midX][midY];

                // Can only jump over opponent pieces
                if (midPiece.type != EMPTY && midPiece.color != piece.color) {
                    return true;
                }
            }
        }
        else if (piece.type == CKING) {
            // Kings can move diagonally in ANY direction
            if (!piece.isJumping && dx == 1 && absDy == 1) {
                return true;
            }
            // Kings jump in ANY direction
            if (dx == 2 && absDy == 2) {
                int midX = (fromX + toX) / 2;
                int midY = (fromY + toY) / 2;
                PieceData midPiece = board[midX][midY];

                if (midPiece.type != EMPTY && midPiece.color != piece.color) {
                    return true;
                }
            }
        }
        return false;
    }

    bool jumpAvailable(int x, int y, const PieceData board[8][8])
    {
        PieceData p = board[x][y];
        if (p.type == EMPTY) return false;

        int forwardDir = (p.color == WHITE) ? -1 : 1;
        std::vector<std::pair<int, int>> directions;

        // Standard checkers only jump forward. Kings jump all 4 ways.
        if (p.type == CHECKER) {
            directions = { {1, forwardDir}, {-1, forwardDir} };
        }
        else if (p.type == CKING) {
            directions = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
        }

        for (auto dir : directions) {
            int midX = x + dir.first;
            int midY = y + dir.second;
            int landX = x + dir.first * 2;
            int landY = y + dir.second * 2;

            // Strict bounds checking before reading the array
            if (landX >= 0 && landX <= 7 && landY >= 0 && landY <= 7) {
                PieceData midPiece = board[midX][midY];
                PieceData landPiece = board[landX][landY];

                if (midPiece.type != EMPTY && midPiece.color != p.color && landPiece.type == EMPTY) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCheckersPromotion(int x, int y, const PieceData board[8][8])
    {
        PieceData p = board[x][y];
        if (p.type == CHECKER) {
            if (p.color == WHITE && y == 0) return true;
            if (p.color == BLACK && y == 7) return true;
        }
        return false;
    }
}