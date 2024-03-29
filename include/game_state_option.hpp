#ifndef _GAME_STATE_OPTION_
#define _GAME_STATE_OPTION_
#include "game_state.hpp"

/**
 * Classe que representa o estado de Općões do jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/05/2010
 * @version	18/05/2010
 */
class GameStateOption : public GameState
{
	private:
		/**
		 * Općão selecionada
		 */
		int mOption;
		/**
		 * AILevel selected
		 */
		int mAILevel;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		~GameStateOption();
		/**
		 * Método para iniciar os atributos do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		virtual void init();
		/**
		 * Método para executar 1 ciclo do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

