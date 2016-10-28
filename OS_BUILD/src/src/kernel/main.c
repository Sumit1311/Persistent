/*
 ======================================
 main.cpp
 -kernel startup code
 ======================================
 */

#include "bootinfo.h"
#include "exception.h"
#include "debug_display.h"
#include "hal.h"
#include "mmngr_phys.h"
#include "mmngr_virtual.h"
#include "kybrd.h"
#include "string.h"
#include "stdio.h"
#include "flpydsk.h"

struct memory_region
{

  uint32_t startLo;
  uint32_t startHi;
  uint32_t sizeLo;
  uint32_t sizeHi;
  uint32_t type;
  uint32_t acpi_3_0;
};

typedef struct memory_region memory_region;

//! different memory regions (in memory_region.type)
char* strMemoryTypes[] =
  { "Available", "Reserved", "ACPI Reclaim", "ACPI NVS Memory" };

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

void
init(multiboot_info* boot_info)
{
  //! get kernel size passed from boot loader
  uint32_t kernelSize = 0;
  _get_kernel_size(&kernelSize);

  //! make demo look nice :)
  debug_clr_scr(0x13);
  debug_goto_xy(0, 0);

  debug_set_color(0x3F);
  debug_printf(
      "                    ~[ Physical Memory Manager Demo ]~                          ");

  debug_goto_xy(0, 24);
  debug_set_color(0x3F);
  debug_printf(
      "                                                                                ");

  debug_goto_xy(0, 2);
  debug_set_color(0x17);

  //! Initialize hal driver
  hal_initialize();

  //! enable all interrupts
//  /enable ();

//! install our exception handlers
  setvect(0, &divide_by_zero_fault);
  setvect(1, &single_step_trap);
  setvect(2, &nmi_trap);
  setvect(3, &breakpoint_trap);
  setvect(4, &overflow_trap);
  setvect(5, &bounds_check_fault);
  setvect(6, &invalid_opcode_fault);
  setvect(7, &no_device_fault);
  setvect(8, &double_fault_abort);
  setvect(10, &invalid_tss_fault);
  setvect(11, &no_segment_fault);
  setvect(12, &stack_fault);
  setvect(13, &general_protection_fault);
  setvect(14, &page_fault);
  setvect(16, &fpu_fault);
  setvect(17, &alignment_check_fault);
  setvect(18, &machine_check_abort);
  setvect(19, &simd_fpu_fault);
  enable();
  pmmngr_init(boot_info->m_memorySize, 0xC0000000 + kernelSize * 512);

  memory_region* region = (memory_region*) 0x1000;

  for (int i = 0; i < 10; ++i)
    {

      if (region[i].type > 4)
        break;

      if (i > 0 && region[i].startLo == 0)
        break;

      pmmngr_init_region(region[i].startLo, region[i].sizeLo);
    }
  pmmngr_deinit_region(0x100000, kernelSize * 512);

  //! initialize our vmm
  vmmngr_initialize();
  kkybrd_install(33);

  //! set drive 0 as current drive
  flpydsk_set_working_drive(0);

  //! install floppy disk to IR 38, uses IRQ 6
  flpydsk_install(38);
}

void
sleep(int ms)
{

  static int ticks = 0;
  ticks = ms + get_tick_count();
  while (ticks > get_tick_count())
    ;
}

//! wait for key stroke
KEYCODE
getch()
{

  KEYCODE key = KEY_UNKNOWN;

  //! wait for a keypress
  while (key == KEY_UNKNOWN)
    key = kkybrd_get_last_key();

  //! discard last keypress (we handled it) and return
  kkybrd_discard_last_key();
  return key;
}

//! command prompt
void
cmd()
{

  debug_printf("\nCommand> ");
}

//! gets next command
void
get_cmd(char* buf, int n)
{

  cmd();

  KEYCODE key = KEY_UNKNOWN;
  bool BufChar;

  //! get command string
  int i = 0;
  while (i < n)
    {

      //! buffer the next char
      BufChar = true;

      //! grab next char
      key = getch();

      //! end of command if enter is pressed
      if (key == KEY_RETURN)
        break;

      //! backspace
      if (key == KEY_BACKSPACE)
        {

          //! dont buffer this char
          BufChar = false;

          if (i > 0)
            {

              //! go back one char
              unsigned y, x;
              debug_get_xy(&x, &y);
              if (x > 0)
                debug_goto_xy(--x, y);
              else
                {
                  //! x is already 0, so go back one line
                  y--;
                  x = debug_get_horz();
                }

              //! erase the character from display
              debug_putc(' ');
              debug_goto_xy(x, y);

              //! go back one char in cmd buf
              i--;
            }
        }

      //! only add the char if it is to be buffered
      if (BufChar)
        {

          //! convert key to an ascii char and put it in buffer
          char c = kkybrd_key_to_ascii(key);
          if (c != 0)
            { //insure its an ascii char

              debug_putc(c);
              buf[i++] = c;
            }
        }

      //! wait for next key. You may need to adjust this to suite your needs
      sleep(10);
    }

  //! null terminate the string
  buf[i] = '\0';
}

//! read sector command
void
cmd_read_sect()
{

  uint32_t sectornum = 0;
  char sectornumbuf[4];
  uint8_t* sector = 0;

  debug_printf("\n\rPlease type in the sector number [0 is default] >");
  get_cmd(sectornumbuf, 3);
  sectornum = atoi(sectornumbuf);
  sectornum = 1;
  debug_printf("\n\rSector %i contents:\n\n\r", sectornum);

  //! read sector from disk
  sector = flpydsk_read_sector(sectornum);

  //! display sector
  if (sector != 0)
    {

      int i = 0;
      for (int c = 0; c < 4; c++)
        {

          for (int j = 0; j < 128; j++)
            debug_printf("0x%x ", sector[i + j]);
          i += 128;

          debug_printf("\n\rPress any key to continue\n\r");
          getch();
        }
    }
  else
    debug_printf("\n\r*** Error reading sector from disk");

  debug_printf("\n\rDone.");
}

//! our simple command parser
bool
run_cmd(char* cmd_buf)
{

  //! exit command
  if (strcmp(cmd_buf, "exit") == 0)
    {
      return true;
    }

  //! clear screen
  else if (strcmp(cmd_buf, "cls") == 0)
    {
      debug_clr_scr(0x17);
    }

  //! help
  else if (strcmp(cmd_buf, "help") == 0)
    {

      debug_puts("\nOS Development Series Keyboard Programming Demo");
      debug_puts("\nwith a basic Command Line Interface (CLI)\n\n");
      debug_puts("Supported commands:\n");
      debug_puts(" - exit: quits and halts the system\n");
      debug_puts(" - cls: clears the display\n");
      debug_puts(" - help: displays this message\n");
      debug_puts(" - read: reads a specific sector and displays it in hex\n");
    }
  else if (strcmp(cmd_buf, "read") == 0)
    {
      cmd_read_sect();
    }

  //! invalid command
  else
    {
      debug_printf("\nUnkown command");
    }

  return false;
}

void
run()
{

  //! command buffer
  char cmd_buf[100];

  while (1)
    {

      //! get command
      get_cmd(cmd_buf, 98);

      //! run command
      if (run_cmd(cmd_buf) == true)
        break;
    }
}

int
main(multiboot_info* boot_info)
{

  //    _asm    mov     word ptr [kernelSize], dx

  init(boot_info);

  debug_goto_xy(0, 0);
  debug_puts("OSDev Series Keyboard Demo");
  debug_puts("\nType \"exit\" to quit, \"help\" for a list of commands\n");
  debug_puts("+-------------------------------------------------------+\n");

  run();

  debug_printf("\nExit command recieved; demo halted");
  for (;;)
    ;
  return 0;
}
