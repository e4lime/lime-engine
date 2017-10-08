#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <SDL.h>
#include "Image.h"
namespace lime {
    // From föreläsningsbilderna
    struct Rectangle : public SDL_Rect
    {
        Rectangle();
        Rectangle(int, int, int, int);
        Rectangle(const Image&);
        Rectangle(const Image&, int, int);
        bool overlaps(const Rectangle&) const;
    };

}

#endif
