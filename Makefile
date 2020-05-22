all: azul

azul: main.o Bag_pack.o Factory.o LinkList.o Wall_tiles util.o
    g++ -Wall -Werror -std=c++14 -O -o azul game.cpp Bag_pack.cpp Factory.cpp LinkList.cpp Wall_tiles.cpp util.cpp

main.o: game.cpp
    g++ -Wall -Werror -std=c++14 -O -c game.cpp

Bag_pack.o: Bag_pack.h Bag_pack.cpp
    g++ -Wall -Werror -std=c++14 -O -c Bag_pack.cpp

Factory.o : Factory.h Factory.cpp
    g++ -Wall -Werror -std=c++14 -O -c Factory.cpp

LinkList.o: LinkList.h LinkList.cpp
    g++ -Wall -Werror -std=c++14 -O -c LinkList.cpp

Wall_tiles: Wall_tiles.h Wall_tiles.cpp
    g++ -Wall -Werror -std=c++14 -O -c Wall_tiles.cpp

util.o: util.h util.cpp
    g++ -Wall -Werror -std=c++14 -O -c util.cpp

clean: 
   rm *.o azul