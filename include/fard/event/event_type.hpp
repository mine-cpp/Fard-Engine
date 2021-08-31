#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/typedefs.hpp>

__FARD_ENUM_CLASS__(event_type)
enum class fard::event_type {
  none = 0,
    window_close = SDL_QUIT,
    key_press = SDL_KEYDOWN,
    key_release = SDL_KEYUP,
    button_press = SDL_MOUSEBUTTONDOWN,
    button_release = SDL_MOUSEBUTTONUP
};
