#ifndef UNIT_HPP
#define UNIT_HPP
#define SIDE1 0
#define SIDE2 1
class Unit{
    public:
    Unit(int x, int y, int side, char identifier_);
    
    char identifier;
    struct {
        int x;
        int y;
        int maxX;
        int maxY;
        int side;
    } info;
    //private:
    
};
#endif