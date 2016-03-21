#include "object.hpp"
#include <iostream>

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

  std::cout << "textura: " << this->texture->width << std::endl;


  /*
    rectangle from texture
  */
  int position_x = 0;
  int position_y = 0;

  position_x = width_per_frame * this->state;
  position_y = height_per_frame * this->actual_frame;


  SDL_Rect act = {position_x, position_y, width_per_frame, height_per_frame};
  /*
    in what rectangle/where the texture will be rendered:
  */
  SDL_Rect other = {this->x, this->y, width_per_frame, height_per_frame};

  // render the actual frame state
  std::cout << "ACT: " << act.x << " , " << act.y << " , " << act.h << " , " << act.w << "\n\n\n\n\n";

  std::cout << "other: " << other.x << " , " << other.y << " , " << other.h << " , " << other.w << "\n\n\n\n\n";

  std::cout << "calculo do width \n\n\n\n";
  SDL_RenderCopy(this->texture->window->renderer, this->texture->get, &act, &other);

  // check if needs to reset actual_frame count, updates current frame count
  if (this->frame_per_action <= (this->actual_frame+1)) {
    this->actual_frame = 0;
  } else {
    this->actual_frame += 1;
  }
}

void Object::inspect_me(int align)
{
  int i;
  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "inspecting object" << std::endl;

  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "{" << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "state => " << state << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "x => " << x << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "y => " << y<< std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "velx => " << velx << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "vely  => " << vely<< std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "actual_frame => " << actual_frame << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "frame_per_action => " << frame_per_action << std::endl;

  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "{" << std::endl;

}
