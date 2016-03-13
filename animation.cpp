#include "animation.h"
#include <cstddef>
#include <vector>
#include <map>
#include <SDL2/SDL.h>

Animation::Animation()
{
  walking_frames = 0;
  actual_walking_frame = 0;
  state = Animation::State::STOPPED;
}

void Animation::update()
{
  std::vector<SDL_Rect> *rect_collection;
  SDL_Rect current_rect;

  std::cout << "STATE:" << state << "\n\n\n\n\n\n";
  std::cout << "ACTUAL_WALKING FRAME:" << actual_walking_frame << "\n\n\n\n\n\n";

  auto it = sprites.find(state);
  if (it == sprites.end()) {
  } else {
    rect_collection = &sprites[state];
    current_rect = (*rect_collection)[actual_walking_frame];
    texture->render(actual_walking_frame, 100, &current_rect);
  }

  actual_walking_frame++;
  if (actual_walking_frame >= walking_frames) {
    actual_walking_frame = 0;
  }
  //
  // switch (state) {
  //   case Animation::State::STOPPED :
  //     *rect_collection = sprites[Animation::State::STOPPED];
  //     current_rect = (*rect_collection)[actual_walking_frame];
  //     texture->render(0, 0, &current_rect);
  //   break;
  //
  //   case Animation::State::WALKING_LEFT :
  //     // std::vector<SDL_Rect> myrect = sprites[Animation::State::STOPPED];
  //     // texture->render(0, 0, sprites.find(Animation::State::WALKING_LEFT)[actual_walking_frame]);
  //   break;
  //
  //   case Animation::State::WALKING_RIGHT :
  //
  //     // std::vector<SDL_Rect> myrect = sprites[Animation::State::STOPPED];
  //     // texture->render(0, 0, sprites.find(Animation::State::WALKING_RIGHT)[actual_walking_frame]);
  //   break;
  // }

}
