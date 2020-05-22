all: azul

azul: main.o 
    g++ -Wall -Werror -std=c++14 -O -o azul game.cpp 

main.o: game.cpp
    g++ -Wall -Werror -std=c++14 -O -c game.cpp

clean:
    rm -f *.o azul *.gch
