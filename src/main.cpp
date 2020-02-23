#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include "header/header.h"

using namespace std;


int main() {

    map game_map;

    int map_size_x, map_size_y;
    
    map_size_x = 5;
    map_size_y = 5;

    build_map(game_map, map_size_x, map_size_y);

    for(int i = 0; i < map_size_x; i++){
        for(int j = 0; j < map_size_y; j++){
            if(MAX_INT == game_map[i][j])
                cout << "*" << "\t";
            else
                cout << game_map[i][j] << "\t";
        }
        cout << "\n" << endl;
    }

}
