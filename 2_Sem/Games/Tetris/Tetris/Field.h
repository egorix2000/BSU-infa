#ifndef Field_h
#define Field_h

#include "Tile.h"

class Field {
private:
    int width_;
    int height_;
    int **field_;
    Field(int width, int height);
    Field(const Field& field) = delete;
    ~Field();
    Field& operator =(const Field&) = delete;
public:
    static Field& getInstance(int width, int height);
    int getWidth() const;
    int getHeight() const;
    void removeFullLines();
    void setTile(const Tile& tile, int color);
    int getTile(int x, int y) const;
};

Field& Field::getInstance(int width, int height) {
    static Field field (width, height);
    return field;
}

Field::Field(int width, int height) {
    width_ = width;
    height_ = height;
    field_ = new int*[width];
    for (int i = 0; i < width; i++) {
        field_[i] = new int[height];
        for (int j = 0; j < height; j++) {
            field_[i][j] = 0;
        }
    }
}

Field::~Field() {
    for (int i = 0; i < width_; i++) {
        delete [] field_[i];
    }
    delete [] field_;
}

void Field::setTile(const Tile& tile, int color) {
    field_[tile.x][tile.y] = color;
}

int Field::getTile(int x, int y) const {
    return field_[x][y];
}

int Field::getWidth() const {
    return width_;
}

int Field::getHeight() const {
    return height_;
}

void Field::removeFullLines() {
    int k = height_ - 1;
    int count = 0;
    for (int i = height_ - 1; i > 0; i--) {
        count = 0;
        for (int j = 0; j < width_; j++) {
            if (field_[j][i] != 0) {
                count++;
            }
            field_[j][k] = field_[j][i];
        }
        if (count < width_) {
            k--;
        }
    }
}

#endif /* Field_h */
