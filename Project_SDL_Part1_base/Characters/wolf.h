#pragma once
#include "animal.h"

#include "../constants.h"
/**
 * class Wolf
 * method - constructor
 */
class Wolf : public Animal {
public:
  // Ctor
  Wolf(SDL_Surface* window_surface_ptr_);
  // Dtor
  ~Wolf();
};