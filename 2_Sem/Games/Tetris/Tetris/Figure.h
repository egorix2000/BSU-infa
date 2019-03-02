#ifndef Figure_h
#define Figure_h

#include "Tile.h"

class Figure {
protected:
    int n_;
    Tile *tiles_;
    int color_;
public:
    Figure();
    Figure(int n, Tile *tiles, int color);
    Figure(const Figure& source);
    ~Figure();
    int getN() const;
    int getColor() const;
    Tile* getTiles() const;
    void moveLeft();
    void moveRight();
    void Rotate();
    void moveDown();
    Figure& operator = (const Figure right);
    Tile& operator [](int index) const;
};

Figure::Figure() {
    n_ = 0;
    tiles_ = nullptr;
    color_ = 0;
}

Figure::Figure(int n, Tile *tiles, int color) {
    n_ = n;
    color_ = color;
    tiles_ = new Tile[n];
    for (int i = 0; i < n; i++) {
        tiles_[i] = tiles[i];
    }
}

Figure::Figure(const Figure& source) {
    n_ = source.getN();
    color_ = source.getColor();
    int a = 0;
    tiles_ = new Tile[n_];
    for (int i = 0; i < n_; i++) {
        tiles_[i] = source.getTiles()[i];
    }
}

Figure::~Figure() {
    delete [] tiles_;
}

int Figure::getN() const {
    return n_;
}

int Figure::getColor() const {
    return color_;
}

Tile* Figure::getTiles() const {
    return tiles_;
}

Figure& Figure::operator = (const Figure right) {
    n_ = right.getN();
    color_ = right.getColor();
    for (int i = 0; i < n_; i++) {
        tiles_[i] = right.getTiles()[i];
    }
    return *this;
}

void Figure::moveLeft() {
    for (int i = 0; i < n_; i++) {
        tiles_[i].x--;
    }
}

void Figure::moveRight() {
    for (int i = 0; i < n_; i++) {
        tiles_[i].x++;
    }
}

void Figure::Rotate() {
    Tile center = tiles_[1]; //center of rotation
    for (int i = 0; i < n_; i++) {
        int x = tiles_[i].y - center.y;
        int y = tiles_[i].x - center.x;
        tiles_[i].x = center.x - x;
        tiles_[i].y = center.y + y;
    }
}

void Figure::moveDown() {
    for (int i = 0; i < n_; i++) {
        tiles_[i].y++;
    }
}

Tile& Figure::operator [](int index) const {
    return tiles_[index];
}

#endif /* Figure_h */
