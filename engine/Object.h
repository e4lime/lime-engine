#ifndef OBJECT_H
#define OBJECT_H

#include "Rectangle.h"
#include "Image.h"
#include "Point2D.h"

namespace lime {

   

    // Abstract
    class Object {
    public:
        // Called from LimeEngine only
         virtual void update() = 0; 
         virtual void render() = 0;

         virtual ~Object();

         // If true LimeEngine will try to delete this object
         bool getDeletionRequest() const;
         void requestDeletion();

    protected :
        const Image imageToRender;
        Rectangle bounds;
        //TODO Private?
        bool requestDelete;
        //TODO: Pass with reference
        Object(Image, Rectangle);
    private:
        Object(const Object&);
        const Object& operator=(const Object&);
        
    };
}

#endif