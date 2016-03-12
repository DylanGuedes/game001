#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#endif

#include "image.h"
#include "game.h"

int main(int argc, char const *argv[])
{
  Image i;
  Game game;
  if (!game.init()) {
    std::cout << "Failed to initialize" << std::endl;
  } else {
    if (!game.load_media()) {
      std::cout << "Failed to load media" << std::endl;
    } else {
      bool quit = false;
      SDL_Event e;
    }

    while (!quit) {
      while (SDL_PoolEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }

      SDL_BlitSurface(game.get_screen_surface(), NULL, game.get_screen_surface(), NULL);

      SDL_UpdateWindowSurface(game.get_window());
    }
  }
  return 0;

}
