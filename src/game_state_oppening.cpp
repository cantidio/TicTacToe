#include "../include/game_state_oppening.hpp"
#include "../include/game_state_menu.hpp"

void GameStateOppening::init()
{
	printf("GameStateOppening init.\n");
	key[KEY_ENTER]	= 0;
	key[KEY_ESC]	= 0;
	mScrool 		= 320;	
	mTicImg 		= Gorgon::Image(420,158);
	mTacImg 		= Gorgon::Image(530,158);
	mToeImg 		= Gorgon::Image(520,158);
	
	int basePos=-10;
	mTicImg.drawText("TTTTTTTTTTTTTTTTTTTTTTTIIIIIIIIII      CCCCCCCCCCCCC"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("T:::::::::::::::::::::TI::::::::I   CCC::::::::::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("T:::::::::::::::::::::TI::::::::I CC:::::::::::::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("T:::::TT:::::::TT:::::TII::::::IIC:::::CCCCCCCC::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("TTTTTT  T:::::T  TTTTTT  I::::I C:::::C       CCCCCC"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::IC:::::C              "						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("        T:::::T          I::::I C:::::C       CCCCCC"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("      TT:::::::TT      II::::::IIC:::::CCCCCCCC::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("      T:::::::::T      I::::::::I CC:::::::::::::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("      T:::::::::T      I::::::::I   CCC::::::::::::C"						,0,basePos+=10,0xFFFFFF);
	mTicImg.drawText("      TTTTTTTTTTT      IIIIIIIIII      CCCCCCCCCCCCC"						,0,basePos+=10,0xFFFFFF);
	
	basePos=-10;
	mTacImg.drawText("TTTTTTTTTTTTTTTTTTTTTTT         AAA                  CCCCCCCCCCCCC"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("T:::::::::::::::::::::T        A:::A              CCC::::::::::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("T:::::::::::::::::::::T       A:::::A           CC:::::::::::::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("T:::::TT:::::::TT:::::T      A:::::::A         C:::::CCCCCCCC::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("TTTTTT  T:::::T  TTTTTT     A:::::::::A       C:::::C       CCCCCC"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T            A:::::A:::::A     C:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T           A:::::A A:::::A    C:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T          A:::::A   A:::::A   C:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T         A:::::A     A:::::A  C:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T        A:::::AAAAAAAAA:::::A C:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T       A:::::::::::::::::::::AC:::::C              "		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("        T:::::T      A:::::AAAAAAAAAAAAA:::::AC:::::C       CCCCCC"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("      TT:::::::TT   A:::::A             A:::::AC:::::CCCCCCCC::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("      T:::::::::T  A:::::A               A:::::ACC:::::::::::::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("      T:::::::::T A:::::A                 A:::::A CCC::::::::::::C"		,0,basePos+=10,0xFFFFFF);
	mTacImg.drawText("      TTTTTTTTTTTAAAAAAA                   AAAAAAA   CCCCCCCCCCCCC"		,0,basePos+=10,0xFFFFFF);
	
	basePos=-10;
	mToeImg.drawText("TTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     EEEEEEEEEEEEEEEEEEEEEE"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("T:::::::::::::::::::::T   OO:::::::::OO   E::::::::::::::::::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("T:::::::::::::::::::::T OO:::::::::::::OO E::::::::::::::::::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("T:::::TT:::::::TT:::::TO:::::::OOO:::::::OEE::::::EEEEEEEEE::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O  E:::::E       EEEEEE"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E:::::E             "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E::::::EEEEEEEEEE   "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E:::::::::::::::E   "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E:::::::::::::::E   "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E::::::EEEEEEEEEE   "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O:::::O     O:::::O  E:::::E             "			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("        T:::::T        O::::::O   O::::::O  E:::::E       EEEEEE"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("      TT:::::::TT      O:::::::OOO:::::::OEE::::::EEEEEEEE:::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("      T:::::::::T       OO:::::::::::::OO E::::::::::::::::::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("      T:::::::::T         OO:::::::::OO   E::::::::::::::::::::E"			,0,basePos+=10,0xFFFFFF);
	mToeImg.drawText("      TTTTTTTTTTT           OOOOOOOOO     EEEEEEEEEEEEEEEEEEEEEE"			,0,basePos+=10,0xFFFFFF);
  
}
GameStateOppening::~GameStateOppening()
{
	printf("GameStateOppening end.\n");
}

bool GameStateOppening::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	if(mScrool > -(mTicImg.getWidth() + mTacImg.getWidth() + mToeImg.getWidth() + 100) )
	{
		Gorgon::Video::get().drawImage(mTicImg,mScrool,40);
		Gorgon::Video::get().drawImage(mTacImg,mScrool + mTicImg.getWidth()+50,40);
		Gorgon::Video::get().drawImage(mToeImg,mScrool + mTicImg.getWidth() + mTacImg.getWidth()+100,40);
	}
	else
	{
		setNextState(new GameStateMenu());
		return false;
	}
	if(key[KEY_ENTER])
	{
		setNextState(new GameStateMenu());
		return false;
	}
	Gorgon::Video::get().show();
	mScrool-=6;
	if(key[KEY_ESC])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

