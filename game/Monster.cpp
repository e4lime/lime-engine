#include "Monster.h"
#include "LimeEngine.h"
#include "Image.h"
#include "Rectangle.h"
#include <iostream>
#include <random>
#define LEFT 0
#define RIGHT 1     
#define UP 2 
#define DOWN 3     

#include "BmpPaths.h"
namespace shooter {

    Monster::Monster(lime::Image img, lime::Rectangle bounds, bool enableCollision) :
        MobileSprite(img, bounds, enableCollision), direction(std::rand() % 2) {
       
    }
   
    void Monster::update() {
        
        int x (bounds.x);
        int y (bounds.y);
        int screenWidth(800);
        int widthOffset(100);

        int speed = 1;

      
        if (x > screenWidth - widthOffset) {
            direction = LEFT;
        }
        else if (x < widthOffset) {
            direction = RIGHT;
           
        }

        if (direction == LEFT) {
            x -= speed;
        }
        else if (direction == RIGHT) {
            x += speed;
        }
        bounds.x = x;
        bounds.y = y;
    }

    void Monster::render() {
       
        SDL_BlitSurface(imageToRender.getSurface(), NULL, lime::LimeEngine::getInstance()->getScreen(), &bounds);
        
    }

    Monster* Monster::createMonster(lime::Point2D location) {
        lime::Image img(MONSTER_IMAGE_PATH, true);
        lime::Rectangle rect(img, location.x(), location.y());
        return new Monster(img, rect, true);
        
    }

    
}