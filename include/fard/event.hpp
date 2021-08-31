#pragma once

#include <set>
#include <SDL2/SDL.h>
#include <fard/utils/typedefs.hpp>
#include <fard/event/event_type.hpp>
#include <fard/event/key_code.hpp>
#include <fard/event/button_code.hpp>

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
  std::set<uint32_t> on_events__;

  bool found_on_event(const event_type __event) const;

};

__FARD_CLASS__(event_handler)
class fard::event_handler {
public:
  event_handler(event_checker& __checker);
  ~event_handler();

  void handle();

private:
  event_checker& checker__;
  event_t handler__;

  void poll();
  void handle_keyboard();
  void handle_mouse();

};
