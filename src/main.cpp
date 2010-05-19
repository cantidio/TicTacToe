#include "../include/game.hpp"

int main()
{
	allegro_init();					//inicia a Allegro
	install_keyboard();				//inicio o teclado
	install_timer();				//inicio o temporizador
	Gorgon::Video::init("teste");	//inicia a Gorgon
	Game game;						//instancia o jogo
	game.run();						//roda o jogo
	return 0;
}END_OF_MAIN()
