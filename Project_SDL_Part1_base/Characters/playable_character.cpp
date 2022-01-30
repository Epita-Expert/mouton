#include "playable_character.h"

namespace image {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {

  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
  window_surface_ptr = IMG_Load(path.c_str());
  return window_surface_ptr;
}
} // namespace image

PlayableCharacter::~PlayableCharacter() {
  SDL_FreeSurface(this->image_ptr_);
}

PlayableCharacter::PlayableCharacter(const std::string& file_path,
                                     SDL_Surface* window_surface_ptr) {
  // InitialiZe the window_surface_ptr_ in the class
  this->window_surface_ptr_ = window_surface_ptr;
  this->image_ptr_ = image::load_surface_for(file_path, this->image_ptr_);
  if (!this->image_ptr_)
    throw std::runtime_error("Could not load image");

  // Give the animal an intial postion
  // in the range of 0 to the frame_width
  this->image_position.x =
      rand() % (frame_width - frame_boundary - this->image_ptr_->w) +
      frame_boundary;

  // in the range of 0 to the frame_height
  this->image_position.y =
      rand() % (frame_height - frame_boundary - this->image_ptr_->h) +
      frame_boundary;
  // Give the size of the rectangle
  // the width of the rectangle will be the same as width of the image
  this->image_position.w = this->image_ptr_->w;
  // the height of the rectangle will be the same as height of the image
  this->image_position.h = this->image_ptr_->h;

  this->speed = 5;
  this->image_direction = Direction::NONE;
  this->direction_x = 0.0;
  this->direction_y = 0.0;
}

void PlayableCharacter::handle_events(SDL_Event const& event) {

  switch (event.type) {
  case SDL_KEYDOWN:
    Uint8 const* keys = SDL_GetKeyboardState(nullptr);

    if (keys[SDL_SCANCODE_W] == 1) {
      image_direction = Direction::UP;
    } else if (keys[SDL_SCANCODE_S] == 1) {
      image_direction = Direction::DOWN;
    } else if (keys[SDL_SCANCODE_A] == 1) {
      image_direction = Direction::LEFT;
    } else if (keys[SDL_SCANCODE_D] == 1) {
      image_direction = Direction::RIGHT;
    } else {
      image_direction = Direction::NONE;
    }
    break;
  }
}

void PlayableCharacter::move() {
  int max_height = frame_height - frame_boundary - this->image_ptr_->h;
  int max_width = frame_width - frame_boundary - this->image_ptr_->w;
  switch (image_direction) {
  case Direction::NONE:
    direction_x += 0.0;
    direction_y += 0.0;
    break;
  case Direction::UP:
    if (image_position.y >= frame_boundary) {
      direction_y -= 1;
    } else {
      direction_x += 0.0;
      direction_y += 0.0;
    }
    break;
  case Direction::DOWN:
    if (image_position.y <= max_height) {
      direction_y += 1;
    } else {
      direction_x += 0.0;
      direction_y += 0.0;
    }
    break;
  case Direction::LEFT:
    if (image_position.x >= frame_boundary) {
      direction_x -= 1;
    } else {
      direction_x += 0.0;
      direction_y += 0.0;
    }
    break;
  case Direction::RIGHT:
    if (image_position.x <= max_width) {
      direction_x += 1;
    } else {
      direction_x += 0.0;
      direction_y += 0.0;
    }
    break;
  }

  image_position.x = direction_x * speed;
  image_position.y = direction_y * speed;
}

void PlayableCharacter::draw() {
  SDL_Rect crop, positionFond;
  crop.x = 0;
  crop.y = 0;
  crop.h = this->image_ptr_->h;
  crop.w = this->image_ptr_->w;
  SDL_BlitSurface(this->image_ptr_, &crop, this->window_surface_ptr_, &image_position);
}

void PlayableCharacter::stop() { image_direction = Direction::NONE; }