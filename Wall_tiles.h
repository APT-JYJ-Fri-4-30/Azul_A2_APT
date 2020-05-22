#ifndef SOURCE_WALL_TILES_H
#define SOURCE_WALL_TILES_H

#include "util.h"
#include <stdio.h>
#include <iostream>
using namespace std;

char wall_tiles_temp_arr[5][5][2];
class Wall_tiles {
private:
public:
    static void store_walls_in_arr(wall_tiles WL[], int player)
    {
        int i = 0;
        for(i = 0 ; i < 5; ++i)
        {
            wall_tiles_temp_arr[0][i][player] = WL[player].tile_line1[i];
        }
        for(i = 0 ; i < 5; ++i)
        {
            wall_tiles_temp_arr[1][i][player] = WL[player].tile_line2[i];
        }
        for(i = 0 ; i < 5; ++i)
        {
            wall_tiles_temp_arr[2][i][player] = WL[player].tile_line3[i];
        }
        for(i = 0 ; i < 5; ++i)
        {
            wall_tiles_temp_arr[3][i][player] = WL[player].tile_line4[i];
        }
        for(i = 0 ; i < 5; ++i)
        {
            wall_tiles_temp_arr[4][i][player] = WL[player].tile_line5[i];
        }
    }

    /*print wall array*/
    void print_wall()
    {
        int i=0,j =0;
        printf("wwall array\n\n");
        for(i=0; i<5;++i)
        {
            for(j=0; j<5;++j)
            {
                printf("%c ",wall_tiles_temp_arr[i][j][0]);
            }
            printf("\n");
        }

        printf("\n\n\n");
        i=0,j =0;
        for(i=0; i<5;++i)
        {
            for(j=0; j<5;++j)
            {
                printf("%c ",wall_tiles_temp_arr[i][j][1]);
            }
            printf("\n");
        }
    }

    void adjust_floor_line_score(wall_tiles WL[], pattern_lines PL[], int player)
    {
        //{-1,-1,-2,-2,-2,-3,-3};
        if(PL[player].tiles_in_floorline == 0)
        {
            WL[player].score = 	WL[player].score;
        }
        else if(PL[player].tiles_in_floorline == 1)
        {
            WL[player].score = 	WL[player].score - 1;
        }
        else if(PL[player].tiles_in_floorline == 2)
        {
            WL[player].score = 	WL[player].score - 2;
        }
        else if(PL[player].tiles_in_floorline == 3)
        {
            WL[player].score = 	WL[player].score - 4;
        }
        else if(PL[player].tiles_in_floorline == 4)
        {
            WL[player].score = 	WL[player].score - 6;
        }
        else if(PL[player].tiles_in_floorline == 5)
        {
            WL[player].score = 	WL[player].score - 8;
        }
        else if(PL[player].tiles_in_floorline == 6)
        {
            WL[player].score = 	WL[player].score - 11;
        }
        else if(PL[player].tiles_in_floorline == 7)
        {
            WL[player].score = 	WL[player].score - 14;
        }
        else
        {
            WL[player].score = 	WL[player].score - 15;
        }
    }


    /*___________check end of the game___________*/
    bool Is_game_ended(pattern_lines PL[], wall_tiles WL[],int player)
    {
        bool end_game = 0;
        int i = 0, j =0, temp = 0;
        //checking horizontal lines
        for(i = 0; i <5; ++i)
        {
            temp = 0;
            for(j = 0; j < 5; ++j)
            {
                if(wall_tiles_temp_arr[i][j][player]=='.')
                {
                    temp = 1;
                }
            }
            if(temp == 0)
            {
                end_game = 1;
                WL[player].score = WL[player].score+2;
            }
        }

        //checking verticle lines
        for(i = 0; i <5; ++i)
        {
            temp = 0;
            for(j = 0; j < 5; ++j)
            {
                if(wall_tiles_temp_arr[j][i][player]=='.')
                {
                    temp = 1;
                }
            }
            if(temp == 0)
            {
                WL[player].score = WL[player].score+7;
            }
        }

        //adjusting floor line tiles into score;
        if(end_game == 1)
        {
            adjust_floor_line_score(WL, PL, 0);
            adjust_floor_line_score(WL, PL, 1);
        }

        /*___________score for player___________*/
        cout << "\n===score for player" << (player+1) << "===\n";
        if(WL[player].score<0)
            WL[player].score = 0;
        cout << WL[player].score ;
        return end_game;
    }

    /*___________Wall tiling___________*/
    static void add_score(wall_tiles WL[], int pattern_line, int player, int y_cor)
    {
        int x_cor = pattern_line-1, i;
        int score_temp_x = 0;
        int score_temp_y = 0;
        int temp = 0;

        //1,0,3
        //-------------------------------------------------------------
        i = y_cor;
        while((i>=0) && (wall_tiles_temp_arr[x_cor][i][player]!='.'))//left
        {
            score_temp_x++;
            --i;
        }
        //-------------------------------------------------------------

        //-------------------------------------------------------------
        i = y_cor+1;
        while((i<=4)&&(wall_tiles_temp_arr[x_cor][i][player] != '.'))
        {
            score_temp_x++;
            ++i;
        }
        //-------------------------------------------------------------

        //-------------------------------------------------------------
        i = x_cor;
        while((i>=0)&&(wall_tiles_temp_arr[i][y_cor][player] != '.'))//up
        {
            score_temp_y++;
            --i;
        }
        //-------------------------------------------------------------

        //-------------------------------------------------------------
        i = x_cor+1;
        while((i<=4) && (wall_tiles_temp_arr[i][y_cor][player] != '.'))
        {
            score_temp_y++;
            ++i;
        }
        //-------------------------------------------------------------
        temp = score_temp_x+score_temp_y-1;
        WL[player].score = WL[player].score+temp;
    }


};

#endif //SOURCE_WALL_TILES_H
