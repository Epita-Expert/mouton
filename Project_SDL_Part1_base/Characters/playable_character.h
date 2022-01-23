#pragma once

#include "../constants.h"

class PlayableCharacter
{
public:
    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    PlayableCharacter(const std::string& file_path,SDL_Surface *window_surface_ptr);
    ~PlayableCharacter() = default;

    void handle_events(SDL_Event const &event);
    void move(double delta_time);
    void draw();
private:
    Direction    image_direction;
    SDL_Surface* window_surface_ptr_; // ptr to the surface on which we want the
                                    // playable character to be drawn, also non-owning
    SDL_Surface* image_ptr_;
    SDL_Rect     image_position;
    double       direction_x;
    double       direction_y;
};