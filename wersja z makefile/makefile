all: prog

prog: obj/main.o obj/Backpack.o obj/Item.o obj/KNP.o obj/Shop.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Backpack.o obj/Item.o obj/KNP.o obj/Shop.o

obj/Backpack.o: src/Backpack.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Backpack.o src/Backpack.cpp

obj/Item.o: src/Item.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Item.o src/Item.cpp

obj/KNP.o: src/KNP.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/KNP.o src/KNP.cpp

obj/Shop.o: src/Shop.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Shop.o src/Shop.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
