#pragma once

#include <cstdint>
#include <SDL2/SDL.h>

#define __FARD_STRUCT__(fard_struct) namespace fard { struct fard_struct; }
#define __FARD_CLASS__(fard_class)   namespace fard { class fard_class; }

namespace fard {

  using int8   = std::int8_t;
  using int16  = std::int16_t;
  using int32  = std::int32_t;
  using int64  = std::int64_t;
  using uint8  = std::uint8_t;
  using uint16 = std::uint16_t;
  using uint32 = std::uint32_t;
  using uint64 = std::uint64_t;

  using window_t       = SDL_Window*;
  using renderer_t     = SDL_Renderer*;

  using texture = SDL_Texture*;
  using rect    = SDL_Rect*;
  using point   = SDL_Point*;
  using flip    = SDL_RendererFlip;

}
