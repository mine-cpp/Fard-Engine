#pragma once

#include <utils/fardtypes.hpp>
#include <image.hpp>

__FARD_CLASS__(Window)

class fard::Window {
public:
  struct Flags {
    fard::uint32_t window = SDL_WINDOW_SHOWN,
      renderer = SDL_RENDERER_ACCELERATED;
  };

  struct Properties {
    fard::string_t title = "Window";
    int x = SDL_WINDOWPOS_CENTERED,
      y = SDL_WINDOWPOS_CENTERED,
      w = 690,
      h = 690,
      index = -1;
    Flags flags = { };
  };

  struct Color {
    uint8_t r = 0,
      g = 0,
      b = 0,
      a = 255;
  };



  Window(const Properties properties);
  ~Window();

  void change_clear_color(const Color new_color);

  void clear() const;
  void draw(const Image& image) const;
  void update() const;

  friend texture_t load_texture(const Window window, const char* path);

private:
  window_t create_window(const Properties properties) const;
  renderer_t create_renderer(const Properties properties) const;

  window_t window__;
  renderer_t renderer__;
  Color clear_color__;

};
