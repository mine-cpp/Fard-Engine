#define __FARD_INTERN__
#include <render.hpp>

void fard::render_system::clear() {
  SDL_SetRenderDrawColor(renderer__, clear_color__.r, clear_color__.g, clear_color__.b, clear_color__.a);
  SDL_RenderClear(renderer__);  
}

void fard::render_system::render(const fard::image& img) {
  SDL_RenderCopyEx(
		   renderer__,
		   img.texture, img.src, img.des,
		   img.angle, img.center, img.flip
		   );
}

void fard::render_system::init(
			       const fard::color clear_color,
			       const char* title, const int x, const int y, const int w, const int h, const Uint32 w_flags,
			       const int index, const Uint32 r_flags
			       ) {
  clear_color__ = clear_color;
  window__ = SDL_CreateWindow(title, x, y, w, h, w_flags);
  renderer__ = SDL_CreateRenderer(window__, index, r_flags);

  while (!(render_queue__.empty()))
    render_queue__.pop();

}

void fard::render_system::work() {
  clear();

  while (!(render_queue__.empty())) {

    const auto& img = render_queue__.front();
    render(img);
    render_queue__.pop();

  }

  update();
}

void fard::render_system::quit() {
  SDL_DestroyWindow(window__);
  SDL_DestroyRenderer(renderer__);

  while (!(render_queue__.empty())) {

    const auto& img = render_queue__.front();
    SDL_DestroyTexture(img.texture);
    render_queue__.pop();

  }

}
