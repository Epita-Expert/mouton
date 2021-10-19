// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>

void init() {
  // Initialize SDL
  std::cout << "Step 1" << std::endl;
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));
  std::cout << "Step 2" << std::endl;

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
  std::cout << "Step 3" << std::endl;
}

namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.
SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {
  window_surface_ptr = IMG_Load(path.c_str());
  if (!window_surface_ptr)
    throw std::runtime_error("Could not load image");
  return window_surface_ptr;
  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
}
} // namespace

// animal
animal::animal(const std::string& file_path, SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
  load_surface_for(file_path, this->image_ptr_);
  srand(time(NULL));

  int speed = 0;
  for (int count = 0; count < 2; count++) {
    while (speed == 0) {
      // speed = rand() % 2 - 1;
      speed = 10;
    }

    vector[count] = speed;
  }
  this->offset_x = vector[0];
  this->offset_y = vector[1];
  std::cout << "Vector 1 is:" << vector[0] << std::endl;
  std::cout << "Vector 2 is:" << vector[1] << std::endl;
}
animal::~animal() { SDL_FreeSurface(this->image_ptr_); }

void animal::draw() {
  auto rect = SDL_Rect{this->offset_x, this->offset_y, 200, 200};
  // this->rect_ = &rect;
  Uint32 color = SDL_MapRGB(this->window_surface_ptr_->format, 255, 0, 25);
  SDL_FillRect(this->window_surface_ptr_, &rect, color);

  // if (SDL_BlitSurface(this->image_ptr_, NULL, this->window_surface_ptr_,
  // &rect))
  //   throw std::runtime_error("Could not apply texture.");

  SDL_BlitScaled(this->image_ptr_, NULL, this->window_surface_ptr_, &rect);

  return;
}

void animal::move() {
  // if (this->offset_x == 0 || this->offset_x == frame_width) {
  //   vector[0] = -vector[0];
  // }
  // if (this->offset_x == 0 || this->offset_x == frame_height) {
  //   vector[1] = -vector[1];
  // }
  this->offset_x = this->offset_x + 1;
  this->offset_y = this->offset_y + 1;
  std::cout << "Vector 1 is:" << this->offset_x << std::endl;
  std::cout << "Vector 2 is:" << this->offset_y << std::endl;
  return;
}

// ground
ground::ground(SDL_Surface* window_surface_ptr) {
  this->window_surface_ptr_ = window_surface_ptr;
  auto rect = SDL_Rect{0, 0, frame_width, frame_height};
  this->rect_ = &rect;
  this->color = SDL_MapRGB(window_surface_ptr->format, 25, 255, 0);
}

ground::~ground() { delete &animals; }

void ground::add_animal(animal animal) { this->animals.push_back(animal); }

void ground::update(SDL_Window* window_ptr_) {
  SDL_FillRect(this->window_surface_ptr_, this->rect_, this->color);
  for (auto& animal : this->animals) {
    animal.move();
    animal.draw();
  }
  SDL_UpdateWindowSurface(window_ptr_);
  //  for(int i = 0; i<animals.size(); ++i) {
  //    animals[i].draw();
  //  }
}

// application
application::application(unsigned n_sheep, unsigned n_wolf) {
  this->window_ptr_ =
      SDL_CreateWindow("Mouton", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       frame_width, frame_height, SDL_WINDOW_OPENGL);
  if (!this->window_ptr_)
    throw std::runtime_error(std::string(SDL_GetError()));

  this->window_surface_ptr_ = SDL_GetWindowSurface(this->window_ptr_);

  if (!this->window_surface_ptr_)
    throw std::runtime_error(std::string(SDL_GetError()));
}

application::~application() {
  SDL_DestroyWindow(this->window_ptr_);
  IMG_Quit();
  SDL_Quit();
}