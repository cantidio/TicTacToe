#include "../include/game_state_menu.hpp"
#include "../include/game_state_option.hpp"
#include "../include/game_state_test.hpp"
#include "../include/game_state_game_single.hpp"
#include "../include/game_state_game_versus.hpp"
#include "../include/game_state_game_watch.hpp"

void GameStateMenu::init()
{
	printf("GameStateMenu init.\n");
	mOption			= 0;
	key[KEY_ENTER]	= 0;
	mTicImg = Gorgon::Image(90,31);
	mTacImg = Gorgon::Image(90,31);
	mToeImg = Gorgon::Image(90,31);
	
	mTicImg.drawText(" ___  _  __ "		,-3,-7,0xFFFFFF);
	mTicImg.drawText("|_ _|| |/ _|"		,-3,03,0xFFFFFF);
	mTicImg.drawText(" | | | ( (_ "		,-3,13,0xFFFFFF);
	mTicImg.drawText(" |_| |_|\\__|"	,-3,23,0xFFFFFF);

	mTacImg.drawText(" ___  _   __ "	,-3,-7,0xFFFFFF);
	mTacImg.drawText("|_ _|/ \\ / _|"	,-3,03,0xFFFFFF);
	mTacImg.drawText(" | || o ( (_ "	,-3,13,0xFFFFFF);
	mTacImg.drawText(" |_||_n_|\\__|"	,-3,23,0xFFFFFF);

	mToeImg.drawText(" ___ _  ___ "		,-3,-7,0xFFFFFF);
	mToeImg.drawText("|_ _/ \\| __|"	,-3,03,0xFFFFFF);
	mToeImg.drawText(" | ( o ) _| "		,-3,13,0xFFFFFF);
	mToeImg.drawText(" |_|\\_/|___|"	,-3,23,0xFFFFFF);
	mAngle=0;
}

GameStateMenu::~GameStateMenu()
{
	printf("GameStateMenu end.\n");
}

bool GameStateMenu::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	Gorgon::Video::get().drawText(" MENU"					,10,80,0xFFFFFF);
	Gorgon::Video::get().drawText(" PLAYER   VS   COMPUTER"	,10,100,0xFFFFFF);
	Gorgon::Video::get().drawText(" PLAYER   VS   PLAYER"	,10,110,0xFFFFFF);
	Gorgon::Video::get().drawText(" COMPUTER VS   COMPUTER"	,10,120,0xFFFFFF);
	Gorgon::Video::get().drawText(" OPTION"					,10,130,0xFFFFFF);
	Gorgon::Video::get().drawText(" QUIT"					,10,140,0xFFFFFF);
	Gorgon::Video::get().drawText(">"						,10,mOption*10+100,0xFFFFFF);
	
	Gorgon::Video::get().drawImageRoteted(mTicImg,260,060,mAngle,45,15);
	Gorgon::Video::get().drawImageRoteted(mTacImg,260,120,mAngle,45,15);
	Gorgon::Video::get().drawImageRoteted(mToeImg,260,180,mAngle,45,15);
	Gorgon::Video::get().show();
	
	mAngle+=2;
	if(key[KEY_UP] && mOption > 0)
	{
		--mOption;
		key[KEY_UP] = 0;
	}
	else if(key[KEY_DOWN] && mOption < 4)
	{
		++mOption;
		key[KEY_DOWN] = 0;
	}
	
	if(key[KEY_ENTER])
	{
		switch(mOption)
		{
			case 0://pl vs pc
				setNextState(new GameStateGameSingle());//GameStateGameSingle()
				break;
			case 1://pl vs pl
				setNextState(new GameStateGameVersus());//GameStateGameVersus()
				break;
			case 2://pc vs pc
				setNextState(new GameStateGameWatch());//GameStateGameWatch()
				break;
			case 3://option
				setNextState(new GameStateOption());
				break;
			default://quit
				pGameRunning=false;
		}
		return false;
	}
	if(key[KEY_ESC])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

