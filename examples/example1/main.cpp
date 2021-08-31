#include <iostream>
#include <SDL2/SDL_image.h>
#include <fard/window.hpp>
#include <fard/event.hpp>
#include <fard/image.hpp>

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);

  fard::window::properties properties = { };
  fard::window window = fard::window(properties);

  fard::event_checker checker = fard::event_checker();
  fard::event_handler handler = fard::event_handler(checker);

  fard::image vr = { };
  vr.texture = window.load_texture("virtual_riot.png");

  bool running = true;

  while (running) {

    handler.handle();
    if (checker.on(fard::event_type::window_closed))
      running = false;

    window.clear();
    window.draw(vr);
    window.update();

  }

  SDL_Quit();
  IMG_Quit();
  return 0;
}
