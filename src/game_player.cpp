#include "../include/game_player.hpp"

GamePlayer::GamePlayer(const GameBoard::BoardValue& pPlayerValue)
{
	mPlayerValue	= pPlayerValue;
	mIsPlaying		= true;
}

void GamePlayer::play()
{
	GameBoard::get().setNextFreePosition(mPlayerValue, 0);
	setIsPlaying(false);
}

void GamePlayer::setIsPlaying(const bool& pIsPlaying)
{
	mIsPlaying = pIsPlaying;
}

bool GamePlayer::isPlaying() const
{
	return mIsPlaying;
}

