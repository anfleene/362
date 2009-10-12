a.out: schdvr.o
	g++ schdvr.o key.o

schdvr.o:  key.o ordered_list.h utility.h 
	g++ -c schdvr.cpp

key.o: key.cpp key.h 
	g++ -c key.cpp
	
clean:
	rm -rf *o *gch a.out
