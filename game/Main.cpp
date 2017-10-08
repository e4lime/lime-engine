#include "ShooterGame.h"

int main(int argc, char * argv[]) {
    shooter::ShooterGame *game = shooter::ShooterGame::createShooterGame();
    game->startGame();

    return 0;
}