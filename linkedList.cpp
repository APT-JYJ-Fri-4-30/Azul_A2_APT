#include<iostream>
#include"linkedList.h"

using namespace std;

linkedList::linkedList()
{
   head = nullptr;
   tail = nullptr;
}

linkedList::~linkedList()
{}

//add tile to ed of list 
void linkedList::addBack(Tile* newTile)
{
   // check if list is empty 
   if (head == nullptr)
   { 
      Node* node = new Node(newTile, nullptr);
      
      // if empty head and tail both point to new first node
      head = node;
      tail = node;
   }
   else
   {
      Node* node = new Node(newTile, nullptr);

      // Change the last node's next to point to the new last node.
      tail->next = node;

      // Change the tail to point to the new last node.
      tail = node;
   }

}



/*copied reference material

   void addNode(int n)
   {
      node *tmp = new node;
      tmp->data = n;
      tmp->next = NULL;

      if(head == NULL)
      {
         head = tmp;
         tail = tmp;
      }
      else
      {
         tail->next = tmp;
         tail = tail->next;
      }
   }
};*/