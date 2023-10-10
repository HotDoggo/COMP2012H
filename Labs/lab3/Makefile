# Definition of variables
CPPFLAGS = -std=c++11 -Wall
SRCS = main.cpp datatype.cpp 	# TODO: Modify this so that you can compile a version with shopLinkedList.cpp
OBJS = main.o datatype.o  		# TODO: Modify this so that you can compile a version with shopLinkedList.cpp
DEPS = $(SRCS:.cpp=.d)

all: shopArray.exe shopLinkedList.exe		# TODO: Modify this so that you can compile shopLinkedList.exe
	del $(OBJS) shopArray.o shopLinkedList.o $(DEPS) shopArray.d shopLinkedList.d

# Rules: 
# target: dependencies
#   command used to create the target
shopArray.exe: $(OBJS) shopArray.o	# TODO: Compile shopLinkedList.exe, either in a separate rule or by utilizing pattern rule
	g++ $(CPPFLAGS) -o $@ $^

shopLinkedList.exe: $(OBJS) shopLinkedList.o
	g++ $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

# To include the .d dependency files
-include $(DEPS)

# -MMD -MP creates the .d dependency files
.cpp.o:; g++ $(CPPFLAGS) -MMD -MP -c $<

clean:;	del *.exe $(OBJS) shopArray.o shopLinkedList.o $(DEPS) shopArray.d shopLinkedList.d

.PRECIOUS: $(OBJS) shopArray.o shopLinkedList.o