#include "Object.h"
#include "GameObject.h"
#include "SDL.h"
#include "Image.h"
#include "Rectangle.h"
#include "Point2D.h"
#include <iostream> //TODO delete me

namespace lime {
    GameObject::GameObject(Image imageToRender, Rectangle bounds, bool enableCollision) :
        Object(imageToRender, bounds), collidable(enableCollision) {
       
        // DO nothing yet
    }

    void GameObject::performCollison(GameObject &other) {
        // Nothing by default
    }

   
    bool GameObject::checkCollision(const GameObject& other) const {
        if (!this->collidable || !other.collidable) {
            return false;
        }

        if (this == &other) {
            return false;
        }

        if (this->bounds.overlaps(other.bounds)) {
            return true;
        }
        return false;
    }
  
}