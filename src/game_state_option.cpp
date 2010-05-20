#include "../include/game_state_option.hpp"
#include "../include/game_state_menu.hpp"

const char* AILevels[] =
{
	"PIECE OF CAKE"	,
	"ULTRA EASY"	,
	"VERY EASY"		,
	"EASY"			,
	"NORMAL"		,
	"HARD"			,
	"VERY HARD"		,
	"ULTRA HARD"	,
	"IMPOSSIBLE"	,
};

void GameStateOption::init()
{
	printf("GameStateOption init.\n");
	Gorgon::Video::get().clear();
	mOption			= 0;
	mAILevel		= 3;
	key[KEY_ENTER]	= 0;
}

GameStateOption::~GameStateOption()
{
	printf("GameStateOption end.\n");
}

bool GameStateOption::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	
	Gorgon::Video::get().drawText(" OPTIONS",10,80,0xFFFFFF);
	
	Gorgon::Video::get().drawText(" AI LEVEL: "			,010,100,0xFFFFFF);
	Gorgon::Video::get().drawText(AILevels[mAILevel]	,100,100,0xFFFFFF);
	Gorgon::Video::get().drawText(" BACK"				,010,110,0xFFFFFF);
	Gorgon::Video::get().drawText(">"					,010,mOption*10+100,0xFFFFFF);
	
	Gorgon::Video::get().show();
	
	
	if(key[KEY_UP] && mOption > 0)
	{
		--mOption;
		key[KEY_UP] = 0;
	}
	else if(key[KEY_DOWN] && mOption < 1)
	{
		++mOption;
		key[KEY_DOWN] = 0;
	}
	
	switch(mOption)
	{
		case 0:
			if(key[KEY_LEFT] && mAILevel > 0)
			{
				--mAILevel;
				key[KEY_LEFT] = 0;
			}
			else if(key[KEY_RIGHT] && mAILevel < 8)
			{
				++mAILevel;
				key[KEY_RIGHT] = 0;
			}
			break;
		default://back
			if(key[KEY_ENTER])
			{
				setNextState(new GameStateMenu());
				return false;
			}
			break;
	}
	
	if(key[KEY_ESC])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

