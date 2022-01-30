#include "./Game/application.h"
#include <ctype.h>
#include <getopt.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void init() {
  if (DEBUG) std::cout << "[DEBUG] SDL initialization" << std::endl;
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
  if (DEBUG) std::cout << "[DEBUG] SDL initialized" << std::endl;
}

// bool cmdOptionExists(char** begin, char** end, const std::string& option) {
//   return std::find(begin, end, option) != end;
// }
int DEBUG = 0;

int main(int argc, char* argv[]) {

  std::cout << "[INFO] Starting up the application" << std::endl;

  if (argc < 3)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  char* cvalue = NULL;
  int c;

  while ((c = getopt(argc, argv, "dhc:")) != -1)
    switch (c) {
    case 'd':
      DEBUG = 1;
      break;
    case 'h':
      fprintf(stderr, "usuage is \n -d : for enabling debug mode \n \n -h: for usage");
      return 0;
    case 'c':
      cvalue = optarg;
      break;
    case '?':
      if (optopt == 'c')
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      return 1;
    default:
      abort();
    }

  init();
  {
    application my_app(std::stoul(argv[optind]), std::stoul(argv[optind++]));
    int retval = my_app.loop(std::stoul(argv[optind++]));
    std::cout << "[INFO] Exiting application with code " << retval << std::endl;
  }

  SDL_Quit();

  return 0;
}