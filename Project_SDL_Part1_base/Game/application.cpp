#include "application.h"

extern int DEBUG;

application::application(unsigned n_sheep, unsigned n_wolf) {
  // creation of the window
  this->window_ptr_ =
      SDL_CreateWindow("Sheep and Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       frame_width, frame_height, 0);
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
  std::unique_ptr<Ground> playing_ground(new Ground(this->window_surface_ptr_));
  this->playing_ground = std::move(playing_ground);

  // Loop to instance all the sheeps
  for (int i = 0; i < n_sheep; i++) {
    // std::unique_ptr<Animal> sheep = std::make_unique<Sheep>(this->window_surface_ptr_);
    std::unique_ptr<Animal> sheep(new Sheep(this->window_surface_ptr_));
    this->playing_ground->add_animal(std::move(sheep));
  }

  // Loop to instance all the wolves
  for (int i = 0; i < n_wolf; i++) {
    // std::unique_ptr<Animal> wolf = std::make_unique<Wolf>(this->window_surface_ptr_);
    std::unique_ptr<Animal> wolf(new Wolf(this->window_surface_ptr_));
    this->playing_ground->add_animal(std::move(wolf));
  }

  this->movement_timer = 0;
  if (DEBUG) std::cout << "[DEBUG] Application created" << std::endl;
}

// DESTRUCTOR
application::~application() {
  // Destroy the window
  SDL_DestroyWindow(this->window_ptr_);
}

// LOOP
int application::loop(unsigned period) {
  auto start = SDL_GetTicks();
  bool running = true;
  int count = 0;

  TTF_Init();
  TTF_Font* font = TTF_OpenFont("../font/Arial.ttf", 32);
  SDL_Color couleurNoir = { 0, 0, 0 };
  SDL_Surface* textSurface = NULL;

  // make a playable character
  std::unique_ptr<Shepherd> shepherd(new Shepherd(this->window_surface_ptr_));
  // std::unique_ptr<Shepherd> shepherd =
  //     std::make_unique<Shepherd>(this->window_surface_ptr_);

  while (running && (SDL_GetTicks() - start < period * 1000)) {
    while (SDL_PollEvent(&window_event_)) {
      shepherd->handle_events(window_event_);
      this->movement_timer = 0;
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

    if (movement_timer <= 25) {
      shepherd->move();
      shepherd->draw();
    } else {
      shepherd->stop();
    }
    shepherd->draw();

    this->playing_ground->game_score();
    std::string var = std::to_string(this->playing_ground->number_of_sheep) + " Sheeps /" + std::to_string(this->playing_ground->number_of_wolf) + " Wolfs";
    textSurface = TTF_RenderText_Blended(font, var.c_str(), couleurNoir);
    
    SDL_Rect position;
    position.x = 10;
    position.y = 10;
    SDL_BlitSurface(textSurface, NULL, this->window_surface_ptr_, &position); /* Blit du texte */
    
    // update the window
    SDL_UpdateWindowSurface(this->window_ptr_);

    // Print every render the number of render
    // std::cout << "Window updated " << count << "times" << std::endl;
    movement_timer++;
    count++;
    SDL_Delay(1000 / frame_rate); // Run the game at 60Hz
  }
  this->playing_ground->game_score();
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_FreeSurface(textSurface);
  return 0;
}
