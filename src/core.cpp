#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fard/core.hpp>

static constexpr int sdl_flags = SDL_INIT_EVERYTHING;
static constexpr int img_flags = IMG_INIT_PNG |
  IMG_INIT_PNG |
  IMG_INIT_TIF;

static void init_sdl() {
  bool initted = !(SDL_Init(sdl_flags));
  if (!initted)
    throw "ERROR: Could not initialize SDL";
}
static void init_img() {
  bool initted = (IMG_Init(img_flags) & img_flags);
  if (!initted)
    throw "ERROR: Could not initialize SDL_image";
}

void fard::init() {
  try {
    init_sdl();
    init_img();
  }
  catch(const char* error) {
    std::cerr << error << std::endl;
  }

}
void fard::quit() {
  SDL_Quit();
  IMG_Quit();
}
