#include <SFML/Graphics.hpp>
#include <time.h>

#include "Player.h"
#include "Field.h"

using namespace sf;


void tick(Player& player, int width, int height) {
    if (player.getDirection() == 0) player.moveDown(1);
    if (player.getDirection() == 1) player.moveLeft(1);
    if (player.getDirection() == 2) player.moveRight(1);
    if (player.getDirection() == 3) player.moveUp(1);
    
    if (player.getX() >= width) player.setX(0);
    if (player.getX() < 0) player.setX(width-1);
    if (player.getY() >= height) player.setY(0);
    if (player.getY() < 0) player.setY(height-1);
}

Player createRandomPlayer(Color color, int width, int height) {
    int x = rand() % width;
    int y = rand() % height;
    int direction = rand() % 4;
    return Player(x, y, direction, color);
}

Player& changePlayerRandomly(Player& player, Color color, int width, int height) {
    player.setX(rand() % width);
    player.setY(rand() % height);
    player.setDirection(rand() % 4);
    player.setColor(color);
    return player;
}

int main() {
	srand(time(0));
    
    int width = 600;
    int height = 480;
    int speed = 4;

    RenderWindow window(VideoMode(width, height), "The Tron Game!");
    window.setFramerateLimit(60);

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("/Users/apple/Downloads/Tron/Tron/images/background.jpg");
	Sprite background(backgroundTexture);
    
    Field& field = Field::getInstance(width, height);

    Player player1 = createRandomPlayer(Color::Red, width, height);
    Player player2 = createRandomPlayer(Color::Green, width, height);

	Sprite sprite;
	RenderTexture textureLines;
	
    
    Font font;
    font.loadFromFile("/Users/apple/Downloads/Tron/Tron/arial.ttf");
    
    Text gameOverText;
    Text pressAnyKey;
    gameOverText.setFont(font);
    gameOverText.setPosition(width/3.3, height/3);
    gameOverText.setCharacterSize(40);
    
    pressAnyKey.setFont(font);
    pressAnyKey.setPosition(width/4, height/2);
    pressAnyKey.setCharacterSize(20);
    pressAnyKey.setFillColor(Color::White);

	bool isGameOver = false;
    bool startGame = false;
    Player *winner;

    while (window.isOpen()) {
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
		}
        
        if (Keyboard::isKeyPressed(Keyboard::Space) && !startGame) {
            startGame = true;
            isGameOver = false;
            field.clear();
            player1 = changePlayerRandomly(player1, Color::Red, width, height);
            player2 = changePlayerRandomly(player2, Color::Green, width, height);
            textureLines.create(width, height);
            textureLines.setSmooth(true);
            sprite.setTexture(textureLines.getTexture());
            textureLines.clear();
            textureLines.draw(background);
        }
        
        if (startGame) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                if (player1.getDirection() != 2) {
                    player1.setDirection(1);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                if (player1.getDirection() != 1) {
                    player1.setDirection(2);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                if (player1.getDirection() != 0) {
                    player1.setDirection(3);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                if (player1.getDirection() != 3) {
                    player1.setDirection(0);
                }
            }
            
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                if (player2.getDirection() != 2) {
                    player2.setDirection(1);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                if (player2.getDirection() != 1) {
                    player2.setDirection(2);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                if (player2.getDirection() != 0) {
                    player2.setDirection(3);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                if (player2.getDirection() != 3) {
                    player2.setDirection(0);
                }
            }
        }

        if (isGameOver) {
            startGame = false;
            std::string colorWin;
            window.clear();
            window.draw(sprite);
            winner->getColor() == Color::Green ? colorWin = "Green" : colorWin = "Red";
            gameOverText.setFillColor(winner->getColor());
            gameOverText.setString(colorWin + " wins!");
            pressAnyKey.setString("Press space to restart game");
            window.draw(gameOverText);
            window.draw(pressAnyKey);
            window.display();
            continue;
        }
        
        if (!startGame) {
            window.clear();
            window.draw(sprite);
            pressAnyKey.setString("Press space to start game");
            window.draw(pressAnyKey);
            window.display();
        } else {
            for(int i = 0; i < speed; i++) {
                tick(player1, width, height);
                tick(player2, width, height);
                if (field.getElement(player1.getX(), player1.getY()) == 1) {
                    winner = &player2;
                    isGameOver = true;
                }
                if (field.getElement(player2.getX(), player2.getY()) == 1) {
                    winner = &player1;
                    isGameOver = true;
                }
                field.setElement(player1.getX(), player1.getY(), 1);
                field.setElement(player2.getX(), player2.getY(), 1);
        
                CircleShape circle(1);
                circle.setPosition(player1.getX(),player1.getY());
                circle.setFillColor(player1.getColor());
                textureLines.draw(circle);
                circle.setPosition(player2.getX(),player2.getY());
                circle.setFillColor(player2.getColor());
                textureLines.draw(circle);
                textureLines.display();
            }

           ////// draw  ///////
            window.clear();
            window.draw(sprite);
            window.display();
        }
	}

    return 0;
}
