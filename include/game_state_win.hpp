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
		GameBoard::BoardValue mWinner;
	public:
		GameStateWin(const GameBoard::BoardValue& pWinner);
		~GameStateWin();
		virtual void init();
		virtual bool run(bool& pGameRunning);
};
#endif

