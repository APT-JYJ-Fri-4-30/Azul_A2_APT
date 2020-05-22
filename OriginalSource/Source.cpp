#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

char tiles[5] = {'B', 'L', 'U', 'R', 'Y'};

/*___________center of table linked list___________*/
int tiles_in_center = 0;
struct Node 
{ 
    char data; 
    struct Node *next; 
    struct Node *prev; 
};


char factory_arr[5][4];
char bag_pack[5][20];
char wall_tiles_temp_arr[5][5][2];

/*___________these two structures represnts whole board of the game___________*/
typedef struct Mosiac_Struct_pattern_lines
{
	char pattern_line1[5];
	char pattern_line2[5];
	char pattern_line3[5];
	char pattern_line4[5];
	char pattern_line5[5];
	char floor_line[7];
	int tiles_in_floorline;
}pattern_lines;

typedef struct Mosiac_Struct_wall_tiles
{
	char tile_line1[5];
	char tile_line2[5];
	char tile_line3[5];
	char tile_line4[5];
	char tile_line5[5];
	int score;
}wall_tiles;

typedef struct Select_Factory_Display
{
	int select_factory_display;
	int select_no_of_tiles;
	char select_color;
}FD;

/*___________checking of factory array is empty___________*/
void store_walls_in_arr(wall_tiles WL[], int player)
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
void print_wall(wall_tiles WL[])
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


/*___________checking of factory array is empty___________*/
bool Is_factory_display_empty(void)
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
/*___________filled the bag with 5 different colors of tiles with 20 tiles each color___________*/
void fill_tiles_bag(void)
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

/*___________set the factory by randomly selecting 20 tiles from bag and placing tiles on factory display___________*/
void fill_factory_display(void)
{
	int i = 0, j = 0;
	srand(time(0));

	while(i < 5)
	{
		j = 0;
		while(j < 4)
		{
			int i_temp, j_temp;
			int max, min, range;

			max = 4; min = 0;
			range = max - min + 1;
			i_temp = rand() % range + min;

			max = 19; min = 0;
			range = max - min + 1;
			j_temp = rand() % range + min;

			if(bag_pack[i_temp][j_temp] == '\0')
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

/*___________check tiles in corresponding wall___________*/
bool check_tiles_in_corresponding_wall(FD FD_t, int pattern_line, int active_player,wall_tiles WL[])
{
	// it will return one if wall has no same color tiles or no tiles
	//it will return 0 if wall has same color tiles already
	int i = 0;
	if(pattern_line == 1)
	{
		for(i = 0; i<5; ++i)
		{
			if((WL[active_player].tile_line1[i] != '.') && (WL[active_player].tile_line1[i] == FD_t.select_color))
			{
				return 0;
			}
		}
	}
	else if(pattern_line == 2)
	{
		for(i = 0; i<5; ++i)
		{
			if((WL[active_player].tile_line2[i] != '.') && (WL[active_player].tile_line2[i] == FD_t.select_color))
			{
				return 0;
			}
		}
	}
	else if(pattern_line == 3)
	{
		for(i = 0; i<5; ++i)
		{
			if((WL[active_player].tile_line3[i] != '.') && (WL[active_player].tile_line3[i] == FD_t.select_color))
			{
				return 0;
			}
		}
	}
	else if(pattern_line == 4)
	{
		for(i = 0; i<5; ++i)
		{
			if((WL[active_player].tile_line4[i] != '.') && (WL[active_player].tile_line4[i] == FD_t.select_color))
			{
				return 0;
			}
		}
	}
	else
	{
		for(i = 0; i<5; ++i)
		{
			if((WL[active_player].tile_line5[i] != '.') && (WL[active_player].tile_line5[i] == FD_t.select_color))
			{
				return 0;
			}
		}
	}
	return 1;
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

/*___________print tiles in bag___________*/
void print_bag(void)
{
	char tile;
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



/*___________drawing center of table___________*/
void print_center_table(struct Node* head_center_table)
{
	struct Node* last; 
	cout << "\n\n===center of the table===\n";
    while (head_center_table != NULL) {   
		cout <<head_center_table->data << " ";
        last = head_center_table;  
        head_center_table = head_center_table->next;  
    } 
	cout << "\n\n";
}

/*___________requested number of tiles are available in center or floor display___________*/
bool Is_requested_tiles_available(FD FD_t, int player, struct Node* node)
{
	int i = 0, temp = 0;
	bool ret_val = 0;
	int no_of_tiles = FD_t.select_no_of_tiles;
	int factory_display = FD_t.select_factory_display - 1;
	//check if requested number of tiles are available in center of table
	if(factory_display == 5)
	{
		int temp = 0;
		struct Node* last; 
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

/*___________pushing into linked list___________*/
void push(struct Node** head_ref, int new_data)  
{  
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
  
    new_node->data = new_data;  
  
    new_node->next = (*head_ref);  
    new_node->prev = NULL;  
  
    if ((*head_ref) != NULL)  
        (*head_ref)->prev = new_node;  
  
    (*head_ref) = new_node;  
}

/*___________delete node at given position___________*/
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    if (*head_ref == NULL || del == NULL) 
	{
        return; 
	}

    if (*head_ref == del) 
	{
        *head_ref = del->next; 
	}

    if (del->next != NULL) 
	{
        del->next->prev = del->prev; 
	}
  
    if (del->prev != NULL) 
	{
        del->prev->next = del->next; 
	}

    free(del); 
} 

/*___________delete node at given position___________*/
void remove_node(struct Node** head_center_table, int n) 
{ 
    if (*head_center_table == NULL || n <= 0) 
	{
        return;
	}
    struct Node* current = *head_center_table; 
    int i; 

    for (int i = 1; current != NULL && i < n; i++) 
	{
        current = current->next; 
	}
  
    if (current == NULL) 
	{
        return; 
	}
  
    deleteNode(head_center_table, current); 
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


/*___________picking tiles from factory display___________*/
bool picking_tiles_from_factory_display(FD FD_t, int player, struct Node** head_center_table)
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
		struct Node* last; 
		struct Node* temp = *head_center_table;
		while (temp != NULL) 
		{   
			if(no_of_tiles_temp == 0)
			{
				break;
			}
			if(FD_t.select_color == temp->data)
			{
				temp = temp->next;
				remove_node(head_center_table,i);
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
				push(head_center_table, factory_arr[factory_display][i]);
				factory_arr[factory_display][i] = '.';
				tiles_in_center++;
			}
		}
	}
	return 1;
}

/*___________drawing mosiac for player___________*/
void draw_mosiac(pattern_lines PL[], wall_tiles WL[], int p)
{
	int i = 0;
	cout << (i+1) << ": ";
	printf("%c %c %c %c %c ", PL[p].pattern_line1[0],PL[p].pattern_line1[1],PL[p].pattern_line1[2],PL[p].pattern_line1[3],PL[p].pattern_line1[4]);
	printf("|| ");
	printf("%c %c %c %c %c \n", WL[p].tile_line1[0],WL[p].tile_line1[1],WL[p].tile_line1[2],WL[p].tile_line1[3],WL[p].tile_line1[4]);

	cout << (i+2) << ": ";
	printf("%c %c %c %c %c ", PL[p].pattern_line2[0],PL[p].pattern_line2[1],PL[p].pattern_line2[2],PL[p].pattern_line2[3],PL[p].pattern_line2[4]);
	printf("|| ");
	printf("%c %c %c %c %c \n", WL[p].tile_line2[0],WL[p].tile_line2[1],WL[p].tile_line2[2],WL[p].tile_line2[3],WL[p].tile_line2[4]);

	cout << (i+3) << ": ";
	printf("%c %c %c %c %c ", PL[p].pattern_line3[0],PL[p].pattern_line3[1],PL[p].pattern_line3[2],PL[p].pattern_line3[3],PL[p].pattern_line3[4]);
	printf("|| ");
	printf("%c %c %c %c %c \n", WL[p].tile_line3[0],WL[p].tile_line3[1],WL[p].tile_line3[2],WL[p].tile_line3[3],WL[p].tile_line3[4]);

	cout << (i+4) << ": ";
	printf("%c %c %c %c %c ", PL[p].pattern_line4[0],PL[p].pattern_line4[1],PL[p].pattern_line4[2],PL[p].pattern_line4[3],PL[p].pattern_line4[4]);
	printf("|| ");
	printf("%c %c %c %c %c \n", WL[p].tile_line4[0],WL[p].tile_line4[1],WL[p].tile_line4[2],WL[p].tile_line4[3],WL[p].tile_line4[4]);

	cout << (i+5) << ": ";
	printf("%c %c %c %c %c ", PL[p].pattern_line5[0],PL[p].pattern_line5[1],PL[p].pattern_line5[2],PL[p].pattern_line5[3],PL[p].pattern_line5[4]);
	printf("|| ");
	printf("%c %c %c %c %c \n", WL[p].tile_line5[0],WL[p].tile_line5[1],WL[p].tile_line5[2],WL[p].tile_line5[3],WL[p].tile_line5[4]);

	cout << "floor line" << ": ";
	printf("%c %c %c %c %c %c %c\n", PL[p].floor_line[0], PL[p].floor_line[1], PL[p].floor_line[2], PL[p].floor_line[3], PL[p].floor_line[4], PL[p].floor_line[5], PL[p].floor_line[6]);
}

/*___________add floor line tiles to bag___________*/
void transfer_tiles_to_bag(char tile_color, int tile_count)
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

/*___________add tiles to floor line___________*/
void adding_tiles_to_floorline(pattern_lines PL[], char tile_color, int tile_count, int player)
{
	int i = 0, j = 0;
	int floor_line_size = 7;
	player = player -1;
	if(PL[player].tiles_in_floorline >= 7)
	{
		transfer_tiles_to_bag(tile_count,tile_color);
	}
	for(i = 0, j = PL[player].tiles_in_floorline; i <tile_count && i < floor_line_size; ++i,++j)
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
	if(pattern_line == 1)
	{
		for(i = 4; i >= 5 - pattern_line; --i)
		{
			if(PL[player].pattern_line1[i] != '.')
			{
				++existing_tiles_in_pattern_lines;
				if(FD_t.select_color != PL[player].pattern_line1[i])
				{
					color_flag = 1;
				}
			}
		}
	}
	else if(pattern_line == 2)
	{
		for(i = 4; i >= 5 - pattern_line; --i)
		{
			if(PL[player].pattern_line2[i] != '.')
			{
				++existing_tiles_in_pattern_lines;
				if(FD_t.select_color != PL[player].pattern_line2[i])
				{
					color_flag = 1;
				}
			}
		}
	}
	else if(pattern_line == 3)
	{
		for(i = 4; i >= 5 - pattern_line; --i)
		{
			if(PL[player].pattern_line3[i] != '.')
			{
				++existing_tiles_in_pattern_lines;
				if(FD_t.select_color != PL[player].pattern_line3[i])
				{
					color_flag = 1;
				}
			}
		}
	}
	else if(pattern_line == 4)
	{
		for(i = 4; i >= 5 - pattern_line; --i)
		{
			if(PL[player].pattern_line4[i] != '.')
			{
				++existing_tiles_in_pattern_lines;
				if(FD_t.select_color != PL[player].pattern_line4[i])
				{
					color_flag = 1;
				}
			}
		}
	}
	else if(pattern_line == 5)
	{
		for(i = 4; i >= 5 - pattern_line; --i)
		{
			if(PL[player].pattern_line5[i] != '.')
			{
				++existing_tiles_in_pattern_lines;
				if(FD_t.select_color != PL[player].pattern_line5[i])
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
	if(existing_tiles_in_pattern_lines == pattern_line) // pattern line is fully filled
	{
		return 1;
	}
	else if(color_flag == 0 && existing_tiles_in_pattern_lines != pattern_line && existing_tiles_in_pattern_lines!=0)//pattern line partially filled with same color
	{
		return 0;
	}
	else if(color_flag == 1) // partially filled with different color
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
	if(pattern_line>5 || pattern_line<1)
	{
		cout << "Enter correct pattern line.\n";
		return 0;
	}

	//checking pattern line 
	pattern_line_status = Is_pattern_line_full(PL,player,pattern_line,FD_t);
	 
	//if pattern line is fully filled
	if((pattern_line_status == 1) || (pattern_line_status == 2))
	{
		cout << "this Pattern line is filled\n";
		return 0;
	}
	else
	{
		if(pattern_line == 1)	
		{
			PL[player].pattern_line1[4] = FD_t.select_color;
			tiles_in_hand--;
		}
		if(pattern_line == 2)	
		{
			for(i = 4; i >= 5 - pattern_line && tiles_in_hand!=0; --i)
			{
				if(PL[player].pattern_line2[i] == '.')
				{
					PL[player].pattern_line2[i] = FD_t.select_color;
					tiles_in_hand--;
				}
			}
		}
		if(pattern_line == 3)	
		{
			for(i = 4; i >= 5 - pattern_line && tiles_in_hand!=0; --i)
			{
				if(PL[player].pattern_line3[i] == '.')
				{
					PL[player].pattern_line3[i] = FD_t.select_color;
					tiles_in_hand--;
				}
			}
		}
		if(pattern_line == 4)	
		{
			for(i = 4; i >= 5 - pattern_line && tiles_in_hand!=0; --i)
			{
				if(PL[player].pattern_line4[i] == '.')
				{
					PL[player].pattern_line4[i] = FD_t.select_color;
					tiles_in_hand--;
				}
			}
		}
		if(pattern_line == 5)	
		{
			for(i = 4; i >= 5 - pattern_line && tiles_in_hand!=0; --i)
			{
				if(PL[player].pattern_line5[i] == '.')
				{
					PL[player].pattern_line5[i] = FD_t.select_color;
					tiles_in_hand--;
				}
			}
		}
		adding_tiles_to_floorline(PL, FD_t.select_color, tiles_in_hand, player+1);
		return 1;
	}
}

void clear_pattern_line(pattern_lines PL[], int pattern_lines, int player)
{
	int i =0;
	if(pattern_lines == 1)
	{
		for(i = 4; i >= (5-pattern_lines); --i)
		{
			PL[player].pattern_line1[i] = '.';
		}
	}
	else if(pattern_lines == 2)
	{
		for(i = 4; i >= (5-pattern_lines); --i)
		{
			PL[player].pattern_line2[i] = '.';
		}
	}
	else if(pattern_lines == 3)
	{
		for(i = 4; i >= (5-pattern_lines); --i)
		{
			PL[player].pattern_line3[i] = '.';
		}
	}
	else if(pattern_lines == 4)
	{
		for(i = 4; i >= (5-pattern_lines); --i)
		{
			PL[player].pattern_line4[i] = '.';
		}
	}
	else
	{
		for(i = 4; i >= (5-pattern_lines); --i)
		{
			PL[player].pattern_line5[i] = '.';
		}
	}
}
void add_tiles_to_bag(pattern_lines PL[], int pattern_lines, int player, char tile_color)
{
	int i =0;
	if(pattern_lines == 2)
	{
		transfer_tiles_to_bag(tile_color, 1);
	}
	else if(pattern_lines == 3)
	{
		transfer_tiles_to_bag(tile_color, 2);
	}
	else if(pattern_lines == 4)
	{
		transfer_tiles_to_bag(tile_color, 3);
	}
	else if(pattern_lines == 5)
	{
		transfer_tiles_to_bag(tile_color, 4);	
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
void add_score(wall_tiles WL[], int pattern_line, int player, int y_cor)
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

/*___________shifting tiles to wall___________*/
void shift_rightmost_tile_to_wall_of_Matching_color(wall_tiles WL[], pattern_lines PL[], int pattern_lines, int player)
{
	int current_y = 0;
	if(pattern_lines == 1)
	{
		if(PL[player].pattern_line1[4] == 'B')
		{
			WL[player].tile_line1[0] = 'B';
			current_y = 0;
		}
		else if(PL[player].pattern_line1[4] == 'Y')
		{
			WL[player].tile_line1[1] = 'Y';
			current_y = 1;
		}
		else if(PL[player].pattern_line1[4] == 'R')
		{
			WL[player].tile_line1[2] = 'R';
			current_y = 2;
		}
		else if(PL[player].pattern_line1[4] == 'U')
		{
			WL[player].tile_line1[3] = 'U';
			current_y = 3;
		}
		else if(PL[player].pattern_line1[4] == 'L')
		{
			WL[player].tile_line1[4] = 'L';
			current_y = 4;
		}
	}
	else if(pattern_lines == 2)
	{
		if(PL[player].pattern_line2[4] == 'L')
		{
			WL[player].tile_line2[0] = 'L';
			add_tiles_to_bag(PL, pattern_lines, player, 'L');
			current_y = 0;
		}
		else if(PL[player].pattern_line2[4] == 'B')
		{
			WL[player].tile_line2[1] = 'B';
			add_tiles_to_bag(PL, pattern_lines, player, 'B');
			current_y = 1;
		}
		else if(PL[player].pattern_line2[4] == 'Y')
		{
			WL[player].tile_line2[2] = 'Y';
			add_tiles_to_bag(PL, pattern_lines, player, 'Y');
			current_y = 2;
		}
		else if(PL[player].pattern_line2[4] == 'R')
		{
			WL[player].tile_line2[3] = 'R';
			add_tiles_to_bag(PL, pattern_lines, player, 'R');
			current_y = 3;
		}
		else if(PL[player].pattern_line2[4] == 'U')
		{
			WL[player].tile_line2[4] = 'U';
			add_tiles_to_bag(PL, pattern_lines, player, 'U');
			current_y = 4;
		}
	}
	else if(pattern_lines == 3)
	{
		if(PL[player].pattern_line3[4] == 'U')
		{
			WL[player].tile_line3[0] = 'U';
			add_tiles_to_bag(PL, pattern_lines, player, 'U');
			current_y = 0;
		}
		else if(PL[player].pattern_line3[4] == 'L')
		{
			WL[player].tile_line3[1] = 'L';
			add_tiles_to_bag(PL, pattern_lines, player, 'L');
			current_y = 1;
		}
		else if(PL[player].pattern_line3[4] == 'B')
		{
			WL[player].tile_line3[2] = 'B';
			add_tiles_to_bag(PL, pattern_lines, player, 'B');
			current_y = 2;
		}
		else if(PL[player].pattern_line3[4] == 'Y')
		{
			WL[player].tile_line3[3] = 'Y';
			add_tiles_to_bag(PL, pattern_lines, player, 'Y');
			current_y = 3;
		}
		else if(PL[player].pattern_line3[4] == 'R')
		{
			WL[player].tile_line3[4] = 'R';
			add_tiles_to_bag(PL, pattern_lines, player, 'R');
			current_y = 4;
		}
	}
	else if(pattern_lines == 4)
	{
		if(PL[player].pattern_line4[4] == 'R')
		{
			WL[player].tile_line4[0] = 'R';
			add_tiles_to_bag(PL, pattern_lines, player, 'R');
			current_y = 0;
		}
		else if(PL[player].pattern_line4[4] == 'U')
		{
			WL[player].tile_line4[1] = 'U';
			add_tiles_to_bag(PL, pattern_lines, player, 'U');
			current_y = 1;
		}
		else if(PL[player].pattern_line4[4] == 'L')
		{
			WL[player].tile_line4[2] = 'L';
			add_tiles_to_bag(PL, pattern_lines, player, 'L');
			current_y = 2;
		}
		else if(PL[player].pattern_line4[4] == 'B')
		{
			WL[player].tile_line4[3] = 'B';
			add_tiles_to_bag(PL, pattern_lines, player, 'B');
			current_y = 3;
		}
		else if(PL[player].pattern_line4[4] == 'Y')
		{
			WL[player].tile_line4[4] = 'Y';
			add_tiles_to_bag(PL, pattern_lines, player, 'Y');
			current_y= 4;
		}
	}
	else
	{
		if(PL[player].pattern_line5[4] == 'Y')
		{
			WL[player].tile_line5[0] = 'Y';
			add_tiles_to_bag(PL, pattern_lines, player, 'Y');
			current_y = 0;
		}
		else if(PL[player].pattern_line5[4] == 'R')
		{
			WL[player].tile_line5[1] = 'R';
			add_tiles_to_bag(PL, pattern_lines, player, 'R');
			current_y = 1;
		}
		else if(PL[player].pattern_line5[4] == 'U')
		{
			WL[player].tile_line5[2] = 'U';
			add_tiles_to_bag(PL, pattern_lines, player, 'U');
			current_y = 2;
		}
		else if(PL[player].pattern_line5[4] == 'L')
		{
			WL[player].tile_line5[3] = 'L';
			add_tiles_to_bag(PL, pattern_lines, player, 'L');
			current_y = 3;
		}
		else if(PL[player].pattern_line5[4] == 'B')
		{
			WL[player].tile_line5[4] = 'B';
			add_tiles_to_bag(PL, pattern_lines, player, 'B');
			current_y = 4;
		}
	}
	clear_pattern_line(PL, pattern_lines, player);
	store_walls_in_arr(WL, player);
	add_score(WL, pattern_lines, player,current_y);
}



/*___________Wall tiling___________*/
void wall_tiling(pattern_lines PL[], wall_tiles WL[], int player, FD FD_t)
{
	if(Is_pattern_line_full(PL, player, 1, FD_t) == 1)
	{
		shift_rightmost_tile_to_wall_of_Matching_color(WL, PL, 1, player);
	}
	if(Is_pattern_line_full(PL, player, 2, FD_t) == 1)
	{
		shift_rightmost_tile_to_wall_of_Matching_color(WL, PL, 2, player);
	}
	if(Is_pattern_line_full(PL, player, 3, FD_t) == 1)
	{
		shift_rightmost_tile_to_wall_of_Matching_color(WL, PL, 3, player);
	}
	if(Is_pattern_line_full(PL, player, 4, FD_t) == 1)
	{
		shift_rightmost_tile_to_wall_of_Matching_color(WL, PL, 4, player);
	}
	if(Is_pattern_line_full(PL, player, 5, FD_t) == 1)
	{
		shift_rightmost_tile_to_wall_of_Matching_color(WL, PL, 5, player);
	}
}
/*___________check if same color tiles left over___________*/
bool Is_same_color_tile_left_over(FD FD_t, int active_player, struct Node *head_center_table)
{
	int i= 0, temp = 0;
	bool ret_val = 1;
	if(FD_t.select_factory_display == 6)
	{
		struct Node* last; 
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

int main()
{
	/*___________local variables___________*/
	int i, j;
	int end_game_track = 0;
	bool active_player = 0;
	char tile;
	int pattern_line = 0;
	int placement_succes_flag = 0;
	bool tile_picking_success_flag = 0;
	struct Node* head_center_table = NULL;
	char player_1[15];
	char player_2[15];

	/*___________Enter player details___________*/
	cout <<"Enter player-1 name:";
	cin >> player_1;

	cout <<"Enter player-2 name:";
	cin >> player_2;

	/*___________Creating empty mosiac for 2 players___________*/
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


	/*___________filled the bag with 5 different colors of tiles with 20 tiles each color___________*/
	fill_tiles_bag();

	/*___________set the factory by randomly selecting 20 tiles from bag and placing 4 tiles on each factory display___________*/
	fill_factory_display();

	/*___________start the game___________*/
	cout << "===Start the game===";

	/*___________printing bag tiles___________*/
	print_bag();

	while(1)
	{
		while(1)
		{
			cout << "\n==========================================================================";
			cout << "\n====================Turn for player:" << (active_player+1) << "====================";

			/*___________print factory display___________*/
			print_factory_display(active_player);

			/*___________drawing mosiac for player___________*/
			cout << "\n\n===Mosiac for Player-" << (active_player+1) << "===\n";
			draw_mosiac( PL,  WL,  active_player);
		
			/*___________drawing center of table___________*/
			print_center_table(head_center_table);


			/*___________Select Factory Display___________*/
			tile_picking_success_flag = 0;
			FD FD_t = {-1, -1, 0};
			while(tile_picking_success_flag!=1)
			{
				FD_t.select_color = 0; FD_t.select_factory_display = -1; FD_t.select_no_of_tiles = -1;
				while((FD_t.select_factory_display>6 || FD_t.select_factory_display < 0)|| (FD_t.select_no_of_tiles < 1) || (!((FD_t.select_color == 'B')||(FD_t.select_color == 'L')||(FD_t.select_color == 'U')||(FD_t.select_color == 'R')||(FD_t.select_color == 'Y'))))
				{
					cout << "enter between (1-5) to choose form factory display and enter 6 to choose from center\n";
					cout << "enter factory_display_number tiles_color number_of_tiles in same order:";
					cin >> FD_t.select_factory_display >> FD_t.select_color >> FD_t.select_no_of_tiles;
				}

				tile_picking_success_flag = Is_same_color_tile_left_over(FD_t, active_player, head_center_table);

				/*___________picking tiles from factory display___________*/

				if(tile_picking_success_flag == 1)
					tile_picking_success_flag = picking_tiles_from_factory_display(FD_t, active_player, &head_center_table);
			}
			cout << "tiles successfully picked\n";


			/*___________placing tiles in pattern lines___________*/
			pattern_line = 0;
			placement_succes_flag = 0;
			while(placement_succes_flag != 1)
			{
				cout << "for pattern line enter[1-5], for floor line enter[6]\n";
				cout << "which pattern line you want to put your tiles in:";
				cin >> pattern_line;
				if(pattern_line == 6)
				{
					adding_tiles_to_floorline(PL, FD_t.select_color, FD_t.select_no_of_tiles, active_player+1);
					break;
				}
				placement_succes_flag = check_tiles_in_corresponding_wall(FD_t, pattern_line, active_player, WL);
				if(placement_succes_flag == 1)
				{
					placement_succes_flag = filling_pattern_line(FD_t, pattern_line, active_player, PL);
				}
			}
			cout << "tiles successfully placed\n";

			/*___________alterning chances of player___________*/
			active_player = !active_player;

			//if tiles in center and factory display are finished goto wall tiling stage
			if((head_center_table == NULL) && (Is_factory_display_empty() == 1))
			{
				break;
			}
			
		}

		cout << "\n==========================================================================";
		cout << "\n==========================Results of wall tiling==========================";

		FD FD_t = {-1, -1, 0};
		/*___________wall tiling by player-1___________*/
		wall_tiling(PL, WL,  0,  FD_t);

		/*___________drawing mosiac for player-1___________*/
		cout << "\n\n===Mosiac for Player-1" << "===\n";
		draw_mosiac( PL,  WL,  0);

		/*___________wall tiling by player-2___________*/
		wall_tiling(PL, WL,  1,  FD_t);

		/*___________drawing mosiac for player-2___________*/
		cout << "\n\n===Mosiac for Player-2" << "===\n";
		draw_mosiac( PL,  WL,  1);

		/*___________cheking game is over for player-1___________*/
		if(1 == Is_game_ended(PL,WL,0))
		{
			end_game_track = 1;
		}
		/*___________cheking game is over for player-2___________*/
		if(1 == Is_game_ended(PL, WL, 1))
		{
			end_game_track = 1;
		}
		 
		if(end_game_track == 1)
		{
			cout << "\nGame is over!!\n\n";
			break;
		}

		/*___________filling factory display___________*/
		fill_factory_display();

		/*___________printing bag tiles___________*/
		print_bag();

		/*__________check end game___________*/
		
	}
	getch();
}











