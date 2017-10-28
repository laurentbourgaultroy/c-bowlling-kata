#include <stdio.h>
#include "bowling.h"

#define ALL_PINS 10

int is_last_frame(int *rolls) {
  for (int i = 0; i < 4; i++)
  {
    if (rolls[i] == NO_ROLL) return 1;
  }

  return 0;
}

int is_spare(int *rolls)
{
  if(rolls[0] + rolls[1] == ALL_PINS) return 1;
  return 0;
}

int is_strike(int *rolls)
{
  if (rolls[0] == ALL_PINS) return 1;
  return 0;
}

int sum(int *rolls, int max)
{
  int result = 0;
  for (int i = 0; i < max; i++)
  {
    if (rolls[i] == NO_ROLL) return result;
    result += rolls[i];
  };
  return result;
}

int bowling_score(int *rolls)
{
  if (is_last_frame(rolls)) return sum(rolls, 3);
  if (is_strike(rolls)) return sum(rolls, 3) + bowling_score(&rolls[1]);
  if (is_spare(rolls)) return sum(rolls, 3) + bowling_score(&rolls[2]);

  return sum(rolls, 2) + bowling_score(&rolls[2]);
}
