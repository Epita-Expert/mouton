#pragma once
#include "animal.h"
#include "../Game/ground.h"
#include "math.h"

/**
 * class Wolf
 * method - constructor
 */
class Wolf : public Animal {
public:
  // Ctor
  Wolf(SDL_Surface* window_surface_ptr_);

  void move(std::vector< std::unique_ptr<Animal> > animals);

  int get_closest_prey (std::vector< std::unique_ptr<Animal> > animals);
  // Dtor
  ~Wolf();
};