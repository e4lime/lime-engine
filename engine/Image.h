#ifndef IMAGE_H
#define IMAGE_H

#include "SDL.h"
#include <string>

namespace lime {
    class Image {
    public:

        //Full file path
        Image(std::string, bool);
        Image();
        ~Image();
        Image(const Image&);
        const Image& operator=(const Image&);
        SDL_Surface* getSurface() const;
    

    private:
        static SDL_Surface* loadImage(std::string, bool);
        SDL_Surface *imageSurface;
    };
   
}

#endif

