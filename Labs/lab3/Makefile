# Definition of variables
CPPFLAGS = -std=c++11 -Wall
SRCS = main.cpp datatype.cpp shopArray.cpp	# TODO: Modify this so that you can compile a version with shopLinkedList.cpp
OBJS = main.o datatype.o shopArray.o 		# TODO: Modify this so that you can compile a version with shopLinkedList.cpp
DEPS = $(SRCS:.cpp=.d)

all: shopArray.exe		# TODO: Modify this so that you can compile shopLinkedList.exe

# Rules: 
# target: dependencies
#   command used to create the target
shopArray.exe: $(OBJS)	# TODO: Compile shopLinkedList.exe, either in a separate rule or by utilizing pattern rule
	g++ $(CPPFLAGS) -o $@ $^

# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CPPFLAGS) -MMD -MP -c $<

clean:;	rm *.exe $(OBJS) $(DEPS)

.PRECIOUS: $(OBJS) shopArray.o shopLinkedList.o