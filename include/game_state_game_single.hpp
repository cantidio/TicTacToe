#ifndef _GAME_STATE_GAME_SINGLE_
#define _GAME_STATE_GAME_SINGLE_
#include "game_state_game.hpp"
#include <gorgon++/gorgon.hpp>

/**
 * Classe que representa o modo de jogo Individual
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/05/2010
 * @version	19/05/2010
 */
class GameStateGameSingle : public GameStateGame
{
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GameStateGameSingle();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 */
		virtual void init();
};
#endif

