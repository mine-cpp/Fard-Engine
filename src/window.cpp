#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <window.hpp>

namespace fard {

  Window::Window(const Properties properties) :
    window__(nullptr), renderer__(nullptr)
  {
    window__ = create_window(properties);
    if (!window__)
      throw "Could not create window";

    renderer__ = create_renderer(properties);
    if (!renderer__)
      throw "Could not create renderer";
  }

  Window::~Window()  {
    SDL_DestroyWindow(window__);
    SDL_DestroyRenderer(renderer__);
  }



  void Window::change_clear_color(const Window::Color new_color) {
    clear_color__ = new_color;
  }



  void Window::clear() const {
    SDL_SetRenderDrawColor(
			   renderer__,
			   clear_color__.r,
			   clear_color__.g,
			   clear_color__.b,
			   clear_color__.a
			   );
    SDL_RenderClear(renderer__);  
  }

  void Window::draw(const Image& image) const {
    SDL_RenderCopyEx(
		     renderer__,
		     image.texture, image.src, image.des,
		     image.angle, image.center, image.flip
		     );
  }

  void Window::update() const {
    SDL_RenderPresent(renderer__);
  }

  window_t Window::create_window(const Window::Properties properties) const {
    return SDL_CreateWindow(
			    properties.title.data(),
			    properties.x, properties.y,
			    properties.w, properties.h,
			    properties.flags.window
			    );
  }

  renderer_t Window::create_renderer(const Window::Properties properties) const {
    return SDL_CreateRenderer(
			      window__,
			      properties.index,
			      properties.flags.renderer
			      );
  }



  texture_t load_texture(const Window window, const char* path) {
    return IMG_LoadTexture(window.renderer__, path);
  }

}
