#pragma once

#include <SDL2/SDL.h>

namespace fard { struct color; }

struct fard::color {
  Uint8 r = 0,
    g = 0,
    b = 0,
    a = 255;
};
