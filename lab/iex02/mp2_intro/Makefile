CXX = g++

FLAGS = -Wall -Wextra -pedantic-errors -Werror -std=c++17 -g -O0

PROG = intro

DIR = RGBA

OBJS = main.o intro.o $(DIR)/rgbapixel.o $(DIR)/png.o

$(PROG) : $(OBJS)
	$(CXX) $(FLAS) $(OBJS) -o $(PROG) -lpng

main.o : main.cpp
	$(CXX) $(FLAGS) -c main.cpp

intro.o : intro.cpp intro.h $(DIR)/rgbapixel.h $(DIR)/png.h
	$(CXX) $(FLAGS) -c intro.cpp

rgbapixel.o : $(DIR)/rgbapixel.cpp $(DIR)/rgbapixel.h
	$(CXX) $(FLAGS) -c RGBA/rgbapixel.cpp

png.o : $(DIR)/png.cpp $(DIR)/png.h
	$(CXX) $(FLAGS) -c RGBA/png.cpp

clean :
	rm -f $(PROG) *.o $(DIR)/*.o
