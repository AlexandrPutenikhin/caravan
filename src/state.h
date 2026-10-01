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
#ifndef CARAVAN_STATE_H
#define CARAVAN_STATE_H
#include <stdbool.h>
#include "termbox2.h"

typedef struct CaravanState CaravanState_t;

CaravanState_t* CaravanState_init();
/**
   ret: True if tick is final, false otherwise
 */
bool CaravanState_tick(CaravanState_t* state, const struct tb_event event);
void CaravanState_draw(const CaravanState_t* state);
void CaravanState_clean(CaravanState_t* state);

#endif
