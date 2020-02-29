#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include "header/gameSystem.h"
#include "header/vector2.h"
#include "header/gameUI.h"
#include "header/map.h"
#include <termios.h>
#include <unistd.h>

map::map(int x, int y)
{
    resize_map(x, y);
}

map::map()
{
    map(0,0);
}

void map::resize_map(int x, int y){
    data = new int *[x];
    for(int i = 0; i < x; i++){
        data[i] = new int [y];
    }

    map_size.setVector2(x, y);
}

void map::build_map(){
    int x, y;
    map_size.getVector2ByR(x, y);

    std::cout << x << " " << y;

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<> random_num(0, x * y -1);

    int *a = new int [x * y];

    for(int i = 0; i < x * y - 1 ; i++){
        a[i] = i + 1;
    }

    for(int i = 0; i < x * y; i++){
        std::swap(a[random_num(mersenne)], a[random_num(mersenne)]);
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            data[i][j] = a[i * y + j];
            if(i == (x -1) || j == (y -1))
                data[x-1][y-1] = MAX_INT;
        }
    }

    delete [] a;

    std::cout << "build map complete";
}

void map::show_map(){
    
    using std::cout;
    using std::endl;

    for(int i = 0; i < map_size.getVector2X(); i++){
        for(int j = 0; j < map_size.getVector2Y(); j++){
            if(MAX_INT == data[i][j])
                cout << "*" << "\t";
            else
                cout << data[i][j] << "\t";
        }
        cout << "\n" << endl;
    }

}

md& map::get_map(){
    return data;
}

Vector2& map::get_map_size(){
    return map_size;

}

map::~map()
{
    for(int i = 0; i < map_size.getVector2X() - 1; i++){
        delete [] data[i];
    }
    delete [] data;
}