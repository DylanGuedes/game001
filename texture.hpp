#pragma once

#include <iostream>
#include "window.hpp"

class Texture
{
  public:
    Window *window;
    Texture(Window *);
    Texture(Window *, std::string);
    int width;
    int height;
    std::string path;
    bool load_from_path();
    SDL_Texture *get;
    void close();

  private:

};

