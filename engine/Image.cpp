#include "Image.h"
#include <string>
#include <stdexcept>


// TODO Fix class
namespace lime {

    Image::Image() {
        // Do nothing
    }

    Image::Image(std::string filePath, bool useTransparency) {

        
        imageSurface = loadImage(filePath, useTransparency);
      
       
    }

   

    Image::~Image() {
        SDL_FreeSurface(imageSurface);
    

    }

    Image::Image(const Image& other) : 
        imageSurface(other.imageSurface){
        imageSurface->refcount++;
   

    }

    const Image& Image::operator=(const Image& other) {
        if (this != &other) {
            SDL_FreeSurface(imageSurface);
            imageSurface = other.imageSurface;
            imageSurface->refcount++;
        }


        return *this;
    }

    /// Public Member Methods ///

    

    SDL_Surface* Image::getSurface() const {
        return imageSurface;
    }

    /// Private Static Methods ///

    SDL_Surface* Image::loadImage(std::string filePath, bool useTransparency) {

        SDL_Surface *loadedImage;
        SDL_Surface *transparentImage;
        loadedImage = SDL_LoadBMP(filePath.c_str());
        
        if (loadedImage) {
         
            loadedImage->refcount++;
            
            if (useTransparency) {
                
                transparentImage = SDL_DisplayFormat(loadedImage);
               

                SDL_FreeSurface(loadedImage);
                if (transparentImage) {
                   
                    transparentImage->refcount++;
                    //Get first pixel 
                    Uint32 transpColor = *(Uint32*)transparentImage->pixels;

                    SDL_SetColorKey(transparentImage, SDL_SRCCOLORKEY | SDL_RLEACCEL, transpColor);
                
                }
                else {
                    
                    throw std::runtime_error("Error: Couldn't convert image to DisplayFormat: " + filePath);
                }
            }
            else {
                return loadedImage;
            }
        }
        else {
            throw std::runtime_error("Error: Couldn't load image: " + filePath);
        }

        return transparentImage;
    }
}