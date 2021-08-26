#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/types.hpp>

__FARD_CLASS__(event_handler)

class fard::event_handler {
public:
  struct mouse {
    int x, y;
    button_bitset_t on_buttons;
  };

  bool is_running() const { return running__; }
  bool is_paused() const { return paused__; }

  bool key_on(const keycode_t keycode) { return on_keys__[keycode]; }
  bool key_off(const keycode_t keycode) { return !(on_keys__[keycode]); }

  int mouse_x() const { return mouse__.x; }
  int mouse_y() const { return mouse__.y; }
  bool buttons_on(const uint32 buttons) const { return (mouse__.on_buttons & buttons); }

  void handle() {

    while (SDL_PollEvent(&event__)) {

    }

    on_keys__ = const_cast<key_array_t>(SDL_GetKeyboardState(nullptr));
    mouse__.on_buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));

  }

private:
  bool running__;
  bool paused__;
  event_t event__;
  key_array_t on_keys__;
  mouse mouse__;

};
