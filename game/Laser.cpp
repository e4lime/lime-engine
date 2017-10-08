#include "Laser.h"
#include "LimeEngine.h"
#include "Image.h"
#include "Rectangle.h"
#include "GameObject.h"
#include "Monster.h"
#include <string>

#include "BmpPaths.h"

namespace shooter {

    Laser::Laser(lime::Image img, lime::Rectangle bounds,bool enableCollision, bool enemy) :
        MobileSprite(img, bounds, enableCollision), enemyLaser(enemy), hit(false) {



    }

    void Laser::update() {


        // Move laserbolt up
        if (!enemyLaser) {
            int y(bounds.y);
            y -= 5;
            bounds.y = y;

            if (y < 0) {
                requestDelete = true;
            }
        }

    }

    void Laser::performCollison(GameObject& other) {
        if (!enemyLaser) {
            Monster *monsterHit = dynamic_cast<Monster*>(&other);
            if (monsterHit) {
                if (!hit) {
                    hit = true;
                    monsterHit->requestDeletion();
                    this->requestDeletion();
                }
            }
        }

    }

    void Laser::render() {
        SDL_BlitSurface(imageToRender.getSurface(), NULL, lime::LimeEngine::getInstance()->getScreen(), &bounds);
    }

    // Enemylaser: Use true if monsters spawned the laser
    Laser* Laser::createLaser(const lime::Point2D& location, bool enemyLaser){
        
        std::string file = FRIENDLY_LASER_FILE_PATH;
        if (enemyLaser) {
            file = ENEMY_LASER_FILE_PATH;
        }

        lime::Image img(file, true);
       

        lime::Rectangle rect(img, location.x(), location.y());
        return new Laser(img, rect, true, enemyLaser);
    }
}