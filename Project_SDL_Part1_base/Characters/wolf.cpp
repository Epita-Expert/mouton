#include "wolf.h"

Wolf::Wolf(SDL_Surface* window_surface_ptr_)
    : Animal("../media/wolf.png", window_surface_ptr_) {
  this->speed = 2.3;
  this->prey = false;
    }
    

Wolf::~Wolf(){
  
}


  void Wolf::move(std::vector< std::unique_ptr<Animal> > animals) {
    
  int max_height = frame_height - frame_boundary - this->image_ptr_->h;
  int max_width = frame_width - frame_boundary - this->image_ptr_->w;

  if (this->image_position.x <= frame_boundary) {
    this->direction_x = -this->direction_x;
    this->image_position.x = frame_boundary;
  }
  if (this->image_position.x >= max_width) {
    this->direction_x = -this->direction_x;
    this->image_position.x = max_width;
  }
  if (this->image_position.y <= frame_boundary) {
    this->direction_y = -this->direction_y;
    this->image_position.y = frame_boundary;
  }

  if (this->image_position.y >= max_height) {
    this->direction_y = -this->direction_y;
    this->image_position.y = max_height;
  }
  int prey = get_closest_prey(std::move(animals));
  if (prey > 0)
  {
  this->direction_x = animals[prey]->get_position().x;
  this->direction_y = animals[prey]->get_position().y;
  }
  this->image_position.x += this->direction_x * this->speed;
  this->image_position.y += this->direction_y * this->speed;
  
}

int Wolf::get_closest_prey (std::vector< std::unique_ptr<Animal> > animals) {
  int dist;
  int shortest;
  int index = -1;
  int i;
  for (i = 0; i < animals.size(); i++)
  {
    if (animals[i]->is_prey())
    {
      shortest=sqrt(pow(this->image_position.x - animals[i]->get_position().x,2) + pow(this->image_position.y - animals[i]->get_position().y,2));
      index = i;
      break;
    }

  }
  for (; i < animals.size(); i++)
  {
    if (animals[i]->is_prey())
    {

      dist=sqrt(pow(this->image_position.x - animals[i]->get_position().x,2) + pow(this->image_position.y - animals[i]->get_position().y,2));
      if(dist < shortest  )
      {
        index = i;
        shortest = dist;
      }

    }

  }
  return index;
}