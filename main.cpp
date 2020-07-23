#include <iostream>
#include <Unit.hpp>
#include <Board.hpp>
#include <sstream>
#include <stdlib.h>

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
    system(""); // activates ansii codes on windows
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
        
        } else if(input[1] < '1' || input[1] > '8' || input[4] < '1' || input[4] > '8'){
            std::cout << "Error: number needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)"<< std::endl;
        
        } else if(input[0] < 'A' || ((input[0] > 'H' && input[0] < 'a') || input[0] > 'h') 
                || input[3] < 'H' || ((input[3] > 'H' && input[3] < 'a') || input[3] > 'h') ){
            std::cout << "Error: letter (a-h) needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)"<< std::endl;
        
        } else if(input[2] != '-'){
            std::cout << "Error: dash needed for position (movement syntax: <NUMBER><LETTER>-<NUMBER2><LETTER2>)" << std::endl;
        
        } else {
            int from_x = letterToNumber(input[0]), from_y = input[1]-'1';
            int to_x = letterToNumber(input[3]), to_y = input[4]-'1';
        
            b.move(from_x, from_y, to_x, to_y);
        
        }
    }
}