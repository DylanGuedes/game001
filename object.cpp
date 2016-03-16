#include "object.hpp"
#include <iostream>
#include "window.hpp"

Object::Object(int x, int y, Texture *texture) :
  x(x),
  y(y),
  texture(texture)
{ }

void Object::update()
{
  // update the frame
  SDL_Rect act = this->texture->frame->updated_frame();
  std::cout << this->texture->frame->actual_frame << " \n\n\n\n";
  int rect_width = (this->texture->width) / Frame::State::TOTAL;
  SDL_Rect other = { this->texture->frame->state * rect_width, act.h*this->texture->frame->actual_frame, act.w, act.h};
  // std::cout << "x: " << act.x << ", y: " << act.y << ", height: " << act.h << ", width: " << act.w << std::endl;

  // render the actual frame state
  SDL_Texture *mytext = this->texture->get;
  SDL_RenderCopy(this->texture->window->renderer, this->texture->get, &other, &act);

  // check if needs to reset actual_frame count
  if (this->texture->frame->total_frames <= (this->texture->frame->actual_frame+1 )) {
    this->texture->frame->actual_frame = 0;
  } else {
    this->texture->frame->actual_frame += 1;
  }
}
