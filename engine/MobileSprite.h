#pragma once
#include "GameObject.h"
//#include "IMovementBehaviour.h"
namespace lime {
    class MobileSprite : public GameObject {
    public:
        // TODO Remove me?
        Rectangle &MobileSprite::getLocationRef();

    protected:
        MobileSprite(Image, Rectangle, bool);
        //IMovementBehaviour *movement;

    private:
        void workAroundPerformMovementCall();

    };

}