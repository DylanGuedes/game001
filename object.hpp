#ifndef OBJECT_H
#define OBJECT_H

#include "texture.hpp"

class Object
{
  public:
    enum State {
      WALKING_LEFT = 0,
      WALKING_RIGHT = 1,
      TOTAL = 2
    };

    enum SpriteStyle {
      COLUMN_STATE = 0,
      ROW_STATE = 1
    };

    Object(int x0, int y0, Object::State initial_State, Texture*, int total_frame, Object::SpriteStyle, int);

    State state;
    SpriteStyle sprite_style;
    int total_states;
    int x;
    int y;
    void update();
    Texture *texture;
    int velx;
    int vely;
    int frame_per_action;
    int actual_frame;
    void inspect_me(int);

  private:
};

#endif
