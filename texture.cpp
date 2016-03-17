#include "SDL2/SDL_image.h"
#include "texture.hpp"
#include "frame.hpp"

Texture::Texture(Window *window, Frame *frame) :
  window(window),
  width(1),
  height(1),
  path(""),
  get(nullptr),
  frame(frame)
{}

Texture::Texture(Window *window, Frame *frame, std::string path) :
  window(window),
  width(1),
  height(1),
  path(path),
  get(nullptr),
  frame(frame)
{
  this->load_from_path();
}

bool Texture::load_from_path()
{
  SDL_Texture *tmp_texture = NULL;
  SDL_Surface *loaded_surface = IMG_Load(this->path.c_str());

  if (loaded_surface == NULL ) {
    std::cout << IMG_GetError();
  } else {
    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

    tmp_texture = SDL_CreateTextureFromSurface(this->window->renderer, loaded_surface);

    if (tmp_texture == NULL) {
      std::cout << SDL_GetError();
    } else {
      this->width = loaded_surface->w;
      this->height = loaded_surface->h;
    }
    SDL_FreeSurface(loaded_surface);
  }

  this->get = tmp_texture;

  return this->get != NULL;
}

void Texture::close()
{
  if (this->get == NULL || this->get == nullptr) {
    // do nothing
  } else {
    SDL_DestroyTexture(this->get);
  }
}
