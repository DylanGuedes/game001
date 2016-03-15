#ifndef SDL_MODULES_H
#define SDL_MODULES_H

namespace SDL
{
  bool init()
  {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cout << SDL_GetError();
      success = false;
    } else {
      if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cout << "Linear texture disabled!" << std::endl;
      }
    }

    return success;
  }

  void quit()
  {
    IMG_Quit();
    SDL_Quit();
  }
};
#endif
