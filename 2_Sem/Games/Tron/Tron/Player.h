#ifndef Player_h
#define Player_h

using namespace sf;

class Player {
private:
    int x_;
    int y_;
    int direction_;
    Color color_;
public:
    Player();
    Player(int x, int y, int direction, Color color);
    Player(const Player& source);
    int getX() const;
    int getY() const;
    int getDirection() const;
    Color getColor() const;
    void setX(int x);
    void setY(int y);
    void setDirection(int direction);
    void setColor(Color color);
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
}

Player::Player(int x, int y, int direction, Color color) {
    x_ = x;
    y_ = y;
    color_ = color;
    direction_ = direction;
}

Player::Player(const Player& source) {
    x_ = source.getX();
    y_ = source.getY();
    color_ = source.getColor();
    direction_ = source.getDirection();
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
