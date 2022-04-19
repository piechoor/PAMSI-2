APP=sort
__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir obj

./${APP}: obj/main.o obj/graph.o
	g++ -o ./${APP} obj/main.o obj/graph.o

obj/main.o: src/main.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/graph.o: src/arr_manag.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/arr_manag.o src/arr_manag.cpp

clean:
	rm -f obj/* ./${APP} core.* core
