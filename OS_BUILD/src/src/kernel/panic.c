//****************************************************************************
//**
//**    panic.cpp
//**
//****************************************************************************

#include "hal.h"
#include "stdarg.h"
#include "debug_display.h"

//! something is wrong--bail out
void
kernel_panic (const char* fmt, ...)
{

  disable ();

  va_list args;
  static char buf[1024];

  va_start(args, fmt);

// We will need a vsprintf() here. I will see if I can write
// one before the tutorial release

  va_end (args);

  char* disclamer =
      "We apologize, MOS has encountered a problem and has been shut down\n\
to prevent damage to your computer. Any unsaved work might be lost.\n\
We are sorry for the inconvenience this might have caused.\n\n\
Please report the following information and restart your computer.\n\
The system has been halted.\n\n";

  debug_clr_scr (0x1f);
  debug_goto_xy (0, 0);
  debug_set_color (0x1f);
  debug_puts (disclamer);

  debug_printf ("*** STOP: %s", fmt);
  for (;;)
    ;
}

