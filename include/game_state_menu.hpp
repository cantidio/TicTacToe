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
		/**
		 * Opcão do menu
		 */
		int mOption;
		/**
		 * Angulo dos logos do menu
		 */
		int mAngle;
		/**
		 * Imagem logo do Tic
		 */
		Gorgon::Image mTicImg;
		/**
		 * Imagem logo do Tac
		 */
		Gorgon::Image mTacImg;
		/**
		 * Imagem logo do Toe
		 */
		Gorgon::Image mToeImg;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		~GameStateMenu();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void init();
		/**
		 * Método que executa 1 passo no estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	bool& pGameRunning, se o jogo está rodando
		 * @return	bool
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

