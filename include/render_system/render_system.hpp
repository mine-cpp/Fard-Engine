#pragma once

#include <queue>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <render_system/color.hpp>
#include <render_system/image.hpp>

namespace fard {

  using window_t       = SDL_Window*;
  using renderer_t     = SDL_Renderer*;
  using render_queue_t = std::queue<image>;

  class render_system;

}

class fard::render_system {
private:
  fard::render_system() { }
  ~fard::render_system() { }

  static fard::window_t       window__;
  static fard::renderer_t     renderer__;
  static fard::color          clear_color__;
  static fard::render_queue_t render_queue__;

  static void clear() {
    SDL_SetRenderDrawColor(renderer__, clear_color__.r, clear_color__.g, clear_color__.b, clear_color__.a);
    SDL_RenderClear(renderer__);  
  }
  static void render(const fard::image& img) { SDL_RenderCopyEx(renderer__, img.texture, img.src, img.des, img.angle, img.center, img.flip); }
  static void update() { SDL_RenderPresent(renderer__); }

public:
  static fard::color clear_color() { return clear_color__; }

  static void add_to_queue(const fard::image img) { render_queue__.push(img); }

  static void init(
		   const fard::color clear_color = { },
		   const char* title = "window", const int x = SDL_WINDOWPOS_CENTERED, const int y = SDL_WINDOWPOS_CENTERED, const int w = 690, const int h = 690, const Uint32 w_flags = SDL_WINDOW_SHOWN,
		   const int index = -1, const Uint32 r_flags = SDL_RENDERER_ACCELERATED
		   ) {
    clear_color__ = clear_color;
    window__ = SDL_CreateWindow(title, x, y, w, h, w_flags);
    renderer__ = SDL_CreateRenderer(window__, index, r_flags);

    while (!(render_queue__.empty()))
      render_queue__.pop();

  }

  static void work() {
    clear();

    while (!(render_queue__.empty())) {

      const auto& img = render_queue__.front();
      render(img);
      render_queue__.pop();

    }

    update();
  }

  static void quit() {
    SDL_DestroyWindow(window__);
    SDL_DestroyRenderer(renderer__);

    while (!(render_queue__.empty())) {

      const auto& img = render_queue__.front();
      SDL_DestroyTexture(img.texture);
      render_queue__.pop();

    }

  }

};

#ifdef __INTERN__

fard::window_t       fard::render_system::window__;
fard::renderer_t     fard::render_system::renderer__;
fard::color          fard::render_system::clear_color__;
fard::render_queue_t fard::render_system::render_queue__ { };

#endif

}
