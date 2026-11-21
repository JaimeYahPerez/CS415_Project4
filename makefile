
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

p3: main.o input.o
	$(CXX) $(CXXFLAGS) main.o input.o -o p3

main.o: main.cpp input.hpp knapsack.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

input.o: input.cpp input.hpp knapsack.hpp
	$(CXX) $(CXXFLAGS) -c input.cpp

clean:
	rm -f *.o p3