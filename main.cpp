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
  i.set_path("x.bmp");
  Game game;
  SDL_Event e;
  bool quit = false;
  if (!game.init()) {
    std::cout << "Failed to initialize" << std::endl;
  } else {
    if (!i.load_path()) {
      std::cout << "Failed to load media" << std::endl;
    } else {
    }

    game.images.push_back(i);

    while (!quit) {
      while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }

      SDL_BlitSurface(i.get_surface(), NULL, game.get_screen_surface(), NULL);

      SDL_UpdateWindowSurface(game.get_window());
    }
  }

  game.close();
  return 0;
}
