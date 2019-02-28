#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <iostream>

#include "Field.h"
#include "Figure.h"
#include "FigureFactory.h"

using namespace sf;

bool check(const Figure& a, const Field& field, int width, int height) {
    for (int i = 0; i < a.getN(); i++) {
       if (a[i].x < 0 || a[i].x >= width || a[i].y >= height) {
           return 0;
       }
       else if (field.getTile(a[i].x, a[i].y)) {
           return 0;
       }
    }
   return 1;
};

int main(int, char**)
{
    srand(time(0));
    
    RenderWindow window;
    VideoMode videoMode(320, 480);
    
    window.create(videoMode, "The Game!");
    
    Texture tilesTexture;
    Texture backgroundTexture;
    Texture frameTexture;
	tilesTexture.loadFromFile("/Users/apple/Downloads/Tetris/Tetris/images/tiles.png");
	backgroundTexture.loadFromFile("/Users/apple/Downloads/Tetris/Tetris/images/background.png");
	frameTexture.loadFromFile("/Users/apple/Downloads/Tetris/Tetris/images/frame.png");
    

    Sprite tile(tilesTexture);
    Sprite background(backgroundTexture);
    Sprite frame(frameTexture);

    int width = 10;
    int height = 20;
    int figureSize = 4;
    float timer = 0;
    float delay = 0.3;
    Field& field = Field::getInstance(width, height);
    
    Figure *a = nullptr;
    Figure *b = nullptr;

	Clock clock;

    while (window.isOpen()) {
        
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }

            if (e.type == Event::KeyPressed) {
                if (a != nullptr) {
                    delete b;
                    b = new Figure(a->getN(), a->getTiles(), a->getColor());
                    if (e.key.code == Keyboard::Up) {
                        a->Rotate();
                    } else if (e.key.code == Keyboard::Left) {
                        a->moveLeft();
                    } else if (e.key.code == Keyboard::Right) {
                        a->moveRight();
                    }
                    
                    if (!check(*a, field, width, height)) {
                        delete a;
                        a = new Figure(b->getN(), b->getTiles(), b->getColor());
                    }
                }
            }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            delay = 0.05;
        }

        ///////Tick//////
        if (timer > delay) {
            if (a != nullptr) {
                delete b;
                b = new Figure(a->getN(), a->getTiles(), a->getColor());
                a->moveDown();
                if (!check(*a, field, width, height)) {
                    for (int i = 0; i < figureSize; i++) {
                        field.setTile((*b)[i], b->getColor());
                    }
                }
            }
            if (a == nullptr || !check(*a, field, width, height)) {
                a = FigureFactory::createRandomSizeFourFigure();
            }
            timer = 0;
        }

        ///////check lines//////////
        field.removeFullLines();

        delay = 0.3;

        /////////draw//////////
        window.clear(Color::White);
        window.draw(background);
        
        for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
             if (field.getTile(i, j) == 0) {
                 continue;
             }
             tile.setTextureRect(IntRect(field.getTile(i, j) * 18, 0, 18, 18));
             tile.setPosition(i * 18, j * 18);
             tile.move(28, 31); //offset
             window.draw(tile);
           }
        }

        if (a != nullptr) {
            for (int i = 0; i < figureSize; i++) {
                tile.setTextureRect(IntRect(a->getColor() * 18, 0, 18, 18));
                tile.setPosition(a->getTiles()[i].x * 18, (*a)[i].y * 18);
                tile.move(28, 31); //offset
                window.draw(tile);
            }
        }

        window.draw(frame);
        window.display();
        
	}

    return 0;
}
