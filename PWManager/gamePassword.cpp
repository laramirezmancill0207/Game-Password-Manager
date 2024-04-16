#include "gamePassword.h"
#include <random>



namespace game
{
	std::string generatePassword()
	{
		std::string randomPass = "";

		//using random device
		//not cryptographically secure but it doesnt need to be because the passwords will be hashed using game passwords anyways

		std::random_device rd;
		std::mt19937 mt(rd());
		//int to choose from password array
		std::uniform_int_distribution indx(0, 3);
		//length of random password
		std::uniform_int_distribution<int> length(12, 16);

		for (int i = 0; i < length(mt); i++)
		{
			//get random characters for length of password
			int range = indx(mt);
			std::uniform_int_distribution<int> indy(0, password[range].length());
			randomPass += password[range][indy(mt)];
		}

		return randomPass;
	}

	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword)
	{
		std::string temp = "";

		//only allow password of 4 or more moves
		if (playedMoves.size() < 4)
		{
			return "";
		}

		std::string coords = "";

		int i = 0;
		//for all played moves
		for (auto& it : playedMoves)
		{
			pieceType type = it.getType();
			coordinates from = it.getFromCoord();
			coordinates to = it.getToCoord();

			//on 3rd move add random password as salt
			if (i == 3)
			{
				temp += gamePassword;
			}

			//add character to pw based on piece type
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
			case CHECKER:
				temp += "c";
				break;
			case CKING:
				temp += "ck";
			}

			//add from coordinate numbers to coords
			coords += std::to_string(from.x) + std::to_string(from.x);

			//add from and to coordinates to temp pass
			temp += std::to_string(from.x) + std::to_string(from.y) + std::to_string(to.x) + std::to_string(to.y);

			i++;
		}

		std::hash<std::string> h;

		//use hash of coords as seed for random
		srand(h(coords));

		std::string allChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*?-+";

		//randomize temp password using seeded rand()
		for (int j = 0; j < temp.length(); j++)
		{
			int r = rand() % allChars.length();

			temp[j] = allChars[r];
		}

		return temp;
	}

	std::map<GameColor, std::map<pieceType, QPixmap>> getPieceImageMap()
	{
		//load images
		QPixmap wp("images/chess/Chess_plt60.png");
		QPixmap wb("images/chess/Chess_blt60.png");
		QPixmap wkn("images/chess/Chess_nlt60.png");
		QPixmap wr("images/chess/Chess_rlt60.png");
		QPixmap wq("images/chess/Chess_qlt60.png");
		QPixmap wki("images/chess/Chess_klt60.png");

		QPixmap bp("images/chess/Chess_pdt60.png");
		QPixmap bb("images/chess/Chess_bdt60.png");
		QPixmap bkn("images/chess/Chess_ndt60.png");
		QPixmap br("images/chess/Chess_rdt60.png");
		QPixmap bq("images/chess/Chess_qdt60.png");
		QPixmap bki("images/chess/Chess_kdt60.png");

		QPixmap w("images/checkers/white");
		QPixmap wk("images/checkers/whiteking");

		QPixmap b("images/checkers/black");
		QPixmap bk("images/checkers/blackking");

		std::map<GameColor, std::map<pieceType, QPixmap>> pieceImageMap;

		//add images to map
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

		pieceImageMap[WHITE][CHECKER] = w;
		pieceImageMap[WHITE][CKING] = wk;

		pieceImageMap[BLACK][CHECKER] = b;
		pieceImageMap[BLACK][CKING] = bk;

		return pieceImageMap;
	}
}
