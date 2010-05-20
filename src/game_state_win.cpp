#include "../include/game_state_win.hpp"
#include "../include/game_state_menu.hpp"

GameStateWin::GameStateWin(const GameBoard::BoardValue& pWinner)
{
	mWinner = pWinner;
}

void GameStateWin::init()
{
	printf("GameStateWin init.\n");
	int basePos		= 60;
	key[KEY_ENTER]	= 0;
	
	Gorgon::Video::get().clear();
	
	if(mWinner != GameBoard::NONE)
	{
		Gorgon::Video::get().drawText("WIN",150,30,0xFFFFFF);
		Gorgon::Video::get().drawText(" KNOCKOUT!!",10,basePos+=10,0xFFFFFF);

		if(mWinner == GameBoard::PLAYER1)
		{
			Gorgon::Video::get().drawText(" PLAYER1 WINS!",10,basePos+=10,0xFFFFFF);
		}
		else
		{
			Gorgon::Video::get().drawText(" PLAYER2 WINS!",10,basePos+=10,0xFFFFFF);
		}
	}
	else
	{
		Gorgon::Video::get().drawText("DRAW  GAME",120,30,0xFFFFFF);
		basePos+=20;
	}
	
	Gorgon::Video::get().drawText(" PRESS ENTER TO RETURN TO MENU",10,basePos+=80,0xFFFFFF);
	Gorgon::Video::get().show();
}

GameStateWin::~GameStateWin()
{
	printf("GameStateWin end.\n");
}

bool GameStateWin::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	
	if(key[KEY_ENTER])
	{
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

