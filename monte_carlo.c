// Write a main() function here to get parameters from the command line
// arguments and then run the Monte Carlo simulation by calling your
// all_same_probability() function.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dice.h"

int main(int argc, char **argv) {
    if (argc != 4) {
       printf("Usage: %s <sides per die> <dice count>\n", argv[0]);
       return 1;
    }

    srand(time(NULL));

    size_t sides = atoi(argv[1]);
    size_t dice_counts = atoi(argv[2]);
    size_t roll_counts = atoi(argv[3]);

    double probability = all_same_probability(sides, dice_counts, roll_counts);

    printf("The probability of rolling the same values with %zu %zu-sided "
           "dice is approximately %f\n", dice_counts, sides, probability);

    return 0;
}
