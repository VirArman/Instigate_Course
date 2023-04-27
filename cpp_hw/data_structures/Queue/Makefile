export EXE_FILE := List
export SOURCE_FILES := $(wildcard *.cpp)
export LIB := $(../LinkedList/List.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

$(EXE_FILE) : $(OBJ_FILES)
	gcc $^ -lm -lstdc++ -o $@

%.o :
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_FILES)  $(EXE_FILE)
clear:
	rm -rf $(OBJ_FILES) 
