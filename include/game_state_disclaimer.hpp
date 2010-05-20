#ifndef _GAME_STATE_DISCLAIMER_
#define _GAME_STATE_DISCLAIMER_
#include "game_state.hpp"
/**
 * Classe que representa o estado disclaimer do jogo
 *
 * @author	Cantidio oliveira Fontes
 * @since	18/05/2010
 * @version	18/05/2010
 */
class GameStateDisclaimer : public GameState
{
	private:
		int mScrool;
	public:
		~GameStateDisclaimer();
		virtual void init();
		virtual bool run(bool& pGameRunning);
};
#endif

