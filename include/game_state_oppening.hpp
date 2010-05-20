#ifndef _GAME_STATE_OPPENING_
#define _GAME_STATE_OPPENING_
#include "game_state.hpp"
#include <gorgon++/gorgon.hpp>
/**
 * Classe que representa o estado de abertura do jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GameStateOppening : public GameState
{
	private:
		/**
		 * Scrool
		 */
		int mScrool;
		/**
		 * Imagem do Tic
		 */
		Gorgon::Image mTicImg;
		/**
		 * Imagem do Tac
		 */
		Gorgon::Image mTacImg;
		/**
		 * Imagem do Toe
		 */
		Gorgon::Image mToeImg;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/08/2010
		 * @version	19/08/2010
		 */
		~GameStateOppening();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/08/2010
		 * @version	19/08/2010
		 */
		virtual void init();
		/**
		 * Método que executa um 1 ciclo do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/08/2010
		 * @version	19/08/2010
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

