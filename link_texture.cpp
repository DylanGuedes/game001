#include "game.h"
#include "link_texture.h"
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

LinkTexture::LinkTexture()
{
  width = 0;
  height = 0;
  texture = NULL;
}

void LinkTexture::set_height(int new_height)
{
  this->height = new_height;
}

int LinkTexture::get_height()
{
  return this->height;
}

void LinkTexture::set_width(int new_width)
{
  this->width = new_width;
}

int LinkTexture::get_width()
{
  return this->width;
}

void LinkTexture::set_texture(SDL_Texture *new_text)
{
  this->texture = new_text;
}

SDL_Texture *LinkTexture::get_texture()
{
  return this->texture;
}

void LinkTexture::free()
{
  if (texture != NULL) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

void LinkTexture::render(int x, int y)
{
  SDL_Rect render_quad = { x, y, width, height };
  SDL_RenderCopy(game->get_renderer(), texture, NULL, &render_quad);
}

LinkTexture::~LinkTexture()
{
  free();
}

Game *LinkTexture::get_game()
{
  return this->game;
}

void LinkTexture::set_game(Game *g)
{
  this->game = g;
}

bool LinkTexture::load_from_file(std::string path)
{
  free();

  SDL_Texture *text = NULL;
  SDL_Surface *loaded_surface = IMG_Load(path.c_str());

  if (loaded_surface == NULL) {
    std::cout << IMG_GetError();
  } else {

    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

    text = SDL_CreateTextureFromSurface(this->get_game()->get_renderer(), loaded_surface);

    if (text == NULL) {
      std::cout << SDL_GetError();
    } else {
      width = loaded_surface->w;
      height = loaded_surface->h;
    }


    SDL_FreeSurface(loaded_surface);
  }


  texture = text;
  return texture != NULL;
}
