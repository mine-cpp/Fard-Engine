#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <fard/core.hpp>
#include <fard/utils/typedefs.hpp>

static constexpr int sdl_flags = SDL_INIT_EVERYTHING,
  img_flags = IMG_INIT_PNG |
  IMG_INIT_PNG |
  IMG_INIT_TIF,
  mix_flags = MIX_INIT_FLAC |
  MIX_INIT_MOD |
  MIX_INIT_MP3 |
  MIX_INIT_OGG;

static constexpr int freq = 41100;
static constexpr fard::uint16_t format = AUDIO_U16;
static constexpr int channels = 2,
  chunksize = 4096;

static void init_sdl() {
  bool initted = !(SDL_Init(sdl_flags));
  if (!initted)
    throw "ERROR: Could not initialize SDL";
}
static void init_img() {
  bool initted = ((IMG_Init(img_flags) & img_flags) == img_flags);
  if (!initted)
    throw "ERROR: Could not initialize SDL_image";
}
static void init_mix() {
  bool initted = ((Mix_Init(mix_flags) & mix_flags) == mix_flags);
  if (!initted)
    throw "ERROR: Could not initialize SDL_mixer";
}
static void init_audio() {
  bool initted = !(Mix_OpenAudio(freq, format, channels, chunksize));
  if (!initted)
    throw "ERROR: Coul not initialize audio";
}

void fard::init() {
  init_sdl();
  init_img();
  init_mix();
  init_audio();
}
void fard::quit() {
  int times_opened = Mix_QuerySpec(nullptr, nullptr, nullptr);

  while(times_opened--)
    Mix_CloseAudio();
  while(Mix_Init(0))
    Mix_Quit();

  IMG_Quit();
  SDL_Quit();
}
