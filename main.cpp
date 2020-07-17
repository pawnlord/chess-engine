#include <iostream>
#include <Unit.hpp>
#include <Board.hpp>
#include <sstream>

int main(){
    std::vector<std::vector<char> >  board = {
        {'R','k','B','Q','K','B','k','R'},
        {'p','p','p','p','p','p','p','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'p','p','p','p','p','p','p','p'},
        {'R','k','B','Q','K','B','k','R'}
    };
    board_info_t board_info = {8, 3, 8, board};
    Board b(board_info);
    std::string input = "";
    while(input != "exit"){
        b.draw();
        std::cout << "x: ";
        std::cin >> input;
        int from_x = std::stoi(input);
        std::cout << "y: ";
        std::cin >> input;
        int from_y = std::stoi(input);
        std::cout << "x: ";
        std::cin >> input;
        int to_x = std::stoi(input);
        std::cout << "y: ";
        std::cin >> input;
        int to_y = std::stoi(input);
        b.move(from_x, from_y, to_x, to_y);
    }
}