#pragma once
#include "board.h"
#include <map>

const std::string password[]{ "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", "!@#$%^&*?-+" };

namespace game
{
	//generate randomized password between 12 and 16 characters
	std::string generatePassword();

	//generate a unique hash corresponding to playedMoves in a game and user randomized gamePassword
	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword);

	/*
	* creates a map of the images used in the game to draw pieces
	* returns a map of QPixmap images corresponding to map[GameColor][pieceType]
	*/
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap();
}