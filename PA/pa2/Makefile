CPPFLAGS = -std=c++11 -g

SHARED  = blockchain.cpp user.cpp transaction.cpp math.cpp consensus.cpp timestamp.cpp
SRCS	= main.cpp $(SHARED)
SRCS_TEST = main_test.cpp $(SHARED)
OBJS	= $(SRCS:.cpp=.o)
OBJS_TEST = $(SRCS_TEST:.cpp=.o)
DEPS	= $(OBJS:.o=.d)


all: PA2.exe 

PA2.exe: $(OBJS) 
	g++ $(CPPFLAGS) -o $@ $^

test: PA2_test.exe

PA2_test.exe: $(OBJS_TEST)
	g++ $(CPPFLAGS) -o $@ $^

# To include the .d dependency files
-include $(DEPS)

%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

clean:;
	del *.o *.exe *.d
# del *.o *.exe *.d  #for Windows

