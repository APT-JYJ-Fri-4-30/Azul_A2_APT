#include <iostream>
#include <stdio.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include "util.h"
#include "Bag_pack.h"
#include "util.h"
#include "Factory.h"
#include "Wall_tiles.h"

using namespace std;
using std::cout;
using std::cin;
using std::endl;

/*___________check tiles in corresponding wall___________*/
bool check_tiles_in_corresponding_wall(FD FD_t, int pattern_line, int active_player, wall_tiles WL[])
{
    // it will return one if wall has no same color tiles or no tiles
    //it will return 0 if wall has same color tiles already
    int i = 0;
    if (pattern_line == 1)
    {
        for (i = 0; i < 5; ++i)
        {
            if ((WL[active_player].tile_line1[i] != '.') && (WL[active_player].tile_line1[i] == FD_t.select_color))
            {
                return 0;
            }
        }
    }
    else if (pattern_line == 2)
    {
        for (i = 0; i < 5; ++i)
        {
            if ((WL[active_player].tile_line2[i] != '.') && (WL[active_player].tile_line2[i] == FD_t.select_color))
            {
                return 0;
            }
        }
    }
    else if (pattern_line == 3)
    {
        for (i = 0; i < 5; ++i)
        {
            if ((WL[active_player].tile_line3[i] != '.') && (WL[active_player].tile_line3[i] == FD_t.select_color))
            {
                return 0;
            }
        }
    }
    else if (pattern_line == 4)
    {
        for (i = 0; i < 5; ++i)
        {
            if ((WL[active_player].tile_line4[i] != '.') && (WL[active_player].tile_line4[i] == FD_t.select_color))
            {
                return 0;
            }
        }
    }
    else
    {
        for (i = 0; i < 5; ++i)
        {
            if ((WL[active_player].tile_line5[i] != '.') && (WL[active_player].tile_line5[i] == FD_t.select_color))
            {
                return 0;
            }
        }
    }
    return 1;
}

/*___________drawing center of table___________*/
void print_center_table(Node* head_center_table)
{
    Node* last;
    std::cout << "\n\n===center of the table===\n";
    while (head_center_table != NULL) {
        std::cout << head_center_table->data << " ";
        last = head_center_table;
        head_center_table = head_center_table->next;
    }
    std::cout << "\n\n";
}


/*___________drawing mosiac for player___________*/
void draw_mosiac(pattern_lines PL[], wall_tiles WL[], int p)
{
    int i = 0;
    cout << (i + 1) << ": ";
    printf("%c %c %c %c %c ", PL[p].pattern_line1[0], PL[p].pattern_line1[1], PL[p].pattern_line1[2], PL[p].pattern_line1[3], PL[p].pattern_line1[4]);
    printf("|| ");
    printf("%c %c %c %c %c \n", WL[p].tile_line1[0], WL[p].tile_line1[1], WL[p].tile_line1[2], WL[p].tile_line1[3], WL[p].tile_line1[4]);

    cout << (i + 2) << ": ";
    printf("%c %c %c %c %c ", PL[p].pattern_line2[0], PL[p].pattern_line2[1], PL[p].pattern_line2[2], PL[p].pattern_line2[3], PL[p].pattern_line2[4]);
    printf("|| ");
    printf("%c %c %c %c %c \n", WL[p].tile_line2[0], WL[p].tile_line2[1], WL[p].tile_line2[2], WL[p].tile_line2[3], WL[p].tile_line2[4]);

    cout << (i + 3) << ": ";
    printf("%c %c %c %c %c ", PL[p].pattern_line3[0], PL[p].pattern_line3[1], PL[p].pattern_line3[2], PL[p].pattern_line3[3], PL[p].pattern_line3[4]);
    printf("|| ");
    printf("%c %c %c %c %c \n", WL[p].tile_line3[0], WL[p].tile_line3[1], WL[p].tile_line3[2], WL[p].tile_line3[3], WL[p].tile_line3[4]);

    cout << (i + 4) << ": ";
    printf("%c %c %c %c %c ", PL[p].pattern_line4[0], PL[p].pattern_line4[1], PL[p].pattern_line4[2], PL[p].pattern_line4[3], PL[p].pattern_line4[4]);
    printf("|| ");
    printf("%c %c %c %c %c \n", WL[p].tile_line4[0], WL[p].tile_line4[1], WL[p].tile_line4[2], WL[p].tile_line4[3], WL[p].tile_line4[4]);

    cout << (i + 5) << ": ";
    printf("%c %c %c %c %c ", PL[p].pattern_line5[0], PL[p].pattern_line5[1], PL[p].pattern_line5[2], PL[p].pattern_line5[3], PL[p].pattern_line5[4]);
    printf("|| ");
    printf("%c %c %c %c %c \n", WL[p].tile_line5[0], WL[p].tile_line5[1], WL[p].tile_line5[2], WL[p].tile_line5[3], WL[p].tile_line5[4]);

    cout << "broken" << ": ";
    printf("%c %c %c %c %c %c %c\n", PL[p].floor_line[0], PL[p].floor_line[1], PL[p].floor_line[2], PL[p].floor_line[3], PL[p].floor_line[4], PL[p].floor_line[5], PL[p].floor_line[6]);
}



/*___________add tiles to floor line___________*/
void adding_tiles_to_floorline(pattern_lines PL[], char tile_color, int tile_count, int player)
{
    int i = 0, j = 0;
    int floor_line_size = 7;
    player = player - 1;
    if (PL[player].tiles_in_floorline >= 7)
    {
        Bag_pack::transfer_tiles_to_bag(tile_count, tile_color);
    }
    for (i = 0, j = PL[player].tiles_in_floorline; i < tile_count && i < floor_line_size; ++i, ++j)
    {
        PL[player].floor_line[j] = tile_color;
        PL[player].tiles_in_floorline++;
    }
}

/*___________checking pattern line ___________*/
int Is_pattern_line_full(pattern_lines PL[], int player, int pattern_line, FD FD_t)
{
    int i = 0, existing_tiles_in_pattern_lines = 0;
    int color_flag = 0;
    if (pattern_line == 1)
    {
        for (i = 4; i >= 5 - pattern_line; --i)
        {
            if (PL[player].pattern_line1[i] != '.')
            {
                ++existing_tiles_in_pattern_lines;
                if (FD_t.select_color != PL[player].pattern_line1[i])
                {
                    color_flag = 1;
                }
            }
        }
    }
    else if (pattern_line == 2)
    {
        for (i = 4; i >= 5 - pattern_line; --i)
        {
            if (PL[player].pattern_line2[i] != '.')
            {
                ++existing_tiles_in_pattern_lines;
                if (FD_t.select_color != PL[player].pattern_line2[i])
                {
                    color_flag = 1;
                }
            }
        }
    }
    else if (pattern_line == 3)
    {
        for (i = 4; i >= 5 - pattern_line; --i)
        {
            if (PL[player].pattern_line3[i] != '.')
            {
                ++existing_tiles_in_pattern_lines;
                if (FD_t.select_color != PL[player].pattern_line3[i])
                {
                    color_flag = 1;
                }
            }
        }
    }
    else if (pattern_line == 4)
    {
        for (i = 4; i >= 5 - pattern_line; --i)
        {
            if (PL[player].pattern_line4[i] != '.')
            {
                ++existing_tiles_in_pattern_lines;
                if (FD_t.select_color != PL[player].pattern_line4[i])
                {
                    color_flag = 1;
                }
            }
        }
    }
    else if (pattern_line == 5)
    {
        for (i = 4; i >= 5 - pattern_line; --i)
        {
            if (PL[player].pattern_line5[i] != '.')
            {
                ++existing_tiles_in_pattern_lines;
                if (FD_t.select_color != PL[player].pattern_line5[i])
                {
                    color_flag = 1;
                }
            }
        }
    }
    else
    {
        // do nothing
    }
    if (existing_tiles_in_pattern_lines == pattern_line) // pattern line is fully filled
    {
        return 1;
    }
    else if (color_flag == 0 && existing_tiles_in_pattern_lines != pattern_line && existing_tiles_in_pattern_lines != 0)//pattern line partially filled with same color
    {
        return 0;
    }
    else if (color_flag == 1) // partially filled with different color
    {
        return 2;
    }
    else // pattern line is empty
    {
        return 0;
    }
}

/*___________placing tiles in pattern lines___________*/
bool filling_pattern_line(FD FD_t, int pattern_line, int player, pattern_lines PL[])
{
    int i = 0;
    int tiles_in_hand = FD_t.select_no_of_tiles;
    int pattern_line_status = 0;

    //enter correct pattern line
    if (pattern_line > 5 || pattern_line < 1)
    {
        cout << "Enter correct pattern line.\n";
        return 0;
    }

    //checking pattern line
    pattern_line_status = Is_pattern_line_full(PL, player, pattern_line, FD_t);

    //if pattern line is fully filled
    if ((pattern_line_status == 1) || (pattern_line_status == 2))
    {
        cout << "this Pattern line is filled\n";
        return 0;
    }
    else
    {
        if (pattern_line == 1)
        {
            PL[player].pattern_line1[4] = FD_t.select_color;
            tiles_in_hand--;
        }
        if (pattern_line == 2)
        {
            for (i = 4; i >= 5 - pattern_line && tiles_in_hand != 0; --i)
            {
                if (PL[player].pattern_line2[i] == '.')
                {
                    PL[player].pattern_line2[i] = FD_t.select_color;
                    tiles_in_hand--;
                }
            }
        }
        if (pattern_line == 3)
        {
            for (i = 4; i >= 5 - pattern_line && tiles_in_hand != 0; --i)
            {
                if (PL[player].pattern_line3[i] == '.')
                {
                    PL[player].pattern_line3[i] = FD_t.select_color;
                    tiles_in_hand--;
                }
            }
        }
        if (pattern_line == 4)
        {
            for (i = 4; i >= 5 - pattern_line && tiles_in_hand != 0; --i)
            {
                if (PL[player].pattern_line4[i] == '.')
                {
                    PL[player].pattern_line4[i] = FD_t.select_color;
                    tiles_in_hand--;
                }
            }
        }
        if (pattern_line == 5)
        {
            for (i = 4; i >= 5 - pattern_line && tiles_in_hand != 0; --i)
            {
                if (PL[player].pattern_line5[i] == '.')
                {
                    PL[player].pattern_line5[i] = FD_t.select_color;
                    tiles_in_hand--;
                }
            }
        }
        adding_tiles_to_floorline(PL, FD_t.select_color, tiles_in_hand, player + 1);
        return 1;
    }
}

void clear_pattern_line(pattern_lines PL[], int pattern_lines, int player)
{
    int i = 0;
    if (pattern_lines == 1)
    {
        for (i = 4; i >= (5 - pattern_lines); --i)
        {
            PL[player].pattern_line1[i] = '.';
        }
    }
    else if (pattern_lines == 2)
    {
        for (i = 4; i >= (5 - pattern_lines); --i)
        {
            PL[player].pattern_line2[i] = '.';
        }
    }
    else if (pattern_lines == 3)
    {
        for (i = 4; i >= (5 - pattern_lines); --i)
        {
            PL[player].pattern_line3[i] = '.';
        }
    }
    else if (pattern_lines == 4)
    {
        for (i = 4; i >= (5 - pattern_lines); --i)
        {
            PL[player].pattern_line4[i] = '.';
        }
    }
    else
    {
        for (i = 4; i >= (5 - pattern_lines); --i)
        {
            PL[player].pattern_line5[i] = '.';
        }
    }
}
void add_tiles_to_bag(Bag_pack& bag_pack, pattern_lines PL[], int pattern_lines, int player, char tile_color)
{
    int i = 0;
    if (pattern_lines == 2)
    {
        bag_pack.transfer_tiles_to_bag(tile_color, 1);
    }
    else if (pattern_lines == 3)
    {
        bag_pack.transfer_tiles_to_bag(tile_color, 2);
    }
    else if (pattern_lines == 4)
    {
        bag_pack.transfer_tiles_to_bag(tile_color, 3);
    }
    else if (pattern_lines == 5)
    {
        bag_pack.transfer_tiles_to_bag(tile_color, 4);
    }
}


/*___________shifting tiles to wall___________*/
void shift_rightmost_tile_to_wall_of_Matching_color(Bag_pack& bag_pack, wall_tiles WL[], pattern_lines PL[], int pattern_lines, int player)
{
    int current_y = 0;
    if (pattern_lines == 1)
    {
        if (PL[player].pattern_line1[4] == 'B')
        {
            WL[player].tile_line1[0] = 'B';
            current_y = 0;
        }
        else if (PL[player].pattern_line1[4] == 'Y')
        {
            WL[player].tile_line1[1] = 'Y';
            current_y = 1;
        }
        else if (PL[player].pattern_line1[4] == 'R')
        {
            WL[player].tile_line1[2] = 'R';
            current_y = 2;
        }
        else if (PL[player].pattern_line1[4] == 'U')
        {
            WL[player].tile_line1[3] = 'U';
            current_y = 3;
        }
        else if (PL[player].pattern_line1[4] == 'L')
        {
            WL[player].tile_line1[4] = 'L';
            current_y = 4;
        }
    }
    else if (pattern_lines == 2)
    {
        if (PL[player].pattern_line2[4] == 'L')
        {
            WL[player].tile_line2[0] = 'L';
            add_tiles_to_bag(bag_pack,PL, pattern_lines, player, 'L');
            current_y = 0;
        }
        else if (PL[player].pattern_line2[4] == 'B')
        {
            WL[player].tile_line2[1] = 'B';
            add_tiles_to_bag(bag_pack,PL, pattern_lines, player, 'B');
            current_y = 1;
        }
        else if (PL[player].pattern_line2[4] == 'Y')
        {
            WL[player].tile_line2[2] = 'Y';
            add_tiles_to_bag(bag_pack,PL, pattern_lines, player, 'Y');
            current_y = 2;
        }
        else if (PL[player].pattern_line2[4] == 'R')
        {
            WL[player].tile_line2[3] = 'R';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'R');
            current_y = 3;
        }
        else if (PL[player].pattern_line2[4] == 'U')
        {
            WL[player].tile_line2[4] = 'U';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'U');
            current_y = 4;
        }
    }
    else if (pattern_lines == 3)
    {
        if (PL[player].pattern_line3[4] == 'U')
        {
            WL[player].tile_line3[0] = 'U';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'U');
            current_y = 0;
        }
        else if (PL[player].pattern_line3[4] == 'L')
        {
            WL[player].tile_line3[1] = 'L';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'L');
            current_y = 1;
        }
        else if (PL[player].pattern_line3[4] == 'B')
        {
            WL[player].tile_line3[2] = 'B';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'B');
            current_y = 2;
        }
        else if (PL[player].pattern_line3[4] == 'Y')
        {
            WL[player].tile_line3[3] = 'Y';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'Y');
            current_y = 3;
        }
        else if (PL[player].pattern_line3[4] == 'R')
        {
            WL[player].tile_line3[4] = 'R';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'R');
            current_y = 4;
        }
    }
    else if (pattern_lines == 4)
    {
        if (PL[player].pattern_line4[4] == 'R')
        {
            WL[player].tile_line4[0] = 'R';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'R');
            current_y = 0;
        }
        else if (PL[player].pattern_line4[4] == 'U')
        {
            WL[player].tile_line4[1] = 'U';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'U');
            current_y = 1;
        }
        else if (PL[player].pattern_line4[4] == 'L')
        {
            WL[player].tile_line4[2] = 'L';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'L');
            current_y = 2;
        }
        else if (PL[player].pattern_line4[4] == 'B')
        {
            WL[player].tile_line4[3] = 'B';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'B');
            current_y = 3;
        }
        else if (PL[player].pattern_line4[4] == 'Y')
        {
            WL[player].tile_line4[4] = 'Y';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'Y');
            current_y = 4;
        }
    }
    else
    {
        if (PL[player].pattern_line5[4] == 'Y')
        {
            WL[player].tile_line5[0] = 'Y';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'Y');
            current_y = 0;
        }
        else if (PL[player].pattern_line5[4] == 'R')
        {
            WL[player].tile_line5[1] = 'R';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'R');
            current_y = 1;
        }
        else if (PL[player].pattern_line5[4] == 'U')
        {
            WL[player].tile_line5[2] = 'U';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'U');
            current_y = 2;
        }
        else if (PL[player].pattern_line5[4] == 'L')
        {
            WL[player].tile_line5[3] = 'L';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'L');
            current_y = 3;
        }
        else if (PL[player].pattern_line5[4] == 'B')
        {
            WL[player].tile_line5[4] = 'B';
            add_tiles_to_bag(bag_pack, PL, pattern_lines, player, 'B');
            current_y = 4;
        }
    }
    clear_pattern_line(PL, pattern_lines, player);
    Wall_tiles::store_walls_in_arr(WL, player);
    Wall_tiles::add_score(WL, pattern_lines, player, current_y);
}



/*___________Wall tiling___________*/
void wall_tiling(Bag_pack& bag_pack, pattern_lines PL[], wall_tiles WL[], int player, FD FD_t)
{
    if (Is_pattern_line_full(PL, player, 1, FD_t) == 1)
    {
        shift_rightmost_tile_to_wall_of_Matching_color(bag_pack, WL, PL, 1, player);
    }
    if (Is_pattern_line_full(PL, player, 2, FD_t) == 1)
    {
        shift_rightmost_tile_to_wall_of_Matching_color(bag_pack, WL, PL, 2, player);
    }
    if (Is_pattern_line_full(PL, player, 3, FD_t) == 1)
    {
        shift_rightmost_tile_to_wall_of_Matching_color(bag_pack, WL, PL, 3, player);
    }
    if (Is_pattern_line_full(PL, player, 4, FD_t) == 1)
    {
        shift_rightmost_tile_to_wall_of_Matching_color(bag_pack, WL, PL, 4, player);
    }
    if (Is_pattern_line_full(PL, player, 5, FD_t) == 1)
    {
        shift_rightmost_tile_to_wall_of_Matching_color(bag_pack, WL, PL, 5, player);
    }
}

bool newGame()
{
    Factory factory;
    Bag_pack bag_pack;
    Wall_tiles wall;

    //local variables
    
    int i, j;
    int end_game_track = 0;
    bool active_player = 0;
    char tile;
    int pattern_line = 0;
    int placement_succes_flag = 0;
    bool tile_picking_success_flag = 0;
    Node* head_center_table = NULL;
    char player_1[15];
    char player_2[15];

    //Enter player details
    cout << "Please enter player 1 name:";
    cin >> player_1;

    cout << "Please enter player 2 name:";
    cin >> player_2;

    //Creating empty mosiac for 2 players
    pattern_lines PL[2] =
    {
            {{' ',' ',' ',' ','.'},{' ',' ',' ','.','.'},{' ',' ','.','.','.'},{' ','.','.','.','.'},{'.','.','.','.','.'},{'\0'},0},
            {{' ',' ',' ',' ','.'},{' ',' ',' ','.','.'},{' ',' ','.','.','.'},{' ','.','.','.','.'},{'.','.','.','.','.'},{'\0'},0}
    };
    wall_tiles WL[2] =
    {
            {{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},0},
            {{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},{'.','.','.','.','.'},0}
    };


    //filled the bag with 5 different colors of tiles with 20 tiles each color
    bag_pack.fill_tiles_bag();

    //set the factory by randomly selecting 20 tiles from bag and placing 4 tiles on each factory display
    factory.fill_factory_display();

    //start the game
    cout << "===Start the game===";

    //printing bag tiles
    bag_pack.print_bag();

    while (1)
    {
        while (1)
        {
            cout << "\n====================Turn for player:" << (active_player + 1) << "====================";

            //print factory display
            factory.print_factory_display(active_player);

            //drawing mosiac for player
            cout << "\n\n===Mosiac for Player-" << (active_player + 1) << "===\n";
            draw_mosiac(PL, WL, active_player);

            //drawing center of table
            print_center_table(head_center_table);


            //Select Factory Display
            tile_picking_success_flag = 0;
            FD FD_t = { -1, -1, 0 };
            while (tile_picking_success_flag != 1)
            {
                FD_t.select_color = 0; FD_t.select_factory_display = -1; FD_t.select_no_of_tiles = -1;
                while ((FD_t.select_factory_display > 6 || FD_t.select_factory_display < 0) || (FD_t.select_no_of_tiles < 1) || (!((FD_t.select_color == 'B') || (FD_t.select_color == 'L') || (FD_t.select_color == 'U') || (FD_t.select_color == 'R') || (FD_t.select_color == 'Y'))))
                {

                    cout << "enter factory_display_number tiles_color number_of_tiles in same order:> ";
                    cin >> FD_t.select_factory_display >> FD_t.select_color >> FD_t.select_no_of_tiles;
                }

                tile_picking_success_flag = factory.Is_same_color_tile_left_over(FD_t, active_player, head_center_table);

                //picking tiles from factory display

                if (tile_picking_success_flag == 1)
                    tile_picking_success_flag = factory.picking_tiles_from_factory_display(FD_t, active_player, &head_center_table);
            }
            cout << "tiles successfully picked\n";


            //placing tiles in pattern lines
            pattern_line = 0;
            placement_succes_flag = 0;
            while (placement_succes_flag != 1)
            {
                cout << "for pattern line enter[1-5], for floor line enter[6]\n";
                cout << "which pattern line you want to put your tiles in:";
                cin >> pattern_line;
                if (pattern_line == 6)
                {
                    adding_tiles_to_floorline(PL, FD_t.select_color, FD_t.select_no_of_tiles, active_player + 1);
                    break;
                }
                placement_succes_flag = check_tiles_in_corresponding_wall(FD_t, pattern_line, active_player, WL);
                if (placement_succes_flag == 1)
                {
                    placement_succes_flag = filling_pattern_line(FD_t, pattern_line, active_player, PL);
                }
            }
            cout << "tiles successfully placed\n";

            //alterning chances of player
            active_player = !active_player;

            //if tiles in center and factory display are finished goto wall tiling stage
            if ((head_center_table == NULL) && (factory.Is_factory_display_empty() == 1))
            {
                break;
            }

        }

        cout << "\n==========================================================================";
        cout << "\n==========================Results of wall tiling==========================";

        FD FD_t = { -1, -1, 0 };
        //wall tiling by player-1
        wall_tiling(bag_pack, PL, WL, 0, FD_t);

        //drawing mosiac for player-1
        cout << "\n\n===Mosiac for Player-1" << "===\n";
        draw_mosiac(PL, WL, 0);

        //wall tiling by player-2
        wall_tiling(bag_pack, PL, WL, 1, FD_t);

        //drawing mosiac for player-2
        cout << "\n\n===Mosiac for Player-2" << "===\n";
        draw_mosiac(PL, WL, 1);

        //cheking game is over for player-1
        if (1 == wall.Is_game_ended(PL, WL, 0))
        {
            end_game_track = 1;
        }
        // game is over for player-2
        if (1 == wall.Is_game_ended(PL, WL, 1))
        {
            end_game_track = 1;
        }

        if (end_game_track == 1)
        {
            cout << "\nGame is over!!\n\n";
            break;
        }

        //filling factory display
        factory.fill_factory_display();

        //printing bag tiles
        bag_pack.print_bag();

        //check end game

    }
}

int main()
{
   int input;

    bool exit = false;

    cout <<"\nWelcome to Azul!"<<endl;
    cout <<"-------------------"<<endl;

    while(!exit)
    {
        cout<<"Menu\n----"<<endl;
        cout<< "1. New Game"<<endl;
        cout<< "2. Load Game"<<endl;
        cout<< "3. Credits (Show student information)"<<endl;
        cout<< "4. Quit"<<endl;
        cout<< ">";
        cin>>input;

        //Detect ^D.
        if (cin.eof())
        {
            exit = true;
            cout << "\nGoodbye!\n";
        }

        else if(input<5 && input>0)
        {
            // option 1 - start new game 
            if (input == 1)
            {
                exit = newGame();
                cout<<"newGame()"<<endl;
            }

            // option 2 load game not functioning
            if (input == 2)
            {
                //exit = loadGame();
                cout<<"loadGame()"<<endl;
            }

            // option 3 - show sudent info
            if (input == 3)
            {
                cout
                << "\nName: Jessica Michelle"
                << "\nStudent ID: s3763653"
                << "\nEmail: s3763653@student.rmit.edu.au\n"
                << "\nName: Junyu Li"
                << "\nStudent ID: s3706335"
                << "\nEmail: s3706335@student.rmit.edu.au\n"
                << "\nName: Yvonne Chen"
                << "\nStudent ID: s3657984"
                << "\nEmail: s3657984@student.rmit.edu.au\n";
            }

            else
            {
                exit = true;
                cout << "\nGoodbye!\n";
            }
        }
    }
}
