#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <map>
#include "link_texture.h"

class Animation
{
  private:

  public:
    int walking_frames;
    int actual_walking_frame;
    std::map<int, std::vector<SDL_Rect> > sprites;

    LinkTexture *texture;
    Animation();
    enum State {
      STOPPED = 0,
      WALKING_LEFT = 1,
      WALKING_RIGHT = 2
    };

    Animation::State state;

    void update();
};

#endif
