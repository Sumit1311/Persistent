#ifndef _DEBUGDISPLAY_H
#define _DEBUGDISPLAY_H
//****************************************************************************
//**
//**    DebugDisplay.h
//**    - Allows displaying debugging information for testing without
//**	worry of compatability nor hardware abstraction.
//**
//****************************************************************************
//============================================================================
//    INTERFACE REQUIRED HEADERS
//============================================================================
//============================================================================
//    INTERFACE DEFINITIONS / ENUMERATIONS / SIMPLE TYPEDEFS
//============================================================================
//============================================================================
//    INTERFACE CLASS PROTOTYPES / EXTERNAL CLASS REFERENCES
//============================================================================
//============================================================================
//    INTERFACE STRUCTURES / UTILITY CLASSES
//============================================================================
//============================================================================
//    INTERFACE DATA DECLARATIONS
//============================================================================
//============================================================================
//    INTERFACE FUNCTION PROTOTYPES
//============================================================================

extern void
debug_clr_scr (const unsigned short c);
extern void
debug_puts (char* str);
extern int
debug_printf (const char* str, ...);
extern unsigned
debug_set_color (const unsigned c);
extern void
debug_goto_xy (unsigned x, unsigned y);
extern void
debug_get_xy (unsigned* x, unsigned* y);
extern int
debug_get_horz ();
extern int
debug_get_vert ();
void
debug_putc (unsigned char c);
//============================================================================
//    INTERFACE OBJECT CLASS DEFINITIONS
//============================================================================
//============================================================================
//    INTERFACE TRAILING HEADERS
//============================================================================
//****************************************************************************
//**
//**    END DebugDisplay.h
//**
//****************************************************************************
#endif
