#include <iostream>

#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "image.h"
#include "game.h"
#include "link_texture.h"
#include "animation.h"

int main(int argc, char const *argv[])
{
  Game game;
  Animation a_yoshi;
  LinkTexture t_yoshi;

  t_yoshi.set_height(73);
  t_yoshi.set_width(73);
  t_yoshi.set_game(&game);

  a_yoshi.state = Animation::State::WALKING_LEFT;

  a_yoshi.walking_frames = 7;
  a_yoshi.actual_walking_frame = 0;
  std::map<int, std::vector<SDL_Rect> > yoshi_sprites;

  std::vector<SDL_Rect> l_w_sprites(7);
  std::vector<SDL_Rect> r_w_sprites(7);
  std::vector<SDL_Rect> stopped(7);

  for(int i=0; i < 7; ++i) {
    l_w_sprites[i].x = 0;
    l_w_sprites[i].y = 64*(i+1);
    l_w_sprites[i].h = 64;
    l_w_sprites[i].w = 70;

    r_w_sprites[i].x = 74;
    r_w_sprites[i].y = 73*(i+1);
    r_w_sprites[i].h = 73;
    r_w_sprites[i].w = 74;

    stopped[i].x = 0;
    stopped[i].y = 73*(4);
    stopped[i].h = 73;
    stopped[i].w = 74;
  }

  yoshi_sprites.insert(std::pair<Animation::State, std::vector<SDL_Rect> >(Animation::State::STOPPED, stopped));
  yoshi_sprites.insert(std::pair<Animation::State, std::vector<SDL_Rect> >(Animation::State::WALKING_LEFT, l_w_sprites));
  yoshi_sprites.insert(std::pair<Animation::State, std::vector<SDL_Rect> >(Animation::State::WALKING_RIGHT, r_w_sprites));

  a_yoshi.sprites = yoshi_sprites;
  SDL_Event e;
  bool quit = false;

  if (!game.init()) {
    std::cout << "Failed to initialize" << std::endl;
  } else {

    t_yoshi.load_from_file("yoshi.png");
    a_yoshi.texture = &t_yoshi;



    SDL_Rect char_sprite[4];

    char_sprite[0].x = 0;
    char_sprite[0].y = 0;
    char_sprite[0].h = 100;
    char_sprite[0].w = 100;

    char_sprite[1].x = 0;
    char_sprite[1].y = 0;
    char_sprite[1].h = 100;
    char_sprite[1].w = 100;

    char_sprite[2].x = 0;
    char_sprite[2].y = 0;
    char_sprite[2].h = 100;
    char_sprite[2].w = 100;

    char_sprite[3].x = 0;
    char_sprite[3].y = 0;
    char_sprite[3].h = 100;
    char_sprite[3].w = 100;

    LinkTexture background;
    background.set_game(&game);
    background.load_from_file("background.png");

    LinkTexture ttr1;
    ttr1.set_game(&game);
    ttr1.load_from_file("foo.png");

    LinkTexture ttr2;
    ttr2.set_game(&game);
    ttr2.load_from_file("foo.png");

    int frame = 0;

    int loc[4];
    loc[0] = 0;
    loc[1] = 150;
    loc[2] = 300;
    loc[3] = 600;

    while (!quit) {
      while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }

      if(frame >= 600) frame = 0;

      SDL_SetRenderDrawColor(game.get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(game.get_renderer());

        a_yoshi.update();

      ++frame;
      SDL_RenderPresent(game.get_renderer());
    }
  }

  game.close();
  return 0;
}
