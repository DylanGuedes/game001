#include "window.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Window::Window() :
  window(nullptr),
  width(1),
  height(1),
  renderer(nullptr),
  success(false),
  title("")
{
  std::cout << "Empty window started." << std::endl;
}

Window::Window(int width, int height, std::string title) :
  window(nullptr),
  width(width),
  renderer(nullptr),
  height(height),
  success(true),
  title(title)
{
  this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);

  if (this->window == NULL) {
    std::cout << SDL_GetError();
    this->success = false;
  } else {
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderer == NULL) {
      std::cout << SDL_GetError();
      this->success = false;
    } else {
      SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
      int img_flags = IMG_INIT_PNG;
      if (!(IMG_Init(img_flags) & img_flags)) {
        std::cout << IMG_GetError();
        this->success = false;
      }
    }
  }
}

void Window::close()
{
  if (this->renderer == NULL || this->renderer == nullptr) {
    SDL_DestroyRenderer(this->renderer);
  }

  if (this->window == NULL || this->window == nullptr) {
    SDL_DestroyWindow(this->window);
  }
}

