#include "sheep.h"

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_) {
  this->speed = 1;
}

Sheep::~Sheep() {}