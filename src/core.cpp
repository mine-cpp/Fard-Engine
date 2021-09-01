#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <fard/core.hpp>

static constexpr int sdl_flags = SDL_INIT_EVERYTHING;
static constexpr int img_flags = IMG_INIT_PNG |
  IMG_INIT_PNG |
  IMG_INIT_TIF;
static constexpr int mix_flags = MIX_INIT_FLAC |
  MIX_INIT_MOD |
  MIX_INIT_MP3 |
  MIX_INIT_OGG;

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
static void init_mix() {
  bool initted = (Mix_Init(mix_flags) & mix_flags);
  if (!initted)
    throw "ERROR: Could not initialize SDL_mixer";
}

void fard::init() {
  try {
    init_sdl();
    init_img();
    init_mix();
  }
  catch(const char* error) {
    std::cerr << error << std::endl;
  }

}
void fard::quit() {
  SDL_Quit();
  IMG_Quit();

  while(Mix_Init(0))
    Mix_Quit();

}
