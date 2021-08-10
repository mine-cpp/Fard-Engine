#pragma once

#include <queue>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct color {
  Uint8 r = 0,
    g = 0,
    b = 0,
    a = 255;
};

struct image {
  SDL_Texture* texture;
  SDL_Rect* des = nullptr,
    * src = nullptr;
  double angle = 0.0;
  SDL_Point* center = nullptr;
  SDL_RendererFlip flip = SDL_FLIP_NONE;
};

class render_system {
private:
  render_system() { }
  ~render_system() { }

  static SDL_Window* window__;
  static SDL_Renderer* renderer__;
  static color clear_color__;
  static std::queue<image> render_queue__;

  static void clear() {
    SDL_SetRenderDrawColor(renderer__, clear_color__.r, clear_color__.g, clear_color__.b, clear_color__.a);
    SDL_RenderClear(renderer__);  
  }
  static void render(const image& img) { SDL_RenderCopyEx(renderer__, img.texture, img.src, img.des, img.angle, img.center, img.flip); }
  static void update() { SDL_RenderPresent(renderer__); }

public:
  static void* window() { return window__; }
  static void* renderer() { return renderer__; }
  static color clear_color() { return clear_color__; }

  static void add_to_queue(const image img) { render_queue__.push(img); }

  static void init(
		  const color clear_color = { },
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

SDL_Window* render_system::window__;
SDL_Renderer* render_system::renderer__;
color render_system::clear_color__;
std::queue<image> render_system::render_queue__ { };

#endif
