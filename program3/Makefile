a.out: main.o
	g++ main.o event_list.o event.o

main.o:  utility.h forklift.h event_list.o plane.o
	g++ -c main.cpp
	
event_list.o: event_list.h event.o
	g++ -c event_list.cpp
		
event.o: event.h package.o
	g++ -c event.cpp

plane.o: plane.h package.o
	g++ -c plane.cpp
	
package.o: package.cpp package.h 
	g++ -c package.cpp
	
clean:
	rm -rf *o *gch a.out
