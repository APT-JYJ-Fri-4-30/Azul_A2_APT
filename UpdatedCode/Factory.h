#ifndef SOURCE_FACTORY_H
#define SOURCE_FACTORY_H

#include <iostream>
#include "LinkList.h"
#include "Bag_pack.h"

using namespace std;
class Factory {
    char factory_arr[5][4];
public:
    /*___________checking of factory array is empty___________*/
    bool Is_factory_display_empty()
    {
        int i = 0, j = 0;
        for(i = 0; i < 5; ++i)
        {
            for(j = 0; j < 4; ++j)
            {
                if(factory_arr[i][j] != '.')
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    /*___________set the factory by randomly selecting 20 tiles from bag and placing tiles on factory display___________*/
    void fill_factory_display()
    {
        int i = 0, j = 0;
        srand(time(0));

        while (i < 5)
        {
            j = 0;
            while (j < 4)
            {
                int i_temp, j_temp;
                int max, min, range;

                max = 4; min = 0;
                range = max - min + 1;
                i_temp = rand() % range + min;

                max = 19; min = 0;
                range = max - min + 1;
                j_temp = rand() % range + min;

                if (bag_pack[i_temp][j_temp] == '\0')
                {
                    continue;
                }
                factory_arr[i][j] = bag_pack[i_temp][j_temp];
                bag_pack[i_temp][j_temp] = '\0';
                ++j;
            }
            ++i;
        }
    }

    /*___________print factory display___________*/
    void print_factory_display(int p)
    {
        int i = 0, j =0;
        cout << "\n\n===factory display:player-"<<(p+1)<<"===\n";
        for(i = 0; i < 5; ++i)
        {
            cout << (i+1) << ": ";
            for(j = 0; j < 4; ++j)
            {
                cout << factory_arr[i][j] << " ";
            }
            cout << "\n";
        }
    }

    /*___________picking tiles from factory display___________*/
    bool picking_tiles_from_factory_display(FD FD_t, int player, Node** head_center_table)
    {
        int i = 0;
        int no_of_tiles = FD_t.select_no_of_tiles;
        int factory_display = FD_t.select_factory_display - 1;

        //check if requested number of tiles are available in center or floor display
        if(Is_requested_tiles_available(FD_t,player, *head_center_table) == 0)
        {
            return 0;
        }
        //picking tiles from center
        if(factory_display == 5)
        {
            int i = 1;
            int no_of_tiles_temp = no_of_tiles;
            Node* last;
            Node* temp = *head_center_table;
            while (temp != NULL)
            {
                if(no_of_tiles_temp == 0)
                {
                    break;
                }
                if(FD_t.select_color == temp->data)
                {
                    temp = temp->next;
                    LinkList::remove_node(head_center_table,i);
                    --no_of_tiles_temp;
                }
                else
                {
                    last = temp;
                    temp = temp->next;
                    ++i;
                }
            }
            tiles_in_center = tiles_in_center - no_of_tiles;
        }
            //picking tiles from factory display
        else
        {
            for(i = 0 ; no_of_tiles!=0 && i<4 ; ++i)
            {
                if(factory_arr[factory_display][i] == FD_t.select_color)
                {
                    factory_arr[factory_display][i] = '.';
                    no_of_tiles--;
                }
            }
            for(i = 0 ; i<4 ; ++i)
            {
                if(factory_arr[factory_display][i] != '.')
                {
                    LinkList::push(head_center_table, factory_arr[factory_display][i]);
                    factory_arr[factory_display][i] = '.';
                    tiles_in_center++;
                }
            }
        }
        return 1;
    }

    /*___________requested number of tiles are available in center or floor display___________*/
    bool Is_requested_tiles_available(FD FD_t, int player, Node* node)
    {
        int i = 0, temp = 0;
        bool ret_val = 0;
        int no_of_tiles = FD_t.select_no_of_tiles;
        int factory_display = FD_t.select_factory_display - 1;
        //check if requested number of tiles are available in center of table
        if(factory_display == 5)
        {
            int temp = 0;
            Node* last;
            while (node != NULL)
            {
                if(node->data == FD_t.select_color)
                {
                    ++temp;
                }
                last = node;
                node = node->next;
            }
            if(temp>=FD_t.select_no_of_tiles)
            {
                return 1;
            }
            else
                return 0;
        }
        else
        {
            for(i = 0 ; i<4 ; ++i)
            {
                if(factory_arr[factory_display][i] == FD_t.select_color)
                {
                    temp++;
                }
                else if(factory_arr[factory_display][i] ==  '.') // incase if we select the FD which is already been taken
                {
                    return 0;
                }
            }
            if(temp>=no_of_tiles)
            {
                ret_val = 1;
            }
        }
        return ret_val;
    }

    /*___________check if same color tiles left over___________*/
    bool Is_same_color_tile_left_over(FD FD_t, int active_player, Node *head_center_table)
    {
        int i= 0, temp = 0;
        bool ret_val = 1;
        if(FD_t.select_factory_display == 6)
        {
            Node* last;
            while (head_center_table != NULL)
            {
                if(head_center_table->data == FD_t.select_color)
                {
                    ++temp;
                }
                last = head_center_table;
                head_center_table = head_center_table->next;
            }
            if(temp>FD_t.select_no_of_tiles)
            {
                ret_val = 0;
            }
        }
        else
        {
            for(i = 0; i < 4; ++i)
            {
                if(factory_arr[FD_t.select_factory_display-1][i] == FD_t.select_color)
                {
                    ++temp;
                }
            }
            if(temp> FD_t.select_no_of_tiles)
                ret_val = 0;
        }
        return ret_val;
    }



};

#endif //SOURCE_FACTORY_H
