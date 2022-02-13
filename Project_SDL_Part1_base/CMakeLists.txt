cmake_minimum_required (VERSION 3.14.0)
project ("Project_SDL_sub")

IF(WIN32)
  message(STATUS "Building for windows")

  set(SDL2_INCLUDE_DIRS "SDL2/include")
  set(SDL2IMAGE_INCLUDE_DIRS "SDL2_image/include")
  set(SDL2TTF_INCLUDE_DIRS "SDL2_ttf/include")

  # Support both 32 and 64 bit builds
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    message(STATUS "Building for 64bit")
    set(SDL2_LINK_DIRS "SDL2/lib/x64")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x64")
    set(SDL2TTF_LINK_DIRS "SDL2_ttf/lib/x64")
  else ()
    message(STATUS "Building for 32bit")
    set(SDL2_LINK_DIRS "SDL2/lib/x86")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x86")
    set(SDL2TTF_LINK_DIRS "SDL2_ttf/lib/x86")
  endif ()

  include_directories(${SDL2_INCLUDE_DIRS})
  include_directories(${SDL2IMAGE_INCLUDE_DIRS})
  include_directories(${SDL2TTF_INCLUDE_DIRS})
  link_directories(${SDL2_LINK_DIRS}, ${SDL2IMAGE_LINK_DIRS}, ${SDL2TTF_INCLUDE_DIRS})

  add_executable(SDL_part1 main.cpp ./Game/application.cpp ./Game/ground.cpp ./Characters/animal.cpp ./Characters/sheep.cpp ./Characters/wolf.cpp ./Characters/playable_character.cpp ./Characters/shepherd.cpp)
  target_link_libraries(SDL_part1 PUBLIC SDL2 SDL2main SDL2_image SDL2_ttf)
ELSE()
  message(STATUS "Building for Linux or Mac")

  find_package(SDL2 REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})

  IF(APPLE)
    # sdl2_image - quick fix for macOS with standard homebrew install (brew install sdl2 && brew install sdl2_image)
    set (CMAKE_CXX_STANDARD 14)
    SET(SDL2_IMAGE_LIBRARY "/usr/local/Cellar/sdl2_image/2.0.5/lib/libSDL2_image.dylib")
    SET(SDL2_IMAGE_INCLUDE_DIR "/usr/local/Cellar/sdl2_image/2.0.5/include/SDL2")

  # sdl2_ttf - quick fix for macOS with standard homebrew install (brew install sdl2_ttf)
    SET(SDL2_TTF_LIBRARY "/usr/local/Cellar/sdl2_ttf/2.0.18_1/lib/libSDL2_ttf.dylib")
    SET(SDL2_TTF_INCLUDE_DIR "/usr/local/Cellar/sdl2_ttf/2.0.18_1/include/SDL2")

    INCLUDE(FindPackageHandleStandardArgs)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(sdl2_image REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR SDL2_TTF_LIBRARY SDL2_TTF_INCLUDE_DIR)
    
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})
    include_directories(${SDL2_TTF_INCLUDE_DIR})

    set(CMAKE_CXX_FLAGS "-L/usr/local/Cellar/sdl2_image/2.0.5/lib -I/usr/local/Cellar/sdl2_image/2.0.5/include -L/usr/local/Cellar/sdl2_ttf/2.0.18_1/lib -I/usr/local/Cellar/sdl2_ttf/2.0.18_1/include -lSDL2 -lSDL2_image -lSDL2_ttf")
    
    # sdl2_image - end of quick fix
  ELSE()
    find_package(SDL2_image REQUIRED)
    include_directories(${SDL2IMAGE_INCLUDE_DIRS})
    find_package(SDL2_ttf REQUIRED)
    include_directories(${SDL2TTF_INCLUDE_DIRS})
  ENDIF()
  add_executable(SDL_part1 main.cpp ./Game/application.cpp ./Game/ground.cpp ./Characters/animal.cpp ./Characters/sheep.cpp ./Characters/wolf.cpp ./Characters/playable_character.cpp ./Characters/shepherd.cpp)
  target_link_libraries(SDL_part1 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
ENDIF()