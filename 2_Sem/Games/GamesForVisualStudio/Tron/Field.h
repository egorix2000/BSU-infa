#ifndef Field_h
#define Field_h

class Field {
private:
    int width_;
    int height_;
    bool **field_;
    Field(int width, int height);
    Field(const Field& field) = delete;
    ~Field();
    Field& operator =(const Field&) = delete;
public:
    static Field& getInstance(int width, int height);
    void setElement(int x, int y, int number);
    bool getElement(int x, int y) const;
    int getWidth() const;
    int getHeight() const;
    void clear();
};

Field& Field::getInstance(int width, int height) {
    static Field field (width, height);
    return field;
}

Field::Field(int width, int height) {
    width_ = width;
    height_ = height;
    field_ = new bool*[width];
    for (int i = 0; i < width; i++) {
        field_[i] = new bool[height];
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

void Field::setElement(int x, int y, int number) {
    field_[x][y] = number;
}

bool Field::getElement(int x, int y) const {
    return field_[x][y];
}

int Field::getWidth() const {
    return width_;
}

int Field::getHeight() const {
    return height_;
}

void Field::clear() {
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            field_[i][j] = 0;
        }
    }
}

#endif /* Field_h */
