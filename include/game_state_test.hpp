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
		/**
		 * Imagem que será escrito teste
		 */
		Gorgon::Image mImg;
		/**
		 * Angulo da imagem
		 */
		int mAngle;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		~GameStateTest();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		virtual void init();
		/**
		 * Método que executa um ciclo do estado
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 * @param	bool& pGameRunning, se o jogo está executando
		 * @return	bool
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

