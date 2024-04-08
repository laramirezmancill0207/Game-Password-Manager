#pragma once
#include "board.h"
#include <map>


namespace chess
{
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap();
}

namespace checkers
{

}