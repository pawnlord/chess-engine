#include <Unit.hpp>
#include <iostream>

class Rook : public Unit{
public:
    Rook(int x, int y, int maxX, int maxY, int side, char identifier_)
        : Unit(x, y, maxX, maxY, side, identifier_)
    {
    }
    
    bool validateMovement(int to_x, int to_y){
        
        if((to_x!=info.x && to_y!=info.y)){
            return false;
        }
        
        info.x=to_x;
        info.y=to_y;
        
        return true;
    }
};