#pragma once

#include <iostream>
#include "window.hpp"
#include "frame.hpp"

class Texture
{
  public:
    Window *window;
    Texture(Window *, Frame *);
    Texture(Window *, Frame *, std::string);
    int width;
    int height;
    std::string path;
    bool load_from_path();
    SDL_Texture *get;
    void close();
    Frame *frame;

  private:

};

