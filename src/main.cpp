#include "Game.h"


int main()
{
    Game game;

    game.Init();
    game.RunLoop();
    game.Shutdown();

    return 0;
}