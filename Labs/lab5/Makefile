CPPFLAGS = -std=c++11

# List all your object files here
OBJECTS = main.o Rectangle.o

all: lab5.exe

lab5.exe: $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $(OBJECTS)

# This pattern will create a .o file for each .cpp file
%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
