#pragma once

#include <fard/utils/types.hpp>
#include <fard/image.hpp>

__FARD_CLASS__(window)
class fard::window {
public:
  struct transform {
    int x = SDL_WINDOWPOS_CENTERED,
      y = SDL_WINDOWPOS_CENTERED,
      w = 690,
      h = 690;
  };

  struct flags {
    uint32_t window = SDL_WINDOW_SHOWN,
      renderer = SDL_RENDERER_ACCELERATED;
  };

  struct properties {
    string_t title = "Window";
    window::transform transform = { };
    int index = -1;
    window::flags flags = { };
  };

  struct color {
    uint8_t r = 0,
      g = 0,
      b = 0,
      a = 255;
  };



  window(const properties __properties);
  ~window();

  void change_clear_color(const color __new_color);

  void clear() const;
  void draw(const image& __img) const;
  void update() const;

  texture_t* load_texture(const string_t __path);

private:
  window_t* create_window(const properties __properties) const;
  renderer_t* create_renderer(const properties __properties) const;

  window_t* window__;
  renderer_t* renderer__;
  color clear_color__;

};
