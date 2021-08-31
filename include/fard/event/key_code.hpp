#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/typedefs.hpp>

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
    key_0 = SDL_SCANCODE_0,

    key_return = SDL_SCANCODE_RETURN,
    escape = SDL_SCANCODE_ESCAPE,
    backspace = SDL_SCANCODE_BACKSPACE,
    tab = SDL_SCANCODE_TAB,
    space = SDL_SCANCODE_SPACE,

    minus = SDL_SCANCODE_MINUS,
    equals = SDL_SCANCODE_EQUALS,
    left_bracket = SDL_SCANCODE_LEFTBRACKET,
    right_bracket = SDL_SCANCODE_RIGHTBRACKET,
    backslash = SDL_SCANCODE_BACKSLASH,
    nonushash = SDL_SCANCODE_NONUSHASH,

    semicolon = SDL_SCANCODE_SEMICOLON,
    apostrophe = SDL_SCANCODE_APOSTROPHE,
    grave = SDL_SCANCODE_GRAVE,

    comma = SDL_SCANCODE_COMMA,
    period = SDL_SCANCODE_PERIOD,
    slash = SDL_SCANCODE_SLASH,

    capslock = SDL_SCANCODE_CAPSLOCK,

    f1 = SDL_SCANCODE_F1,
    f2 = SDL_SCANCODE_F2,
    f3 = SDL_SCANCODE_F3,
    f4 = SDL_SCANCODE_F4,
    f5 = SDL_SCANCODE_F5,
    f6 = SDL_SCANCODE_F6,
    f7 = SDL_SCANCODE_F7,
    f8 = SDL_SCANCODE_F8,
    f9 = SDL_SCANCODE_F9,
    f10 = SDL_SCANCODE_F10,
    f11 = SDL_SCANCODE_F11,
    f12 = SDL_SCANCODE_F12,

    printscreen = SDL_SCANCODE_PRINTSCREEN,
    scrolllock = SDL_SCANCODE_SCROLLLOCK,
    pause = SDL_SCANCODE_PAUSE,
    insert = SDL_SCANCODE_INSERT,

    home = SDL_SCANCODE_HOME,
    pageup = SDL_SCANCODE_PAGEUP,
    pagedown = SDL_SCANCODE_PAGEDOWN,
    key_delete = SDL_SCANCODE_DELETE,
    end = SDL_SCANCODE_END,

    right = SDL_SCANCODE_RIGHT,
    left = SDL_SCANCODE_LEFT,
    down = SDL_SCANCODE_DOWN,
    up = SDL_SCANCODE_UP

  // TODO
  // add more keys
};
