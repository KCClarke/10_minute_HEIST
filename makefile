# makefile

COMPILER = gcc -std=c99
FLAGS = -g -I. -Wall

OBJECTS = tests/tests.o cards/master_card_list.o players/players.o

heist: main.o $(OBJECTS)
	$(COMPILER) -o $@ main.o $(OBJECTS)

main.o: main.c
	$(COMPILER) $(FLAGS) -c main.c -o main.o

run:
	./heist

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	rm -f heist
	rm -f debug_heist
	clear