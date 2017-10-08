#include "Ship.h"
#include "LimeEngine.h"
#include "Image.h"
#include "Rectangle.h"
#include <iostream>
#include "Laser.h"
#include "Point2D.h"

#include "BmpPaths.h"
namespace shooter {

    Ship::Ship(lime::Image img, lime::Rectangle bounds, bool enableCollision) :
        MobileSprite(img, bounds, enableCollision) {
        //TODO dangerous?
        lime::LimeEngine::getInstance()->addEventListener(this);
    }
   
    void Ship::update() {
        int x(bounds.x);
        x = xPolledFromEvent;
        if (x > 0 && x < 800) {
           
            bounds.x = x - bounds.w / 2;
        }
    }
    
    void Ship::render() {
        SDL_BlitSurface(imageToRender.getSurface(), NULL, lime::LimeEngine::getInstance()->getScreen(), &bounds);

    }
    
    Ship* Ship::createShip(lime::Point2D location) {
        lime::Image img(SHIP_IMAGE_PATH, true);
        lime::Rectangle rect(img, location.x(), location.y());
        return new Ship(img, rect, true);
    }

    void Ship::eventPerformed(SDL_Event& eve) {
        switch (eve.type) {
            
        case SDL_MOUSEMOTION:
            xPolledFromEvent = eve.motion.x;
            break;
            case SDL_MOUSEBUTTONDOWN:
                Ship::shootLaserForward();
            break;
        }
    }

    /// Private Member Methods ///
    void Ship::shootLaserForward() {
        lime::Point2D spawnFrom(bounds.x + (bounds.w / 2) - 6, bounds.y);
        lime::LimeEngine::getInstance()->addObject(
            shooter::Laser::createLaser(spawnFrom, false));
    }
}