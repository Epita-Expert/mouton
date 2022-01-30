#include "wolf.h"

Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_, 2.3, Type::WOLF) {}

Wolf::~Wolf() {}

void Wolf::update() {
  this->move();
  this->draw();
}