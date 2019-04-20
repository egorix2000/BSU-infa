#ifndef Tile_h
#define Tile_h

class Tile {
public:
    int x;
    int y;
    Tile();
    Tile(const Tile& tile);
    Tile& operator = (const Tile& tile);
};

Tile::Tile() {
    x = 0;
    y = 0;
}

Tile::Tile(const Tile& tile) {
    x = tile.x;
    y = tile.y;
}

Tile& Tile::operator = (const Tile& tile) {
    x = tile.x;
    y = tile.y;
    return *this;
}

#endif /* Tile_h */
