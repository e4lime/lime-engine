#include "Point2D.h"
#include <iostream>
namespace lime {

    Point2D::Point2D() :
        xPos(0), yPos(0) {
        //Do nothing
    }

    Point2D::Point2D(int x, int y) :
        xPos(x), yPos(y){
        //Do nothing
    }

    int Point2D::x() const {
        return xPos;
    }

    int& Point2D::x() {
        return xPos;
    }

    int Point2D::y() const {
   
        return yPos;
    }

    int& Point2D::y() {

        return yPos;
    }

    std::ostream& operator<<(std::ostream &left, const Point2D &right) {
        return left << "(" << right.x() << ", " << right.y() << ")";
    }

    
}