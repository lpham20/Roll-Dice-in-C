# This Makefile can build two different programs: roll_dice and monte_carlo.
# Both programs use the dice module. If you simply run "make" it will build the
# roll_dice program, since that is the first target in the file. You can run
# "make monte_carlo" to build the monte_carlo program.

CFLAGS=-std=c99 -Wall

roll_dice: roll_dice.o dice.o
	gcc $(CFLAGS) roll_dice.o dice.o -o roll_dice

monte_carlo: monte_carlo.o dice.o
	gcc $(CFLAGS) monte_carlo.o dice.o -o monte_carlo

monte_carlo.o: monte_carlo.c dice.h
	gcc $(CFLAGS) -c monte_carlo.c

roll_dice.o: roll_dice.c dice.h
	gcc $(CFLAGS) -c roll_dice.c

dice.o: dice.c dice.h
	gcc $(CFLAGS) -c dice.c

clean:
	rm -f roll_dice monte_carlo *.o
