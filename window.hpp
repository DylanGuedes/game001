#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>
#include <map>

class Object;

class Window
{
  public:
    enum ObjectCode {
      YOSHI = 0,
      BUTTON = 1,
      TOWER = 2,
      TOTAL = 3
    };

    Window();
    Window(int, int, std::string);
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::string title;
    int width;
    int height;
    bool success;
    void close();
    std::map<Window::ObjectCode, Object*> objects;

  private:

};
#endif
