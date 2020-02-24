#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include "header/header.h"
#include "header/vector2.h"

using namespace std;


int main() {

    map game_map;

    int map_size_x, map_size_y;
    
    cin >> map_size_x;
    cin >> map_size_y;

    Vector2 map_size(map_size_x, map_size_y); 
    Vector2 player_pos(map_size_x - 1, map_size_y - 1);   

    build_map(game_map, map_size);

    char input = 0;
    
    do{
        show_map(game_map, map_size);
        cin >> input;
    }while(move_player(game_map, input, player_pos, map_size));

}
