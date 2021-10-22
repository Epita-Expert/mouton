// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <stdio.h>
#include <string>

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}

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

namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {

  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
  window_surface_ptr = IMG_Load(path.c_str());
  return window_surface_ptr;
}
} // namespace

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_) {
  this->speed = 1;
}

Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_) {
  this->speed = 2.3;
}

Animal::Animal(const std::string& file_path, SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
  this->direction_x = this->arr[rand() % 2];
  this->direction_y = this->arr[rand() % 2];

  // Load the texture of the animal
  this->image_ptr_ = load_surface_for(file_path, this->image_ptr_);
  if (!this->image_ptr_)
    throw std::runtime_error("Could not load image");

  // Give the animal an intial postion
  // in the range of 0 to the frame_width
  this->image_position.x =
      rand() % (frame_width - frame_boundary - this->image_ptr_->w) +
      frame_boundary;

  // in the range of 0 to the frame_height
  this->image_position.y =
      rand() % (frame_height - frame_boundary - this->image_ptr_->h) +
      frame_boundary;
  // Give the size of the rectangle
  // the width of the rectangle will be the same as width of the image
  this->image_position.w = this->image_ptr_->w;
  // the height of the rectangle will be the same as height of the image
  this->image_position.h = this->image_ptr_->h;
}

Animal::~Animal() {
  // Free the surface that has the texture for animals
  SDL_FreeSurface(this->image_ptr_);
}

void Animal::draw() {
  // Put the animal's image surface on the window surface
  SDL_Rect crop, positionFond;
  crop.x = 0;
  crop.y = 0;
  crop.h = this->image_ptr_->h;
  crop.w = this->image_ptr_->w;

  SDL_BlitSurface(this->image_ptr_, &crop, this->window_surface_ptr_,
                  &image_position);
}

void Animal::move() {
  int max_height = frame_height - frame_boundary - this->image_ptr_->h;
  int max_width = frame_width - frame_boundary - this->image_ptr_->w;

  if (this->image_position.x <= frame_boundary) {
    this->direction_x = -this->direction_x;
    this->image_position.x = frame_boundary;
  }
  if (this->image_position.x >= max_width) {
    this->direction_x = -this->direction_x;
    this->image_position.x = max_width;
  }
  if (this->image_position.y <= frame_boundary) {
    this->direction_y = -this->direction_y;
    this->image_position.y = frame_boundary;
  }

  if (this->image_position.y >= max_height) {
    this->direction_y = -this->direction_y;
    this->image_position.y = max_height;
  }
  this->image_position.x += this->direction_x * this->speed;
  this->image_position.y += this->direction_y * this->speed;
}


ground::ground(SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
  // Initialize the dynamic table array
  this->animals = {};
}

ground::~ground() {
  // Free the dynamic table array
  this->animals.clear();
  // delete &animals;
}

void ground::add_animal(Animal* animal) {
  // Add the type animal to the dynamic array
  this->animals.push_back(animal);
}

void ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));
  for (Animal* a : this->animals) {
    a->draw();
    a->move();
  }
}
