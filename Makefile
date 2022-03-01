tagrun: tags.o driver.o
	g++ tags.o driver.o -o tagrun -std=c++2a
 
tags.o: src/tags.cpp src/tags.h
	g++ -c src/tags.cpp


driver.o: src/driver.cpp
	g++ -c src/driver.cpp
   
run: tagrun.exe
	./tagrun.exe
# deletes all the object code files
clean:
	@rm -f *.o
	@rm tagrun
	@rm data/tags.txt
# driver: driver.o
# 	g++ driver.o -o driver -std=c++2a

# driver.o: driver.cpp driver.h
# 	g++ -c driver.cpp

# run:
# 	./driver.o

# clean:
# 	rm bin/*.o	