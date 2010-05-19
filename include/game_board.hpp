#ifndef _GAME_BOARD_
#define _GAME_BOARD_
#include <gorgon++/gorgon.hpp>
/**
 * Classe que representa o tabuleiro do jogo
 *
 * @author	Cantidio Oliveira Fontes
 * @since	18/05/2010
 * @version	19/05/2010
 */
class GameBoard
{
	public:
		/**
		 * Possiveis valores aceitos no tabuleiro
		 */
		enum BoardValue
		{
			NONE	= 0,
			PLAYER1	= 1,
			PLAYER2	= -1
		};
	private:
		/**
		 * Método que alloca a matriz do tabuleiro interno
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 */
		void mallocInternalBoard();
	protected:
		/**
		 * Ponteiro para a única instancia da classe
		 */
		static GameBoard* mSingleton;
		/**
		 * matriz interna do tabuleiro
		 */
		BoardValue** mInternalBoard;
		/**
		 * tamanho do lado do tabuleiro
		 */
		int mSize;
		/**
		 * vetor que guarda todas as jogadas feitas no tabuleiro
		 */
		std::vector<Gorgon::Point> mMoves;
		/**
		 * Método construtor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		GameBoard();
		/**
		 * Método destrutor
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		virtual ~GameBoard();
	public:
		/**
		 * Método estático que retorna a instância da classe
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 * @return	GameBoard&
		 */
		static GameBoard& get();
		/**
		 * Método que retorna o tamanho do lado do tabuleiro
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @return	int
		 */
		int getSize() const;
		/**
		 * Método que reinicializa os valores do tabuleiro
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 */
		void reset();
		/**
		 * Método que retorna o valor de uma posicão especificada
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 * @param	const Gorgon::Point& pPosition, posicao a pegar o valor no tabuleiro
		 * @return	GameBoard::BoardValue&
		 */
		const GameBoard::BoardValue& getPosition(const Gorgon::Point& pPosition,bool debug=false) const;
		/**
		 * Método que retorna o número de posicões vazias no tabuleiro
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @return	int
		 */
		int getFreePositionNumber() const;
		/**
		 * Método para setar uma posicão no tabuleiro
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 * @param	const BoardValue&		pValue		, valor a inserir no tabuleiro
		 * @parma	const Gorgon::Point&	pPosition	, posicão a inserir o valor( Y = linha, X = coluna )
		 */
		void setPosition(const BoardValue& pValue, const Gorgon::Point& pPosition);
		/**
		 * Método para setar um valor na posicão no tabuleiro livre, dado um escape
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	const BoardValue&		pValue	, valor a inserir no tabuleiro
		 * @parma	int&					pEscape	, quantas posićões vazias vai saltar
		 */
		void setNextFreePosition(const GameBoard::BoardValue& pValue, int pEscape);
		/**
		 * Método que desfaz a última jogada realizada no tabuleiro
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		void undoLastMove();
		/**
		 * Método que retorna se o jogo acabou
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	18/05/2010
		 */
		GameBoard::BoardValue gameOver() const;
		/**
		 * Método que desenha o tabuleiro e suas pecas
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	18/05/2010
		 * @version	19/05/2010
		 * @param	const Gorgon::Point& pPosition, posicão a desenhar o tabuleiro
		 */
		void draw(const Gorgon::Point& pPosition) const;
		/**
		 * Método para retornar a utilidade do tabuleiro para determinado jogador
		 *
		 * @author	Cantidio Oliveira Fontes
		 * @since	19/05/2010
		 * @version	19/05/2010
		 * @param	GameBoard::BoardValue& pPlayer, jogador que será analisada a utilidade
		 * @return	int
		 */
		int getUtil(GameBoard::BoardValue& pPlayer) const;
};
#endif
