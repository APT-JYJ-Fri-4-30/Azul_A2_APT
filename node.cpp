#include "node.h"

// Takes a tile pointer and a node pointer.
Node::Node(Tile* newTile, Node* newNext) 
{
   tile = newTile;
   next = newNext;
}