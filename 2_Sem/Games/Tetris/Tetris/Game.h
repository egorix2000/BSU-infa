#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>

#include "Field.h"
#include "Figure.h"
#include "FigureFactory.h"

using namespace sf;

class Game {
private:
    std::string pathToProject_;
    int screenWidth_;
    int screenHeight_;
    int figureSize_;
    float timer_;
    float delaySlow_;
    float delayFast_;
    float delayCurrent_;
    bool isGameStarted_;
    bool isGameOver_;
    int score_;
    std::ifstream fin_;
    std::ofstream fout_;
    Field *field_;
    Figure *a_;
    Figure *b_;
    Font font_;
    Text gameOverText_;
    Text pressAnyKey_;
    Text yourScoreText_;
    Text maxScoreText_;
    Text currentScoreText_;
    Texture backgroundTexture_;
    Texture tilesTexture_;
    Texture frameTexture_;
    Sprite backgroundSprite_;
    Sprite tileSprite_;
    Sprite frameSprite_;
    Clock clock_;
    RenderWindow window_;
    RectangleShape blackRectangle_;
    RectangleShape blackScoreRectangle_;
public:
    Game(int screenWidth, int screenHeight, int fieldWidth, int fieldHeight,
         int figureSize, double delaySlow, double delayFast, std::string pathToProject);
    ~Game();
    Game& launchGame();
    Game& restart();
    Game& gameOver();
    bool check(const Figure& a) const;
    bool checkForGameOver(const Figure& a) const;
    void draw();
    void tick();
};

Game::Game(int screenWidth, int screenHeight, int fieldWidth, int fieldHeight,
            int figureSize, double delaySlow, double delayFast, std::string pathToProject) {
    
    pathToProject_ = pathToProject;
    
    tilesTexture_.loadFromFile(pathToProject + "images/tiles.png");
    backgroundTexture_.loadFromFile(pathToProject + "images/background.png");
    frameTexture_.loadFromFile(pathToProject + "images/frame.png");
    font_.loadFromFile(pathToProject + "arial.ttf");
    
    tileSprite_.setTexture(tilesTexture_);
    backgroundSprite_.setTexture(backgroundTexture_);
    frameSprite_.setTexture(frameTexture_);
    screenWidth_ = screenWidth;
    screenHeight_ = screenHeight;
    figureSize_ = figureSize;
    timer_ = 0;
    delayCurrent_ = delaySlow;
    delaySlow_ = delaySlow;
    delayFast_ = delayFast;
    field_ = &Field::getInstance(fieldWidth, fieldHeight);
    isGameStarted_ = false;
    isGameOver_ = false;
    score_ = 0;
    
    a_ = nullptr;
    b_ = nullptr;
    
    gameOverText_.setFont(font_);
    gameOverText_.setPosition(screenWidth/5, screenHeight/7);
    gameOverText_.setCharacterSize(30);
    gameOverText_.setFillColor(Color::Red);
    gameOverText_.setString("Game Over!");
    
    pressAnyKey_.setFont(font_);
    pressAnyKey_.setPosition(15, screenHeight/5);
    pressAnyKey_.setCharacterSize(20);
    pressAnyKey_.setFillColor(Color::White);
    pressAnyKey_.setString("Press space to restart game");
    
    yourScoreText_.setFont(font_);
    yourScoreText_.setPosition(screenWidth/5, screenHeight/4);
    yourScoreText_.setCharacterSize(20);
    yourScoreText_.setFillColor(Color::White);
    
    maxScoreText_.setFont(font_);
    maxScoreText_.setPosition(screenWidth/5, screenHeight/3);
    maxScoreText_.setCharacterSize(20);
    maxScoreText_.setFillColor(Color::White);
    
    currentScoreText_.setFont(font_);
    currentScoreText_.setPosition(screenWidth - screenWidth/4 + 5, 35);
    currentScoreText_.setCharacterSize(30);
    currentScoreText_.setFillColor(Color::White);
    
    
    blackRectangle_.setPosition(0, 0);
    blackRectangle_.setSize(Vector2f(screenWidth_, screenHeight_));
    blackRectangle_.setFillColor(Color(0, 0, 0, 130));
    
    blackScoreRectangle_.setPosition(screenWidth - screenWidth/4, 30);
    blackScoreRectangle_.setSize(Vector2f(70, 50));
    blackScoreRectangle_.setFillColor(Color(0, 0, 0, 170));
}

Game::~Game() {
    delete a_;
    delete b_;
}

Game& Game::launchGame() {
    window_.create(VideoMode(screenWidth_, screenHeight_), "The Tetris Game!");
    
    while (window_.isOpen()) {
        
        float time = clock_.getElapsedTime().asSeconds();
        clock_.restart();
        timer_ += time;
        
        Event e;
        while (window_.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window_.close();
            }
            
            if (e.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed(Keyboard::Space) && !isGameStarted_) {
                    restart();
                }
                if (a_ != nullptr && isGameStarted_) {
                    delete b_;
                    b_ = new Figure(*a_);
                    if (e.key.code == Keyboard::Up) {
                        a_->Rotate();
                    } else if (e.key.code == Keyboard::Left) {
                        a_->moveLeft();
                    } else if (e.key.code == Keyboard::Right) {
                        a_->moveRight();
                    }
                    
                    if (!check(*a_)) {
                        delete a_;
                        a_ = new Figure(*b_);
                    }
                }
            }
        }
        
        if (isGameOver_) {
            gameOver();
            continue;
        }
        
        if (!isGameStarted_) {
            window_.clear();
            window_.draw(backgroundSprite_);
            window_.draw(blackRectangle_);
            pressAnyKey_.setString("Press space to start game");
            window_.draw(pressAnyKey_);
            window_.display();
        } else {
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                delayCurrent_ = delayFast_;
            }
            
            if (timer_ > delayCurrent_) {
                tick();
            }
            
            score_ += field_->removeFullLines();
            delayCurrent_ = delaySlow_;
            draw();
        }
    }
    return *this;
}

Game& Game::restart() {
    isGameStarted_ = true;
    isGameOver_ = false;
    score_ = 0;
    
    field_->clear();
    
    a_ = nullptr;
    b_ = nullptr;
    return *this;
}

Game& Game::gameOver() {
    isGameStarted_ = false;
    window_.draw(backgroundSprite_);
    for (int i = 0; i < field_->getWidth(); i++) {
        for (int j = 0; j < field_->getHeight(); j++) {
            if (field_->getTile(i, j) == 0) {
                continue;
            }
            tileSprite_.setTextureRect(IntRect(field_->getTile(i, j) * 18, 0, 18, 18));
            tileSprite_.setPosition(i * 18, j * 18);
            tileSprite_.move(28, 31); //offset
            window_.draw(tileSprite_);
        }
    }
    
    fin_.open(pathToProject_ + "maxScore.txt");
    int maxScore = 0;
    fin_ >> maxScore;
    
    if (score_ > maxScore) {
        fout_.open(pathToProject_ + "maxScore.txt", std::ofstream::out | std::ofstream::trunc);
        maxScore = score_;
        fout_ << maxScore;
        fout_.close();
    }
    
    fin_.close();
    
    yourScoreText_.setString("Your score: " + std::to_string(score_));
    maxScoreText_.setString("Max score: " + std::to_string(maxScore));
    
    window_.draw(frameSprite_);
    window_.draw(blackRectangle_);
    window_.draw(gameOverText_);
    window_.draw(pressAnyKey_);
    window_.draw(yourScoreText_);
    window_.draw(maxScoreText_);
    window_.display();
    return *this;
}

void Game::tick() {
    if (a_ != nullptr) {
        delete b_;
        b_ = new Figure(*a_);
        a_->moveDown();
        if (!check(*a_)) {
            for (int i = 0; i < figureSize_; i++) {
                field_->setTile((*b_)[i], b_->getColor());
            }
        }
    }
    if (a_ == nullptr || !check(*a_)) {
        if (a_ != nullptr && checkForGameOver(*a_)) {
            isGameOver_ = true;
            isGameStarted_ = false;
        } else {
            a_ = FigureFactory::createRandomSizeFourFigure();
        }
    }
    timer_ = 0;
}

void Game::draw() {
    window_.clear();
    window_.draw(backgroundSprite_);
    
    for (int i = 0; i < field_->getWidth(); i++) {
        for (int j = 0; j < field_->getHeight(); j++) {
            if (field_->getTile(i, j) == 0) {
                continue;
            }
            tileSprite_.setTextureRect(IntRect(field_->getTile(i, j) * 18, 0, 18, 18));
            tileSprite_.setPosition(i * 18, j * 18);
            tileSprite_.move(28, 31); //offset
            window_.draw(tileSprite_);
        }
    }
    
    if (a_ != nullptr) {
        for (int i = 0; i < figureSize_; i++) {
            tileSprite_.setTextureRect(IntRect(a_->getColor() * 18, 0, 18, 18));
            tileSprite_.setPosition(a_->getTiles()[i].x * 18, (*a_)[i].y * 18);
            tileSprite_.move(28, 31); //offset
            window_.draw(tileSprite_);
        }
    }
    currentScoreText_.setString(std::to_string(score_));
    
    window_.draw(blackScoreRectangle_);
    window_.draw(currentScoreText_);
    window_.draw(frameSprite_);
    window_.display();
}

bool Game::check(const Figure& a) const {
    for (int i = 0; i < a.getN(); i++) {
        if (a[i].x < 0 || a[i].x >= field_->getWidth() || a[i].y >= field_->getHeight()) {
            return false;
        }
        else if (field_->getTile(a[i].x, a[i].y)) {
            return false;
        }
    }
    return true;
};

bool Game::checkForGameOver(const Figure& a) const {
    for (int i = 0; i < a.getN(); i++) {
        if (a[i].y <= 1) {
            return true;
        }
    }
    return false;
}

#endif /* Game_h */
