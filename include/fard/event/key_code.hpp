#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/types.hpp>

__FARD_ENUM_CLASS__(key_code)
enum class fard::key_code {
  a = SDL_SCANCODE_A,
    b = SDL_SCANCODE_B,
    c = SDL_SCANCODE_C,
    d = SDL_SCANCODE_D,
    e = SDL_SCANCODE_E,
    f = SDL_SCANCODE_F,
    g = SDL_SCANCODE_G,
    h = SDL_SCANCODE_H,
    i = SDL_SCANCODE_I,
    j = SDL_SCANCODE_J,
    k = SDL_SCANCODE_K,
    l = SDL_SCANCODE_L,
    m = SDL_SCANCODE_M,
    n = SDL_SCANCODE_N,
    o = SDL_SCANCODE_O,
    p = SDL_SCANCODE_P,
    q = SDL_SCANCODE_Q,
    r = SDL_SCANCODE_R,
    s = SDL_SCANCODE_S,
    t = SDL_SCANCODE_T,
    u = SDL_SCANCODE_U,
    v = SDL_SCANCODE_V,
    w = SDL_SCANCODE_W,
    x = SDL_SCANCODE_X,
    y = SDL_SCANCODE_Y,
    z = SDL_SCANCODE_Z,

    key_1 = SDL_SCANCODE_1,
    key_2 = SDL_SCANCODE_2,
    key_3 = SDL_SCANCODE_3,
    key_4 = SDL_SCANCODE_4,
    key_5 = SDL_SCANCODE_5,
    key_6 = SDL_SCANCODE_6,
    key_7 = SDL_SCANCODE_7,
    key_8 = SDL_SCANCODE_8,
    key_9 = SDL_SCANCODE_9,
    key_0 = SDL_SCANCODE_0

  // TODO
  // add more keys
};
