/*
 ======================================
 main.cpp
 -kernel startup code
 ======================================
 */

#include "exception.h"
#include "debug_display.h"
#include "hal.h"

/*
 *	Our uber-1337 logo
 */
char* logo =
    "\
    __  _______  _____\n\
   /  |/  / __ \\/ ___/\n\
  / /|_/ / / / /\\__ \\ Microcomputer Operating System \n\
 / /  / / /_/ /___/ / -------------------------------\n\
/_/  /_/\\____//____/  \n\n";

int
main ()
{

  //! Initialize hal driver
  hal_initialize ();

  //! enable all interrupts
//  /enable ();

//! install our exception handlers
  setvect (0, &divide_by_zero_fault);
  setvect (1, &single_step_trap);
  setvect (2, &nmi_trap);
  setvect (3, &breakpoint_trap);
  setvect (4, &overflow_trap);
  setvect (5, &bounds_check_fault);
  setvect (6, &invalid_opcode_fault);
  setvect (7, &no_device_fault);
  setvect (8, &double_fault_abort);
  setvect (10, &invalid_tss_fault);
  setvect (11, &no_segment_fault);
  setvect (12, &stack_fault);
  setvect (13, &general_protection_fault);
  setvect (14, &page_fault);
  setvect (16, &fpu_fault);
  setvect (17, &alignment_check_fault);
  setvect (18, &machine_check_abort);
  setvect (19, &simd_fpu_fault);
  enable ();
  //! clear and init display
  debug_clr_scr (0x13);
  debug_goto_xy (0, 0);
  debug_set_color (0x19);

  //! render text and logo
  debug_puts (logo);
  debug_set_color (0x17);
  debug_puts (
      "Weee.... The PIC, PIT, and exception handlers are installed!\n\n");
  debug_puts ("Hitting any key will fire the default HAL handlers as we do\n");
  debug_puts ("not have a keyboard driver yet to install one.\n\n");
  debug_printf ("Cpu vender: %s \n\n", get_cpu_vender ());

  // Go into a loop--constantly display the current tick count
  for (;;)
    {
      debug_goto_xy (0, 14);
      debug_printf ("Current tick count: %i", get_tick_count ());
    }

  return 0;
}
