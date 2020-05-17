#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

#include "tile.h"

class Node
{
public:
   Node(Tile* newTile, Node* newNext);
   
   Tile* tile;
   Node* next;
};

#endif // ASSIGN2_NODE_H