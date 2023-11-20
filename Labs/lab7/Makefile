CPPFLAGS = -std=c++11

all: lab7.exe

lab7.exe: order_item.o order.o main.cpp
	g++ -o $@ $(CPPFLAGS) order_item.o order.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
