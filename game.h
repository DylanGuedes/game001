#ifndef GAME_H
#define GAME_H

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#endif

#include <iostream>

class Game
{
  private:
    SDL_Window *window;
    SDL_Surface *screen_surface;
    std::string name;
    int width;
    int height;
  public:

    void set_window(SDL_Window *);
    SDL_Window *get_window();
    bool init();
    Game();
    void set_name(std::string);
    std::string get_name();
    void set_screen_surface(SDL_Surface *);
    SDL_Surface *get_screen_surface();
    void set_height(int);
    void set_width(int);
    int get_height();
    int get_width();
};

#endif
