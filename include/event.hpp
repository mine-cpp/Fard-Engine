#pragma once

#include <SDL2/SDL.h>
#include <utils/fardtypes.hpp>

__FARD_CLASS__(Event_handler)

class fard::Event_handler {
public:
  struct Mouse {
    int x, y;
    uint32 buttons;
  };

private:
  Event_handler() { }
  ~Event_handler() { }

  bool running__;
  bool paused__;
  SDL_Event event__;
  uint8* keys__;
  Mouse mouse__;

public:
  bool is_running() const { return running__; }
  bool is_paused() const { return paused__; }
  const uint8* keys() const { return keys__; }
  Mouse mouse() const { return mouse__; }

  bool key_pressed(const keycode_t keycode) { return keys__[keycode]; }
  bool key_not_pressed(const keycode_t keycode) { return !(keys__[keycode]); }

  static void handle() {

    while (SDL_PollEvent(&event__)) {

    }

    keys__ = const_cast<uint8*>(SDL_GetKeyboardState(nullptr));
    mouse__.buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));

  }

};
