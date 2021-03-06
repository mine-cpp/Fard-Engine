#include <SDL2/SDL.h>
#include <fard/event.hpp>

namespace fard {

  event_checker::event_checker() :
    on_keys__(nullptr), mouse__ { },
    on_events__ { }
  { }
  event_checker::~event_checker() { }

  bool event_checker::on_key(const key_code __key) {
    return on_keys__[static_cast<int>(__key)];
  }

  int event_checker::mouse_x() const {
    return mouse__.x;
  }
  int event_checker::mouse_y() const {
    return mouse__.y;
  }
  bool event_checker::on_button(const button_code __button) const {
    return (mouse__.on_buttons & static_cast<int>(__button));
  }

  bool event_checker::on(const event_type __event) const {
    if (found_on_event(__event))
      return true;

    return false;
  }



  bool event_checker::found_on_event(const event_type __event) const {
    auto it = on_events__.find(static_cast<int>(__event));
    if (it != on_events__.end())
      return true;

    return false;
  }



  event_handler::event_handler(event_checker& __checker) :
    checker__(__checker), handler__ { }
  { }
  event_handler::~event_handler() { }

  void event_handler::handle() {
    poll();
    handle_keyboard();
    handle_mouse();
  }



  void event_handler::poll() {
    checker__.on_events__.clear();

    while (SDL_PollEvent(&handler__))
      checker__.on_events__.insert(handler__.type);

    checker__.on_events__.insert(static_cast<int>(event_type::none));
  }
  void event_handler::handle_keyboard() {
    checker__.on_keys__ = const_cast<key_t*>(SDL_GetKeyboardState(nullptr));
  }
  void event_handler::handle_mouse() {
    checker__.mouse__.on_buttons = SDL_GetMouseState(
						     &(checker__.mouse__.x),
						     &(checker__.mouse__.y)
						     );
  }

}
