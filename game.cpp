#include "game.h"
#include <list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game()
{
  this->set_window(NULL);
  this->set_width(640);
  this->set_height(480);
}

bool Game::init()
{
  bool success = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << SDL_GetError();
  } else {
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      std::cout << "Warning: Linear texture disabled!" << std::endl;
    }
    this->set_window(SDL_CreateWindow(this->get_name().c_str(),
          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->get_width(),
          this->get_height(), SDL_WINDOW_SHOWN));
    if (this->get_window() == NULL) {
      std::cout << SDL_GetError();
      success = false;
    } else {
      this->set_renderer(SDL_CreateRenderer(this->get_window(), -1, SDL_RENDERER_ACCELERATED));
      if (this->get_renderer() == NULL) {
        success = false;
      } else {
        SDL_SetRenderDrawColor(this->get_renderer(), 0xFF, 0xFF, 0xFF, 0xff);
        int img_flags = IMG_INIT_PNG;
        if (!(IMG_Init(img_flags) & img_flags)) {
          std::cout << IMG_GetError();
          success = false;
        }
      }
    }
  }

  return success;
}

void Game::set_name(std::string new_name)
{
  this->name = new_name;
}

std::string Game::get_name()
{
  return this->name;
}

void Game::set_window(SDL_Window *new_window)
{
  this->window = new_window;
}

SDL_Window *Game::get_window()
{
  return this->window;
}

void Game::set_screen_surface(SDL_Surface *new_surface)
{
  this->screen_surface = new_surface;
}

SDL_Surface *Game::get_screen_surface()
{
  return this->screen_surface;
}

int Game::get_height()
{
  return this->height;
}

int Game::get_width()
{
  return this->width;
}

void Game::set_width(int new_w)
{
  this->width = new_w;
}

void Game::set_height(int new_h)
{
  this->height = new_h;
}

void Game::set_renderer(SDL_Renderer *new_rend)
{
  this->renderer = new_rend;
}

SDL_Renderer *Game::get_renderer()
{
  return this->renderer;
}

void Game::close()
{
  for (auto it : this->images) {
    SDL_FreeSurface(it.get_surface());
  }

  for (auto it : this->textures) {
    SDL_DestroyTexture(it);
  }

  SDL_DestroyRenderer(this->get_renderer());
  SDL_DestroyWindow(this->get_window());

  IMG_Quit();
  SDL_Quit();
}

void Game::add_texture(SDL_Texture *new_texture)
{
  this->textures.push_back(new_texture);
}

void Game::load_texture(std::string path)
{
  SDL_Texture *texture = NULL;
  SDL_Surface *loaded_surface = IMG_Load(path.c_str());
  if (loaded_surface == NULL) {
    std::cout << IMG_GetError();
  } else {
    texture = SDL_CreateTextureFromSurface(this->get_renderer(), loaded_surface);
    if (texture == NULL) {
      std::cout << SDL_GetError();
    } else {
      SDL_FreeSurface(loaded_surface);
    }
  }

  this->add_texture(texture);
}

void Game::create_renderer()
{
  this->set_renderer(SDL_CreateRenderer(this->get_window(), -1, SDL_RENDERER_ACCELERATED));
}
