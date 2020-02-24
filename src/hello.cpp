#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include "header/header.h"
#include "header/vector2.h"

void build_map(map &m, Vector2 &size){
    int x, y;
    size.getVector2ByR(x, y);

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<> random_num(0, x*y -1);

    int *a = new int [x * y - 1];

    for(int i = 0; i < x * y; i++){
        a[i] = i + 1;
    }

    for(int i = 0; i < x * y; i++){
        std::swap(a[random_num(mersenne)], a[random_num(mersenne)]);
    }

    m = new int *[x];

    for(int i = 0; i < x; i++)
        m[i] = new int [y];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            m[i][j] = a[i * y + j];
            if(i * j == (x -1) * (y -1))
                m[x-1][y-1] = MAX_INT;
        }
    }
}

void show_map(const map &m, Vector2 &size){
    
    using std::cout;
    using std::endl;

    for(int i = 0; i < size.getVector2X(); i++){
        for(int j = 0; j < size.getVector2Y(); j++){
            if(MAX_INT == m[i][j])
                cout << "*" << "\t";
            else
                cout << m[i][j] << "\t";
        }
        cout << "\n" << endl;
    }

}

bool move_player(map &m, const char &input, Vector2 &player_pos, const Vector2 &limit_size){

    switch (input)
    {
    case 'a':
        if(std::isOverSize(player_pos.getVector2X(), player_pos.getVector2Y() - 1, limit_size)){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X()][player_pos.getVector2Y() - 1]);
            player_pos.setVector2Y(player_pos.getVector2Y() - 1);
        }
        return true;
        break;
    case 'w':
        if(std::isOverSize(player_pos.getVector2X() - 1, player_pos.getVector2Y(), limit_size)){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X() - 1][player_pos.getVector2Y()]);
            player_pos.setVector2X(player_pos.getVector2X() - 1);
        }
        return true;
        break;
    case 'd':
        if(std::isOverSize(player_pos.getVector2X(), player_pos.getVector2Y() + 1, limit_size)){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X()][player_pos.getVector2Y() + 1]);
            player_pos.setVector2Y(player_pos.getVector2Y() + 1);
        }
        return true;
        break;
    case 's':
        if(std::isOverSize(player_pos.getVector2X() + 1, player_pos.getVector2Y(), limit_size)){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X() + 1][player_pos.getVector2Y()]);
            player_pos.setVector2X(player_pos.getVector2X() + 1);
        }
        return true;
        break;
    case 27:
        return false;
        break;
    }

}