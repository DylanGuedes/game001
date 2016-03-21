#include "button.hpp"

Button::Button(Button::State init_state, Object *object, int width, int height) :
  object(object),
  state(init_state),
  width(width),
  height(height),
  action(Button::Action::SPAWN_MONSTER)
{
  this->x = object->x;
  this->y = object->y;
}

bool Button::handle_event(SDL_Event *e)
{
  bool do_action = false;
  if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
    int x_pos, y_pos;
    SDL_GetMouseState(&x_pos, &y_pos);
    bool mouse_over = true;

    if (
        (x_pos < this->x) ||
        (x_pos > this->x + this->width) ||
        ((this->y + this->height) < y_pos) ||
        (this->y > y_pos)
       ) {
      mouse_over = false;
    }

    if (!mouse_over) {
      this->state = Button::State::BUTTON_SPRITE_MOUSE_OUT;
    } else {
      switch (e->type) {
        case SDL_MOUSEMOTION:
          this->state = Button::State::BUTTON_SPRITE_MOUSE_OVER_MOTION;
        break;

        case SDL_MOUSEBUTTONDOWN:
          this->state = Button::State::BUTTON_SPRITE_MOUSE_DOWN;
          do_action = true;
        break;

        case SDL_MOUSEBUTTONUP:
          this->state = Button::State::BUTTON_SPRITE_MOUSE_UP;
        break;
      }
    }
  }

  return do_action;
}

void Button::update()
{
  SDL_Rect position;
  SDL_Rect sprite;

  if (this->object->sprite_style == Object::SpriteStyle::COLUMN_STATE) {
    position = { this->x, this->y, this->width, this->height };
    sprite = { this->state * this->width, 0, this->width, this->height };
  } else {
    position = { this->x, this->y, this->width, this->height };
    sprite = { 0, this->height * this->state, this->width, this->height };
  }

  // std::cout << "position: { " << position.x << ", " << position.y << ", " << position.w << ", " << position.h << "}" << std::endl;
  // std::cout << "sprite: { " << sprite.x << ", " << sprite.y << ", " << sprite.w << ", " << sprite.h << "}" << std::endl;
  // std::cout << "button update" << std::endl;
  SDL_RenderCopy(this->object->texture->window->renderer, this->object->texture->get, &sprite, &position);
}

void Button::inspect_me(int align)
{
  int i;
  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "inspecting button" << std::endl;

  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "{" << std::endl;

  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "state => " << state << std::endl;
  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "width => " << width << std::endl;
  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "height => " << height<< std::endl;
  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "x => " << x << std::endl;
  for (i=0; i < align; ++i) std::cout << "\t";
  std::cout << "y => " << y<< std::endl;

  this->object->inspect_me(align+1);


  for (i=0; i < align-1; ++i) std::cout << "\t";
  std::cout << "}" << std::endl;


}
