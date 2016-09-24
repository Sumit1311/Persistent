/*
 ====================================================
 entry.cpp
 -This is the kernel entry point. This is called
 from the boot loader
 ====================================================
 */

extern void
main();

void
clear();

//extern void _cdecl InitializeConstructors();
extern void
Exit();

void
kernel_entry()
{

  //init();

  //! Execute global constructors
  //InitializeConstructors();

  //!	Call kernel entry point
  main();

  //! Cleanup all dynamic dtors
  //Exit ();

  clear();
  for (;;)
    ;
}
