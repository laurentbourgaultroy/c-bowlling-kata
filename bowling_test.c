#include <stdio.h>
#include <check.h>
#include "bowling.h"

static int test_status = 0;
static int game_rolls[22];

void reset_rolls(int *rolls)
{
  for (int i = 0; i < 22; i++)
  {
    rolls[i] = NO_ROLL;
  }
}

void roll_many(int *rolls, int pins, int count)
{
  for (int i = 0; i < count; i++)
  {
    rolls[i] = pins;
  }
}

void assert_equals(char *message, int expected, int actual)
{
  if (expected == actual) return;

  printf("ERROR: %s, expected %d but got %d\n", message, expected, actual);
  test_status = -1;
}

void test_all_gutter_is_zero_score()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 0, 20);

  assert_equals("reset score", NO_ROLL, game_rolls[21]);
  int score = bowling_score(game_rolls);

  assert_equals("all gutter game", 0, score);
}

void test_single_pin_per_rolls()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 1, 20);

  int score = bowling_score(game_rolls);

  assert_equals("single pin per roll game", 20, score);
}

int main(int argc, char** argv)
{
  test_all_gutter_is_zero_score();
  test_single_pin_per_rolls();
  return test_status;
}
