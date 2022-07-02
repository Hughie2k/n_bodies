CC := g++
FLAGS := -Wall -Werror
INCLUDE := C:\Users\hugho\dev\SFML-2.5.1\include
LIB := C:\Users\hugho\dev\SFML-2.5.1\lib
LIBRARIES := -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype

output.exe: vector.o body.o planet.o main.o
	$(CC) $(FLAGS) -o output.exe main.o planet.o body.o vector.o timer.o -L $(LIB) $(LIBRARIES) 

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

vector.o: vector.cpp vector.hpp
timer.o: timer.cpp timer.hpp
body.o: body.cpp body.hpp vector.hpp
planet.o: planet.cpp planet.hpp body.hpp vector.hpp
main.o: main.cpp planet.hpp body.hpp vector.hpp