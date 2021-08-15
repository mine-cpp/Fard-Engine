#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace fard { struct image; }

struct fard::image {
  SDL_Texture* texture;
  SDL_Rect* des = nullptr,
    * src = nullptr;
  double angle = 0.0;
  SDL_Point* center = nullptr;
  SDL_RendererFlip flip = SDL_FLIP_NONE;
};
