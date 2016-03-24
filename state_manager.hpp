#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <SDL2/SDL.h>

namespace StateManager
{
  enum GameStates {
    GAMESTATE_MENU = 0,
    GAMESTATE_STAGE1 = 1,
    GAMESTATE_PAUSED = 2,
    GAMESTATE_EXIT = 3
  };

  bool render_stage1(Window *window)
  {
    SDL_SetRenderDrawColor(window->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(window->renderer);

    for (auto it : window->objects) {
      it.second->update();
    }

    SDL_RenderPresent(window->renderer);
  }

  bool handle_state(StateManager::GameStates *current_state, Window *window)
  {
    switch (*current_state) {
      case GameStates::GAMESTATE_MENU :
        break;

      case GameStates::GAMESTATE_STAGE1 :
        render_stage1(window);
        break;

      case GameStates::GAMESTATE_PAUSED :
        break;

      case GameStates::GAMESTATE_EXIT :
        return false;
        break;

      default:
        break;
    }

    return true;
  }

  bool get_actions(StateManager::GameStates *current_state, Window *window)
  {
    SDL_Event e;
    StateManager::GameStates update_state;
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        *current_state = StateManager::GameStates::GAMESTATE_EXIT;
      } else {
      }
    }

    return handle_state(current_state, window);
  }

  void prepare_objects(Window *window)
  {
    Texture *yoshi_texture = new Texture(window, "yoshi.png");
    Object *oYoshi = new Object(250, 250, Object::State::WALKING_LEFT, yoshi_texture, 8, Object::SpriteStyle::COLUMN_STATE, 2);
    window->objects.insert(std::pair<Window::ObjectCode, Object *>(Window::ObjectCode::YOSHI, oYoshi));
    Texture *tower_texture = new Texture(window, "Tower0001.png");
    Object *oTower = new Object(0, 0, Object::State::WALKING_LEFT, tower_texture, 4, Object::SpriteStyle::ROW_STATE, 1);
    window->objects.insert(std::pair<Window::ObjectCode, Object *>(Window::ObjectCode::TOWER, oTower));
  }

  void prepare_stages(Window *window)
  {
    prepare_objects(window);
  }
}

#endif
