# Makefile

COMPILER = gcc
CFLAGS   = -std=c99 -g -I. -Wall -MMD -MP

# Source files
SRC = main.c \
      cards/cards.c \
      players/players.c \
	  tower/tower.c \
      tests/tests.c \
      tests/test_players.c \
      tests/test_cards.c \
	  tests/test_copying.c \
	  tests/test_tower.c

# Object files in build/ maintaining folder structure
OBJ = $(patsubst %.c,build/%.o,$(SRC))
DEP = $(patsubst %.c,build/deps/%.d,$(SRC))

# Executable
TARGET = build/heist

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(COMPILER) $(CFLAGS) -o $@ $(OBJ)

# Compile rule for objects
build/%.o: %.c
	@mkdir -p $(dir $@) build/deps/$(dir $*) 2>/dev/null || true
	$(COMPILER) $(CFLAGS) -c $< -o $@

# Include dependency files
-include $(DEP)

# Run
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -rf build
	clear
