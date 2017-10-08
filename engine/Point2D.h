#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
namespace lime {
    class Point2D {
    public:
        Point2D();
        Point2D(int, int);
        

        int x() const;
        int& x();

        int y() const;
        int& y();

       
    private:
        int xPos;
        int yPos;
    };
     std::ostream& operator<<(std::ostream&, const Point2D);
}
#endif