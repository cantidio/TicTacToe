#include "../include/game_state_win.hpp"
#include "../include/game_state_menu.hpp"

GameStateWin::GameStateWin(const GameBoard::BoardValue& pWinner)
{
	mWinner = pWinner;
}

void GameStateWin::init()
{
	printf("GameStateWin init.\n");
	Gorgon::Video::get().clear();
	int basePos = 60;
	if(mWinner != GameBoard::NONE)
	{
		Gorgon::Video::get().drawText("WIN",160-7,30,0xFFFFFF);
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
		Gorgon::Video::get().drawText("DRAW  GAME",160-37,30,0xFFFFFF);
	}
	
	Gorgon::Video::get().drawText(" PRESS ENTER TO RETURN TO MENU",10,basePos+=50,0xFFFFFF);
	Gorgon::Video::get().show();
}

GameStateWin::~GameStateWin()
{
	printf("GameStateWin end.\n");
}

bool GameStateWin::run(bool& pGameRunning)
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

