#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "node.h"

class linkedList
{
public:
   linkedList();
   ~linkedList();
   void addBack(Tile* newTile);
   Node* head;
protected:
   //Node* head;
   Node* tail;
};

#endif //ASSIGN2_LINKEDLIST_H
