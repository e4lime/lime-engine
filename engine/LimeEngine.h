#ifndef LIMEENGINE_H
#define LIMEENGINE_H
#define DEFAULT_FPS 30
#include "SDL.h"
#include <vector>
#include "IEventListener.h"
#include "GameObject.h"
namespace lime {

    // Singleton
    // use createLimeEngine(int) once before getInstance() or
    // engine will be created with default FPS
    //
    // Call init before you add objects with transparancy
    class LimeEngine {
    public:
        
    
        // 0 if successful else -1
        int init();
        // 0 if successful else -1
        int start();
        // 0 if successful else -1
        int stop();
        void addObject(Object*);
        // Calls createLimeEngine(int) if it havnt been called
        static LimeEngine* getInstance();
        static LimeEngine* createLimeEngine(int);
        SDL_Surface* getScreen() const;

        void addEventListener(IEventListener*);

    private:

         const int MAX_FPS;
         SDL_Surface *screen;
         std::vector<Object*> allObjects;
         std::vector<IEventListener*> allEventListener;
         Uint32 black;
        

         static LimeEngine* instance;

         void runGameLoop();
         // 0 if successful else -1
         int initVideo();
         //Delays frame if frame is faster than MAX_FPS
         void delayFrameIfNeeded(Uint32);
         // Returns true if user quited
         bool handleEvents();
         void updateLogic();
         void updateGraphics();
         void detectCollisions();
         void removeDeletionRequestingObjects();



         LimeEngine(int);
         LimeEngine(const LimeEngine&);
         const LimeEngine& operator=(const LimeEngine&);
         
    };

   

}

#endif
