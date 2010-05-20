#include "../include/game_state_game_versus.hpp"
#include "../include/game_player_human.hpp"

GameStateGameVersus::~GameStateGameVersus()
{
	printf("GameStateGameVersus end.\n");
}

void GameStateGameVersus::init()
{
	printf("GameStateGameVersus init.\n");
	GameBoard::get().reset();									//resetamos o tabuleiro
	mPlayer1		= new GamePlayerHuman(GameBoard::PLAYER1);	//criamos o jogador1, humano
	mPlayer2		= new GamePlayerHuman(GameBoard::PLAYER2);	//criamos o jogador2, humano
	mNowPlaying 	= mPlayer1;									//setamos o primeiro player a jogar
	key[KEY_ESC]	= 0;
	key[KEY_ENTER]	= 0;
}

