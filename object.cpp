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

  // std::cout << "x: " << act.x << ", y: " << act.y << ", height: " << act.h << ", width: " << act.w << std::endl;

  // render the actual frame state
  SDL_Texture *mytext = this->texture->get;
  SDL_RenderCopy(this->texture->window->renderer, this->texture->get, NULL, &act);

  // check if needs to reset actual_frame count
  if (this->texture->frame->total_frames <= this->texture->frame->actual_frame) {
    this->texture->frame->actual_frame = 0;
  } else {
    this->texture->frame->actual_frame += 1;
  }
}
