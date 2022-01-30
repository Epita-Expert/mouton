#include "sheep.h"

Sheep::Sheep(SDL_Surface* window_surface_ptr_)
    : Animal("../media/sheep.png", window_surface_ptr_, 1, Type::SHEEP) {
  this->sex = rand() % 2;
  this->boost_cooldown = 0;
  this->offspring_cooldown = 0;
  this->growth_cooldown = 10;
  std::cout << "[Logger] Sheep " << this << " created" << std::endl;
}
Sheep::~Sheep() {}

void Sheep::grow() {
  if (this->growth_cooldown > 0)
    this->growth_cooldown--;
}

int Sheep::getSex() { return sex; }

int Sheep::canHaveOffspring() {
  if (this->growth_cooldown > 0) {
    std::cout << "[Logger] Sheep is too young" << std::endl;
    return 0; //Too young
  }
  if (this->sex == 1) {
    std::cout << "[Logger] A male can't give birth" << std::endl;
    return 0; //It's a male
  }
  if (this->offspring_cooldown > 0) {
    std::cout << "[Logger] Female is recovering" << std::endl;
    return 0; //Recovering from last offspring
  }
  return 1;
}

std::unique_ptr<Animal> Sheep::getOffspring(SDL_Surface* window_surface_ptr_) {
  this->offspring_cooldown = 10;
  std::unique_ptr<Animal> sheep(new Sheep(window_surface_ptr_));
  return sheep;
}

void Sheep::update() {
  if (this->boost_cooldown > 0)
    this->boost_cooldown--;
  if (this->offspring_cooldown > 0)
    this->offspring_cooldown--;
    this->grow();
}

void Sheep::move() {
  int max_height = frame_height - frame_boundary - image_ptr_->h;
  int max_width = frame_width - frame_boundary - image_ptr_->w;
  int boost = 1;
  if (boost_cooldown > 0) {
    boost = 2;
  }

  if (image_position.x <= frame_boundary) {
    direction_x = -direction_x;
    image_position.x = frame_boundary;
  }
  if (image_position.x >= max_width) {
    direction_x = -direction_x;
    image_position.x = max_width;
  }
  if (image_position.y <= frame_boundary) {
    direction_y = -direction_y;
    image_position.y = frame_boundary;
  }

  if (image_position.y >= max_height) {
    direction_y = -direction_y;
    image_position.y = max_height;
  }
  image_position.x += direction_x * speed * boost;
  image_position.y += direction_y * speed * boost;
}