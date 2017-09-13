
Objects= main.o Graph.o NeighborhoodPolicy.o IOcost.o

test: $(Objects)
	g++ -o Ordering $(Objects)

main.o: common.h main.cc
	g++ -c main.cc

Graph.o: common.h Graph.cc
	g++ -c Graph.cc

NeighborhoodPolicy.o: common.h NeighborhoodPolicy.cc
	g++ -c NeighborhoodPolicy.cc

IOcost.o: common.h IOcost.cc
	g++ -c IOcost.cc

clean:
	rm -f $(Objects)
	rm -f Ordering
