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

int
main(multiboot_info* boot_info)
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
  //! get memory size in KB
  uint32_t memSize = 1024 + boot_info->m_memoryLo + boot_info->m_memoryHi * 64;

  //! initialize the physical memory manager
  //! we place the memory bit map used by the PMM at the end of the kernel in memory
  pmmngr_init(memSize, 0x100000 + kernelSize * 512);

  debug_printf(
      "pmm initialized with %i KB physical memory; memLo: %i memHi: %i\n\n",
      memSize, boot_info->m_memoryLo, boot_info->m_memoryHi);

  debug_set_color(0x19);
  debug_printf("Physical Memory Map :\n");
  memory_region* region = (memory_region*) 0x1000;

  for (int i = 0; i < 15; ++i)
    {

      //! sanity check; if type is > 4 mark it reserved
      if (region[i].type > 4)
        region[i].type = 1;

      //! if start address is 0, there is no more entries, break out
      if (i > 0 && region[i].startLo == 0)
        break;

      //! display entry
      debug_printf(
          "region %i: start: 0x%x%x length (bytes): 0x%x%x type: %i (%s)\n", i,
          region[i].startHi, region[i].startLo, region[i].sizeHi,
          region[i].sizeLo, region[i].type, strMemoryTypes[region[i].type - 1]);

      //! if region is avilable memory, initialize the region for use
      if (region[i].type == 1)
        pmmngr_init_region(region[i].startLo, region[i].sizeLo);
    }

  //! deinit the region the kernel is in as its in use
  pmmngr_deinit_region(0x100000, kernelSize * 512);

  debug_set_color(0x17);

  debug_printf(
      "\npmm regions initialized: %i allocation blocks; used or reserved blocks: %i\nfree blocks: %i\n",
      pmmngr_get_block_count(), pmmngr_get_use_block_count(),
      pmmngr_get_free_block_count());

  //! allocating and deallocating memory examples...

  debug_set_color(0x12);

  uint32_t* p = (uint32_t*) pmmngr_alloc_block();
  debug_printf("\np allocated at 0x%x", p);

  uint32_t* p2 = (uint32_t*) pmmngr_alloc_blocks(2);
  debug_printf("\nallocated 2 blocks for p2 at 0x%x", p2);

  pmmngr_free_block(p);
  p = (uint32_t*) pmmngr_alloc_block();
  debug_printf("\nUnallocated p to free block 1. p is reallocated to 0x%x", p);

  pmmngr_free_block(p);
  pmmngr_free_blocks(p2, 2);
  while (1)
    ;
  return 0;
}
