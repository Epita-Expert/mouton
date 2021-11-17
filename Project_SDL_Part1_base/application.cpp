#include "game.h"

application::application(unsigned n_sheep, unsigned n_wolf) {

  // creation of the window
  this->window_ptr_ =
      SDL_CreateWindow("Sheep and Wolf", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, frame_width, frame_height, 0);
  if (!this->window_ptr_) {
    std::cout << "Failed to create window\n";
    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    return;
  }

  // Get the Ptr of the window surface
  this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);
  if (!window_surface_ptr_) {
    std::cout << "Failed to get window's surface\n";
    std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
    return;
  }

  // Put the window in the right color
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  // Instanciation of ground
  ground* playing_ground = new ground(this->window_surface_ptr_);
  this->playing_ground = playing_ground;

  // Loop to instance all the sheeps
  for (int i = 0; i < n_sheep; i++) {
    Animal* sheep = new Sheep(this->window_surface_ptr_);
    this->playing_ground->add_animal(sheep);
  }

  for (int i = 0; i < n_wolf; i++) {
    Animal* wolf = new Wolf(this->window_surface_ptr_);
    this->playing_ground->add_animal(wolf);
  }

  // Loop to instance all the wolves
}

// DESTRUCTOR
application::~application() {
  // Destroy the window
  SDL_DestroyWindow(this->window_ptr_);
  // Free the surface of the window
  SDL_FreeSurface(this->window_surface_ptr_);
}

// LOOP
int application::loop(unsigned period) {
  auto start = SDL_GetTicks();
  bool running = true;

  int count = 0;

  while (running && (SDL_GetTicks() - start < period * 1000)) {
    while (SDL_PollEvent(&window_event_)) {
      switch (window_event_.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_WINDOWEVENT:
        break;
      }
    }
    // update the playing ground with the animals
    this->playing_ground->update();

    // update the window
    SDL_UpdateWindowSurface(this->window_ptr_);

    // Print every render the number of render
    // std::cout << "Window updated " << count << "times" << std::endl;
    count++;
    SDL_Delay(1000 / frame_rate); // Run the game at 60Hz
  }
  return 0;
}

