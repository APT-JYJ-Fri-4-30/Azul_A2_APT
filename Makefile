all: azul

azul: main.o 
    g++ -Wall -Werror -std=c++14 -O -o azul game.cpp 

main.o: game.cpp
    g++ -Wall -Werror -std=c++14 -O -c Bag_pack.h Factory.h LinkList.h Wall_tiles.h util.h game.cpp
