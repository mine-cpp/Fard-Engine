#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/typedefs.hpp>

__FARD_ENUM_CLASS__(button_code)
enum class fard::button_code {
  left = SDL_BUTTON_LEFT,
    right = SDL_BUTTON_RIGHT,
    middle = SDL_BUTTON_MIDDLE,
    x1 = SDL_BUTTON_X1,
    x2 = SDL_BUTTON_X2
};
