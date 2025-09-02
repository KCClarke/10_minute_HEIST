### INSTRUCTIONS ##############################
#
# In the terminal, if you type:
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

OBJECTS = tests/tests.o cards/master_card_list.o

### playable commands
heist: main.o $(OBJECTS)
	$(COMPILER) -o $@ main.o $(OBJECTS)

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