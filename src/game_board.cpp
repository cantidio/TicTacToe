#include "../include/game_board.hpp"
GameBoard* GameBoard::mSingleton = 0;

void GameBoard::mallocInternalBoard()
{

	mInternalBoard = (GameBoard::BoardValue **) malloc (sizeof(GameBoard::BoardValue*) * mSize);
	for(int i = 0; i < mSize; ++i)
	{
		mInternalBoard[i] = (GameBoard::BoardValue *)malloc(sizeof(GameBoard::BoardValue) * mSize);
	}
	//reset();
}

GameBoard::GameBoard()
{
	mSize = 3;
	mallocInternalBoard();
}

GameBoard::~GameBoard()
{
}

GameBoard& GameBoard::get()
{
	if(!GameBoard::mSingleton)
	{
		GameBoard::mSingleton = new GameBoard();
	}
	return *GameBoard::mSingleton;
}

int GameBoard::getSize() const
{
	return mSize;
}

void GameBoard::reset()
{
	int width,height;
	for(height = mSize - 1; height >= 0; --height)
	{
		for(width = mSize - 1; width >= 0; --width)
		{
			mInternalBoard[height][width] = GameBoard::NONE;
		}
	}
	mMoves.empty();
}

void GameBoard::setPosition(const BoardValue& pValue, const Gorgon::Point& pPosition)
{
	if(pPosition.getX() < mSize && pPosition.getY() < mSize)
	{
		mInternalBoard[(int)pPosition.getY()][(int)pPosition.getX()] = pValue;
		if(pValue!=GameBoard::NONE)
			mMoves.push_back(pPosition);
	}
}

const GameBoard::BoardValue& GameBoard::getPosition(const Gorgon::Point& pPosition,bool debug) const
{
//	if(pPosition.getX() < mSize && pPosition.getY() < mSize)
//	{
		if(debug)
		{
			printf("getPosition: linha: %d, coluna: %d value: %d\n",(int)pPosition.getY(),(int)pPosition.getX(),getPosition(pPosition));
		}
		return mInternalBoard[(int)pPosition.getY()][(int)pPosition.getX()];
//	}
}
int GameBoard::getFreePositionNumber() const
{
	Gorgon::Point pos;
	int free=0;
    for(pos.setY(0); pos.getY() < mSize; pos.addY(1))
    {
        for(pos.setX(0); pos.getX() < mSize; pos.addX(1))
        {
            if(getPosition(pos) == GameBoard::NONE)
            {
				++free;
	        }
        }
    }
    return free;
}

void GameBoard::undoLastMove()
{
	const int moveNumber = mMoves.size();
	if(moveNumber > 0)
	{
		const Gorgon::Point lastMove = mMoves[moveNumber - 1];
		mMoves.pop_back();
		//printf("tira do tabuleiro: %d %d\n",(int)lastMove.getY(),(int)lastMove.getX());
		setPosition(GameBoard::NONE, lastMove);
	}
}

void GameBoard::setNextFreePosition(const GameBoard::BoardValue& pValue, int pEscape)
{
	Gorgon::Point pos;
    for(pos.setY(0); pos.getY() < mSize; pos.addY(1))
    {
        for(pos.setX(0); pos.getX() < mSize; pos.addX(1))
        {
            if(getPosition(pos) == GameBoard::NONE)
            {
				--pEscape;
		        if(pEscape == -1)
		        {
		        	setPosition(pValue,pos);
		            return;
		        }
	        }
        }
    }
}

void GameBoard::draw(const Gorgon::Point& pPosition) const
{
	Gorgon::Point i;	
	char aux;
	for(i.setY(0); i.getY() < mSize; i.addY(1))
	{
		for(i.setX(0); i.getX() < mSize; i.addX(1))
		{
			switch(getPosition(i))
			{
				case GameBoard::NONE:		aux = ' ';	break;
				case GameBoard::PLAYER1:	aux = 'X';	break;
				case GameBoard::PLAYER2:	aux = 'O';	break;
			}
			Gorgon::Video::get().drawText(pPosition.getX() + 10 + i.getX() * 10,pPosition.getY() + i.getY()*10,0xFFFFFF,-1,"%c ",aux);
		}
	}
}

GameBoard::BoardValue GameBoard::gameOver() const
{
    short i,j;
	char diagonal1, diagonal2, horizontal, vertical;

    for(i = 0, diagonal1 = diagonal2 = 1; i < mSize; ++i)
    {
        for(vertical = horizontal = 1,j = 0; j < mSize - 1; ++j)
        {
        	//if(getPosition((j,i)) == GameBoard::NONE || getPosition((j,i)) != getPosition((j+1,i)))					horizontal	= 0;
			//if(getPosition((i,j)) == GameBoard::NONE || getPosition((i,j)) != getPosition((i,j+1)))					vertical	= 0;
        	
            if(mInternalBoard[i][j] == GameBoard::NONE || mInternalBoard[i][j] != mInternalBoard[i][j+1])					horizontal	= 0;
			if(mInternalBoard[j][i] == GameBoard::NONE || mInternalBoard[j][i] != mInternalBoard[j+1][i])					vertical	= 0;
        }
        if(horizontal	== 1)	return mInternalBoard[i][j-1];
        if(vertical		== 1)  	return mInternalBoard[j-1][i];
        if(i < mSize - 1)
        {
        	//if(!(getPosition((i,i))			!=0 && getPosition((i,i))			== getPosition((i+1,i+1)))			)	diagonal1 = 0;
			//if(!(getPosition((mSize-1-i,i))	!=0 && getPosition((mSize-1-i,i))	== getPosition((mSize-2-i,i+1)))	)	diagonal2 = 0;
			if(!(mInternalBoard[i][i]			!=0 && mInternalBoard[i][i]			== mInternalBoard[i+1][i+1])		)	diagonal1 = 0;
			if(!(mInternalBoard[i][mSize-1-i]	!=0 && mInternalBoard[i][mSize-1-i]	== mInternalBoard[i+1][mSize-2-i])	)	diagonal2 = 0;
		}
    }
   	if(diagonal1) return mInternalBoard[i-1][i-1];
    if(diagonal2) return mInternalBoard[i-1][mSize-i];
    return GameBoard::NONE;
}

int GameBoard::getUtil(GameBoard::BoardValue& pPlayer) const
{
	int i,j,util = 0;
	char aux1,aux2;
	GameBoard::BoardValue win	= gameOver();
	GameBoard::BoardValue enemy	= (pPlayer == GameBoard::PLAYER1) ? GameBoard::PLAYER2 : GameBoard::PLAYER1;
	char linhaFalsa, colunaFalsa, diagonal1Falsa, diagonal2Falsa;
	short scoreV, scoreH, scoreD1, scoreD2;
	if(win != GameBoard::NONE)
	{
		util = (win == pPlayer) ? 30 : -30;
	}
		
	//possibilidades do jogador 1 vencer
	for(i=diagonal1Falsa=diagonal2Falsa=scoreD1=scoreD2=0; i < mSize; ++i)
	{
		for(j=linhaFalsa=scoreH=scoreV=colunaFalsa=0; j < mSize; ++j)
		{
			if(getPosition(Gorgon::Point(j,i)) == pPlayer) scoreH++;
			else if(getPosition(Gorgon::Point(j,i)) == enemy)	linhaFalsa = 1;
			if(getPosition(Gorgon::Point(i,j)) == enemy) scoreV++;
			else if(getPosition(Gorgon::Point(i,j)) == enemy)	colunaFalsa = 1;
		}
		if(!linhaFalsa)						util+= 1 + scoreH;
		if(!colunaFalsa)					util+= 1 + scoreV;
		
		if(getPosition(Gorgon::Point(i,i))				== pPlayer) ++scoreD1;
		else if(getPosition(Gorgon::Point(i,i))			== enemy) diagonal1Falsa = 1;
		if(getPosition(Gorgon::Point(mSize-1-i,i))		== pPlayer) ++scoreD2;
		else if(getPosition(Gorgon::Point(mSize-1-i,i))	== enemy) diagonal2Falsa = 1;
	}

	if(!diagonal1Falsa)	util+= 1 + scoreD1;
	if(!diagonal2Falsa)	util+= 1 + scoreD2;

	//possibilidades do jogador 2 vencer
	for(i=diagonal1Falsa=diagonal2Falsa=0; i < mSize; ++i)
	{
		for(j=linhaFalsa=scoreH=scoreV=colunaFalsa=0; j < mSize; ++j)
		{
			if(getPosition(Gorgon::Point(j,i)) == enemy) scoreH++;
			else if(getPosition(Gorgon::Point(j,i)) == pPlayer)		linhaFalsa	= 1;
			if(getPosition(Gorgon::Point(i,j)) == enemy) scoreH++;
			else if(getPosition(Gorgon::Point(i,j)) == pPlayer)		colunaFalsa	= 1;
		}
		if(!linhaFalsa)						util-= 1 + scoreH;
		if(!colunaFalsa)					util-= 1 + scoreV;
		if(getPosition(Gorgon::Point(i,i))				== enemy) ++scoreD1;
		else if(getPosition(Gorgon::Point(i,i))			== pPlayer)	diagonal1Falsa = 1;
		if(getPosition(Gorgon::Point(i,mSize-1-i))		== enemy) ++scoreD2;
		else if(getPosition(Gorgon::Point(i,mSize-1-i))	== pPlayer)	diagonal2Falsa = 1;
	}
	if(!diagonal1Falsa)	util-= 1 + scoreD1;
	if(!diagonal2Falsa)	util-= 1 + scoreD2;
	
	return util;
}
