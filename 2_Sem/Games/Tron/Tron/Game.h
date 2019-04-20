#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

#include "Player.h"
#include "Field.h"
#include "FormSFML.h"
#include "Database.h"

using namespace sf;
using namespace form;

class Game {
private:
    int width_;
    int height_;
    int speed_;
    std::string pathToProject_;
    Texture backgroundTexture_;
    Sprite background_;
    Field *field_;
    std::vector<Player> players_;
    RenderWindow window_;
    Font font_;
    RenderTexture textureLines_;
    Sprite sprite_;
    Text gameOverText_;
    Text pressAnyKey_;
    bool isGameOver_;
    bool isGameStarted_;
    Player *winner_;
    CircleShape circle_;
    bool doesEnterNameWindowActive_;
    Button confirmNamesButton_;
    std::vector<Input> inputNamePlayers_;
    Database* database_;
public:
    Game(int width, int height, int speed, std::string pathToProjec);
    Game& launchGame();
    Player addRandomPlayer(Color, int *control, std::string name);
    Player& changePlayerRandomly(Player& player, Color color, int width, int height, std::string name);
    Game& restart();
    Game& gameOver();
    Game& enterPlayerNames();
    void tick(Player& player);
};

Game::Game(int width, int height, int speed, std::string pathToProject) {
    width_ = width;
    height_ = height;
    speed_ = speed;
    pathToProject_ = pathToProject;
    
    backgroundTexture_.loadFromFile(pathToProject_ + "images/background.jpg");
    background_.setTexture(backgroundTexture_);
    font_.loadFromFile(pathToProject_ + "fonts/arial.ttf");
    
    field_ = &Field::getInstance(width_, height_);
    database_ = &Database::getInstance(pathToProject_ + "results.txt");
    database_->readScores();
    
    gameOverText_.setFont(font_);
    gameOverText_.setPosition(width_/3.3, height_/3);
    gameOverText_.setCharacterSize(40);
    
    pressAnyKey_.setFont(font_);
    pressAnyKey_.setPosition(width_/4, height_/2);
    pressAnyKey_.setCharacterSize(20);
    pressAnyKey_.setFillColor(Color::White);
    pressAnyKey_.setString("Press space to restart game");
    
    isGameOver_ = false;
    isGameStarted_ = false;
    doesEnterNameWindowActive_ = true;
    confirmNamesButton_.setProberties(20, 20 + (inputNamePlayers_.size() + 1) * 40, 70, 30, "Next", pathToProject_);
    
    circle_.setRadius(1);
}

Player Game::addRandomPlayer(Color color, int *control, std::string name) {
    int x = rand() % width_;
    int y = rand() % height_;
    int direction = rand() % 4;
    players_.push_back(Player(x, y, direction, color, control, true, name));
    inputNamePlayers_.push_back(Input(20, 20 + inputNamePlayers_.size() * 40, 200, 30, "", color));
    confirmNamesButton_.setProberties(20, 20 + (inputNamePlayers_.size() + 1) * 40, 70, 30, "Next", pathToProject_);
    return players_.back();
}

Player& Game::changePlayerRandomly(Player& player, Color color, int width, int height, std::string name) {
    player.setX(rand() % width);
    player.setY(rand() % height);
    player.setDirection(rand() % 4);
    player.setColor(color);
    player.setIsInGame(true);
    player.setName(name);
    return player;
}

Game& Game::launchGame() {
    window_.create(VideoMode(width_, height_), "The Tron Game!");
    window_.setFramerateLimit(60);
    
    while (window_.isOpen()) {
        Event e;
        while (window_.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window_.close();
                break;
            }
        }
        
        if (doesEnterNameWindowActive_) {
            if (e.type == sf::Event::MouseButtonPressed) {
                if (e.mouseButton.button == sf::Mouse::Left) {
                    Vector2i mouse = Mouse::getPosition(window_);
                    
                    if (confirmNamesButton_.select(mouse)) {
                        doesEnterNameWindowActive_ = false;
                        for (int i = 0; i < inputNamePlayers_.size(); i++) {
                            players_[i].setName(inputNamePlayers_[i].readText());
                        }
                    }
                    
                    for (int i = 0; i < inputNamePlayers_.size(); i++) {
                        inputNamePlayers_[i].select(mouse);
                    }
                }
            }
            if (e.type == sf::Event::TextEntered) {
                sleep(milliseconds(300));
                for (int i = 0; i < inputNamePlayers_.size(); i++) {
                    if (inputNamePlayers_[i].select()) {
                        inputNamePlayers_[i].reText(e.text.unicode);
                    }
                }
                
            }
            enterPlayerNames();
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Space) && isGameOver_ && !doesEnterNameWindowActive_) {
            isGameOver_ = false;
            isGameStarted_ = false;
            doesEnterNameWindowActive_ = true;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Space) && !isGameStarted_ && !doesEnterNameWindowActive_) {
            restart();
        }
        
        if (isGameStarted_) {
            for (int i = 0; i < players_.size(); i++) {
                if (e.key.code == players_[i].getControlDirection(0)) {
                    if (players_[i].getDirection() != 2) {
                        players_[i].setDirection(1);
                    }
                }
                if (e.key.code == players_[i].getControlDirection(1)) {
                    if (players_[i].getDirection() != 1) {
                        players_[i].setDirection(2);
                    }
                }
                if (e.key.code == players_[i].getControlDirection(2)) {
                    if (players_[i].getDirection() != 0) {
                        players_[i].setDirection(3);
                    }
                }
                if (e.key.code == players_[i].getControlDirection(3)) {
                    if (players_[i].getDirection() != 3) {
                        players_[i].setDirection(0);
                    }
                }
            }
            
        }
        
        if (isGameOver_ && !doesEnterNameWindowActive_) {
            gameOver();
            continue;
        }
        
        if (!isGameStarted_ && !doesEnterNameWindowActive_) {
            window_.clear();
            window_.draw(sprite_);
            pressAnyKey_.setString("Press space to start game");
            window_.draw(pressAnyKey_);
            window_.display();
        } else if (!doesEnterNameWindowActive_) {
            for(int i = 0; i < speed_; i++) {
                for (int i = 0; i < players_.size(); i++) {
                    if (players_[i].getIsInGame()) {
                        tick(players_[i]);
                        if (field_->getElement(players_[i].getX(), players_[i].getY()) == 1) {
                            players_[i].setIsInGame(false);
                            if (count_if(players_.begin(), players_.end(), [](Player& player){
                                return player.getIsInGame() == true;
                            }) == 1) {
                                winner_ = &(*find_if(players_.begin(), players_.end(), [](Player& player){
                                    return player.getIsInGame() == true;
                                }));
                                isGameOver_ = true;
                                database_->addPoint(winner_->getName());
                                database_->writeScores();
                                break;
                            }
                        }
                    }
                }
                
                for (int i = 0; i < players_.size(); i++) {
                    field_->setElement(players_[i].getX(), players_[i].getY(), 1);
                }
                
                for (int i = 0; i < players_.size(); i++) {
                    field_->setElement(players_[i].getX(), players_[i].getY(), 1);
                    circle_.setPosition(players_[i].getX(),players_[i].getY());
                    circle_.setFillColor(players_[i].getColor());
                    textureLines_.draw(circle_);
                }
                textureLines_.display();
            }
            
            ////// draw  ///////
            window_.clear();
            window_.draw(sprite_);
            window_.display();
        }
    }
    return *this;
}

Game& Game::restart() {
    isGameStarted_ = true;
    isGameOver_ = false;
    field_->clear();
    for (int i = 0; i < players_.size(); i++) {
        changePlayerRandomly(players_[i], players_[i].getColor(), width_, height_, players_[i].getName());
    }
    textureLines_.create(width_, height_);
    textureLines_.setSmooth(true);
    sprite_.setTexture(textureLines_.getTexture());
    textureLines_.clear();
    textureLines_.draw(background_);
    return *this;
}

Game& Game::enterPlayerNames() {
    window_.clear();
    
    window_.draw(confirmNamesButton_.displayButton());
    window_.draw(confirmNamesButton_.displayText());
    
    window_.draw(inputNamePlayers_[0].displayButton());
    window_.draw(inputNamePlayers_[0].displayText());
    for (int i = 0; i < inputNamePlayers_.size(); i++) {
        window_.draw(inputNamePlayers_[i].displayButton());
        window_.draw(inputNamePlayers_[i].displayText());
    }
    window_.display();
    return *this;
}

Game& Game::gameOver() {
    isGameStarted_ = false;
    window_.clear();
    window_.draw(sprite_);
    gameOverText_.setFillColor(winner_->getColor());
    gameOverText_.setString(winner_->getName() + " wins!");
    window_.draw(gameOverText_);
    window_.draw(pressAnyKey_);
    window_.display();
    return *this;
}

void Game::tick(Player& player) {
    if (player.getDirection() == 0) player.moveDown(1);
    if (player.getDirection() == 1) player.moveLeft(1);
    if (player.getDirection() == 2) player.moveRight(1);
    if (player.getDirection() == 3) player.moveUp(1);
    
    if (player.getX() >= width_) player.setX(0);
    if (player.getX() < 0) player.setX(width_-1);
    if (player.getY() >= height_) player.setY(0);
    if (player.getY() < 0) player.setY(height_-1);
}


#endif /* Game_h */
