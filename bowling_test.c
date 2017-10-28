#include <stdio.h>
#include "bowling.h"

static int test_status = 0;
static int game_rolls[22];

void reset_rolls(int *rolls)
{
  for (int i = 0; i < 22; i++) rolls[i] = END_OF_ROLLS;
}

void roll_many(int *rolls, int pins, int count)
{
  for (int i = 0; i < count; i++) rolls[i] = pins;
}

void assert_equals(char *message, int expected, int actual)
{
  if (expected == actual) return;

  printf(
    "ERROR: %s, expected %d but got %d\n",
    message,
    expected,
    actual);

  test_status = -1;
}

void test_all_gutter_is_zero_score()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 0, 20);

  assert_equals(
    "all gutter game",
    0,
    bowling_score(game_rolls));
}

void test_single_pin_per_rolls()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 1, 20);

  assert_equals(
    "all gutter game",
    20,
    bowling_score(game_rolls));
}

void test_one_spare_game()
{
  reset_rolls(game_rolls);
  game_rolls[0] = 4;
  game_rolls[1] = 6;
  game_rolls[2] = 3;
  roll_many(&game_rolls[3], 0, 17);

  assert_equals(
    "single spare game",
    16,
    bowling_score(game_rolls));
}

void test_all_spare_game()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 5, 21);

  assert_equals(
    "all spare game",
    150,
    bowling_score(game_rolls));
}

void test_single_strike()
{
  reset_rolls(game_rolls);
  game_rolls[0] = 10;
  game_rolls[1] = 4;
  game_rolls[2] = 3;
  roll_many(&game_rolls[3], 0, 16);

  assert_equals(
    "single strike game",
    24,
    bowling_score(game_rolls));
}

void test_all_strike_game()
{
  reset_rolls(game_rolls);
  roll_many(game_rolls, 10, 12);

  assert_equals(
    "all spare game",
    300,
    bowling_score(game_rolls));
}

int main(int argc, char** argv)
{
  test_all_gutter_is_zero_score();
  test_single_pin_per_rolls();
  test_one_spare_game();
  test_all_spare_game();
  test_single_strike();
  test_all_strike_game();

  if (test_status == 0) puts("OK");

  return test_status;
}
