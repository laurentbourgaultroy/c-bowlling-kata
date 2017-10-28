#ifndef BOWLING_H
#define BOWLING_H

/** Marker for the end of the game rolls */
#define END_OF_ROLLS -1

/**
 * Compute the final score for a game of bowling from the game rolls
 * \param rolls: Pointer to values of rolls, terminated by END_OF_ROLLS
 */
int bowling_score(int *rolls);

#endif
