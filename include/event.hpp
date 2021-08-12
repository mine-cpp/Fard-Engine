#pragma once

#include <SDL2/SDL.h>

class event_system {
private:
  event_system() { }
  ~event_system() { }

  static bool running__;
  static bool pause__;
  static SDL_Event event__;
  static Uint8* keys__;
  static int mouse_x__;
  static int mouse_y__;
  static Uint32 buttons__;

public:
  static bool running() { return running__; }
  static bool pause() { return pause__; }
  static SDL_Event event() { return event__; }
  static const Uint8* keys() { return keys__; }
  static int mouse_x() { return mouse_x__; }
  static int mouse_y() { return mouse_y__; }
  static Uint32 buttons() { return buttons__; }

  static bool key(const SDL_Scancode k) { return keys__[k]; }

  static void work() {

    while (SDL_PollEvent(&event__)) {

    }

    keys__ = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
    buttons__ = SDL_GetMouseState(&mouse_x__, &mouse_y__);

  }

};
