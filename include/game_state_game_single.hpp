#ifndef _GAME_STATE_GAME_SINGLE_
#define _GAME_STATE_GAME_SINGLE_
#include "game_state_game.hpp"
#include <gorgon++/gorgon.hpp>

class GameStateGameSingle : public GameStateGame
{
	private:
		int mOption;
	public:
		~GameStateGameSingle();
		virtual void init();
		virtual bool run(bool& pGameRunning);
};
#endif

