#include "object.hpp"
#include <iostream>
#include "window.hpp"

/*
   Usage example:
   Object oExample(50, 200, &mytexture);
*/
Object::Object(int x0, int y0, Object::State initial_state, Texture *texture, int total_frame_per_action, Object::SpriteStyle sprite_style) :
  state(initial_state),
  x(x0),
  y(y0),
  texture(texture),
  velx(0),
  vely(0),
  actual_frame(0),
  sprite_style(sprite_style),
  frame_per_action(total_frame_per_action)
{ }

void Object::update()
{
  // update the frame
  int width_per_frame = 0;
  int height_per_frame = 0;

  width_per_frame = this->texture->width / Object::State::TOTAL;
  height_per_frame = this->texture->height / this->frame_per_action;

  int position_x = 0;
  int position_y = 0;

  position_x = width_per_frame * this->state;
  position_y = height_per_frame * this->actual_frame;

  SDL_Rect act = {position_x, position_y, width_per_frame, height_per_frame};
  SDL_Rect other = {position_x, position_y, this->texture->height, this->texture->width};
  // std::cout << "act: " << position_x << ", " << position_y << ", " << width_per_frame << ", " << height_per_frame << std::endl;

  // render the actual frame state
  SDL_RenderCopy(this->window->renderer, this->texture->get, &act, &other);

  // check if needs to reset actual_frame count, updates current frame count
  if (this->frame_per_action <= (this->actual_frame)) {
    this->actual_frame = 0;
  } else {
    this->actual_frame += 1;
  }
}
