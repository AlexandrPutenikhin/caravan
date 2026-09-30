#include <stdint.h>
#include "caravan_rand.h"

#define FOUR_CHARS_TO_INT32(b0, b1, b2, b3) b0 ^ (b1 >> 8) ^ (b2 >> 16) ^ (b3 >> 24)

const uint32_t MAGIC_1 = FOUR_CHARS_TO_INT32('e', 'x', 'p', 'a');
const uint32_t MAGIC_2 = FOUR_CHARS_TO_INT32('n', 'd', ' ', '3');
const uint32_t MAGIC_3 = FOUR_CHARS_TO_INT32('2', '-', 'b', 'y');
const uint32_t MAGIC_4 = FOUR_CHARS_TO_INT32('t', 'e', ' ', 'k');

union Caravan_RandBlock {
  uint32_t inWords[16];
  uint8_t inBytes[64];
};

void Caravan_RandState_init(union Caravan_RandBlock* state, const uint32_t seed[8])
{
  state->inWords[0] = MAGIC_1;
  state->inWords[1] = seed[0];
  state->inWords[2] = seed[1];
  state->inWords[3] = seed[2];
  state->inWords[4] = seed[3];
  state->inWords[5] = MAGIC_2;
  state->inWords[11] = seed[4];
  state->inWords[12] = seed[5];
  state->inWords[13] = seed[6];
  state->inWords[14] = seed[7];
}
