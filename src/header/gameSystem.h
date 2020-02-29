#pragma once
#include "vector2.h"
#include "map.h"

#define _DEBUG true

struct game_status
{
    Vector2 player_position;

    map game_map;

    ~game_status();
};


const int MAX_INT = 2147483647;

void build_map(map &m, Vector2 &size);
void show_map(const map &m,const Vector2 &size);

bool move_player(game_status &gs, const char &input);

void input_option(const bool &onoff);

void play_game(game_status &gs);