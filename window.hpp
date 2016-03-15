#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>

class Window
{
  public:
    Window();
    Window(int, int, std::string);
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::string title;
    int width;
    int height;
    bool success;
    void close();

  private:

};
#endif
