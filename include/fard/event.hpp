#pragma once

#include <fard/utils/types.hpp>

__FARD_CLASS__(event_handler)

class fard::event_handler {
public:
  struct mouse {
    int x, y;
    button_bitset_t on_buttons;
  };

  bool is_running() const;
  bool is_paused() const;

  bool key_on(const keycode_t __key);

  int mouse_x() const;
  int mouse_y() const;
  bool buttons_on(const button_bitset_t __buttons) const;

  void handle();

private:
  bool running__;
  bool paused__;
  event_t event__;
  key_array_t on_keys__;
  mouse mouse__;

};
