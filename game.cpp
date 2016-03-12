#include "game.h"
#include <SDL2/SDL.h>
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
    this->set_window(SDL_CreateWindow(this->get_name().c_str(),
          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->get_width(),
          this->get_height(), SDL_WINDOW_SHOWN));
    if (this->get_window() == NULL) {
      std::cout << SDL_GetError();
      success = false;
    } else {
      this->set_screen_surface(SDL_GetWindowSurface(this->get_window()));
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

