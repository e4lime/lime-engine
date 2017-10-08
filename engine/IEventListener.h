#ifndef IEVENTLISTENER_H
#define IEVENTLISTENER_H
#include <SDL.h>
namespace lime {
    class IEventListener {
    public:
        virtual void eventPerformed(SDL_Event&) = 0;
    };
}
#endif