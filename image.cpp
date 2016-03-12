#include "image.h"
#include <SDL2/SDL.h>

void Image::set_surface(SDL_Surface *surf)
{
  this->surface = surf;
}

SDL_Surface *Image::get_surface()
{
  return this->surface;
}

void Image::set_path(std::string new_path)
{
  this->path = new_path;
}

std::string Image::get_path()
{
  return this->path;
}

bool Image::load_path()
{
  bool success = true;
  this->set_surface(SDL_LoadBMP(this->get_path().c_str()));
  if (this->get_surface() == NULL) {
    std::cout << SDL_GetError();
    success = false;
  }

  return success;
}
