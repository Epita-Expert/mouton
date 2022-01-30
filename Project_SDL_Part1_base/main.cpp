#include "./Game/application.h"
#include <stdio.h>
#include <string>

void init() {
  std::cout << "[Logger] SDL initialization" << std::endl;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
  std::cout << "[Logger] SDL initialized" << std::endl;
}

int main(int argc, char* argv[]) {

  std::cout << "[Logger] Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  init();
  {
    application my_app(std::stoul(argv[1]), std::stoul(argv[2]));
    int retval = my_app.loop(std::stoul(argv[3]));
    std::cout << "Exiting application with code " << retval << std::endl;
  }

  SDL_Quit();

  return 0;
}