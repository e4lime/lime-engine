#include "LimeEngine.h"
#include <SDL.h>
#include <vector>
#include <iostream>



namespace lime {

    LimeEngine* LimeEngine::instance = NULL;
    

    //Public

    LimeEngine::LimeEngine(int maxFps) : MAX_FPS(maxFps){
        // do nothing
    }

    /// Public Static Methods
    
    LimeEngine* LimeEngine::createLimeEngine(int maxFps) {
        // TODO Add check for null
        LimeEngine::instance = new LimeEngine(maxFps);
        return LimeEngine::instance;
    }

    LimeEngine* LimeEngine::getInstance() {
        if (!LimeEngine::instance) {
            LimeEngine::instance = createLimeEngine(DEFAULT_FPS);
        }
        return LimeEngine::instance;
    }

    /// Public Member Functions ///

    int LimeEngine::init() {

        if (SDL_Init(SDL_INIT_EVERYTHING)) {
            return -1;
        }

        if (initVideo()) {
            return -1;
        }
        return 0;
    }

    int LimeEngine::start() {
        runGameLoop();
        return 0;
    }

    int LimeEngine::stop() {
        for (int i = 0, max = allObjects.size(); i != max; ++i) {
            delete allObjects[i];
        }
        SDL_FreeSurface(screen);
        delete instance;
        return 0;
    }

    void LimeEngine::addObject(Object* objectToAdd) {
        allObjects.push_back(objectToAdd);
    }

    void LimeEngine::addEventListener(IEventListener* listener) {
        allEventListener.push_back(listener);
    }

    SDL_Surface* LimeEngine::getScreen() const {
        return screen;
    }


    /// Private Member functions ///

    void LimeEngine::runGameLoop() {
        bool quit = false;
        while (!quit) {
            
            // Start frame timer
            Uint32 ticksStartOfFrame = SDL_GetTicks();

            quit = handleEvents();
            updateLogic();
            updateGraphics();
            detectCollisions();
            removeDeletionRequestingObjects();
            delayFrameIfNeeded(ticksStartOfFrame);
        }
    }
    bool LimeEngine::handleEvents() {

        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            for (int i = 0, max = allEventListener.size(); i != max; ++i) {
                allEventListener[i]->eventPerformed(eve);
            }
            switch(eve.type) {
            case SDL_QUIT:
                return true;
                break;
            }
        }
        return false;
    }

    void LimeEngine::updateLogic() {
        for (int i = 0, max = allObjects.size(); i != max; ++i) {
            allObjects[i]->update();
        }
    }

    void LimeEngine::updateGraphics() {
        SDL_FillRect(screen, NULL, black);
        // Update Graphics
        for (int i = 0, max = allObjects.size(); i != max; ++i) {

            allObjects[i]->render();
        }


        SDL_Flip(screen);
    }

    void LimeEngine::detectCollisions() {
        for (int i = 0, max = allObjects.size(); i != max; ++i) {
            GameObject* thisGameObject = dynamic_cast<GameObject*>(allObjects[i]);
            if (thisGameObject) {
                for (int j = 0, max = allObjects.size(); j != max; ++j) {
                    GameObject *thatGameObject = dynamic_cast<GameObject*>(allObjects[j]);
                    if (thatGameObject) {
                        if (thisGameObject->checkCollision(*thatGameObject)) {
                            thisGameObject->performCollison(*thatGameObject);
                        }
                    }
                }
            }
        }
    }

    // TODO use some flag
    void LimeEngine::removeDeletionRequestingObjects() {

        for (std::vector<Object*>::iterator iter = allObjects.begin();
                iter != allObjects.end(); ) {
            Object* obj = *iter;
            if (obj->getDeletionRequest()) {
                iter = allObjects.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    int LimeEngine::initVideo() {
        if (!(screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE | SDL_DOUBLEBUF))) {
            return -1;
        }

        Uint32 black(SDL_MapRGB(screen->format, 255, 255, 255));
        return 0;
    }

    void LimeEngine::delayFrameIfNeeded(Uint32 frameStartTicks) {
        Uint32 passedTicks = SDL_GetTicks() - frameStartTicks;
        const unsigned int minimumTicks = 1000 / MAX_FPS;
        if (passedTicks < minimumTicks) {
            SDL_Delay(minimumTicks - passedTicks);
        }
    }

}