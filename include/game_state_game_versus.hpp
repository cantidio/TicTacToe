#ifndef _GAME_STATE_GAME_VERSUS_
#define _GAME_STATE_GAME_VERSUS_
#include "game_state_game.hpp"
#include <gorgon++/gorgon.hpp>

/**
 * Classe que representa o modo de jogo Versus
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GameStateGameVersus : public GameStateGame
{
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GameStateGameVersus();
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

