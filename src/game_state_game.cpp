#include "../include/game_state_game.hpp"
#include "../include/game_state_win.hpp"
#include "../include/game_player_human.hpp"

GameStateGame::~GameStateGame()
{
	printf("GameStateGame end.\n");
}

void GameStateGame::init()
{
	printf("GameStateGame init.\n");
	GameBoard::get().reset();									//resetamos o tabuleiro
	mPlayer1		= new GamePlayerHuman(GameBoard::PLAYER1);	//criamos o jogador1, humano
	mPlayer2		= new GamePlayer(GameBoard::PLAYER2);		//criamos o jogador2, PC-BURRO
	mNowPlaying 	= mPlayer1;									//setamos o primeiro player a jogar, talvez randomizar isso
	key[KEY_ESC]	= 0;
	key[KEY_ENTER]	= 0;
}

bool GameStateGame::run(bool& pGameRunning)
{
	GameBoard::BoardValue boardScore = GameBoard::get().gameOver();
	
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	GameBoard::get().draw((120,100));
	mNowPlaying->draw((120,100));
	Gorgon::Video::get().show();
	
	if(boardScore != GameBoard::NONE)//alguém ganhou!
	{
		setNextState(new GameStateWin(boardScore));
		return false;
	}
	
	mNowPlaying->play();			//jogador da vez joga
	if(!mNowPlaying->isPlaying())	//se o turno do jogador estiver acabado, troca
	{
		mNowPlaying = (mNowPlaying == mPlayer1) ? mPlayer2 : mPlayer1;
		mNowPlaying->setIsPlaying(true);
	}
	
	if(key[KEY_ESC])
	{
		pGameRunning = false;
		return false;
	}
	return true;
}


