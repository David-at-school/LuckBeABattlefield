#include "Game.h"
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "Hello there, ZaXx was here" << std::endl;

	Game game;
	game.Initialize();

	// wait for keyboard enter to exit
	bool quit = false;
	SDL_Event event;
	while (!quit && !game.IsQuit())
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		game.Draw();
		game.Update();
	}

	SDL_Quit();
	return 0;
}