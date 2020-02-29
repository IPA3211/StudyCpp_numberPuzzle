#pragma once
#include "vector2.h"

typedef int** md;

class map
{
private:
    Vector2 map_size;
    md data;

public:
    map();
    map(int x, int y);

    void resize_map(int x, int y);
    void build_map();
    void show_map();
    
    md& get_map();
    Vector2& get_map_size();
    ~map();
};

