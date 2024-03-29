#include "../include/game_player_human.hpp"

GamePlayerHuman::GamePlayerHuman(const GameBoard::BoardValue& pPlayerValue) : GamePlayer(pPlayerValue){}
GamePlayerHuman::~GamePlayerHuman(){}

void GamePlayerHuman::play()
{
	if(key[KEY_RIGHT] && mPosition.getX() < GameBoard::get().getSize() - 1)
	{
		mPosition.addX(1);
		key[KEY_RIGHT] = 0;
	}
	else if(key[KEY_LEFT] && mPosition.getX() > 0)
	{
		mPosition.subX(1);
		key[KEY_LEFT] = 0;
	}
	if(key[KEY_DOWN] && mPosition.getY() < GameBoard::get().getSize() - 1)
	{
		mPosition.addY(1);
		key[KEY_DOWN] = 0;	
	}
	else if(key[KEY_UP] && mPosition.getY() > 0)
	{
		mPosition.subY(1);
		key[KEY_UP] = 0;
	}
	
	if(key[KEY_ENTER])
	{
		if(GameBoard::get().getPosition(mPosition) == GameBoard::NONE)
		{
			GameBoard::get().setPosition(mPlayerValue, mPosition);
			setIsPlaying(false);
		}
		else
		{
			printf("posicão inválida!\n");
		}
		key[KEY_ENTER] = 0;
	}
}

void GamePlayerHuman::draw() const
{
	Gorgon::Video::get().drawRectangle
	(
		GameBoard::get().getLocation() + Gorgon::Point(-1,8) + Gorgon::Point(mPosition.getX()*80, mPosition.getY()*70) ,
		Gorgon::Rectangle(80,70),
		0xFF0000
	);
}

