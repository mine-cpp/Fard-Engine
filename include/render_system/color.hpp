#pragma once

#include <utils/fardtypes.hpp>

__FARD_STRUCT__(color)

struct fard::color {
  fard::uint8 r = 0,
    g = 0,
    b = 0,
    a = 255;
};
