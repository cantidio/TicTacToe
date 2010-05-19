#include "../include/game_player_computer.hpp"

GamePlayerComputer::GamePlayerComputer(const GameBoard::BoardValue& pPlayerValue) : GamePlayer(pPlayerValue){}
GamePlayerComputer::~GamePlayerComputer(){}

void GamePlayerComputer::play()
{
	mCurrentDepth = 0;
	int movesToEnd = GameBoard::get().getFreePositionNumber();
	max(mPlayerValue,movesToEnd);
	printf("Move: %d\n",mMove);
	GameBoard::get().setNextFreePosition(mPlayerValue, mMove);
	setIsPlaying(false);
}

void GamePlayerComputer::draw(const Gorgon::Point& pPosition) const
{
	Gorgon::Video::get().drawText("LOADING...",10,230,0xFFFFFF);
}

int GamePlayerComputer::max(GameBoard::BoardValue pPlayer,const int& movesToEnd)
{
	int aux, util = -999999;
	//int escape=0;

	if(movesToEnd == 0 /*|| mCurrentDepth >= DIFICULDADE*/)
	{
		return GameBoard::get().getUtil(pPlayer);
	}
	++mCurrentDepth;
	for(int i = 0; i < movesToEnd; ++i)
	{
		GameBoard::get().setNextFreePosition(pPlayer,i);
		aux = min((GameBoard::BoardValue)-pPlayer,movesToEnd - 1);
		GameBoard::get().undoLastMove();
		
		if(aux >= util)
		{
			util = aux;
			if(mCurrentDepth==1)
				mMove = i;
		}
    }
    --mCurrentDepth;
	return util;
}

int GamePlayerComputer::min(GameBoard::BoardValue pPlayer,const int& movesToEnd)
{
	int aux, util = 999999;

	if(movesToEnd == 0 /*|| mCurrentDepth >= DIFICULDADE*/)
	{
		return GameBoard::get().getUtil(pPlayer);
	}
	++mCurrentDepth;
	for(int i = 0; i < movesToEnd; ++i)
	{
		GameBoard::get().setNextFreePosition(pPlayer,i);
		aux = max((GameBoard::BoardValue)-pPlayer,movesToEnd-1);
		GameBoard::get().undoLastMove();
		if(aux <= util) util = aux;
	}
	--mCurrentDepth;
	return util;
}

