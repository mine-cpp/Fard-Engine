#pragma once

#include <string>
#include <cstdint>
#include <SDL2/SDL.h>

#define __FARD_STRUCT__(fard_struct) namespace fard { struct fard_struct; }
#define __FARD_CLASS__(fard_class) namespace fard { class fard_class; }
#define __FARD_ENUM_CLASS__(fard_enum) namespace fard { enum class fard_enum; }

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

  using window_t = SDL_Window;
  using renderer_t = SDL_Renderer;

  using texture_t = SDL_Texture;
  using rect_t = SDL_Rect;
  using point_t = SDL_Point;
  using flip_t = SDL_RendererFlip;

  using key_t = uint8_t;
  using button_bitset_t = uint32_t;
  using event_t = SDL_Event;

}
