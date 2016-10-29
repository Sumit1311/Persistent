//****************************************************************************
//**
//**    [FILE NAME]
//**    - [FILE DESCRIPTION]
//**
//****************************************************************************
//============================================================================
//    IMPLEMENTATION HEADERS
//============================================================================

#include "stdarg.h"
#include "string.h"
#include "debug_display.h"
#include "hal.h"

//============================================================================
//    IMPLEMENTATION PRIVATE DEFINITIONS / ENUMERATIONS / SIMPLE TYPEDEFS
//============================================================================
//============================================================================
//    IMPLEMENTATION PRIVATE CLASS PROTOTYPES / EXTERNAL CLASS REFERENCES
//============================================================================
//============================================================================
//    IMPLEMENTATION PRIVATE STRUCTURES / UTILITY CLASSES
//============================================================================
//============================================================================
//    IMPLEMENTATION REQUIRED EXTERNAL REFERENCES (AVOID)
//============================================================================
//============================================================================
//    IMPLEMENTATION PRIVATE DATA
//============================================================================

//! video memory
uint16_t *video_memory = (uint16_t *) 0xB8000;

//! current position
uint8_t cursor_x = 0;
uint8_t cursor_y = 0;

//! current color
uint8_t _color = 0;

//============================================================================
//    INTERFACE DATA
//============================================================================
//============================================================================
//    IMPLEMENTATION PRIVATE FUNCTION PROTOTYPES
//============================================================================
//============================================================================
//    IMPLEMENTATION PRIVATE FUNCTIONS
//============================================================================

//! Updates hardware cursor
void
debug_update_cur(int x, int y)
{

  // get location
  uint16_t cursorLocation = y * 80 + x;

  // send location to vga controller to set cursor
//#if 0
  disable();
  outportb(0x3D4, 14);
  outportb(0x3D5, cursorLocation >> 8); // Send the high byte.
  outportb(0x3D4, 15);
  outportb(0x3D5, cursorLocation); // Send the low byte.
  enable();
//#endif
}

void
scroll()
{

  if (cursor_y >= 25)
    {

      uint16_t attribute = _color << 8;

      //! move current display up one line
      for (int i = 0 * 80; i < 24 * 80; i++)
        video_memory[i] = video_memory[i + 80];

      //! clear the bottom line
      for (int i = 24 * 80; i < 25 * 80; i++)
        video_memory[i] = attribute | ' ';

      cursor_y = 24;
    }
}

void
debug_putc(unsigned char c)
{

  uint16_t attribute = _color << 8;

  //! backspace character
  if (c == 0x08 && cursor_x)
    cursor_x--;

  //! tab character
  else if (c == 0x09)
    cursor_x = (cursor_x + 8) & ~(8 - 1);

  //! carriage return
  else if (c == '\r')
    cursor_x = 0;

  //! new line
  else if (c == '\n')
    {
      cursor_x = 0;
      cursor_y++;
    }

  //! printable characters
  else if (c >= ' ')
    {

      //! display character on screen
      uint16_t* location = video_memory + (cursor_y * 80 + cursor_x);
      *location = c | attribute;
      cursor_x++;
    }

  //! if we are at edge of row, go to new line
  if (cursor_x >= 80)
    {

      cursor_x = 0;
      cursor_y++;
    }

  //! if we are at the last line, scroll up
  if (cursor_y >= 25)
    scroll();

  //! update hardware cursor
  debug_update_cur(cursor_x, cursor_y);

}

char tbuf[32];
char bchars[] =
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E',
      'F' };

void
itoa(unsigned i, unsigned base, char* buf)
{
  int pos = 0;
  int opos = 0;
  int top = 0;

  if (i == 0 || base > 16)
    {
      buf[0] = '0';
      buf[1] = '\0';
      return;
    }

  while (i != 0)
    {
      tbuf[pos] = bchars[i % base];
      pos++;
      i /= base;
    }
  top = pos--;
  for (opos = 0; opos < top; pos--, opos++)
    {
      buf[opos] = tbuf[pos];
    }
  buf[opos] = 0;
}

void
itoa_s(int i, unsigned base, char* buf)
{
  if (base > 16)
    return;
  if (i < 0)
    {
      *buf++ = '-';
      i *= -1;
    }
  itoa(i, base, buf);
}

//============================================================================
//    INTERFACE FUNCTIONS
//============================================================================

unsigned
debug_set_color(const unsigned c)
{

  unsigned t = _color;
  _color = c;
  return t;
}

void
debug_goto_xy(unsigned x, unsigned y)
{

  if (cursor_x <= 80)
    cursor_x = x;

  if (cursor_y <= 25)
    cursor_y = y;

  //! update hardware cursor to new position
  debug_update_cur(cursor_x, cursor_y);
}

void
debug_clr_scr(const unsigned short c)
{

  //! clear video memory by writing space characters to it
  for (int i = 0; i < 80 * 25; i++)
    video_memory[i] = ' ' | (c << 8);

//! move position back to start
  debug_goto_xy(0, 0);
}

void
debug_puts(char* str)
{

  if (!str)
    return;

  for (size_t i = 0; i < strlen(str); i++)
    debug_putc(str[i]);
}

int
debug_printf(const char* str, ...)
{

  if (!str)
    return 0;

  va_list args;
  va_start(args, str);

  for (size_t i = 0; i < strlen(str); i++)
    {

      switch (str[i])
        {

      case '%':

        switch (str[i + 1])
          {

        /*** characters ***/
        case 'c':
          {
            char c = va_arg(args, char);
            debug_putc(c);
            i++;		// go to next character
            break;
          }

          /*** address of ***/
        case 's':
          {
            int c = va_arg (args, int);
            char str[64] =
              { 0 };
            strcpy(str, (const char*) c);
            debug_puts(str);
            i++;		// go to next character
            break;
          }

          /*** integers ***/
        case 'd':
        case 'i':
          {
            int c = va_arg(args, int);
            char str[32] =
              { 0 };
            itoa_s(c, 10, str);
            debug_puts(str);
            i++;		// go to next character
            break;
          }

          /*** display in hex ***/
        case 'X':
        case 'x':
          {
            int c = va_arg(args, int);
            char str[32] =
              { 0 };
            itoa_s(c, 16, str);
            debug_puts(str);
            i++;		// go to next character
            break;
          }

        default:
          va_end (args);
          return 1;
          }

        break;

      default:
        debug_putc(str[i]);
        break;
        }

    }

  va_end (args);
  return 1;
}

//! returns position
void
debug_get_xy(unsigned* x, unsigned* y)
{
  if (x == 0 || y == 0)
    return;

  *x = cursor_x;
  *y = cursor_y;
}

//! returns horzontal width
int
debug_get_horz()
{

  return 80;
}

//! returns vertical height
int
debug_get_vert()
{

  return 24;
}

//============================================================================
//    INTERFACE CLASS BODIES
//============================================================================
//****************************************************************************
//**
//**    END[DebugDisplay.cpp]
//**
//****************************************************************************
