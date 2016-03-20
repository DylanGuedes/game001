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
#include "texture.hpp"
#include "button.hpp"
#include "timer.hpp"

int main(int argc, char const *argv[])
{
  SDL::init();

  Window window(640, 480, "Random Game");
  Texture tYoshi(&window, "yoshi.png");
  Object oYoshi(50, 200, Object::State::WALKING_LEFT, &tYoshi, 8, Object::SpriteStyle::COLUMN_STATE);
  Texture tButton(&window, "button.png");
  Object oButton(0, 0, Object::State::WALKING_LEFT, &tButton, 1, Object::SpriteStyle::ROW_STATE);
  Button button(Button::State::BUTTON_SPRITE_MOUSE_OUT, &oButton, 300, 200);

  button.inspect_me(1);

  bool quit = false;
  SDL_Event e;

  oYoshi.velx = 40;
  oYoshi.vely = 40;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      } else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_LEFT:
            oYoshi.state = Object::State::WALKING_LEFT;
            if (oYoshi.x >= 0) {
              oYoshi.x -= oYoshi.velx;
            }
          break;

          case SDLK_RIGHT:
            oYoshi.state = Object::State::WALKING_RIGHT;
            if ((oYoshi.x < window.width)) {
              oYoshi.x += oYoshi.velx;
            }
          break;

          case SDLK_UP:
            if (oYoshi.y > 0) {
              oYoshi.y -= oYoshi.vely;
            }
          break;

          case SDLK_DOWN:
            if (oYoshi.y <= window.height) {
              oYoshi.y += oYoshi.vely;
            }
          break;

          default:
          break;
        }
      } else {
        button.handle_event(&e);
        std::cout << "seconds since start: " << (t.get_ticks() / 1000.f) << std::endl;
      //   std::cout << "estado: " << oYoshi.state << std::endl;
      //   std::cout << "sprite_style: " << oYoshi.sprite_style << std::endl;
      //   std::cout << "actual_frame: " << oYoshi.actual_frame << std::endl;
      }
    }

    SDL_SetRenderDrawColor(window.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window.renderer);

    oYoshi.update();
    button.update();

    SDL_RenderPresent(window.renderer);
  }

  tYoshi.close();
  window.close();
  SDL::quit();
  return 0;
}
