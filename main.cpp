#include <iostream>
#include <Unit.hpp>
#include <Board.hpp>
#include <sstream>

int letterToNumber(char letter){
    if(letter <= 'Z'){
        return letter-'A';
    } else if(letter <= 'z'){
        return letter-'a';
    } else {
        std::cout << "Error: No letter " << (int)letter << std::endl;
        return -1;
    }
    
}

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
        std::cout << "Your Move: ";
        std::cin >> input;
        if(input.size() < 5){
            std::cout << "Error: not long enough (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)" << std::endl;
        } else if(input[0] < '1' || input[0] > '8' || input[3] < '1' || input[3] > '8'){
            std::cout << "Error: number needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)"<< std::endl;
        } else if(input[1] < 'A' || ((input[1] > 'H' && input[1] < 'a') || input[1] > 'h') 
                || input[4] < 'H' || ((input[4] > 'H' && input[4] < 'a') || input[4] > 'h') ){
            std::cout << "Error: letter (a-h) needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)"<< std::endl;
        } else if(input[2] != '-'){
            std::cout << "Error: dash needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)" << std::endl;
        } else {
            int from_x = input[0]-'1', from_y = letterToNumber(input[1]);
            int to_x = input[3]-'1', to_y = letterToNumber(input[4]);
            b.move(from_x, from_y, to_x, to_y);
        }
    }
}