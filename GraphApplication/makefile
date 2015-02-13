all:wordLadder
wordLadder: main.o Graphs.o queue.o
	g++ main.o Graphs.o queue.o  -o wordLadder
Graphs.o: Graphs.cpp Graphs.h
	g++ -c Graphs.cpp

main.o: main.cpp Graphs.h
	g++ -c main.cpp

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

clean:
	rm -rf *o wordLadder
