#include "Object.h"

namespace lime {
    Object::Object(Image imageToRender, Rectangle bounds) :
        imageToRender(imageToRender), bounds(bounds), requestDelete(false) {

    }

    Object::~Object() {

    }

    void Object::requestDeletion() {
        requestDelete = true;
    }

    bool Object::getDeletionRequest() const {
        return requestDelete;
    }
}