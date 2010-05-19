#ifndef _GAME_PLAYER_COMPUTER_
#define _GAME_PLAYER_COMPUTER_
#include "game_player.hpp"

/**
 * Classe que representa um jogador humano
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GamePlayerComputer : public GamePlayer
{
	private:
		int mCurrentDepth;
		int mMove;
	public:
		/**
		 * Método construtor do jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const GameBoard::BoardValue& pPlayerValue, valor do jogador no tabuleiro
		 */
		GamePlayerComputer(const GameBoard::BoardValue& pPlayerValue);
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GamePlayerComputer();
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
		 * @param	const Gorgon::Point& pPosition, posicão do tabuleiro
		 */
		virtual void draw(const Gorgon::Point& pPosition) const;
		/**
		 * Método que tende a máximizar a jogada do jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	GameBoard::GameValue pValue, valor do jogador
		 * @param	const int& movesToEnd, número de jogadas para terminar
		 * @return	int
		 */
		int max(GameBoard::BoardValue pPlayer,const int& movesToEnd);
		/**
		 * Método que tende a minimizar a jogada do inimigo do jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	GameBoard::GameValue pValue, valor do jogador
		 * @param	const int& movesToEnd, número de jogadas para terminar
		 * @return	int
		 */
		int min(GameBoard::BoardValue pPlayer,const int& movesToEnd);
};
#endif

