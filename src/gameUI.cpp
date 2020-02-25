#include <iostream>
#include "header/header.h"
#include "header/vector2.h"
#include "header/gameUI.h"

void new_game(){
    map game_map;
    game_status gs;
    int map_size_x, map_size_y;
    
    cin >> map_size_x;
    cin >> map_size_y;

    gs.map_limit = new Vector2(map_size_x, map_size_y);
    gs.player_position = new Vector2(map_size_x - 1, map_size_y - 1);
    
    build_map(gs.game_map, map_size);
    play_game(gs);
}

void show_start_UI(){
    
    using namespace std;

    char input;

    cout << "숫자 퍼즐" << endl;
    cout << "1 : 새로운 시작" << endl;
    cout << "2 : 계속하기" << endl;
    cout << "3 : 종 료" << endl;

    cin >> input;

    switch (input)
    {
        case '1':
            new_game();
            break;
        case '2':
            /* Load game */
            break;
        case '3':  
            return; // exit program
            break;
        
        default:
            break;
    }

}

void show_pause_UI(){

    using namespace std;

    cout << "일시 정지" << endl;
    cout << "1 : 계 속 " << endl;
    cout << "2 : 다시하기 " << endl;
    cout << "3 : 저 장 " << endl;
    cout << "4 : 메인으로" << endl;

    switch (input)
    {
        case '1':
            play_game(game_map, map_size, player_pos);
            break;
        case '2':
            new_game();
            break;
        case '3':  
            /* save game */
            break;
        case '4':
            break;
        default:
            break;
    }
}