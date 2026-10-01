/**
   Entry point
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
#include "termbox2.h"
#include "state.h"

int main(void)
{
  int initStatus = tb_init();
  if (initStatus != TB_OK) return initStatus;

  CaravanState_t* state = (CaravanState_t*)CaravanState_init();

  struct tb_event ev = {0};
  while (1) {
    if (CaravanState_tick(state, ev)) break;
    CaravanState_draw(state);
    tb_present();
    tb_poll_event(&ev);
  }

  CaravanState_clean(state);
  return tb_shutdown();
}
