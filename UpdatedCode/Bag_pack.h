#ifndef  BAG_PACK_H
#define BAG_PACK_H

#include <stdio.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

char bag_pack[5][20];
char tiles[5] = {'B', 'L', 'U', 'R', 'Y'};
class Bag_pack {
public:
    /*___________filled the bag with 5 different colors of tiles with 20 tiles each color___________*/
    void fill_tiles_bag()
    {
        char tile;
        int i = 0, j = 0;
        for(i = 0; i < 5; ++i)
        {
            tile = tiles[i];
            for(j = 0; j < 20; ++j)
            {
                bag_pack[i][j] = tile;
            }
        }
    }

    

    /*___________print tiles in bag___________*/
    void print_bag()
    {
        int i = 0, j = 0;
        cout << "\n=== printing tiles in bag===\n";
        for(i = 0; i < 5; ++i)
        {
            for(j = 0; j < 20; ++j)
            {
                if(bag_pack[i][j] == '\0')
                {
                    cout << "* ";
                }
                else
                {
                    cout << bag_pack[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    /*___________add floor line tiles to bag___________*/
    static void transfer_tiles_to_bag(char tile_color, int tile_count)
    {
        int temp = tile_count;
        int i = 0, j = 0;
        int flag = 0;
        while(tile_count!=0)
        {
            for(i = 0; i < 5; ++i)
            {
                for(j = 0; j < 20; ++j)
                {
                    if(bag_pack[i][j] == '\0')
                    {
                        bag_pack[i][j] = tile_color;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1)
                {
                    flag = 0;
                    break;
                }
            }
            tile_count--;
        }
    }


};

#endif //BAG_PACK_H
