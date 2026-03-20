#include "gamePassword.h"
#include <random>
#include <openssl/sha.h>
#include <QByteArray>
#include <QString>

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
			std::uniform_int_distribution<int> indy(0, password[range].length()-1);
			randomPass += password[range][indy(mt)];
		}

		return randomPass;
	}

	std::string moveHashFuction(std::vector<Move> playedMoves, std::string gamePassword)
	{
		// Only allow password of 4 or more moves
		if (playedMoves.size() < 4) {
			return "";
		}

		std::string rawState = "";
		int i = 0;

		// Build the raw state string from the board
		for (auto& it : playedMoves)
		{
			pieceType type = it.getType();
			coordinates from = it.getFromCoord();
			coordinates to = it.getToCoord();

			// Add piece identifier
			switch (type) {
			case KING:    rawState += "K"; break;
			case QUEEN:   rawState += "q"; break;
			case ROOK:    rawState += "r"; break;
			case BISHOP:  rawState += "b"; break;
			case KNIGHT:  rawState += "k"; break;
			case PAWN:    rawState += "p"; break;
			case CHECKER: rawState += "c"; break;
			case CKING:   rawState += "ck"; break;
			}

			// Add coordinates
			rawState += std::to_string(from.x) + std::to_string(from.y) + std::to_string(to.x) + std::to_string(to.y);

			// On 3rd move add the system generated game password as salt
			if (i == 3) {
				rawState += gamePassword;
			}
			i++;
		}

		// Hash the raw state using SHA-256
		unsigned char hash[SHA256_DIGEST_LENGTH];
		SHA256(reinterpret_cast<const unsigned char*>(rawState.c_str()), rawState.length(), hash);

		// Convert the binary hash to a readable Hex string or Base64
		QByteArray qba(reinterpret_cast<const char*>(hash), SHA256_DIGEST_LENGTH);
		return qba.toBase64().toStdString();
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
