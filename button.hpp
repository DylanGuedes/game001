#ifndef BUTTON_H
#define BUTTON_H

#include "object.hpp"

class Button
{
  public:
    Object *object;

    enum State {
      BUTTON_SPRITE_MOUSE_OUT = 0,
      BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
      BUTTON_SPRITE_MOUSE_DOWN = 2,
      BUTTON_SPRITE_MOUSE_UP = 3,
      BUTTON_SPRITE_TOTAL = 4
    };

    Button::State state;
    Button(Button::State, Object*);
  private:
};
#endif
