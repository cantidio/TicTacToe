#ifndef _GAME_PLAYER_HUMAN_
#define _GAME_PLAYER_HUMAN_
#include "game_player.hpp"

/**
 * Classe que representa um jogador humano
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GamePlayerHuman : public GamePlayer
{
	protected:
		/**
		 * Posicao do cursor no tabuleiro
		 */
		Gorgon::Point mPosition;
	public:
		/**
		 * Método construtor do jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const GameBoard::BoardValue& pPlayerValue, valor do jogador no tabuleiro
		 */
		GamePlayerHuman(const GameBoard::BoardValue& pPlayerValue);
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GamePlayerHuman();
		/**
		 * Método que faz o jogador jogar
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void play();
		/**
		 * Método que desenha o jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void draw() const;
};
#endif

