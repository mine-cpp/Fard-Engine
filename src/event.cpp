#include <SDL2/SDL.h>
#include <fard/event.hpp>

namespace fard {

  bool event_checker::on_key(const keycode __key) {
    return on_keys__[static_cast<int>(__key)];
  }

  int event_checker::mouse_x() const {
    return mouse__.x;
  }
  int event_checker::mouse_y() const {
    return mouse__.y;
  }
  bool event_checker::on_button(const buttoncode __button) const {
    return (mouse__.on_buttons & __button);
  }

  bool event_checker::on(const event_type __event) const {
    if (found_on_event(__event))
      return true;

    return false;
  }



  bool event_checker::found_on_event(const event_type __event) const {
    auto it = on_events__.find(__event);
    if (it != on_events__.end())
      return true;

    return false;
  }



  void event_handler::handle() {
    poll();
    handle_keyboard();
    handle_mouse();
  }



  void event_handler::poll() {

    while (SDL_PollEvent(&handler__)) {

      // TODO
      // add event enum, so that it'll be updated
      // in this loop

    }

  }
  void event_handler::handle_keyboard() {
    //on_keys__ = const_cast<key_array_t>(SDL_GetKeyboardState(nullptr));
  }
  void event_handler::handle_mouse() {
    //mouse__.on_buttons = SDL_GetMouseState(&(mouse__.x), &(mouse__.y));
  }

}
