# Builds everything under src/ into bin/unique-engine.
#
# Uses the vendored SFML 3.1.0 in third_party/sfml (not the system apt
# package, which is 2.6.x). Regenerate that vendor install with:
#   cmake -S third_party/sfml-src -B third_party/sfml-build \
#     -DCMAKE_BUILD_TYPE=Release \
#     -DCMAKE_INSTALL_PREFIX="$(pwd)/third_party/sfml" \
#     -DSFML_BUILD_EXAMPLES=OFF -DSFML_BUILD_TEST_SUITE=OFF -DSFML_BUILD_DOC=OFF
#   cmake --build third_party/sfml-build -j$(nproc)
#   cmake --install third_party/sfml-build

CXX      := g++
CXXSTD   := -std=c++17
BUILD_DIR := build
BIN_DIR   := bin
TARGET    := $(BIN_DIR)/unique-engine

SFML_DIR := $(abspath third_party/sfml)

CXXFLAGS := $(CXXSTD) -Wall -Wextra -Isrc -isystem $(SFML_DIR)/include
LDFLAGS  := -L$(SFML_DIR)/lib -Wl,-rpath,$(SFML_DIR)/lib \
            -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
            -lGL -lGLU

SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPS    := $(OBJECTS:.o=.d)

.PHONY: all run clean

ifeq ($(strip $(SOURCES)),)
all:
	@echo "No .cpp files under src/ yet -- add some (e.g. src/main.cpp) and run 'make' again."
else
all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
endif

-include $(DEPS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
