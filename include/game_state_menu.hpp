#ifndef _GAME_STATE_MENU_
#define _GAME_STATE_MENU_
#include "game_state.hpp"
#include <gorgon++/gorgon.hpp>
/**
 * Classe que representa o estado do menu principal do jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GameStateMenu : public GameState
{
	private:
		int mOption;
	public:
		~GameStateMenu();
		virtual void init();
		virtual bool run(bool& pGameRunning);
};
#endif

