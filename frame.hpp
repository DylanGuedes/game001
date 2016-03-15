#pragma once

#include "SDL2/SDL.h"

class Frame
{
  public:

    enum State {
      WALKING_LEFT = 0,
      WALKING_RIGHT = 1,
      TOTAL = 2
    };

    int aggr_height;
    int aggr_width;
    State state;
    int total_frames;
    int actual_frame;
    SDL_Rect updated_frame();
    Frame();

  public:
};
