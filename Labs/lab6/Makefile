CPPFLAGS = -std=c++11

all: lab6.exe

lab6.exe: browser.o tab.o main.cpp
	g++ -o $@ $(CPPFLAGS) browser.o tab.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
