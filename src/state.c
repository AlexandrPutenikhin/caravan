/**
   Game state supervisor
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
#include <malloc.h>
#include "termbox2.h"
#include "state.h"

struct CaravanState {
  int width, height;
};

CaravanState_t* CaravanState_init()
{
  CaravanState_t* state = malloc(sizeof(struct CaravanState));
  state->width = tb_width();
  state->height = tb_height();
  return state;
}

bool CaravanState_tick(CaravanState_t* state, const struct tb_event event)
{
  if (event.type == TB_EVENT_KEY && event.key == TB_KEY_CTRL_C) return true;

  if (event.type == TB_EVENT_RESIZE) {
    state->width = event.w;
    state->height = event.h;
  }

  return false;
}

void CaravanState_draw(const CaravanState_t* state)
{
  tb_clear();
  for (int i = 0; i < state->width; i++) {
    tb_set_cell(i, state->height - 1, ' ', TB_BLACK, TB_WHITE | TB_BRIGHT);
  }
}

void CaravanState_clean(CaravanState_t* state)
{
  free(state);
}
