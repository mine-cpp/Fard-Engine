#include <window.hpp>

fard::Window::Window(const Properties properties) {
  window__ = SDL_CreateWindow(
			      properties.title.data(),
			      properties.x, properties.y,
			      properties.w, properties.h,
			      properties.flags.window
			      );
  renderer__ = SDL_CreateRenderer(
				  window__,
				  properties.index,
				  properties.flags.renderer
				  );
}

fard::Window::~Window() {
  SDL_DestroyWindow(window__);
  SDL_DestroyRenderer(renderer__);
}

void fard::Window::clear_screen() const {
  SDL_SetRenderDrawColor(renderer__, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
  SDL_RenderClear(renderer__);  
}

void fard::Window::render(const fard::Image& image) const {
  SDL_RenderCopyEx(
		   renderer__,
		   image.texture, image.src, image.des,
		   image.angle, image.center, image.flip
		   );
}

void fard::Window::update() const { SDL_RenderPresent(renderer__); }
