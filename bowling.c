#include <stdio.h>
#include "bowling.h"

int bowling_score(int *rolls)
{
  int score = 0;
  int *current_roll;

  current_roll = rolls;
  while(*current_roll != NO_ROLL)
  {
    score += *current_roll;
    current_roll++;
  }

  return score;
}
