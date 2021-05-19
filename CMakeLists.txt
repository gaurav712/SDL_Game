cmake_minimum_required(VERSION 3.5)

project(SDL_Game LANGUAGES C)

add_executable(SDL_Game src/main.c src/player.c)

target_link_libraries(SDL_Game SDL2)
