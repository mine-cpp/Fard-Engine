#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fard/window.hpp>

namespace fard {

  window::window(const properties __properties) :
    window__(nullptr), renderer__(nullptr)
  {
    window__ = create_window(__properties);
    if (!window__)
      throw "Could not create window";

    renderer__ = create_renderer(__properties);
    if (!renderer__)
      throw "Could not create renderer";
  }

  window::~window()  {
    SDL_Destroywindow(window__);
    SDL_DestroyRenderer(renderer__);
  }



  void window::change_clear_color(const color __new_color) {
    clear_color__ = __new_color;
  }



  void window::clear() const {
    SDL_SetRenderDrawColor(
			   renderer__,
			   clear_color__.r,
			   clear_color__.g,
			   clear_color__.b,
			   clear_color__.a
			   );
    SDL_RenderClear(renderer__);  
  }

  void window::draw(const image& __img) const {
    SDL_RenderCopyEx(
		     renderer__,
		     __img.texture, __image.src, __image.des,
		     __img.angle, __image.center, __image.flip
		     );
  }

  void window::update() const {
    SDL_RenderPresent(renderer__);
  }

  window_t window::create_window(const properties __properties) const {
    return SDL_Createwindow(
			    __properties.title.c_str(),
			    __properties.x, __properties.y,
			    __properties.w, __properties.h,
			    __properties.flags.window
			    );
  }

  renderer_t window::create_renderer(const properties __properties) const {
    return SDL_CreateRenderer(
			      window__,
			      __properties.index,
			      __properties.flags.renderer
			      );
  }



  texture_t window::load_texture(const string_t __path) {
    return IMG_LoadTexture(renderer__, __path.c_str());
  }

}
