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
		long mFrameNumber;
		GameState* mNextState;
	public:
		GameState();
		virtual ~GameState(){}
		virtual void init(){}
		virtual bool run(bool& pGameRunning);
		virtual GameState* getNextState() const;
		void setNextState(GameState* pNextState);
		long getFrameNumber() const;
};
#endif

