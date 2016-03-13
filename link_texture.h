#ifndef LINK_TEXTURE_H
#define LINK_TEXTURE_H

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include "image.h"

class Game;

class LinkTexture
{
  public:
    void set_height(int h);
    void set_width(int w);
    void set_texture(SDL_Texture *);
    int get_height();
    int get_width();
    SDL_Texture *get_texture();
    void render(int x, int y, SDL_Rect *clip = NULL);
    void free();
    void set_game(Game *new_g);
    Game *get_game();
    bool load_from_file(std::string path);
    LinkTexture();
    ~LinkTexture();
  private:
    int height;
    int width;
    SDL_Texture *texture;
    Game *game;
};

#endif
