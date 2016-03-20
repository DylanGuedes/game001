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

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char const *argv[])
{
  SDL::init();

  Window window(640, 480, "Random Game");
  Texture tYoshi(&window, "yoshi.png");
  Object oYoshi(0, 0, Object::State::WALKING_LEFT, &tYoshi, 8, Object::SpriteStyle::COLUMN_STATE);
  Texture tButton(&window, "button.png");
  Object oButton(0, 0, Object::State::WALKING_LEFT, &tButton, 1, Object::SpriteStyle::ROW_STATE);
  Button button(Button::State::BUTTON_SPRITE_MOUSE_OUT, &oButton, 300, 200);

  button.inspect_me(1);

  bool quit = false;
  SDL_Event e;

  oYoshi.velx = 0;
  oYoshi.vely = 0;

  Timer fps_counter;
  Timer cap_timer;
  int counted_frames = 0;

  fps_counter.start();
  float avg_fps = 0;

  while (!quit) {
    cap_timer.start();
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


      }
    }
    int width_per_frame = oYoshi.texture->width / Object::State::TOTAL;
    int height_per_frame = oYoshi.texture->height / oYoshi.frame_per_action;
    oYoshi.x += oYoshi.velx;
    oYoshi.y += oYoshi.vely;

    if (oYoshi.y <= 0 && oYoshi.x >= (window.width - width_per_frame)) {
      oYoshi.x = 0;
      oYoshi.y = 0;
    }

    if (oYoshi.y > (window.height - height_per_frame)) {
      oYoshi.vely = 0;
    }

    if (oYoshi.x > (window.width - width_per_frame)){
      oYoshi.velx = 0;
    }


    if (oYoshi.y < (window.height - height_per_frame)) {
      if (oYoshi.x == 0) {
        oYoshi.vely = 1;
      }
    } else {
      if (oYoshi.x < (window.width - width_per_frame)) {
        oYoshi.velx = 1;
      } else {
        oYoshi.vely = -1;
      }
    }


    avg_fps = counted_frames / (fps_counter.get_ticks() / 1000.f);
    if (avg_fps > 2000000) {
      avg_fps = 0;
    }
    // std::cout << "avg_fps: " << avg_fps << std::endl;
    ++counted_frames;

    SDL_SetRenderDrawColor(window.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window.renderer);

    oYoshi.update();
    button.update();

    SDL_RenderPresent(window.renderer);

    int frame_ticks = cap_timer.get_ticks();
    if (frame_ticks < SCREEN_TICKS_PER_FRAME) {
      SDL_Delay(SCREEN_TICKS_PER_FRAME - frame_ticks);
    }
  }

  tYoshi.close();
  window.close();
  SDL::quit();
  return 0;
}
