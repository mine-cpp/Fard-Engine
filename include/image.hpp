#pragma once

#include <utils/fardtypes.hpp>

__FARD_STRUCT__(Image)

struct fard::Image {
  fard::texture_t texture;
  fard::rect_t des = nullptr,
    src = nullptr;
  double angle = 0.0;
  fard::point_t center = nullptr;
  fard::flip_t flip = SDL_FLIP_NONE;
};
