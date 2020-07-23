#include <Board.hpp>
#include <iostream>
#include <sstream>

Board::Board(board_info_t board_info_){
    board_info = board_info_;
    
    for(int i = 0; i < board_info.board.size(); i++){
        for(int j = 0; j < board_info.board[i].size(); j++) {
            if(board_info.board[i][j] != '.'){
                if(board_info.board[i][j] == 'p'){
                    units.push_back(new Pawn(j, i, board_info.board.size(), board_info.board[i].size()-1, (i > board_info.dividing_x)? SIDE2: SIDE1, board_info.board[i][j] ));    
                } else if(board_info.board[i][j] == 'R'){
                    units.push_back(new Rook(j, i, board_info.board.size(), board_info.board[i].size()-1, (i > board_info.dividing_x)? SIDE2: SIDE1, board_info.board[i][j] ));    
                } else {
                    units.push_back(new Unit(j, i, board_info.board.size(), board_info.board[i].size()-1, (i > board_info.dividing_x)? SIDE2: SIDE1, board_info.board[i][j] ));
                }
            }
        }

    }
}

void Board::draw(){
    std::vector<char> board_str;
    std::vector<std::string> color_str;
    for(int i = 0; i < board_info.size_y; i++){
        for(int j = 0; j < board_info.size_x; j++){
            board_str.push_back('.');
            color_str.push_back("\x1b[0m");
        }
        board_str.push_back('\n');
        color_str.push_back("\x1b[0m");
    }
    board_str.push_back(0);
    for(int i = 0; i < units.size(); i++){
        board_str[units[i]->info.x + (units[i]->info.y*(board_info.size_x+1))] = units[i]->identifier;
        color_str[units[i]->info.x + (units[i]->info.y*(board_info.size_x+1))] = (units[i]->info.side == SIDE1) ? "\x1b[31m" : "\x1b[32m";
    }
    for(int i = 0; i < board_str.size(); i++){
        std::cout << color_str[i];
        std::cout << board_str[i];
        if(board_str[i] != '\n'){
            std::cout << "  ";
        }
    }
}

int Board::move(int from_x, int from_y, int to_x, int to_y){
    int unit_id = -1;
    for(int i = 0; i < units.size(); i++){
        if(units[i]->info.x == from_x && units[i]->info.y == from_y){
            unit_id = i;
        }
        if(units[i]->info.x == to_x && units[i]->info.y == to_y){
            std::cout << "Error: unit in the way" << std::endl; 
            return 0;
        }
    }
    if(unit_id == -1){
        std::cerr << "Error: no unit at " << from_x << from_y << std::endl; 
        return 0;
    }
    if(!units[unit_id]->validateMovement(to_x, to_y)){
        std::cerr << "Error: invalid move!" << std::endl; 
        return 0;
    }
    units[unit_id]->info.x = to_x;
    units[unit_id]->info.y = to_y;
    return 1;
}
