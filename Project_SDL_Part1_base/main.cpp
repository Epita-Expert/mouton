#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

int application::loop(unsigned period) {

  ground ground(this->window_surface_ptr_);
  animal sheep1("../media/sheep.png",this->window_surface_ptr_);
  ground.add_animal(sheep1);
  auto start = SDL_GetTicks();
  bool running = true;

  int count = 0;

  while (running && (SDL_GetTicks() - start < period)) {
    while (SDL_PollEvent(&window_event_)) {
      switch (window_event_.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_WINDOWEVENT:
        break;
      }
    }
    // SDL_UpdateWindowSurface(this->window_ptr_);
    ground.update(this->window_ptr_);
    // Print every render the number of render
    std::cout << "Window updated" << count << "times" << std::endl;
    count++;
    SDL_Delay(1000 / 60); // Run the game at 60Hz
  }
  return 0;
}


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

  int retval = my_app.loop(std::stoul(argv[3]));

  std::cout << "Exiting application with code " << retval << std::endl;

  SDL_Quit();

  return 0;
}