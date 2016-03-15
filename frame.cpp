#include "frame.hpp"
#include <iostream>
#include <SDL2/SDL.h>

Frame::Frame() :
  state(Frame::State::WALKING_RIGHT),
  total_frames(0),
  actual_frame(0),
  aggr_width(1),
  aggr_height(1)
{
}

SDL_Rect Frame::updated_frame()
{
  SDL_Rect new_rect;

  new_rect.x = 100;
  new_rect.w = ((this->aggr_width) / (Frame::State::TOTAL));
  new_rect.h = ((this->aggr_height) / (this->total_frames));
  new_rect.y = 100;

  return new_rect;
}
