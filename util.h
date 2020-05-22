#ifndef SOURCE_UTIL_H
#define SOURCE_UTIL_H

class pattern_lines{
public:
    char pattern_line1[5];
    char pattern_line2[5];
    char pattern_line3[5];
    char pattern_line4[5];
    char pattern_line5[5];
    char floor_line[7];
    int tiles_in_floorline;
};

class wall_tiles{
public:
    char tile_line1[5];
    char tile_line2[5];
    char tile_line3[5];
    char tile_line4[5];
    char tile_line5[5];
    int score;
};

class FD{
public:
    int select_factory_display;
    int select_no_of_tiles;
    char select_color;
};

#endif //SOURCE_UTIL_H
