#include"linkedList.h"

int main()
{
   char colors[5] = {'R', 'Y', 'B', 'L', 'U'};
   linkedList a;
   Tile* tile = new Tile(colors[1]);
   a.addBack(tile);
   return 0;
}