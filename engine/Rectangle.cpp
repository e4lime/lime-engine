#include "Rectangle.h"

namespace lime {

    Rectangle::Rectangle() {
        x = 0;
        y = 0;
        h = 0;
        w = 0;
    }

    Rectangle::Rectangle(int x, int y, int width, int height) {
        this->x = x;
        this->y = y;
        w = width;
        h = height;
    }

    Rectangle::Rectangle(const Image& image) {
        Rectangle(image, 0, 0);
    }

    Rectangle::Rectangle(const Image& image, int xPosition, int yPosition) {

        this->x = xPosition;
        this->y = yPosition;
        SDL_Surface* imgSurf = image.getSurface();
        this->w = imgSurf->w;
        this->h = imgSurf->h;

    }

    bool Rectangle::overlaps(const Rectangle& other) const {
        int left1 = this->x;
        int left2 = other.x;
        int right1 = this->x + this->w;
        int right2 = other.x + other.w;
        int top1 = this->y;
        int top2 = other.y;
        int bottom1 = this->y + this->h;
        int bottom2 = other.y + other.h;

        if (bottom1 < top2 ||
            top1 > bottom2 ||
            right1 < left2 ||
            left1 > right2) {
            return false;
        }


        return true;
    }
}
