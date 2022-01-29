#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "../constants.h"
#include "../Characters/animal.h"
#include "../Characters/wolf.h"
#include "../Characters/sheep.h"
#include "../Characters/playable_character.h"


// The "ground" on which all the animals live (like the std::vector
// in the zoo example).
class ground {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  // Some attribute to store all the wolves and sheep
  std::vector< std::unique_ptr<Animal> > animals;

  std::vector< std::unique_ptr<PlayableCharacter> > playableCharacters;
  


public:
  ground(SDL_Surface* window_surface_ptr); // todo: Ctor
  ~ground(); // todo: Dtor, again for clean up (if necessary)
  void add_animal(std::unique_ptr<Animal> animal); // todo: Add an animal
  void add_playable_character(std::unique_ptr<PlayableCharacter> playableCharacter);
  void update(); // todo: "refresh the screen": Move animals and draw them
                 // Possibly other methods, depends on your implementation
};