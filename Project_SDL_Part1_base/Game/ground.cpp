#include "ground.h"
#include "../Characters/sheep.h"
Ground::Ground(SDL_Surface* window_surface_ptr) {

  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
}

Ground::~Ground() {
  // Free the dynamic table array
  this->animals.clear();
  // delete &animals;
}

void Ground::add_animal(std::unique_ptr<Animal> animal) {
  // Add the type animal to the dynamic array
  this->animals.push_back(std::move(animal));
}

void Ground::add_playable_character(
    std::unique_ptr<PlayableCharacter> PlayableCharacter) {
  this->playableCharacters.push_back(std::move(PlayableCharacter));
}

void Ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  for (auto& a : this->animals) {
    a->update();
  }
}