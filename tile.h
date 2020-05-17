#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <string>
#include <iostream>

typedef char Color;

class Tile
{
public:
   Tile(Color newColor);

   // To get the colour char use tileObject.color or tileObject->color.
   Color color;
};

#endif // ASSIGN2_TILE_H