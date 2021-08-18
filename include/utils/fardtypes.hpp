#pragma once

#include <string>
#include <cstdint>
#include <SDL2/SDL.h>

#define __FARD_STRUCT__(fard_Struct) namespace fard { struct fard_Struct; }
#define __FARD_CLASS__(fard_Class)   namespace fard { class fard_Class; }

namespace fard {

  using string = std::string;

  using int8   = std::int8_t;
  using int16  = std::int16_t;
  using int32  = std::int32_t;
  using int64  = std::int64_t;
  using uint8  = std::uint8_t;
  using uint16 = std::uint16_t;
  using uint32 = std::uint32_t;
  using uint64 = std::uint64_t;

  using window_t   = SDL_Window*;
  using renderer_t = SDL_Renderer*;

  using texture = SDL_Texture*;
  using rect    = SDL_Rect*;
  using point   = SDL_Point*;
  using flip    = SDL_RendererFlip;

  using keycode_t = SDL_Scancode;

}
