#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Object.h"
#include "Image.h"
#include "Rectangle.h"
#include "Point2D.h"

namespace lime {
    class GameObject : public Object {
    public:
        // True if collision with another GO
        bool checkCollision(const GameObject&) const;
        // Calls when collision occured
        virtual void performCollison(GameObject&);

   
    protected:
        GameObject(Image, Rectangle, bool);
        // True if GO should have collision
        //TODO use flags
        bool collidable;

    };
}
#endif