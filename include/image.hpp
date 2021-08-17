#pragma once

#include <utils/fardtypes.hpp>

__FARD_STRUCT__(Image)

struct fard::Image {
  fard::texture texture;
  fard::rect des = nullptr,
    src = nullptr;
  double angle = 0.0;
  fard::point center = nullptr;
  fard::flip flip = SDL_FLIP_NONE;
};
