tagrun: tags.o driver.o
	g++ bin/tags.o bin/driver.o -o tagrun -std=c++2a
 
tags.o: src/tags.cpp src/tags.h
	g++ -c src/tags.cpp -o bin/tags.o


driver.o: src/driver.cpp
	g++ -c src/driver.cpp -o bin/driver.o
   
clean:
	@rm -f bin/*.o
	@rm tagrun
	@rm data/tags.txt	