#include "../include/game_state_game_single.hpp"
#include "../include/game_player_human.hpp"
#include "../include/game_player_computer.hpp"

GameStateGameSingle::~GameStateGameSingle()
{
	printf("GameStateGameSingle end.\n");
}

void GameStateGameSingle::init()
{
	printf("GameStateGameSingle init.\n");
	GameBoard::get().reset();										//resetamos o tabuleiro
	mPlayer1		= new GamePlayerHuman(GameBoard::PLAYER1);		//criamos o jogador1, humano
	mPlayer2		= new GamePlayerComputer(GameBoard::PLAYER2);	//criamos o jogador2, PC-MINMAX
	mNowPlaying 	= mPlayer1;										//setamos o primeiro player a jogar, talvez randomizar isso
	key[KEY_ESC]	= 0;
	key[KEY_ENTER]	= 0;
}

