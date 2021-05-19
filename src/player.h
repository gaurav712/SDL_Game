#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

typedef struct Player
{
    void (* const draw)(Uint8, Uint8);
} player_namespace_struct;

extern player_namespace_struct const player;

#endif // PLAYER_H
