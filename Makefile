driver: driver.o
	g++ driver.o -o driver -std=c++2a

driver.o: driver.cpp driver.h
	g++ -c driver.cpp

run:
	./driver.o

clean:
	rm bin/*.o

	