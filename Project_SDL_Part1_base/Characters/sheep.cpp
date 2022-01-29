#include "sheep.h"

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_) {
  this->speed = 1;
  this->sex = rand() % 2;
  this->boost_cooldown = 0;
  this->offspring_cooldown = 0;
}

Sheep::~Sheep() {}