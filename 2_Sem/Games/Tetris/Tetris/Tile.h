#ifndef Tile_h
#define Tile_h

class Tile {
public:
    int x;
    int y;
    Tile& operator = (const Tile& tile);
};

Tile& Tile::operator = (const Tile& tile) {
    x = tile.x;
    y = tile.y;
    return *this;
}

#endif /* Tile_h */
