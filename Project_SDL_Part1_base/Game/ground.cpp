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

    for (auto& b: this->animals) {
      if (a.get() == b.get()) continue; // Si se sont les meme animaux
      if (abs(a->getPosx() - b->getPosx()) > 10 || abs(a->getPosy() - b->getPosy()) > 10) continue;// S'ils ne sont pas a cote
      if (a->getType() != Type::SHEEP || b->getType() != Type::SHEEP) continue; // S'ils ne sont pas des moutons
      std::cout << "[Logger] Sheep " << a.get() << " and " << b.get() << " met " << std::endl;
      Sheep * s1 = dynamic_cast<Sheep*>(a.get());
      Sheep * s2 = dynamic_cast<Sheep*>(b.get()); 
      if (s1->getSex() == s2->getSex()) continue; // S'ils ont le meme sexe
      if (s1->getSex() == 0 && s1->offspring_cooldown == 0) {
        s1->offspring_cooldown = 10;
        std::unique_ptr<Animal> sheep(new Sheep(this->window_surface_ptr_));
        this->add_animal(std::move(sheep));
      } else if (s2->getSex() == 0 && s2->offspring_cooldown == 0) {
        s2->offspring_cooldown = 10;
        std::unique_ptr<Animal> sheep(new Sheep(this->window_surface_ptr_));
        this->add_animal(std::move(sheep));
      } else {
        std::cout << "[Logger] Female is recovering" << std::endl;
      }
    }

    a->update();
  }
}