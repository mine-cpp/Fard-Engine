#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <utils/fardtypes.hpp>
#include <image.hpp>

__FARD_CLASS__(Window)

class fard::Window {
public:
  struct Flags {
    fard::uint32 window = SDL_WINDOW_SHOWN,
      renderer = SDL_RENDERER_ACCELERATED;
  };

  struct Properties {
    fard::string title = "Window";
    int x = SDL_WINDOWPOS_CENTERED,
      y = SDL_WINDOWPOS_CENTERED,
      w = 690,
      h = 690,
      index = -1;
    Flags flags = { };
  };

  struct Color {
    uint8 r = 0,
      g = 0,
      b = 0,
      a = 255;
  };

private:
  window_t   window__;
  renderer_t renderer__;

public:
  Window(const Properties properties);
  ~Window();

  Color clear_color;

  window_t window() const;
  renderer_t renderer() const;

  void clear_screen() const;
  void render(const Image& image) const;
  void update() const;
};
