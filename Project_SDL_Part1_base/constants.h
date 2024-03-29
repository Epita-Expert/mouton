#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>

// Mode
//Log level
extern int DEBUG;

// Defintions
const double frame_rate = 60.0; // refresh rate
const double frame_time = 1. / frame_rate;
const unsigned frame_width = 1400; // Width of window in pixel
const unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
const unsigned frame_boundary = 50;

// Maximum eyesight distance
const unsigned eyesight_distance = 100;
const unsigned touch_distance = 15;

enum class Type { SHEEP, WOLF, DOG };
