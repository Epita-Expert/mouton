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
} // namespace

PlayableCharacter::~PlayableCharacter() {
 
}

PlayableCharacter::PlayableCharacter(const std::string& file_path,SDL_Surface *window_surface_ptr){
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
}



void PlayableCharacter::handle_events(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1) {
                std::cout << "UP \n";
                image_direction = Direction::UP;
            }
            else if(keys[SDL_SCANCODE_S] == 1){
                std::cout << "DOWN \n";
                image_direction = Direction::DOWN;
            }
            else if(keys[SDL_SCANCODE_A] == 1){
                std::cout << "LEFT \n";
                image_direction = Direction::LEFT;
            }
            else if(keys[SDL_SCANCODE_D] == 1){
                std::cout << "RIGHT \n";
                image_direction = Direction::RIGHT;
            } else {
                std::cout << "NONE \n";
                image_direction = Direction::NONE;
            }   
            break;
    }
}

void PlayableCharacter::move(double delta_time)
{
    switch(image_direction)
    {
        case Direction::NONE:
            direction_x += 0.0;
            direction_y += 0.0;
            break;
        case Direction::UP:
            direction_y = direction_y - (250.0 * delta_time);
            break;
        case Direction::DOWN:
            direction_y = direction_y + (250.0 * delta_time);
            break;
        case Direction::LEFT:
            direction_x = direction_x - (250.0 * delta_time);
            break;
        case Direction::RIGHT:
            direction_x = direction_x + (250.0 * delta_time);
            break;
    }

    image_position.x = direction_x;
    image_position.y = direction_y;
}


void PlayableCharacter::draw()
{
    SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &image_position);
}

void PlayableCharacter::stop() {
    image_direction = Direction::NONE;
}