#pragma once

#include <fard/utils/types.hpp>

__FARD_STRUCT__(image)

struct fard::image {
  texture_t texture;
  rect_t des = nullptr,
    src = nullptr;
  double angle = 0.0;
  point_t center = nullptr;
  flip_t flip = SDL_FLIP_NONE;
};
