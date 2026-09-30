/**
   CSPRNG based on Salsa20
   Copyright (C) 2026  Alexandr Putenikhin

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
