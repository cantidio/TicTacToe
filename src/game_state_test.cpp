#include "../include/game_state_test.hpp"

void GameStateTest::init()
{
	printf("GameStateTest init.\n");
	Gorgon::Video::get().clear();
	mAngle	= 0;
	mImg	= Gorgon::Image(30,7);
//	mImg.clear(0x0000FF);
	mImg.drawText("TEST",0,0,0xFFFFFF);
	key[KEY_ENTER] = 0;
}

GameStateTest::~GameStateTest()
{
	printf("GameStateTest end.\n");
}

bool GameStateTest::run(bool& pGameRunning)
{
	GameState::run(pGameRunning);
	Gorgon::Video::get().clear();
	Gorgon::Video::get().drawImageRoteted
	(
		mImg,
		100,
		120,
		mAngle+=5,
		15,3
	);
	Gorgon::Video::get().drawImageRoteted
	(
		mImg,
		190,120,
		-mAngle,
		15,3
	);
	Gorgon::Video::get().drawText(" TEST STATE"					,10,20,0xFFFFFF);
	Gorgon::Video::get().drawText(" PRESS ESC OR ENTER TO QUIT"	,10,220,0xFFFFFF);
	Gorgon::Video::get().show();
	if(key[KEY_ESC] || key[KEY_ENTER])
	{
		pGameRunning=false;
		return false;
	}
	return true;
}

