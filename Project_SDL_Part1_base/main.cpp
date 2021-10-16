#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr) {
  window_surface_ptr_ = window_surface_ptr;
  image_ptr_ = IMG_Load(file_path.c_str());
  if (!image_ptr_)
    throw std::runtime_error("Could not load image");
}

void animal::draw() {
  if (SDL_BlitSurface(image_ptr_, NULL, window_surface_ptr_, NULL))
    throw std::runtime_error("Could not apply texture.");
  return;
}

// sheep::sheep() : animal() {}

// sheep::move() {
//   if (vector[0] == 0 && vector[1] == 0) { // If no vector
//     vector[0] = rand() % 1;
//     vector[1] = rand() % 1;
//   }
//   if (offset_x == 0 || offset_x == frame_width))
//   {
//     vector[0] = -vector[0];
//   }
//   if (offset_x == 0 || offset_x == frame_height))
//   {
//     vector[1] = -vector[1];
//   }
//   offset_x = vector[0];
//   offset_y = vector[1];
// }

application::application(unsigned n_sheep, unsigned n_wolf) {
  window_ptr_ =
      SDL_CreateWindow("Mouton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       frame_width, frame_height, SDL_WINDOW_OPENGL);
  if (!window_ptr_)
    throw std::runtime_error(std::string(SDL_GetError()));

  window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

  if (!window_surface_ptr_)
    throw std::runtime_error(std::string(SDL_GetError()));
}

int application::loop(unsigned period) {

  // renderer_ptr_ = SDL_CreateRenderer(
  //     window_ptr, -1,
  //     SDL_RENDERER_ACCELERATED |
  //         SDL_RENDERER_PRESENTVSYNC); // SDL_RENDERER_ACCELERATED

  // if (!renderer_ptr_)
  //   throw std::runtime_error(std::string(SDL_GetError()));
  // SDL_SetRenderDrawColor(renderer_ptr_, 255, 0, 0, 255);

  // auto surf = IMG_Load("../media/herbe.png");
  // if (!surf)
  //   throw std::runtime_error("Could not load image");

  auto rect = SDL_Rect{0, 0, frame_width, frame_height};
  SDL_FillRect(window_surface_ptr_, &rect, 0x0000FF91);


  animal sheep1("../media/sheep.png", window_surface_ptr_);
  sheep1.draw();

  // auto sheep_surf = IMG_Load("../media/sheep.png");
  // if (!sheep_surf)
  //   throw std::runtime_error("Could not load image");

  // if (SDL_BlitSurface(sheep_surf, NULL, window_surface_ptr_, NULL))
  //   throw std::runtime_error("Could not apply texture.");

  // sheep sheep1('../media/sheep.png', )

  auto start = SDL_GetTicks();
  bool running = true;
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
    SDL_UpdateWindowSurface(window_ptr_);
    // SDL_RenderClear(renderer_ptr_);
    // SDL_RenderPresent(renderer_ptr_);
  }
  return 0;
}

application::~application() {
  // SDL_DestroyRenderer(renderer_ptr_);
  SDL_DestroyWindow(window_ptr_);
  IMG_Quit();
  SDL_Quit();
}

animal::~animal() { SDL_FreeSurface(image_ptr_); }
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