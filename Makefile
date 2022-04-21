APP=graph
__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir obj

./${APP}: obj/main.o obj/graph.o
	g++ -o ./${APP} obj/main.o obj/graph.o

obj/main.o: src/main.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/graph.o: src/graph.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/graph.o src/graph.cpp

clean:
	rm -f obj/* ./${APP} core.* core
