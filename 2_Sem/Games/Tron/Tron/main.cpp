#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>

#include "Game.h"

using namespace sf;

int main() {
	srand(time(0));
    
    Game game (600, 480, 4);
    int control1[4] = { (int) Keyboard::Left, (int) Keyboard::Right, (int) Keyboard::Up,  (int) Keyboard::Down};
    int control2[4] = { (int) Keyboard::A, (int) Keyboard::D, (int) Keyboard::W, (int) Keyboard::S };
    int control3[4] = { (int) Keyboard::J, (int) Keyboard::L, (int) Keyboard::I, (int) Keyboard::K };

    game.addRandomPlayer(Color::Red, control1, "Red");
    game.addRandomPlayer(Color::Green, control2, "Green");
    game.addRandomPlayer(Color::White, control3, "White");
    
    game.startGame();

    return 0;
}
