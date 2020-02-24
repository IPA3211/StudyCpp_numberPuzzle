#pragma once
#include "vector2.h"


typedef int** map;

const int MAX_INT = 2147483647;

void build_map(map &m, Vector2 &size);
void show_map(const map &m, Vector2 &size);
bool move_player(map &m, const char &input, Vector2 &player_pos, const Vector2 &limit_size);