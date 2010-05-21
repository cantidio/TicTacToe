#ifndef _GAME_STATE_
#define _GAME_STATE_
#include <gorgon++/gorgon.hpp>

/**
 * Classe que representa um estado do jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/08/2010
 * @version	19/08/2010
 */
class GameState
{
	private:
		/**
		 * Número de frames que já passaram pelo estado
		 */
		long mFrameNumber;
		/**
		 * Ponteiro para o próximo estado
		 */
		GameState* mNextState;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	18/08/2010
		 */
		GameState();
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	18/08/2010
		 */
		virtual ~GameState(){}
		/**
		 * Método que inicializa os atributos do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	18/08/2010
		 */
		virtual void init(){}
		/**
		 * Método que executa um ciclo do estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	19/08/2010
		 * @param	bool& pGameRunning, se o jogo está executando
		 * @return	bool
		 */
		virtual bool run(bool& pGameRunning);
		/**
		 * Método que retorna o ponteiro para o próximo estado do jogo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	19/08/2010
		 * @return	GameState*
		 */
		virtual GameState* getNextState() const;
		/**
		 * Método para setar o próximo estado do jogo
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	19/08/2010
		 * @param	GameState* pNextState, ponteiro para o próximo estado
		 */
		void setNextState(GameState* pNextState);
		/**
		 * Método que retorna o número de frames/ciclos que já foram executados no estado
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/08/2010
		 * @version	19/08/2010
		 * @return	long
		 */
		long getFrameNumber() const;
};
#endif

