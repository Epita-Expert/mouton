#include "playable_character.h"



PlayableCharacter::PlayableCharacter(const std::string& file_path,SDL_Surface *window_surface_ptr){
    // InitialiZe the window_surface_ptr_ in the class
    this->window_surface_ptr_ = window_surface_ptr;
    // this->image_ptr_ = game::load_surface_for(file_path, this->image_ptr_);
    // if (!this->image_ptr_)
    //     throw std::runtime_error("Could not load image");

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

PlayableCharacter::~PlayableCharacter() {
  // Free the surface that has the texture for animals
  SDL_FreeSurface(this->image_ptr_);
}

void PlayableCharacter::handle_events(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                // image_direction = Direction::UP;
                std::cout << "Move up \n"; 
            else if(keys[SDL_SCANCODE_S] == 1)
                // image_direction = Direction::DOWN;
                std::cout << "Move down \n"; 
            else if(keys[SDL_SCANCODE_A] == 1)
                // image_direction = Direction::LEFT;
                std::cout << "Move left \n"; 
            else if(keys[SDL_SCANCODE_D] == 1)
                // image_direction = Direction::RIGHT;
                std::cout << "Move right \n"; 
            break;
    }
}