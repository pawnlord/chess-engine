#include <Board.hpp>
#include <iostream>

Board::Board(board_info_t board_info_){
    board_info = board_info_;
    
    for(int i = 0; i < board_info.board.size(); i++){
        for(int j = 0; j < board_info.board[i].size(); j++) {
            if(board_info.board[i][j] != '.'){
                units.push_back(Unit(j, i, (i > board_info.dividing_x)? SIDE2: SIDE1, board_info.board[i][j] ));
            }
        }

    }
}

void Board::draw(){
    std::vector<char> v;
    for(int i = 0; i < board_info.size_y; i++){
        for(int j = 0; j < board_info.size_x; j++){
            v.push_back('.');
        }
        v.push_back('\n');
    }
    v.push_back(0);
    for(int i = 0; i < units.size(); i++){
        v[units[i].info.x + (units[i].info.y*(board_info.size_x+1))] = units[i].identifier;
    }
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i];
        if(v[i] != '\n'){
            std::cout << "  ";
        }
    }
}

int Board::move(int from_x, int from_y, int to_x, int to_y){
    int unit_id = -1;
    for(int i = 0; i < units.size(); i++){
        if(units[i].info.x == from_x && units[i].info.y == from_y){
            unit_id = i;
        }
        if(units[i].info.x == to_x && units[i].info.y == to_y){
            std::cout << "Error: unit in the way" << std::endl; 
            return 0;
        }
    }
    if(unit_id == -1){
        std::cerr << "Error: no unit at " << from_x << from_y << std::endl; 
        return 0;
    }
    units[unit_id].info.x = to_x;
    units[unit_id].info.y = to_y;
    return 1;
}
