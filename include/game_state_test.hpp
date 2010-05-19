#ifndef _GAME_STATE_TEST_
#define _GAME_STATE_TEST_
#include "game_state.hpp"
/**
 * Classe que representa o estado de teste do jogo
 *
 * @author	Cantidio oliveira Fontes
 * @since	18/05/2010
 * @version	18/05/2010
 */
class GameStateTest : public GameState
{
	private:
		Gorgon::Image mImg;
		int mAngle;
	public:
		~GameStateTest();
		virtual void init();
		virtual bool run(bool& pGameRunning);
};
#endif

