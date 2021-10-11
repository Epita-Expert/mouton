#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

application::application(unsigned n_sheep, unsigned n_wolf) {
  SDL_Window* window_ptr_;
  SDL_Surface* window_surface_ptr_;
  SDL_Event window_event_;

  SDL_Renderer* renderer;

  auto window_ptr =
      SDL_CreateWindow("Mouton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       frame_width, frame_height, SDL_WINDOW_OPENGL);
  if (!window_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);

  if (!window_surface_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  renderer = SDL_CreateRenderer(
      window_ptr_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  bool running = true;
  while (running) {
    SDL_Delay(5000);
    while (SDL_PollEvent(&window_event_)) {
      if (window_event_.type == SDL_QUIT) {
        running = false;
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyWindow(window_ptr_);
  SDL_DestroyRenderer(renderer);
}

application::~application() {}

int main(int argc, char* argv[]) {

  std::cout << "Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  init();

  std::cout << "Done with initilization" << std::endl;

  application my_app(std::stoul(argv[1]), std::stoul(argv[2]));

  std::cout << "Created window" << std::endl;

  // int retval = my_app.loop(std::stoul(argv[3]));

  // std::cout << "Exiting application with code " << retval << std::endl;

  SDL_Quit();

  return 0;
}

// int main() {
//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_Window *window;
//     SDL_Renderer *renderer;
//     window = SDL_CreateWindow("SDL Project", SDL_WINDOWPOS_CENTERED,
//     SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_OPENGL); renderer =
//     SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
//     SDL_RENDERER_PRESENTVSYNC); SDL_SetRenderDrawColor(renderer, 255, 0, 0,
//     255); bool running = true; SDL_Event event; while (running) {
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = false;
//             }
//         }
//         SDL_RenderClear(renderer);
//         SDL_RenderPresent(renderer);
//     }
//     // SDL_Delay(5000);
//     SDL_DestroyWindow(window);
//     SDL_DestroyRenderer(renderer);
//     return 0;
// }

// class String {
// private:
//   char* s;
//   int size;

// public:
//   String(char*); // constructor
//   ~String();     // destructor
// };

// String::String(char* c) {
//   size = strlen(c);
//   s = new char[size + 1];
//   strcpy(s, c);
// }
// String::~String() { delete[] s; }