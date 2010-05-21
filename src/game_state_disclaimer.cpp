#include "../include/game_state_disclaimer.hpp"
#include "../include/game_state_oppening.hpp"

void GameStateDisclaimer::init()
{
	printf("GameStateDisclaimer init.\n");
	mScrool			= 320;
	key[KEY_ENTER]	= 0;
	
}

GameStateDisclaimer::~GameStateDisclaimer()
{
	printf("GameStateDisclaimer end.\n");
}

bool GameStateDisclaimer::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	
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
	
	Gorgon::Video::get().drawText("                                      _   _"																		,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("                                     | | | |                                               _     _"				,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText(" _ __   _____      _____ _ __ ___  __| | | |__  _   _    __ _  ___  _ __ __ _  ___  _ __ _| |_ _| |_ "			,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("| '_ \\ / _ \\ \\ /\\ / / _ \\ '__/ _ \\/ _` | | '_ \\| | | |  / _` |/ _ \\| '__/ _` |/ _ \\| '_ \\_   _|_   _|"	,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("| |_) | (_) \\ V  V /  __/ | |  __/ (_| | | |_) | |_| | | (_| | (_) | | | (_| | (_) | | | ||_|   |_|"			,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("| .__/ \\___/ \\_/\\_/ \\___|_|  \\___|\\__,_| |_.__/ \\__, |  \\__, |\\___/|_|  \\__, |\\___/|_| |_|"			,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("| |                                              __/ |   __/ |           __/ |                       "			,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().drawText("|_|                                             |___/   |___/           |___/                        "			,mScrool,basePos+=10,0xDDDDDD);
	Gorgon::Video::get().show();
	mScrool-=3;
	
	if(mScrool < -820 || key[KEY_ENTER])
	{
		setNextState(new GameStateOppening());
		return false;
	}
	else if(key[KEY_ESC])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

