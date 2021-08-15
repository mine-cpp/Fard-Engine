#pragma once

#include <utils/fardtypes.hpp>

namespace fard { struct color; }

struct fard::color {
  fard::uint8 r = 0,
    g = 0,
    b = 0,
    a = 255;
};
