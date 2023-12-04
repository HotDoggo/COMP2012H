CPPFLAGS = -std=c++11 -g

SHARED  = datatype.cpp opendatabase.cpp chaindatabase.cpp
SRCS	= main.cpp $(SHARED)
SRCS_TEST = main_test.cpp $(SHARED)
OBJS	= $(SRCS:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

all: PA4.exe 

PA4.exe: $(OBJS) 
	g++ $(CPPFLAGS) -o $@ $^

test: PA4_test.exe

PA4_test.exe: $(OBJS_TEST)
	g++ $(CPPFLAGS) -o $@ $^

# To include the .d dependency files
-include $(DEPS)

# Additional .tpp dependencies
bst.h: bst.tpp
opendatabase.h: opendatabase.tpp

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

clean:;
	del *.o PA4.exe PA4_test.exe *.d
# del *.o *.exe *.d  #for Windows

