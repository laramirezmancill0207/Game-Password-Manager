#pragma once
#include "board.h"
#include <map>

const std::string password[]{ "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", "!@#$%^&*?-+" };

std::string generatePassword();

namespace chess
{
	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword);
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap();
}

namespace checkers
{
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap();
	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword);
}