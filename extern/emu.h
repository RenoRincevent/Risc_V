/*
 *	emulation special function interface
 *
 *	This file is part of GLISS2
 *	Copyright (c) 2017, IRIT UPS.
 *
 *	GLISS is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	GLISS is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with GLISS2; if not, write to the Free Software
 *	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef GLISS_RISCV_EMU_H
#define GLISS_RISCV_EMU_H

#include <stdint.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS ON

#if defined(__cplusplus)
extern  "C" {
#endif

#define GLISS_EMU_STATE
#define GLISS_EMU_INIT(s)
#define GLISS_EMU_DESTROY(s)

/* Values */
#define FP_INEXACT     FE_INEXACT
#define FP_DIVBYZERO   FE_DIVBYZERO
#define FP_UNDERFLOW   FE_UNDERFLOW
#define FP_OVERFLOW    FE_OVERFLOW
#define FP_INVALID     FE_INVALID
#define FP_ALLEXCEPT   FE_ALL_EXCEPT

/* Functions */
#define fp_clearexcept(flag) feclearexcept(flag)  /* clear a set of exceptions */
#define fp_raiseexcept(flag) feraiseexcept(flag)  /* 'set' a set of exceptions */
#define fp_testexcept(flag)  fetestexcept(flag)   /* test a set of exceptions */
#define fp_sqrt(x) sqrt(x)
#define fp32_sqrt(x) sqrtf(x)

#define BreakPoint		0
#define	IntegerOverflow		1
#define AddressError		2
#define SystemCall		3
#define Trap			4
#define InvalidOperation 	5
#define IllegalInstruction	6

void Prefetch(int uncached, int32_t pAddr, int32_t vAddr, int IorD, int hint);
void SignalException(int exception);
uint64_t COP_SD(int z, int rt);
uint32_t COP_SW(int z, int rt);
void SyncOperation(int stype);

void aquirement();
void release();
void notReserve();
void reserve(int memoryWord);
uint32_t reserved(int memoryWord);
int lrAddr;
int hasLr;

void idle_While_No_Interrupts_Pending();

#if defined(__cplusplus)
}
#endif

#endif /* GLISS_RISCV_EMU_H */
