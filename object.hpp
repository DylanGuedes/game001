#ifndef OBJECT_H
#define OBJECT_H

#include "texture.hpp"
#include "window.hpp"

class Object
{
  public:
    int x;
    int y;
    void update();
    Object(int, int, Texture *);
    Texture *texture;
    Window *window;
    int velx;
    int vely;


  private:
};

#endif
