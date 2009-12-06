a.out: columnsorter.o
	g++ main.cpp
	
columnsorter.o: columnsorter.h utility.h
	g++ -c columnsorter.cpp

clean:
	rm -rf *o *gch a.out
