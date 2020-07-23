#include <Unit.hpp>
#include <iostream>

class Pawn : public Unit{
public:
    Pawn (int x, int y, int maxX, int maxY, int side, char identifier_)
        : Unit(x, y, maxX, maxY, side, identifier_)
    {
    }
    
    bool validateMovement(int to_x, int to_y){
        int direction = info.side ? -1: 1;
        int starting_y = info.side ? info.maxY-1 : 1;

        std::cout << "starting: " << starting_y << std::endl;

        if(to_x != info.x){
            return false;
        }

        if(info.y == starting_y){
            std::cout << "in " << starting_y << std::endl;
            direction*=2;
            if(direction < 0){
                if(to_y < info.y+direction || to_y > info.y){
                    return false;
                }
            }else {
                if(to_y > info.y+direction || to_y < info.y){
                    return false;
                }
            }
        } else if(to_y != info.y+direction){
            return false;
        }

        info.x=to_x;
        info.y=to_y;
        
        return true;
    }
};