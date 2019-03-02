#ifndef Player_h
#define Player_h

#include <string>

using namespace sf;

class Player {
private:
    int x_;
    int y_;
    int direction_;
    Color color_;
    int *control_;
    bool isInGame_;
    std::string name_;
public:
    Player();
    Player(int x, int y, int direction, Color color, int* control, bool isInGame, std::string name);
    Player(const Player& source);
    int getX() const;
    int getY() const;
    int getDirection() const;
    Color getColor() const;
    int getControlDirection(int direction) const;
    std::string getName() const;
    bool getIsInGame() const;
    void setX(int x);
    void setY(int y);
    void setDirection(int direction);
    void setColor(Color color);
    void setIsInGame(bool isInGame);
    void setName(std::string name);
    void moveLeft(int n);
    void moveRight(int n);
    void moveUp(int n);
    void moveDown(int n);
    Player& operator = (const Player& right);
};

Player::Player() {
    x_ = 0;
    y_ = 0;
    color_ = Color::White;
    direction_ = 0;
    control_ = nullptr;
    isInGame_ = false;
    name_ = "";
}

Player::Player(int x, int y, int direction, Color color, int* control, bool isInGame, std::string name) {
    x_ = x;
    y_ = y;
    color_ = color;
    direction_ = direction;
    control_ = new int[4];
    for (int i = 0; i < 4; i++) {
        control_[i] = control[i];
    }
    isInGame_ = isInGame;
    name_ = name;
}

Player::Player(const Player& source) {
    x_ = source.getX();
    y_ = source.getY();
    color_ = source.getColor();
    direction_ = source.getDirection();
    control_ = new int[4];
    for (int i = 0; i < 4; i++) {
        control_[i] = source.getControlDirection(i);
    }
    isInGame_ = source.getIsInGame();
    name_ = source.getName();
}

int Player::getX() const {
    return x_;
}

int Player::getY() const {
    return y_;
}

int Player::getDirection() const {
    return direction_;
}

Color Player::getColor() const {
    return color_;
}

int Player::getControlDirection(int direction) const {
    return control_[direction];
}

bool Player::getIsInGame() const {
    return isInGame_;
}

std::string Player::getName() const {
    return name_;
}

void Player::setX(int x) {
    x_ = x;
}

void Player::setY(int y) {
    y_ = y;
}

void Player::setDirection(int direction) {
    direction_ = direction;
}

void Player::setColor(Color color) {
    color_ = color;
}

void Player::setIsInGame(bool isInGame) {
    isInGame_ = isInGame;
}

void Player::setName(std::string name) {
    name_ = name;
}

void Player::moveLeft(int n) {
    x_ -= n;
}

void Player::moveRight(int n) {
    x_ += n;
}

void Player::moveUp(int n) {
    y_ -= n;
}

void Player::moveDown(int n) {
    y_ += n;
}

Player& Player::operator = (const Player& right) {
    x_ = right.getX();
    y_ = right.getY();
    color_ = right.getColor();
    direction_ = right.getDirection();
    return *this;
}

#endif /* Player_h */
