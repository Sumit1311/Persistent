/*
 ======================================
 main.cpp
 -kernel startup code
 ======================================
 */

#include "debug_display.h"
#include "hal.h"

void
main ()
{

  int i = 0x12;

  debug_clr_scr (0x18);

  debug_goto_xy (4, 4);
  debug_set_color (0x17);
  debug_printf ("+-----------------------------------------+\n");
  debug_printf ("|    MOS 32 Bit C++ Kernel Executing!     |\n");
  debug_printf ("+-----------------------------------------+\n\n");
  debug_set_color (0x12);

  debug_set_color (0x12);
  debug_printf ("\ni as integer ........................");
  debug_printf ("\ni in hex ............................");

  debug_goto_xy (25, 8);
  debug_set_color (0x1F);
  debug_printf ("\n[%i]", i);
  debug_printf ("\n[0x%x]", i);

  debug_goto_xy (4, 16);
  debug_set_color (0x1F);
  debug_printf ("\n\nI am preparing to load... Hold on, please... :)");

  hal_initialize ();

}
