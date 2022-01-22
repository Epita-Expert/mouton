#pragma once
#include "animal.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

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