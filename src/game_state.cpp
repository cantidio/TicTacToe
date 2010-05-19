#include "../include/game_state.hpp"

GameState::GameState()
{
	mNextState	= 0;
	mFrameNumber= 0;
	mNextState	= 0;
}

void GameState::setNextState(GameState* pNextState)
{
	mNextState = pNextState;
}

GameState* GameState::getNextState() const
{
	return mNextState;
}

bool GameState::run(bool& pGameRunning)
{
	++mFrameNumber;
}

long GameState::getFrameNumber() const
{
	return mFrameNumber;
}
