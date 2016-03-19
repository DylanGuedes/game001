#include "button.hpp"

Button::Button(Button::State init_state, Object *object) :
  object(object),
  state(init_state)
{ }



