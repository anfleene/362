a.out: main.o plane.o package.o package_creator.o forklift.o utility.o
	g++ main.o plane.o package.o package_creator.o

main.o:  main.cpp 
	g++ -c main.cpp
		
plane.o: plane.cpp plane.h package.o
	g++ -c plane.cpp
	
package_creator.o: package.o
	g++ -c package_creator.cpp

package.o: package.cpp package.h
	g++ -c package.cpp
	
forklift.o: forklift.h
	g++ -c forklift.h

utility.o: utility.h
	g++ -c utility.h

clean:
	rm -rf *o *gch a.out
