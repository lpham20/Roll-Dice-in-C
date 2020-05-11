#include "dice.h"


unsigned int roll_die(size_t sides) {
    return rand() % sides + 1;
}


void roll_dice(unsigned int *dice, size_t sides, size_t count) {
    for (size_t i = 0; i < count; i++) {
        dice[i] = roll_die(sides);
    }
}


void print_dice(const unsigned int *dice, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%u", dice[i]);
        if (i < count - 1) {
            putchar(' ');
        }
    }
}

bool are_all_same(unsigned int *dice, size_t count) {
  int value = dice[0];
  for (size_t i = 1; i < count; i++) {
    if (value != dice[i]) {
      return false;
    }
  }
  return true;
}

double all_same_probability(size_t sides, size_t dice_count, size_t roll_count) {
  unsigned int dice[dice_count];
  int count = 0;
  for (size_t i = 0; i < roll_count; i++) {
    roll_dice(dice, sides, dice_count);
    if (are_all_same(dice, dice_count)) {
      count += 1;
    }
  }
  return (double) count / roll_count;
}
