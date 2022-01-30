#include "sheep.h"

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_, 1, Type::SHEEP) {
  this->sex = rand() % 2;
  this->boost_cooldown = 0;
  this->offspring_cooldown = 0;
}

int Sheep::getSex() { return sex; }

Sheep::~Sheep() {}
