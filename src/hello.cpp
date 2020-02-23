#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include "header/header.h"

void build_map(map &m, int x, int y){
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