#include "animal.h"
#include "sheep.h"

namespace game {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path, SDL_Surface* window_surface_ptr) {

  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
  window_surface_ptr = IMG_Load(path.c_str());
  return window_surface_ptr;
}
} // namespace game

Animal::Animal(const std::string& file_path, SDL_Surface* window_surface_ptr, int speed,
               Type type) {

  this->speed = speed;
  this->type = type;
  // Should be only for sheep
  direction_x = arr[rand() % 2];
  direction_y = arr[rand() % 2];
  // InitialiZe the window_surface_ptr_ in the class
  window_surface_ptr_ = window_surface_ptr;
  // Load the texture of the animal
  image_ptr_ = game::load_surface_for(file_path, image_ptr_);
  if (!image_ptr_)
    throw std::runtime_error("Could not load image");

  // Give the animal an intial postion
  // in the range of 0 to the frame_width
  image_position.x =
      rand() % (frame_width - frame_boundary - image_ptr_->w) + frame_boundary;

  // in the range of 0 to the frame_height
  image_position.y =
      rand() % (frame_height - frame_boundary - image_ptr_->h) + frame_boundary;
  // Give the size of the rectangle
  // the width of the rectangle will be the same as width of the image
  image_position.w = image_ptr_->w;
  // the height of the rectangle will be the same as height of the image
  image_position.h = image_ptr_->h;
}

Animal::~Animal() {
  // Free the surface that has the texture for animals
  SDL_FreeSurface(image_ptr_);
}

void Animal::draw() {
  // Put the animal's image surface on the window surface
  // SDL_Rect crop;
  // crop.x = 0;
  // crop.y = 0;
  // crop.h = image_ptr_->h;
  // crop.w = image_ptr_->w;

  SDL_BlitSurface(this->image_ptr_, NULL, this->window_surface_ptr_, &image_position);
}

void Animal::move() {
  int max_height = frame_height - frame_boundary - image_ptr_->h;
  int max_width = frame_width - frame_boundary - image_ptr_->w;

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
  image_position.x += direction_x * speed;
  image_position.y += direction_y * speed;
}

void Animal::update() {
  this->move();
  this->draw();
}

int Animal::getPosx() { return image_position.x; }
int Animal::getPosy() { return image_position.y; }
std::vector<float> Animal::getDirections() {
  return {
    direction_x, direction_y
  };
}

void Animal::changeDirections(float dirx, float diry) {
  direction_x = dirx;
  direction_y = diry;
}

Type Animal::getType() { return type; }