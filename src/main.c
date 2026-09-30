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
