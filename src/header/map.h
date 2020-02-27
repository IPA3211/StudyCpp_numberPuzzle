#pragma once
#include "vector2.h"

class map
{
private:
    Vector2 map_size;
    int **data;

public:
    map(int x, int y);

    void build_map();
    void show_map();
    
    int** get_map();
    Vector2 get_map_size();
    ~map();
};

