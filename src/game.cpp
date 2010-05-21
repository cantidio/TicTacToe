#include "../include/game.hpp"
#include "../include/game_state_disclaimer.hpp"
int gFrameControler;
void game_time()
{
	++gFrameControler;
}END_OF_FUNCTION(game_time);

/*class Timer
{
	private:
		int mFps;
		Timer* mSingleton;
	public:
		Timer()
		{
			LOCK_VARIABLE(gFrameControler);//variável temporizador
			LOCK_FUNCTION(game_time);
			install_int_ex(game_time, BPS_TO_TIMER(mFps));
		}
};*/

Game::Game()
{
	printf("Game init.\n");
	
	LOCK_VARIABLE(gFrameControler);					//tranca variável temporizador
	LOCK_FUNCTION(game_time);						//tranca funćão temporizador
	install_int_ex(game_time, BPS_TO_TIMER(30));	//seta o jogo para 30 FPS
	
	mGameState		= new GameStateDisclaimer();	//seta o estado inicial do jogo
	mGameRunning	= true;							//jogo está rodando
	mFrame			= 0;							//seta o frame para 0
	mGameState->init();								//inicia o estado inicial do jogo
}

Game::~Game()
{
	printf("Game end.\n");
}

void Game::run()
{
	while(mGameRunning)
	{
		while(gFrameControler > 0)
		{
			if(!mGameState->run(mGameRunning))
			{
				GameState* aux = mGameState->getNextState();	//pega o próximo estado
				delete mGameState;								//deleta o estado atual
				if(aux)
				{
					mGameState = aux;							//atualiza
					mGameState->init();
				}
				else if(mGameRunning)							//se o estado mudar, e o próximo estado for inválido
				{												//e o jogo continuar executando, aborte-o
					printf("GameStateNULL.\n");
					printf("Force ShutDown.\n");
					mGameRunning = false;
					break;
				}
			}
			--gFrameControler;
			++mFrame;
		}
	}
	printf("Total number of frames: %ld\n",mFrame);
}

