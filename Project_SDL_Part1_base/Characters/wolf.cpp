#include "wolf.h"

Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_) {
  this->speed = 2.3;
}

Wolf::~Wolf() {}