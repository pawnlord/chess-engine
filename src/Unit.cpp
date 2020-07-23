#include <Unit.hpp>

Unit::Unit(int x, int y, int maxX, int maxY, int side, char identifier_) {
    info.x = x;
    info.y = y;
    info.side = side;
    info.maxX = maxX;
    info.maxY = maxY;
    identifier = identifier_;
}