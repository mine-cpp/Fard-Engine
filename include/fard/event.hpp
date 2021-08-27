#pragma once

#include <set>
#include <fard/utils/types.hpp>

__FARD_ENUM_CLASS__(event_type)
enum class fard::event_type {
    none = 0,
    window_closed,
    key_pressed, key_released,
    button_pressed, button_released
};

__FARD_ENUM_CLASS__(key_code)
enum class fard::key_code {
  // TODO
  // add keys
};

__FARD_ENUM_CLASS__(button_code)
enum class fard::button_code {
  // TODO
  // add mouse buttons
};



__FARD_CLASS__(event_checker)
class fard::event_checker {
public:
  event_checker();
  ~event_checker();

  bool on_key(const key_code __key);

  int mouse_x() const;
  int mouse_y() const;
  bool on_button(const button_code __button) const;

  bool on(const event_type __event) const;

private:
  friend class event_handler;

  struct mouse {
    int x, y;
    button_bitset_t on_buttons;
  };



  key_t* on_keys__;
  mouse mouse__;
  std::set<event_type> on_events__;

  bool found_on_event(const event_type __event) const;

};

__FARD_CLASS__(event_handler)
class fard::event_handler {
public:
  event_handler();
  ~event_handler();

  void handle();

private:
  event_t handler__;

  void poll();
  void handle_keyboard();
  void handle_mouse();

};
