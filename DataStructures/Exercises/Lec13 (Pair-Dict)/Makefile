#============================================================
# Project: Dictionary with Custom Pair Implementation
# File:    Makefile
# Author:  [Ali El-bana]
# Date:    [2025-08-18]
# Version: [v1.0]
#------------------------------------------------------------
# Description:
# Makefile for compiling the Dictionary project with custom
# Pair implementation. Handles compilation, linking, and
# cleanup operations for the multi-file project.
#------------------------------------------------------------
# Notes:
# - Uses g++ compiler with C++11 standard
# - Includes debugging symbols and warnings
# - Project path: G:\DSA\MetwallyCourse\DataStructures\Exercises\Lec13 (Pair-Dict)
#============================================================

# =================== Compiler Settings =================
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O2
TARGET = dict_program
PROJECT_PATH = "G:\DSA\MetwallyCourse\DataStructures\Exercises\Lec13 (Pair-Dict)"

# =================== Source Files ===================
SOURCES = main.cpp Dict-Pair.cpp
HEADERS = Dict-Pair.hpp
OBJECTS = $(SOURCES:.cpp=.o)

# =================== Build Rules ====================

# Default target
all: $(TARGET)
	@echo "=== Build completed successfully ==="
	@echo "Executable: $(TARGET).exe"
	@echo "Project path: $(PROJECT_PATH)"

# Link the executable
$(TARGET): $(OBJECTS)
	@echo "=== Linking executable ==="
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	@echo "=== Compiling $< ==="
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =================== Utility Targets ================

# Run the program
run: $(TARGET)
	@echo "=== Running program ==="
	@echo ""
	./$(TARGET)

# Clean build files
clean:
	@echo "=== Cleaning build files ==="
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe
	@echo "Clean completed"

# Rebuild everything
rebuild: clean all
	@echo "=== Rebuild completed ==="

# Debug build (with extra debugging info)
debug: CXXFLAGS += -DDEBUG -g3
debug: $(TARGET)
	@echo "=== Debug build completed ==="

# Release build (optimized)
release: CXXFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)
	@echo "=== Release build completed ==="

# =================== Help Target ===================
help:
	@echo "=== Available Make Targets ==="
	@echo "all      - Build the project (default)"
	@echo "run      - Build and run the program"
	@echo "clean    - Remove all build files"
	@echo "rebuild  - Clean and build"
	@echo "debug    - Build with debug symbols"
	@echo "release  - Build optimized release version"
	@echo "help     - Show this help message"
	@echo ""
	@echo "Project: Dictionary with Custom Pair"
	@echo "Path: $(PROJECT_PATH)"

# =================== Dependencies ===================
main.o: main.cpp Dict-Pair.hpp
Dict-Pair.o: Dict-Pair.cpp Dict-Pair.hpp

# Mark targets that don't create files
.PHONY: all clean run rebuild debug release help

#======================= End of File ===================