#ifndef _GAME_STATE_GAME_WATCH_
#define _GAME_STATE_GAME_WATCH_
#include "game_state_game.hpp"
#include <gorgon++/gorgon.hpp>

/**
 * Classe que representa o modo de jogo Versus
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GameStateGameWatch : public GameStateGame
{
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GameStateGameWatch();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void init();
};
#endif

