APP=graph
__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir obj

./${APP}: obj/main.o obj/graph.o obj/graph_matrix.o obj/graph_list.o
	g++ -o ./${APP} obj/main.o obj/graph.o obj/graph_matrix.o obj/graph_list.o

obj/main.o: src/main.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/graph.o: src/graph.cpp inc/graph.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/graph.o src/graph.cpp

obj/graph_matrix.o: src/graph_matrix.cpp inc/graph_matrix.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/graph_matrix.o src/graph_matrix.cpp

obj/graph_list.o: src/graph_list.cpp inc/graph_list.hh
	g++ -Iinc -W -Wall -pedantic -c -o obj/graph_list.o src/graph_list.cpp

clean:
	rm -f obj/* ./${APP} core.* core
