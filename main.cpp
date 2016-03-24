#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <fstream>

#include "window.hpp"
#include "sdl_modules.hpp"
#include "texture.hpp"
#include "object.hpp"
#include "texture.hpp"
#include "button.hpp"
#include "timer.hpp"
#include "tile.hpp"
#include "state_manager.hpp"
#include <vector>

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int TILE_WIDTH = 40;
const int TILE_HEIGHT = 40;

int main(int argc, char const *argv[])
{
  if (not SDL::init()) {
    std::cout << "Starting the game" << std::endl;
  } else {
    Window window(640, 480, "Random Game");

    bool quit = false;
    StateManager::GameStates actual_state = StateManager::GameStates::GAMESTATE_STAGE1;

    StateManager::prepare_stages(&window);

    while (!quit) {
      quit = !StateManager::get_actions(&actual_state, &window);
    }

    window.close();
  }

  SDL::quit();
  return 0;
}
