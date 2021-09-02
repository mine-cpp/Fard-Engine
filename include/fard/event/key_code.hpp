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
    non_us_backslash = SDL_SCANCODE_NONUSBACKSLASH,

    semicolon = SDL_SCANCODE_SEMICOLON,
    apostrophe = SDL_SCANCODE_APOSTROPHE,
    grave = SDL_SCANCODE_GRAVE,

    comma = SDL_SCANCODE_COMMA,
    period = SDL_SCANCODE_PERIOD,
    slash = SDL_SCANCODE_SLASH,
    non_us_slash = SDL_SCANCODE_NONUSHASH,

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
    f13 = SDL_SCANCODE_F13,
    f14 = SDL_SCANCODE_F14,
    f15 = SDL_SCANCODE_F15,
    f16 = SDL_SCANCODE_F16,
    f17 = SDL_SCANCODE_F17,
    f18 = SDL_SCANCODE_F18,
    f19 = SDL_SCANCODE_F19,
    f20 = SDL_SCANCODE_F20,
    f21 = SDL_SCANCODE_F21,
    f22 = SDL_SCANCODE_F22,
    f23 = SDL_SCANCODE_F23,
    f24 = SDL_SCANCODE_F24,

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
    up = SDL_SCANCODE_UP,

    numlock = SDL_SCANCODE_NUMLOCKCLEAR,
    clear = SDL_SCANCODE_NUMLOCKCLEAR,

    kp_divide = SDL_SCANCODE_KP_DIVIDE,
    kp_multiply = SDL_SCANCODE_KP_MULTIPLY,
    kp_minux = SDL_SCANCODE_KP_MINUS,
    kp_plus = SDL_SCANCODE_KP_PLUS,
    kp_enter = SDL_SCANCODE_KP_ENTER,
    kp_equals = SDL_SCANCODE_KP_EQUALS,
    kp_1 = SDL_SCANCODE_KP_1,
    kp_2 = SDL_SCANCODE_KP_2,
    kp_3 = SDL_SCANCODE_KP_3,
    kp_4 = SDL_SCANCODE_KP_4,
    kp_5 = SDL_SCANCODE_KP_5,
    kp_6 = SDL_SCANCODE_KP_6,
    kp_7 = SDL_SCANCODE_KP_7,
    kp_8 = SDL_SCANCODE_KP_8,
    kp_9 = SDL_SCANCODE_KP_9,
    kp_0 = SDL_SCANCODE_KP_0,
    kp_period = SDL_SCANCODE_KP_PERIOD,

    power = SDL_SCANCODE_POWER

  // TODO
  // add more keys
};
