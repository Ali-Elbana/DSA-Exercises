#
#============================================================
# Project: Array-Based Stack Data Structure
# File:    Makefile
# Author:  [Ali El-bana]
# Date:    2025-08-15
# Version: v1.1
#------------------------------------------------------------
# Description:
# Build configuration for Stack implementation with
# compilation rules, dependencies, and utility targets
#------------------------------------------------------------
# Notes:
# - Adapted for Windows 10 with MinGW g++
# - Build and run directly from this Makefile
#============================================================

# ====================== Build Configuration ======================
# ----- Compiler Settings -----
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# ----- Project Files -----
TARGET = stack_demo.exe
SOURCES = main.cpp Stack-Array.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Stack-Array.hpp

# ====================== Build Targets ======================

# ----- Default Target -----
all: $(TARGET)
	@echo Build completed successfully!

# ----- Main Executable -----
$(TARGET): $(OBJECTS)
	@echo Linking executable: $@
	$(CXX) $(CXXFLAGS) -o $@ $^

# ----- Object Files -----
%.o: %.cpp $(HEADERS)
	@echo Compiling: $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ====================== Utility Targets ======================

# ----- Clean Build Artifacts -----
clean:
	@echo Cleaning build artifacts...
	del /Q $(OBJECTS) $(TARGET) 2>nul || echo No files to clean.
	@echo Clean completed!

# ----- Run Program -----
run: $(TARGET)
	@echo Running program...
	$(TARGET)

# ----- Debug Build -----
debug: CXXFLAGS += -g -DDEBUG -O0
debug: $(TARGET)
	@echo Debug build completed!

# ----- Release Build -----
release: CXXFLAGS += -O3 -DNDEBUG
release: $(TARGET)
	@echo Release build completed!

# ----- Rebuild Everything -----
rebuild: clean all

# ----- Show Help -----
help:
	@echo Available targets:
	@echo   all      - Build the project (default)
	@echo   clean    - Remove build artifacts
	@echo   run      - Build and run the program
	@echo   debug    - Build with debug symbols
	@echo   release  - Build optimized release version
	@echo   rebuild  - Clean and build
	@echo   help     - Show this help message

# ----- Phony Targets -----
.PHONY: all clean run debug release rebuild help

#======================= End of File ===================
