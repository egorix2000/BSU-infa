#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>

#include "Game.h"

using namespace sf;


int main(int, char**)
{
    srand(time(0));
    Game game(320, 480, 10, 20, 4, 0.3, 0.05, "");
    game.launchGame();
    return 0;
}
