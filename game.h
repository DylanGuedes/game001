#ifndef GAME_H
#define GAME_H

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include <list>
#include "image.h"

class Game
{
  private:
    SDL_Window *window;
    SDL_Surface *screen_surface;
    std::string name;
    int width;
    int height;
    SDL_Renderer *renderer;
  public:
    std::list<SDL_Texture *> textures;
    std::list<Image> images;
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
    void close();
    void set_renderer(SDL_Renderer *);
    SDL_Renderer *get_renderer();
    void add_texture(SDL_Texture *);
    void load_texture(std::string);
    void create_renderer();

};

#endif
