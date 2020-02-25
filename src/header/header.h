#pragma once
#include "vector2.h"

typedef int** map;

struct game_status
{
    Vector2 &player_position;
    const Vector2 &map_limit;
    map game_map;
};


const int MAX_INT = 2147483647;

void build_map(map &m, Vector2 &size);
void show_map(const map &m, Vector2 &size);
bool move_player(game_status &gs, const char &input);
void input_option(const bool &onoff);
void play_game(game_status &gs);