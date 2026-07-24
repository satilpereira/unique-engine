# Isolated single-file experiments: every *.cpp here is its own standalone
# program, compiled independently -- nothing links against src/.
#
#   make              build all experiments -> bin/<name>
#   make bin/window   build just window.cpp -> bin/window
#   make run-window   build and run window.cpp

CXX      := g++
CXXSTD   := -std=c++17
BIN_DIR  := bin

SFML_DIR := $(abspath ../third_party/sfml)

CXXFLAGS := $(CXXSTD) -Wall -Wextra -isystem $(SFML_DIR)/include
LDFLAGS  := -L$(SFML_DIR)/lib -Wl,-rpath,$(SFML_DIR)/lib \
            -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
            -lGL -lGLU

SOURCES := $(wildcard *.cpp)
TARGETS := $(patsubst %.cpp,$(BIN_DIR)/%,$(SOURCES))

.PHONY: all clean

all: $(TARGETS)

$(BIN_DIR)/%: %.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run-%: $(BIN_DIR)/%
	./$(BIN_DIR)/$*

clean:
	rm -rf $(BIN_DIR)
