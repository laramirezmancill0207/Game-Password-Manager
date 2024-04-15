#include "gameHelper.h"
#include <random>

std::string generatePassword()
{
	std::string randomPass = "";

	//using random device
	//not cryptographically secure but it doesnt need to be because the passwords will be hashed using game passwords anyways

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution indx(0, 3);
	std::uniform_int_distribution<int> length(12, 16);

	for (int i = 0; i < length(mt); i++)
	{
		int range = indx(mt);
		std::uniform_int_distribution<int> indy(0, password[range].length());
		randomPass += password[range][indy(mt)];
	}

	return randomPass;
}

namespace chess
{
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap()
	{
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

		std::map<GameColor, std::map<pieceType, QPixmap>> pieceImageMap;

		pieceImageMap[WHITE][PAWN] = wp;
		pieceImageMap[WHITE][BISHOP] = wb;
		pieceImageMap[WHITE][KNIGHT] = wkn;
		pieceImageMap[WHITE][ROOK] = wr;
		pieceImageMap[WHITE][QUEEN] = wq;
		pieceImageMap[WHITE][KING] = wki;

		pieceImageMap[BLACK][PAWN] = bp;
		pieceImageMap[BLACK][BISHOP] = bb;
		pieceImageMap[BLACK][KNIGHT] = bkn;
		pieceImageMap[BLACK][ROOK] = br;
		pieceImageMap[BLACK][QUEEN] = bq;
		pieceImageMap[BLACK][KING] = bki;

		return pieceImageMap;
	}

	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword)
	{
		std::string temp = "";

		if (playedMoves.size() < 4)
		{
			return "";
		}

		std::string coords = "";

		int i = 0;
		for (auto& it : playedMoves)
		{
			pieceType type = it.getType();
			coordinates from = it.getFromCoord();
			coordinates to = it.getToCoord();

			if (i == 3)
			{
				temp += gamePassword;
			}

			switch (type) {
			case KING:
				temp += "K";
				break;
			case QUEEN:
				temp += "q";
				break;
			case ROOK:
				temp += "r";
				break;
			case BISHOP:
				temp += "b";
				break;
			case KNIGHT:
				temp += "k";
				break;
			case PAWN:
				temp += "p";
				break;
			}

			
			coords += std::to_string(from.x) + std::to_string(from.x);

			temp += std::to_string(from.x) + std::to_string(from.y) + std::to_string(to.x) + std::to_string(to.y);

			i++;
		}

		std::hash<std::string> h;

		srand(h(coords));

		std::string allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*?-+";

		for (int j = 0; j < temp.length(); j++)
		{
			int r = rand() % allChars.length();

			temp[j] = allChars[r];
		}

		return temp;
	}
}



namespace checkers
{
	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap()
	{
		QPixmap w("icons/chess/Chess_plt60.png");
		QPixmap wk("icons/chess/Chess_klt60.png");

		QPixmap b("icons/chess/Chess_pdt60.png");
		QPixmap bk("icons/chess/Chess_kdt60.png");

		std::map<GameColor, std::map<pieceType, QPixmap>> pieceImageMap;

		pieceImageMap[WHITE][NORMAL] = w;
		pieceImageMap[WHITE][KING] = wk;

		pieceImageMap[BLACK][NORMAL] = b;
		pieceImageMap[BLACK][KING] = bk;

		return pieceImageMap;
	}
}