CXX=g++
CXXFLAGS=-std=c++14 -Wall

main: main.o online_algorithm.o offline_algorithm.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

online_algorithm.o: online_algorithm.cpp online_algorithm.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

offline_algorithm.o: offline_algorithm.cpp offline_algorithm.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf *.o main