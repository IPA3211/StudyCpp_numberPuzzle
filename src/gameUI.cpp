#include <iostream>
#include "header/gameSystem.h"
#include "header/vector2.h"
#include "header/gameUI.h"

void new_game(){
    game_status gs;
    int map_size_x, map_size_y;
    
    std::cout << "맵 사이즈를 선택해 주세요 : ";

    std::cin >> map_size_x;
    std::cin >> map_size_y;

    // Vector2 map_limit(map_size_x, map_size_y);
    // Vector2 player_position(map_size_x - 1, map_size_y - 1);

    // gs.map_limit = map_limit;
    // gs.player_position = player_position;
    
    gs.game_map = new map(map_size_x, map_size_y);
    gs.player_position.setVector2(map_size_x - 1, map_size_y - 1);
    gs.game_map.build_map();
    
    play_game(gs);

    std::cout << "game end";
    
}

void show_start_UI(){

    input_option(false);
    
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

void show_pause_UI(game_status gs){

    input_option(false);

    using namespace std;

    cout << "일시 정지" << endl;
    cout << "1 : 계 속 " << endl;
    cout << "2 : 다시하기 " << endl;
    cout << "3 : 저 장 " << endl;
    cout << "4 : 메인으로" << endl;

    char input;
    cin >> input;

    switch (input)
    {
        case '1':
            play_game(gs);
            break;
        case '2':
            gs.~game_status();
            new_game();
            break;
        case '3':  
            /* save game */
            break;
        case '4':
            gs.~game_status();
            show_start_UI();
            break;
        default:
            break;
    }
}