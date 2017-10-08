#include "MobileSprite.h"
#include "Image.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "GameObject.h"

namespace lime {

    
    MobileSprite::MobileSprite(Image imageToRender, Rectangle bounds, bool enableCollison) :
        GameObject(imageToRender, bounds, enableCollison) {
     
    
        // Do nothing
    }

    /// Public Member Functions ///

    Rectangle &MobileSprite::getLocationRef(){
        return bounds;
    }


    
    /// Public Static Functions ///

   
  

}