### INSTRUCTIONS ##############################
#
# In the terminal, if you type:
#
# 	make
#		You build the debug version of heist.
#
# 	make debug_run
# 		You run the debug version.
#
#
# 	make heist
# 		You build the playable version of heist.
#
# 	make run
#		You run the playable version of heist.
#
#
# 	make clean
# 		You deletee the object files generated
#       and clear the terminal.
#
###############################################

COMPILER = gcc -std=c99
FLAGS = -g -I. -Wall

CORE_OBJECTS = terminal/output.o terminal/input.o game/game.o move/move.o random/random.o bots/bot.o
DEBUG_OBJECTS = debug_main.o tests/harness.o game/test_game.o move/test_move.o


### debug commands
debug_heist: $(CORE_OBJECTS) $(DEBUG_OBJECTS)
	$(COMPILER) -o $@ $(CORE_OBJECTS) $(DEBUG_OBJECTS)

debug_main.o: main.c
	$(COMPILER) $(FLAGS) -DDEBUG=1 -c main.c -o debug_main.o

debug_run:
	./debug_heist


### playable commands
heist: main.o $(CORE_OBJECTS)
	$(COMPILER) -o $@ main.o $(CORE_OBJECTS)

main.o: main.c
	$(COMPILER) $(FLAGS) -c main.c -o main.o

run:
	./heist

### The following horrible looking grawlix tells the 
### compiler to make .o files from our .c files.
%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	rm -f heist
	rm -f debug_heist
	clear

### end of file ###