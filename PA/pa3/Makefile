CPPFLAGS = -std=c++11 -g

all: PA3.exe

PA3.exe: utils.o main.cpp
	g++ -o $@ $(CPPFLAGS) utils.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o PA3.exe

# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
