#include "game.h"

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