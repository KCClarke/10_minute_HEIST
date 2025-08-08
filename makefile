### INSTRUCTIONS ##############################
#
# In the terminal, if you type:
#
# 	make
#		you build the debug version of heist
#
# 	make debug_run
# 		you run the debug version
#
#
# 	make heist
# 		you build the playable version of heist
#
# 	make run
#		you run the playable version of heist
#
#
# 	make clean
# 		deletes the object files generated and
# 		clears the terminal
#
###############################################

COMPILER = gcc -std=c99
FLAGS = -g -I. -Wall

CORE_OBJECTS = terminal/output.o terminal/input.o game/game.o move/move.o random/random.o
DEBUG_OBJECTS = debug_main.o tests/harness.o game/test_game.o move/test_move.o


### debug
debug_heist: $(CORE_OBJECTS) $(DEBUG_OBJECTS)
	$(COMPILER) -o $@ $(CORE_OBJECTS) $(DEBUG_OBJECTS)

debug_main.o: main.c
	$(COMPILER) $(FLAGS) -DDEBUG=1 -c main.c -o debug_main.o

debug_run:
	./debug_heist


### playable
heist: main.o $(CORE_OBJECTS)
	$(COMPILER) -o $@ main.o $(CORE_OBJECTS)

main.o: main.c
	$(COMPILER) $(FLAGS) -c main.c -o main.o

run:
	./heist

### The following horrible looking grawlix tells the 
# compiler to make .o files from our .c files
%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	rm -f heist
	rm -f debug_heist
	clear

### end of file ###