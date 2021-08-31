#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/typedefs.hpp>

__FARD_ENUM_CLASS__(event_type)
enum class fard::event_type {
  none = 0,
    window_closed = SDL_QUIT,
    key_pressed = SDL_KEYDOWN,
    key_released = SDL_KEYUP,
    button_pressed = SDL_MOUSEBUTTONDOWN,
    button_released = SDL_MOUSEBUTTONUP
};
