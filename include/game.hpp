#ifndef _GAME_
#define _GAME_
#include "game_state.hpp"

/**
 * Classe que representa o jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/05/2010
 * @version	21/05/2010
 */
class Game
{
	private:
		/**
		 * Estado atual do jogo
		 */
		GameState* mGameState;
		/**
		 * Se o jogo está rodando
		 */
		bool mGameRunning;
		/**
		 * Qual frame do jogo está
		 */
		long int mFrame;
	public:
		/**
		 * Método construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		Game();
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		virtual ~Game();
		/**
		 * Método que executa o jogo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	21/05/2010
		 */
		void run();
};
#endif

