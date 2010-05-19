#ifndef _GAME_STATE_GAME_
#define _GAME_STATE_GAME_
#include "game_state.hpp"
#include "game_board.hpp"
#include "game_player.hpp"

/**
 * Classe que representa o estado de jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/05/2010
 * @version	19/05/2010
 */
class GameStateGame : public GameState
{
	private:
		/**
		 * Variável que guarda o jogador1 do jogo
		 */
		GamePlayer*	mPlayer1;
		/**
		 * Variável que guarda o jogador2 do jogo
		 */
		GamePlayer*	mPlayer2;
		/**
		 * Variável que guarda quem está jogando
		 */
		GamePlayer* mNowPlaying;
	public:
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		~GameStateGame();
		/**
		 * Método para setar a inicializaćão do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 */
		virtual void init();
		/**
		 * Método para rodar 1 ciclo do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 * @param	bool& pGameRunning, variável que fala se o jogo está rodando, pode ser alterada
		 */
		virtual bool run(bool& pGameRunning);
};
#endif

