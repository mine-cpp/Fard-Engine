#pragma once

#include <queue>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <utils/fardtypes.hpp>
#include <render_system/color.hpp>
#include <render_system/image.hpp>

namespace fard { class render_system; }

class fard::render_system {
private:
  render_system() { }
  ~render_system() { }

  using render_queue_t = std::queue<image>;
  static fard::window_t       window__;
  static fard::renderer_t     renderer__;
  static fard::color          clear_color__;
  static render_queue_t       render_queue__;

  static void clear();
  static void render(const fard::image& img);
  static void update() { SDL_RenderPresent(renderer__); }

public:
  static fard::color clear_color() { return clear_color__; }

  static SDL_Texture* load_texture(const char* path) { return IMG_LoadTexture(renderer__, path); }
  static void add_to_queue(const fard::image img) { render_queue__.push(img); }

  static void init(
		   const fard::color clear_color = { },
		   const char* title = "window", const int x = SDL_WINDOWPOS_CENTERED, const int y = SDL_WINDOWPOS_CENTERED, const int w = 690, const int h = 690, const Uint32 w_flags = SDL_WINDOW_SHOWN,
		   const int index = -1, const Uint32 r_flags = SDL_RENDERER_ACCELERATED
		   );
  static void work();
  static void quit();

};

#ifdef __FARD_INTERN__

fard::window_t                      fard::render_system::window__;
fard::renderer_t                    fard::render_system::renderer__;
fard::color                         fard::render_system::clear_color__;
fard::render_system::render_queue_t fard::render_system::render_queue__ { };

#endif
