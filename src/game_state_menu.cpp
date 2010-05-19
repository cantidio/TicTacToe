#include "../include/game_state_menu.hpp"
#include "../include/game_state_option.hpp"
#include "../include/game_state_test.hpp"
#include "../include/game_state_game_single.hpp"

void GameStateMenu::init()
{
	printf("GameStateMenu init.\n");
	Gorgon::Video::get().clear();
	mOption			= 0;
	key[KEY_ENTER]	= 0;
}

GameStateMenu::~GameStateMenu()
{
	printf("GameStateMenu end.\n");
}

bool GameStateMenu::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	Gorgon::Video::get().drawText(" MENU"					,10,20,0xFFFFFF);
	Gorgon::Video::get().drawText(" PLAYER   VS   COMPUTER"	,10,40,0xFFFFFF);
	Gorgon::Video::get().drawText(" PLAYER   VS   PLAYER"	,10,50,0xFFFFFF);
	Gorgon::Video::get().drawText(" COMPUTER VS   COMPUTER"	,10,60,0xFFFFFF);
	Gorgon::Video::get().drawText(" OPTION"					,10,70,0xFFFFFF);
	Gorgon::Video::get().drawText(" QUIT"					,10,80,0xFFFFFF);
	Gorgon::Video::get().drawText(">"						,10,mOption*10+40,0xFFFFFF);
	Gorgon::Video::get().show();
	
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
				setNextState(new GameStateGame());
				break;
			case 1://pl vs pl
				setNextState(new GameStateTest());//GameStateGameVersus()
				break;
			case 2://pc vs pc
				setNextState(new GameStateTest());//GameStateGameWatch()
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

