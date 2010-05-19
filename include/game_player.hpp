#ifndef _GAME_PLAYER_
#define _GAME_PLAYER_
#include "game_board.hpp"

/**
 * Classe que representa um jogador
 *
 * @author	Cantidio Oliveira Fontes
 * @since	19/05/2010
 * @version	19/05/2010
 */
class GamePlayer
{
	protected:
		/**
		 * valor do personagem no tabuleiro
		 */
		GameBoard::BoardValue mPlayerValue;
		/**
		 * se o personagem está jogando
		 */
		bool mIsPlaying;
	public:
		/**
		 * Método Construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const GameBoard::BoardValue& pPlayerValue, valor do personagem no tabuleiro
		 */
		GamePlayer(const GameBoard::BoardValue& pPlayerValue);
		/**
		 * Método Destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual ~GamePlayer(){}
		/**
		 * Método chamado a cada iteracão com o personagem para que o mesmo jogue
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 */
		virtual void play();
		/**
		 * Método para setar se o jogador está jogando no momento
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const bool& pIsPlaying, se o jogador está jogando
		 */
		void setIsPlaying(const bool& pIsPlaying);
		/**
		 * Método que retorna se o jogador está jogando
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @return	bool
		 */
		bool isPlaying() const;
		/**
		 * Método que desenha o jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const Gorgon::Point& pPosition, a posicão do tabuleiro
		 */
		virtual void draw(const Gorgon::Point& pPosition) const {}
};
#endif

