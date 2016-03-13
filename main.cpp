#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "image.h"
#include "game.h"
#include "link_texture.h"

int main(int argc, char const *argv[])
{
  Game game;
  SDL_Event e;
  bool quit = false;

  if (!game.init()) {
    std::cout << "Failed to initialize" << std::endl;
  } else {

    LinkTexture background;
    background.set_game(&game);
    background.load_from_file("background.png");

    LinkTexture ttr1;
    ttr1.set_game(&game);
    ttr1.load_from_file("foo.png");

    while (!quit) {
      while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }

      SDL_SetRenderDrawColor(game.get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(game.get_renderer());

      background.render(0, 0);
      ttr1.render(540, 190);

      SDL_RenderPresent(game.get_renderer());
    }
  }

  game.close();
  return 0;
}
