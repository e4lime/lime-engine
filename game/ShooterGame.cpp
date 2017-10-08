#include "ShooterGame.h"
#include "LimeEngine.h"
#include "Monster.h"
#include "Ship.h"
#include "Laser.h"
#include <iostream>

namespace shooter {

  
    ///Public Static Functions ///

    ShooterGame* ShooterGame::createShooterGame() {
        return new ShooterGame();
    }

    //Public member Functions ///
    int ShooterGame::startGame() {
        engine = lime::LimeEngine::createLimeEngine(40);
        engine->init();
 
        // Two rows of monsters in top of screen
        addMonsters(7, 25, 110, 25);
        addMonsters(6, 180, 110, 75);

        // Player at bottom of screen
        engine->addObject(Ship::createShip(lime::Point2D(350, 460)));

        if (engine->start()) {
            return -1;
        }
        return engine->stop();
    }

    /// Private ///
    ShooterGame::ShooterGame() {}

    void ShooterGame::addMonsters(const int amountOfMonsters, const int targetRow, const int spacing, const int firstOffset) {
        for (int i = 0; i != amountOfMonsters; ++i) {
            Monster *mon = Monster::createMonster(lime::Point2D(i * spacing + firstOffset, targetRow));
            engine->addObject(mon);
        }
    }
}