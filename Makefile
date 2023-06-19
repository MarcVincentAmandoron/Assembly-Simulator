AssemblySimulator: main.o
	g++ -o AssemblySimulator main.o
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o AssemblySimulator