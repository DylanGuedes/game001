#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
      game.load_texture("texture.png");
    }

    game.images.push_back(i);

    while (!quit) {
      while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }

      SDL_SetRenderDrawColor(game.get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(game.get_renderer());

      SDL_Rect right_viewport;
      right_viewport.x = 0;
      right_viewport.y = 0;
      right_viewport.w = game.get_width() / 2;
      right_viewport.h = game.get_height() / 2;
      SDL_RenderSetViewport(game.get_renderer(), &right_viewport);
      for (auto it : game.textures) {
        SDL_RenderCopy(game.get_renderer(), it, NULL, NULL);
      }

      SDL_RenderPresent(game.get_renderer());
    }
  }

  game.close();
  return 0;
}
