#ifndef _GAME_STATE_DISCLAIMER_
#define _GAME_STATE_DISCLAIMER_
#include "game_state.hpp"
/**
 * Classe que representa o estado disclaimer do jogo
 *
 * @author	Cantidio oliveira Fontes
 * @since	18/05/2010
 * @version	20/05/2010
 */
class GameStateDisclaimer : public GameState
{
	private:
		/**
		 * variável que guarda a posicão do scrool no estado
		 */
		int mScrool;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		~GameStateDisclaimer();
		/**
		 * Método que inicializa os atributos da classe
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	20/05/2010
		 */
		virtual void init();
		/**
		 * Método que executa um ciclo do estado
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	18/05/2010
		 * @version	20/05/2010
		 * @param	bool& pGameRunning, se o estado está executando
		 * @return	bool
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

