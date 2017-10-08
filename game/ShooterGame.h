#ifndef SHOOTERGAME_H
#define SHOOTERGAME_H
#include "LimeEngine.h"
namespace shooter {
    class ShooterGame{ 
    public:
        static ShooterGame* createShooterGame();
        // 0 if successful else -1
        int startGame();
    private:
        lime::LimeEngine *engine;

        ShooterGame();
        ShooterGame(const ShooterGame&);
        const ShooterGame& operator=(const ShooterGame&);
        // Add X monsters to Y row with Z spacing and A offset
        void addMonsters(int, int, int, int);

    };
}
#endif