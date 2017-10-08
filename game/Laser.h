#ifndef LASER_H
#define LASER_H
#include "MobileSprite.h"
#include "Image.h"
#include "Rectangle.h" 
#include "Point2D.h"
//#include "IMovementBehaviour.h"
namespace shooter {
    class Laser : public lime::MobileSprite
    {
    public:

        void lime::Object::update();
        void lime::Object::render();
        void performCollison(GameObject&);
        static Laser* createLaser(const lime::Point2D&, bool);



    private:
        Laser(lime::Image, lime::Rectangle, bool, bool);
        bool enemyLaser;
        bool hit;
    };
}

#endif
