#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

application::application(unsigned n_sheep, unsigned n_wolf) {
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;

  SDL_Renderer* renderer_ptr_;

  auto window_ptr =
      SDL_CreateWindow("Mouton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       frame_width, frame_height, SDL_WINDOW_OPENGL);
  if (!window_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);

  if (!window_surface_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  renderer_ptr_ = SDL_CreateRenderer(
      window_ptr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //SDL_RENDERER_ACCELERATED

  if (!renderer_ptr_)
    throw std::runtime_error(std::string(SDL_GetError()));
  SDL_SetRenderDrawColor(renderer_ptr_, 255, 0, 0, 255);

  bool running = true;
  while (running) {
    while (SDL_PollEvent(&window_event_)) {
      if (window_event_.type == SDL_QUIT) {
        running = false;
      }
    }
    SDL_RenderClear(renderer_ptr_);
    SDL_RenderPresent(renderer_ptr_);
  }

  SDL_DestroyRenderer(renderer_ptr_);
  SDL_DestroyWindow(window_ptr);
}

application::~application() {}

int main(int argc, char* argv[]) {

  std::cout << "Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  std::cout << "Step 0" << std::endl;

  init();

  std::cout << "Done with initilization" << std::endl;

  application my_app(std::stoul(argv[1]), std::stoul(argv[2]));

  std::cout << "Created window" << std::endl;

  // int retval = my_app.loop(std::stoul(argv[3]));

  // std::cout << "Exiting application with code " << retval << std::endl;

  SDL_Quit();

  return 0;
}