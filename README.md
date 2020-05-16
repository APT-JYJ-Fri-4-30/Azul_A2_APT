# Azul_A2_APT


# 1.	Introduction

We have developed an application of Azul game which is based on C++ programming language. Azul is game which is based on setting the tiles of different colors at different appropriate slots and earn respective score. It can be played by 2,3 and 4 players. This application has been designed in such a way that the game can be played by two players only. 
So, first of all we will discuss how the game is played with respect to designed application.

<br />
# 2.	Game Rules

 First, you would have two boards, and 100 tiles. Among which tiles are of 5 different colors hence there would be 20 tiles of each color. For two player there would be 5 factory displays. Each factory display would contain randomly selected four tiles from the bag. Since this is not physical game rather it is built on computer application and also being played by two players only hence, chances of players would be alternating automatically by program.
Game is divided in three steps:

<br />

# 2.1. Step-1: Factory offer
In factory offer stage, first task is to arrange tiles from factory and placing these tiles on to pattern lines of respective player. Tiles can be picked by two different ways.

**1>**	Either you can select same color of all tiles from any of the factory display rest of the tiles would go to the center of the table.

**2>** Or you can pick all the same color of tiles from the center of the table. As we already mentioned that this game is based on computer application and tiles are selected randomly automatically by machine itself hence there was no logic of having first player tile. 

when all the places of a pattern line is filled, pattern line is considered to be completed and if you have picked extra number of tiles then these tiles would go to floor line. In upcoming round, you cannot place the tiles in a pattern line if the same color of tile is already places in corresponding wall. Whenever a tiles goes in floor line you would lose some score and the scoring respective to floor line is done in the manner shown below.
 
If more than seven tiles goes to floor line then extra tiles would be added in to bag. When all the tiles in the center of the table and the factory display have been finished we will go for next round only if any horizontal lines by any of the player is not filled.


# 2.2. Step-2: Wall tiling
In wall tiling phase you would go from top to bottom and check every pattern line. If pattern line is completely filled then the last tile of the pattern line will be added to corresponding same color slot in wall tile and remaining number of tiles are added into bag. If the pattern line which is not completely filled is left over as it is.

# 2.2.1. Scoring
scoring happens when tiles of respective players are shifted from pattern lines to wall tiles. So whenever a tile is shifted it will score few points based on given conditions:

**1>**	If there is no adjacent tile of the newly shifted tile then it will score 1 point.

**2>**	If there are n horizontal adjacent tiles with the newly shifted tile then it will score n+1 points.

**3>**	If there are m vertical tiles adjacent to the newly shifted tile then it will score m+1 points.

**4>**	If it has both n horizontal and m vertical tiles adjacent then it would score m+n-1 points.

# 2.3. Step-3:Preparing for next round
If none of the horizontal is finished we will go for next round, for next round again we will setup factory display by choosing random tiles from the bag and would start in same manner again.

<br />

# 3.	End of the game
Game will be ended only if one player has completed at least one horizontal line. When the end of game comes, again the final marking of score will be done for each player which contain following stages.

**1>**	2 points are given on completing each number of horizontal wall.

**2>**	7 points are given on completing each number of vertical line of wall.

**3>**	10 points are given if you have placed all five colors in your wall.

**4>**	Points are deducted according to the number of tiles in floor line.

<br />

# 4.	Analysis of Application

Game starts by taking user input for two players. To design the mosaic of player, we would use two structure because it is more efficient to  keep the data organized. Among these two structure one structure represents pattern lines, floor tiles and total number of tiles added in for the particular player and second structure represent score of the player and wall tiles status. Choosing structure as data structure is a wise choice also because it makes game easier to save.

Apart from using structure, we used linked list also which is used for the purpose of storing tiles in the center of table. Since it was not known initially that how many tiles can be there in center of table so linked list is most suitable data structure for such kind of scenarios. Whenever same color tiles are selected from the factory display, rest of the tiles are added to the center of the tile and for this application I have used push function which link a new node in to linked list. Whenever we want to select the tiles from the center of the table we would delete the matching color nodes of given number from the linked list for this purpose I have used the function of remove node. To print the tiles in the center of table, I have used the function called print center table which would iterate through the linked list and would print each of the nodes.

Bag, which contains one hundred tiles, 20 of each color, is being created by two dimensional global array. Since bag is not associated with any player so it was best to choose two dimensional array for the bag. The other reason for choosing two dimensional array to represent bag is that it has fixed number of tiles initially. Apart from bag, factory display is also represented by a two dimensional array and reason for choosing factory display as array is same which is that it was initially known that how many number of tiles we have to store and how many number of factory displays we have to use.
Once we have defined all the required data structure now it is time to get in the flow of playing game.
First of all in the main function we will have to initialize all the players mosaics by filling those with dots because dots are representing empty mosaics. After that we would fill the bag with 100 tiles where each color has 20 tiles. Once bag is filled, it would fill factory display by randomly selecting tiles from the bag. Now bag is printed to show that which tiles have selected to fill the factory display. 

Now program enters in infinite loop, program would exit from infinite loop only if it game has ended. In loop,  there is one more loop which would perform the step of factory offer. In inner loop factory offer chance would be given to each player alternatively and when all the tiles in center and factory display have been finished, program execution will come out of inner loop.
Now wall tiling step would be performed by both the players simultaneously and results would be printed. One wall tiling results have been published, the program would check for the end of game condition and would print the score for both the players in both the cases of game is ended or not. If game is ended, program execution will come out of external loop and if game is not ended then program will repeat the execution for external loop representing next round of the game. 

<br />

# 5.References

•	https://www.ultraboardgames.com/azul/game-rules.php

•	https://www.dicetower.com/game-video/azul-review-zee-garcia






 

