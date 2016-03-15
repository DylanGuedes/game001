#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "window.hpp"
#include "sdl_modules.hpp"
#include "texture.hpp"
#include "object.hpp"
#include "frame.hpp"
#include "texture.hpp"

int main(int argc, char const *argv[])
{
  SDL::init();
  Frame fYoshi;
  Window window(640, 480, "Random Game");
  Texture tYoshi(&window, &fYoshi);
  tYoshi.path = "yoshi.png";
  tYoshi.load_from_path();
  Object oYoshi(100, 100, &tYoshi);

  fYoshi.aggr_height = tYoshi.height;
  fYoshi.aggr_width = tYoshi.width;
  fYoshi.state = Frame::State::WALKING_LEFT;
  fYoshi.total_frames = 8;
  fYoshi.actual_frame = 0;

  bool quit = false;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      } else {
      }
    }

    SDL_SetRenderDrawColor(window.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window.renderer);

    oYoshi.update();

    SDL_RenderPresent(window.renderer);
  }

  tYoshi.close();
  window.close();
  SDL::quit();
  return 0;
}
