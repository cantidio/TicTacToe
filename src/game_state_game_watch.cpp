#include "../include/game_state_game_watch.hpp"
#include "../include/game_player_computer.hpp"

GameStateGameWatch::~GameStateGameWatch()
{
	printf("GameStateGameWatch end.\n");
}

void GameStateGameWatch::init()
{
	printf("GameStateGameWatch init.\n");
	GameBoard::get().reset();										//resetamos o tabuleiro
	mPlayer1		= new GamePlayerComputer(GameBoard::PLAYER1);	//criamos o jogador1, PC
	mPlayer2		= new GamePlayerComputer(GameBoard::PLAYER2);	//criamos o jogador2, PC
	mNowPlaying 	= mPlayer1;										//setamos o primeiro player a jogar
	key[KEY_ESC]	= 0;
	key[KEY_ENTER]	= 0;
}

