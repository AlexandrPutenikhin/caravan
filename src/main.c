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
#define TB_IMPL
#include "termbox2.h"

int main(void)
{
  struct tb_event ev;
  tb_init();

  while (1) {
    tb_poll_event(&ev);
    if (ev.type == TB_EVENT_KEY && ev.key == TB_KEY_ESC) break;
  }

  tb_shutdown();
  return 0;
}
