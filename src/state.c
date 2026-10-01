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
#include "state.h"

struct CaravanState {
  int tickNum;
};

CaravanState_t* CaravanState_init()
{
  CaravanState_t* state = malloc(sizeof(struct CaravanState));
  state->tickNum = 0;
  return state;
}

bool CaravanState_tick(CaravanState_t* state, const struct tb_event event)
{
  state->tickNum++;
  if (event.type == TB_EVENT_KEY && event.key == TB_KEY_CTRL_C) return true;
  return false;
}

void CaravanState_draw(CaravanState_t* state)
{
  tb_clear();
  tb_printf(0, 0, TB_WHITE, TB_BLACK, "Tick: %d", state->tickNum);
}

void CaravanState_clean(CaravanState_t* state)
{
  free(state);
}
