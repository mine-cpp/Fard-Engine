#pragma once

#include <set>
#include <fard/utils/types.hpp>

__FARD_CLASS__(event_checker)
class fard::event_checker {
public:
  enum class event_type {
    none = 0,
    window_closed,
    key_pressed, key_released,
    button_pressed, button_released
  };

  bool on_key(const keycode_t __key);

  int mouse_x() const;
  int mouse_y() const;
  bool on_button(const button_bitset_t __button) const;

  bool on(const event_type __event) const;

private:
  friend class event_handler;

  struct mouse {
    int x, y;
    button_bitset_t on_buttons;
  };

  key_array_t on_keys__;
  mouse mouse__;
  std::set<event_type> on_events__;

  bool found_on_event(const event_type __event) const;

};

__FARD_CLASS__(event_handler)
class fard::event_handler {
public:
  void handle();

private:
  event_t handler__;

  void poll();
  void handle_keyboard();
  void handle_mouse();

};
