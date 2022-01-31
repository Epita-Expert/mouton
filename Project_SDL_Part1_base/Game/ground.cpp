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

void Ground::game_score() {
  this->number_of_sheep = 0;
  this->number_of_wolf = 0;
  for (int i = 0; i < this->animals.size(); i++) {
    if (this->animals[i]->getType() == Type::SHEEP) {
      this->number_of_sheep++;
    }
    if (this->animals[i]->getType() == Type::WOLF) {
      this->number_of_wolf++;
    }
  }
  
  if (DEBUG) std::cout << "[DEBUG] Animals size " << (this->animals.size()) << std::endl;
  if (DEBUG) std::cout << "[DEBUG] SHEEP " << (this->number_of_sheep) << std::endl;
  if (DEBUG) std::cout << "[DEBUG] WOLF " << (this->number_of_wolf) << std::endl;
}

void Ground::add_playable_character(
    std::unique_ptr<PlayableCharacter> PlayableCharacter) {
  this->playableCharacters.push_back(std::move(PlayableCharacter));
}

void Ground::update() {
  // The ground gets repainted
  SDL_FillRect(this->window_surface_ptr_, NULL,
               SDL_MapRGB(this->window_surface_ptr_->format, 153, 255, 51));

  // for (auto& a : this->animals) {
  for (int i = 0; i < this->animals.size(); i++) {

    auto& a = this->animals[i];
    // for (auto& b : this->animals) {
    for (int j = 0 + i; j < this->animals.size(); j++) {
      // Si c'est le meme animal
      auto& b = this->animals[j];
      // if (DEBUG) std::cout << "[DEBUG] Animal " << (a->getType() == Type::WOLF) << " and "
      //           << b.get() << std::endl;

      if (a.get() == b.get())
        continue;

      // S'ils se touche
      if (abs(a->getPosx() - b->getPosx()) < touch_distance &&
          abs(a->getPosy() - b->getPosy()) < touch_distance) {
        // If it's 2 sheeps
        if (a->getType() == Type::SHEEP && b->getType() == Type::SHEEP) {
          if (DEBUG) std::cout << "[DEBUG] Sheep " << a.get() << " and " << b.get() << " have met "
                    << std::endl;
          Sheep* s1 = dynamic_cast<Sheep*>(a.get());
          Sheep* s2 = dynamic_cast<Sheep*>(b.get());
          if (s1->getSex() == s2->getSex()) {
            continue; // S'ils ont le meme sexe
          }
          if (s1->canHaveOffspring()) {
            std::unique_ptr<Animal> sheep = s1->getOffspring(this->window_surface_ptr_);
            this->add_animal(std::move(sheep));
          } else if (s2->canHaveOffspring()) {
            std::unique_ptr<Animal> sheep = s2->getOffspring(this->window_surface_ptr_);
            this->add_animal(std::move(sheep));
          }
        } 
        // Kill sheep
      }

      // S'ils se voyent
      if (abs(a->getPosx() - b->getPosx()) < eyesight_distance &&
          abs(a->getPosy() - b->getPosy()) < eyesight_distance) {
        if (a->getType() == Type::SHEEP &&
            b->getType() == Type::WOLF) { // If it's a sheep and a wolf
          if (DEBUG) std::cout << "[DEBUG] Sheep " << a.get() << " and wolf " << b.get()
                    << " have met " << std::endl;
          Sheep* sheep = dynamic_cast<Sheep*>(a.get());
          
          sheep->boost(b->getDirections());
        } else if (a->getType() == Type::WOLF && b->getType() == Type::SHEEP) {
          if (DEBUG) std::cout << "[DEBUG] Sheep and wolf " << b.get() << " and wolf " << a.get()
                    << " have met " << std::endl;
          Sheep* sheep = dynamic_cast<Sheep*>(b.get());
          sheep->boost(b->getDirections());
        }
      }
    }
    a->update();
  }
}