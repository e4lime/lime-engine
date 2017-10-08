#ifndef SHIP_H
#define SHIP_H
#include "MobileSprite.h"
#include "Image.h"
#include "Rectangle.h" 
#include "Point2D.h"
#include "IEventListener.h"

namespace shooter {
    class Ship : public lime::MobileSprite, public lime::IEventListener
    {
    public:
       
        void lime::Object::update();
        void lime::Object::render();
        
        static Ship* createShip(lime::Point2D);

        void IEventListener::eventPerformed(SDL_Event&);
        
        
    private:
        Ship(lime::Image, lime::Rectangle, bool);
        // Mouse x pos from event, used in update()
        int xPolledFromEvent;
        void shootLaserForward();
    };
}

#endif
