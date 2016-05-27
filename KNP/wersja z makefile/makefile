all: prog

prog: obj/main.o obj/Graf.o obj/Stoper.o obj/element.o obj/list_head.o obj/list_table.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Graf.o obj/Stoper.o obj/element.o obj/list_head.o obj/list_table.o

obj/Graf.o: src/Graf.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Graf.o src/Graf.cpp

obj/element.o: src/element.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/element.o src/element.cpp

obj/Stoper.o: src/Stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Stoper.o src/Stoper.cpp

obj/list_head.o: src/list_head.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/list_head.o src/list_head.cpp

obj/list_table.o: src/list_table.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/list_table.o src/list_table.cpp

obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp


clean:
	rm -f obj/*.o
