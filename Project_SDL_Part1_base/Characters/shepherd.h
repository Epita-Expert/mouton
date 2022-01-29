#pragma once
#include "playable_character.h"

class Shepherd : public PlayableCharacter {
public:
  Shepherd(SDL_Surface* window_surface_ptr);

  ~Shepherd();
};