#include "../include/game_state_disclaimer.hpp"
#include "../include/game_state_menu.hpp"

void GameStateDisclaimer::init()
{
	printf("GameStateDisclaimer init.\n");
	Gorgon::Video::get().clear();
	Gorgon::Video::get().drawText("DISCLAIMER",160-39,30,0xFFFFFF);
	int basePos=60;
	Gorgon::Video::get().drawText("  THIS IS A TEST MADE WITH GORGON++  "	,10,basePos+=10,0xFFFFFF);
	Gorgon::Video::get().drawText("  THIS GAME IS FREE AND OPENSOURCE   "	,10,basePos+=10,0xFFFFFF);
	Gorgon::Video::get().drawText("IF YOU PAID FOR THIS YOU WERE FOOLED."	,10,basePos+=10,0xFFFFFF);
	Gorgon::Video::get().drawText(" ANY COMMENT, SUGESTION OR GREETINGS:"	,10,basePos+=20,0xFFFFFF);
	Gorgon::Video::get().drawText("     ANIQUILATORBLOODY@GMAIL.COM     "	,10,basePos+=20,0xFFFFFF);
	Gorgon::Video::get().drawText("       HTTP://GORGONSGATE.COM        "	,10,basePos+=10,0xFFFFFF);
	Gorgon::Video::get().drawText("             THANKS. =)              "	,10,basePos+=10,0xFFFFFF);
	Gorgon::Video::get().show();
}
GameStateDisclaimer::~GameStateDisclaimer()
{
	printf("GameStateDisclaimer end.\n");
}

bool GameStateDisclaimer::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	
	if(getFrameNumber() == 180 || key[KEY_ENTER])
	{
		key[KEY_ENTER] = 0;
		setNextState(new GameStateMenu());
		return false;
	}
	else if(key[KEY_ESC])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

