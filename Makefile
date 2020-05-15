# compiler
CC		:= g++

# directories
CPP_DIR := src
OBJ_DIR := src/obj

# files
CPP 	:= $(wildcard $(CPP_DIR)/*.cpp)
OBJ 	:= $(patsubst $(CPP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP))

# application build
BUILD	:= bin/app.exe

# special windows flags
NOWIN 	:= -mwindows

# gtk flags 
GTK   	:= $(shell pkg-config gtkmm-3.0 --cflags --libs)

#link object file
$(BUILD): $(OBJ)
	$(CC) -o $@ $^ $(GTK)

# object files
$(OBJ_DIR)/%.o: $(CPP_DIR)/%.cpp
	$(CC) -c -o $@ $< $(GTK)

# clean build
clean: clean-objs
	rm -rf $(BUILD)

# clean obj files
clean-objs:
	rm -rf $(wildcard $(OBJ_DIR)/*.o)