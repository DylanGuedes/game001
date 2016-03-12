#include "image.h"

Image::Image(SDL_Surface *surf)
{
  this->set_surface(surf);
}

SDL_Surface *Image::set_surface()
{
  return this->surface;
}

void Image::set_surface(SDL_Surface *surf)
{
  this->surface = surf;
}

void Image::set_path(std::string new_path)
{
  this->path = new_path;
}

std::string Image::get_path()
{
  return this->path;
}
