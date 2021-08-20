#pragma once

#include <string>
#include <cstdint>
#include <SDL2/SDL.h>

#define __FARD_STRUCT__(fard_Struct) namespace fard { struct fard_Struct; }
#define __FARD_CLASS__(fard_Class) namespace fard { class fard_Class; }

namespace fard {

  using string_t = std::string;

  using int8_t = std::int8_t;
  using int16_t = std::int16_t;
  using int32_t = std::int32_t;
  using int64_t = std::int64_t;
  using uint8_t = std::uint8_t;
  using uint16_t = std::uint16_t;
  using uint32_t = std::uint32_t;
  using uint64_t = std::uint64_t;

  using window_t = SDL_Window*;
  using renderer_t = SDL_Renderer*;

  using texture_t = SDL_Texture*;
  using rect_t = SDL_Rect*;
  using point_t = SDL_Point*;
  using flip_t = SDL_RendererFlip;

  using keycode_t = SDL_Scancode;

}
