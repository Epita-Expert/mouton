#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "../Characters/animal.h"
#include "../Characters/playable_character.h"
#include "../Characters/sheep.h"
#include "../Characters/shepherd.h"
#include "../Characters/wolf.h"
#include "../constants.h"

// The "ground" on which all the animals live (like the std::vector
// in the zoo example).
class Ground {
private:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface* window_surface_ptr_;

  // Some attribute to store all the wolves and sheeps
  std::vector<std::unique_ptr<Animal>> animals;
  std::vector<std::unique_ptr<PlayableCharacter>> playableCharacters;

public:
  int number_of_sheep;
  int number_of_wolf;
  Ground(SDL_Surface* window_surface_ptr); // todo: Ctor
  ~Ground(); // todo: Dtor, again for clean up (if necessary)
  void add_animal(std::unique_ptr<Animal> animal, Type); // todo: Add an animal
  void numberOfAnimals(Type); // count number of specific animal
  void
  add_playable_character(std::unique_ptr<PlayableCharacter> playableCharacter);
  void update(); // todo: "refresh the screen": Move animals and draw them
                 // Possibly other methods, depends on your implementation
};