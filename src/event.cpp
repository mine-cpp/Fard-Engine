#include <SDL2/SDL.h>
#include <fard/event.hpp>

namespace fard {

  bool event_handler::is_running() const {
    return running__;
  }
  bool event_handler::is_paused() const {
    return paused__;
  }

  bool event_handler::on_key(const keycode_t __key) {
    return on_keys__[__key];
  }

  int event_handler::mouse_x() const {
    return mouse__.x;
  }
  int event_handler::mouse_y() const {
    return mouse__.y;
  }
  bool event_handler::on_button(const button_bitset_t __button) const {
    return (mouse__.on_buttons & __button);
  }

  void event_handler::handle() {
    poll();
    handle_keyboard();
    handle_mouse();
  }



  void event_handler::poll() {

    while (SDL_PollEvent(&event__)) {

      // TODO
      // add event enum, so that it'll be updated
      // in this loop

    }

  }
  void event_handler::handle_keyboard() {
    on_keys__ = const_cast<key_array_t>(SDL_GetKeyboardState(nullptr));
  }
  void event_handler::handle_mouse() {
    mouse__.on_buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));
  }

}
