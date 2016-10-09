/*
 ====================================================
 entry.cpp
 -This is the kernel entry point. This is called
 from the boot loader
 ====================================================
 */

#include "bootinfo.h"

extern void
main(multiboot_info *boot_info);

void
clear();

//extern void _cdecl InitializeConstructors();
extern void
Exit();

void
kernel_entry(multiboot_info *boot_info)
{

  //init();

  //! Execute global constructors
  //InitializeConstructors();

  //!	Call kernel entry point
  main(boot_info);

  //! Cleanup all dynamic dtors
  //Exit ();

  clear();
  for (;;)
    ;
}
