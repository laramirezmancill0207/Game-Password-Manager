#include "gameHelper.h"

#include <random>;

const std::string password[] { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", "!@#$%^&*?-+"};

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

	std::string generatePassword()
	{
		std::string randomPass = "";

		//using random device
		//not cryptographically secure but it doesnt need to be because the passwords will be hashed using game passwords anyways

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution indx(0, 3);
		std::uniform_int_distribution<int> length(8, 14);

		for (int i = 0; i < length(mt); i++)
		{
			int range = indx(mt);
			std::uniform_int_distribution<int> indy(0, password[range].length());
			randomPass += password[range][indy(mt)];
		}

		return randomPass;
	}
}



namespace checkers
{

}