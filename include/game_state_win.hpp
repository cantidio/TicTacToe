#ifndef _GAME_STATE_WIN_
#define _GAME_STATE_WIN_
#include "game_state.hpp"
#include "game_board.hpp"

/**
 * Classe que representa o estado win do jogo
 *
 * @author	Cantidio oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GameStateWin : public GameState
{
	private:
		/**
		 * Valor do vencedor do jogo
		 */
		GameBoard::BoardValue mWinner;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const GameBoard::BoardValue& pWinner, vencedor da partida
		 */
		GameStateWin(const GameBoard::BoardValue& pWinner);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		~GameStateWin();
		/**
		 * Método que inicializa o estado
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void init();
		/**
		 * Método que executa um ciclo do estado
		 *
		 * @author	Cantidio oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	bool& pGameRunning, se o jogo está executando
		 * @return	bool
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

