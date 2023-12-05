CPPFLAGS = -std=c++11 -fno-elide-constructors # -static-libgcc -static-libstdc++
CPPFLAGS_leak = -std=c++11 -fno-elide-constructors -fsanitize=address,leak,undefined

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak


all: create_directory test_utils test_expr test_parse test_complex test_combine
	@echo "build all tests"

test_utils: create_directory test_utils.exe test_utils_leak.exe
	@echo "build test_utils"

test_expr: create_directory test_expr.exe test_expr_leak.exe
	@echo "build test_expr"

test_parse: create_directory test_parse.exe test_parse_leak.exe
	@echo "build test_parse"

test_complex: create_directory test_complex.exe test_complex_leak.exe
	@echo "build test_complex"

test_combine: create_directory test_combine.exe test_combine_leak.exe
	@echo "build test_combine"

create_directory:
	mkdir -p $(OBJ_DIR) $(OBJ_DIR_leak)

UTILS_SOURCES = test_utils.cpp utils.cpp
UTILS_OBJECTS = $(addprefix $(OBJ_DIR)/,$(UTILS_SOURCES:.cpp=.o))
UTILS_OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(UTILS_SOURCES:.cpp=.o))

test_utils.exe: $(UTILS_OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

test_utils_leak.exe: $(UTILS_OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

EXPR_SOURCES = test_expr.cpp
EXPR_OBJECTS = $(addprefix $(OBJ_DIR)/,$(EXPR_SOURCES:.cpp=.o))
EXPR_OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(EXPR_SOURCES:.cpp=.o))

test_expr.exe: $(EXPR_OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

test_expr_leak.exe: $(EXPR_OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^
	
PARSE_SOURCES = test_parse.cpp utils.cpp
PARSE_OBJECTS = $(addprefix $(OBJ_DIR)/,$(PARSE_SOURCES:.cpp=.o))
PARSE_OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(PARSE_SOURCES:.cpp=.o))

test_parse.exe: $(PARSE_OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

test_parse_leak.exe: $(PARSE_OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^
	
COMPLEX_SOURCES = test_complex.cpp utils.cpp
COMPLEX_OBJECTS = $(addprefix $(OBJ_DIR)/,$(COMPLEX_SOURCES:.cpp=.o))
COMPLEX_OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(COMPLEX_SOURCES:.cpp=.o))

test_complex.exe: $(COMPLEX_OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

test_complex_leak.exe: $(COMPLEX_OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^
	
COMBINE_SOURCES = test_combine.cpp utils.cpp
COMBINE_OBJECTS = $(addprefix $(OBJ_DIR)/,$(COMBINE_SOURCES:.cpp=.o))
COMBINE_OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(COMBINE_SOURCES:.cpp=.o))

test_combine.exe: $(COMBINE_OBJECTS)
	g++ -o $@ $(CPPFLAGS) $^

test_combine_leak.exe: $(COMBINE_OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -c $< -o $@

clean:
	del  -r  $(OBJ_DIR) $(OBJ_DIR_leak) *.exe 
