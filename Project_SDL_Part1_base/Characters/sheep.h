#pragma once
#include "animal.h"
/**
 * Class Sheep - derived from Animal
 */
class Sheep : public Animal {
private:
  int sex;
  int growth_cooldown;

public:
  int offspring_cooldown;
  int boost_cooldown;
  /**
   * Method - contructor
   * @param window_surface_ptr_ pointer to SDL_Surface
   */
  Sheep(SDL_Surface* window_surface_ptr_);
  /**
   * Method - detroyer
   */
  ~Sheep();
  // implement functions that are purely virtual in base class
  int getSex();
  void grow();
  void update();
  void move();
  int canHaveOffspring();
  std::unique_ptr<Animal> getOffspring(SDL_Surface* window_surface_ptr_);
};