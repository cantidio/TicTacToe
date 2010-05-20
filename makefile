all: main

relink: game_board
	g++ src/main.cpp obj/* -o game.e `gorgon-config --libs` `allegro-config --libs`
	
main: src/main.cpp game game_states game_board game_player game_player_human game_player_computer
	g++ src/main.cpp obj/* -o game.e `gorgon-config --libs` `allegro-config --libs`

game: include/game.hpp src/game.cpp
	g++ -c src/game.cpp
	@mv game.o obj/

game_states:	game_state				game_state_test	game_state_disclaimer	\
				game_state_oppening		game_state_menu 						\
				game_state_game			game_state_win							\
				game_state_game_single	game_state_game_versus					\
				game_state_game_watch	game_state_option

game_state: include/game_state.hpp src/game_state.cpp
	g++ -c src/game_state.cpp
	@mv game_state.o obj/

game_state_test: include/game_state_test.hpp src/game_state_test.cpp
	g++ -c src/game_state_test.cpp
	@mv game_state_test.o obj/

game_state_disclaimer: include/game_state_disclaimer.hpp src/game_state_disclaimer.cpp
	g++ -c src/game_state_disclaimer.cpp
	@mv game_state_disclaimer.o obj/

game_state_oppening: include/game_state_oppening.hpp src/game_state_oppening.cpp
	g++ -c src/game_state_oppening.cpp
	@mv game_state_oppening.o obj/

game_state_menu: include/game_state_menu.hpp src/game_state_menu.cpp
	g++ -c src/game_state_menu.cpp
	@mv game_state_menu.o obj/

game_state_game: include/game_state_game.hpp src/game_state_game.cpp
	g++ -c src/game_state_game.cpp
	@mv game_state_game.o obj/

game_state_win: include/game_state_win.hpp src/game_state_win.cpp
	g++ -c src/game_state_win.cpp
	@mv game_state_win.o obj/

game_state_game_single: include/game_state_game_single.hpp src/game_state_game_single.cpp
	g++ -c src/game_state_game_single.cpp
	@mv game_state_game_single.o obj/

game_state_game_versus: include/game_state_game_versus.hpp src/game_state_game_versus.cpp
	g++ -c src/game_state_game_versus.cpp
	@mv game_state_game_versus.o obj/

game_state_game_watch: include/game_state_game_watch.hpp src/game_state_game_watch.cpp
	g++ -c src/game_state_game_watch.cpp
	@mv game_state_game_watch.o obj/

game_state_option: include/game_state_option.hpp src/game_state_option.cpp
	g++ -c src/game_state_option.cpp
	@mv game_state_option.o obj/

game_board: include/game_board.hpp src/game_board.cpp
	g++ -c src/game_board.cpp
	@mv game_board.o obj/

game_player: include/game_player.hpp src/game_player.cpp
	g++ -c src/game_player.cpp
	@mv game_player.o obj/

game_player_human: include/game_player_human.hpp src/game_player_human.cpp
	g++ -c src/game_player_human.cpp
	@mv game_player_human.o obj/

game_player_computer: include/game_player_computer.hpp src/game_player_computer.cpp
	g++ -c src/game_player_computer.cpp
	@mv game_player_computer.o obj/

clean:
	rm obj/*
	rm game.e

