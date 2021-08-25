#pragma once

#include <SDL2/SDL.h>
#include <fard/utils/types.hpp>

__FARD_CLASS__(EventHandler)

class fard::EventHandler {
public:
  struct Mouse {
    int x, y;
    uint32 on_buttons;
  };

private:
  EventHandler() { }
  ~EventHandler() { }

  bool running__;
  bool paused__;
  event_t event__;
  key_array_t on_keys__;
  Mouse mouse__;

public:
  bool is_running() const { return running__; }
  bool is_paused() const { return paused__; }

  bool key_on(const keycode_t keycode) { return on_keys__[keycode]; }
  bool key_off(const keycode_t keycode) { return !(on_keys__[keycode]); }

  int mouse_x() const { return mouse.x; }
  int mouse_y() const { return mouse.y; }
  bool buttons_on(const uint32 buttons) const { return (mouse__.on_buttons & buttons); }

  void handle() {

    while (SDL_PollEvent(&event__)) {

    }

    on_keys__ = const_cast<key_array_t>(SDL_GetKeyboardState(nullptr));
    mouse__.on_buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));

  }

};
