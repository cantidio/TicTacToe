#include "../include/game_state_game.hpp"
#include "../include/game_state_win.hpp"

GameStateGame::GameStateGame()
{
	GameBoard::get().setLocation(Gorgon::Point(40,7));
	mFrameNumber2 = 0;
}

GameStateGame::~GameStateGame()
{
	delete mPlayer1;
	delete mPlayer2;
}

bool GameStateGame::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();			//limpa o vídeo
	GameBoard::get().draw();				//desenha o tabuleiro
	mNowPlaying->draw();					//desenha o jogador
	Gorgon::Video::get().show();			//mostra no vídeo
	
	switch(GameBoard::get().getBoardState())
	{
		case GameBoard::WIN:				//Alguém ganhou
		case GameBoard::DRAW:				//Deu empate
			setNextState(new GameStateWin(GameBoard::get().getWinner()));
			
			if(mFrameNumber2 > 60) return false;
			++mFrameNumber2;
			
			break;
		case GameBoard::PLAYING:			//Jogando
			mNowPlaying->play();			//jogador da vez joga
			if(!mNowPlaying->isPlaying())	//se o turno do jogador estiver acabado, troca
			{
				mNowPlaying = (mNowPlaying == mPlayer1) ? mPlayer2 : mPlayer1;
				mNowPlaying->setIsPlaying(true);
			}
	}
	if(key[KEY_ESC])
	{
		pGameRunning = false;
		return false;
	}
	return true;
}


