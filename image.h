#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <SDL2/SDL.h>

class Image
{
  private:
    SDL_Surface *surface;
    std::string path;

  public:
    SDL_Surface *get_surface();
    void set_surface(SDL_Surface *);
    bool load_path();
    void set_path(std::string new_path);
    std::string get_path();
};

#endif
