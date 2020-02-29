#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include "header/gameSystem.h"
#include "header/vector2.h"
#include "header/gameUI.h"
#include <termios.h>
#include <unistd.h>

bool move_player(game_status &gs, const char &input){
    Vector2 &player_pos = gs.player_position;
    md &m = gs.game_map.get_map();

    switch (input)
    {
    case 'a':
        if(std::isOverSize(player_pos.getVector2X(), player_pos.getVector2Y() - 1, gs.game_map.get_map_size())){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X()][player_pos.getVector2Y() - 1]);
            player_pos.setVector2Y(player_pos.getVector2Y() - 1);
        }
        return true;
        break;
    case 'w':
        if(std::isOverSize(player_pos.getVector2X() - 1, player_pos.getVector2Y(), gs.game_map.get_map_size())){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X() - 1][player_pos.getVector2Y()]);
            player_pos.setVector2X(player_pos.getVector2X() - 1);
        }
        return true;
        break;
    case 'd':
        if(std::isOverSize(player_pos.getVector2X(), player_pos.getVector2Y() + 1, gs.game_map.get_map_size())){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X()][player_pos.getVector2Y() + 1]);
            player_pos.setVector2Y(player_pos.getVector2Y() + 1);
        }
        return true;
        break;
    case 's':
        if(std::isOverSize(player_pos.getVector2X() + 1, player_pos.getVector2Y(), gs.game_map.get_map_size())){
            std::swap(m[player_pos.getVector2X()][player_pos.getVector2Y()], m[player_pos.getVector2X() + 1][player_pos.getVector2Y()]);
            player_pos.setVector2X(player_pos.getVector2X() + 1);
        }
        return true;
        break;
    case 27:
        show_pause_UI(gs);
        return false;
        break;
    default:
        return true;
        break;
    }

}

void input_option(const bool &onoff){
    
    termios t;

    if(onoff){
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
    }
    else{
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag |= ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
    }

}

void play_game(game_status &gs){

    input_option(true);

    char input;

    do{
        system("clear");
        gs.game_map.show_map();
        std::cin >> input;
    }while(move_player(gs, input));

}

game_status::~game_status(){
    
}