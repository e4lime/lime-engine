#ifndef MONSTER_H
#define MONSTER_H

#include "MobileSprite.h"
#include "Image.h"
#include "Rectangle.h" 
#include "Point2D.h"

namespace shooter {
    class Monster : public lime::MobileSprite
    {
    public:

        void lime::Object::update();
        void lime::Object::render();

        static Monster* createMonster(lime::Point2D);



    private:
        Monster(lime::Image, lime::Rectangle, bool);
        int direction;

    };
}

#endif
