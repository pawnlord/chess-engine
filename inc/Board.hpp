#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <Unit.hpp>
#include <vector>

typedef struct{
    int size_x;
    int dividing_x; //divides board into white and black
    int size_y;
    std::vector<std::vector<char> > board;
} board_info_t;

class Board{
    public: 
    Board(board_info_t board_info_);

    void draw();
    
    int move(int from_x, int from_y, int to_x, int to_y);

    std::vector<Unit> units;
    
    private:
    board_info_t board_info;
};
#endif