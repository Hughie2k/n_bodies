CC = g++
OBJS = main.o planet.o drawableparticle.o viewcontroller.o fpscounter.o timer.o vector.o
FLAGS = -Wall -Werror -std=c++20
LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system


output: $(OBJS)
	$(CC) $(FLAGS) -o output $(OBJS) $(LIBRARIES)

run: output
	./output
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

vector.o: vector.cpp vector.hpp
timer.o: timer.cpp timer.hpp
fpscounter.o: fpscounter.cpp fpscounter.hpp vector.hpp
viewcontroller.o: viewcontroller.cpp viewcontroller.hpp timer.hpp
drawableparticle.o: drawableparticle.cpp drawableparticle.hpp vector.hpp
planet.o: planet.cpp drawableparticle.hpp vector.hpp
particlesystem.o: particlesystem.cpp particlesystem.hpp drawableparticle.hpp timer.hpp vector.hpp
main.o: particlesystem.hpp planet.hpp particle.hpp timer.hpp vector.hpp