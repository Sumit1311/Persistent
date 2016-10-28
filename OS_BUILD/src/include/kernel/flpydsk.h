#ifndef _FLPYDSK_DRIVER_H
#define _FLPYDSK_DRIVER_H
//****************************************************************************
//**
//**    flpydsk.h
//**
//****************************************************************************

//============================================================================
//    INTERFACE REQUIRED HEADERS
//============================================================================

#include "stdint.h"
#include <stdbool.h>

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

//! install floppy driver
void
flpydsk_install(int irq);

//! set current working drive
void
flpydsk_set_working_drive(uint8_t drive);

//! get current working drive
uint8_t
flpydsk_get_working_drive();

//! read a sector
uint8_t*
flpydsk_read_sector(int sectorLBA);

//! converts an LBA address to CHS
void
flpydsk_lba_to_chs(int lba, int *head, int *track, int *sector);

//============================================================================
//    INTERFACE OBJECT CLASS DEFINITIONS
//============================================================================
//============================================================================
//    INTERFACE TRAILING HEADERS
//============================================================================
//****************************************************************************
//**
//**    END [flpydsk.h]
//**
//****************************************************************************

#endif
