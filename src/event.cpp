#include <SDL2/SDL.h>
#include <fard/event.hpp>

namespace fard {

  bool event_handler::is_running() const {
    return running__;
  }
  bool event_handler::is_paused() const {
    return paused__;
  }

  bool event_handler::key_on(const keycode_t __key) {
    return on_keys__[__key];
  }
  bool event_handler::key_off(const keycode_t __key) {
    return !(on_keys__[__key]);
  }

  int event_handler::mouse_x() const {
    return mouse__.x;
  }
  int event_handler::mouse_y() const {
    return mouse__.y;
  }
  bool event_handler::buttons_on(const button_bitset_t __buttons) const {
    return (mouse__.on_buttons & __buttons);
  }

  void event_handler::handle() {

    while (SDL_PollEvent(&event__)) {

    }

    on_keys__ = const_cast<key_array_t>(SDL_GetKeyboardState(nullptr));
    mouse__.on_buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));

  }

}
