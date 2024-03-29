/*
 *	emulation special function implementation
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

#include <gliss/emu.h>
#include <math.h>
#include <fenv.h>

/**
 * Function called for the "pref" instruction.
 * Change its content to specialize the simulator.
 */
void Prefetch(int uncached, int32_t pAddr, int32_t vAddr, int IorD, int hint) {
}

/**
 * Function called when an exception is invoked.
 * Change its content to specialize the simulator.
 */
void SignalException(int exception) {
}

/**
 * Function called when a 64-bit coprocessor register is stored.
 * Change its content to specialize the simulator.
 */
uint64_t COP_SD(int z, int rt) {
	return 0;
}

/**
 * Function called when a 32-bit coprocessor register is stored.
 * Change its content to specialize the simulator.
 */
uint32_t COP_SW(int z, int rt) {
	return 0;
}

/**
 * Function called when the "sync" instruction is executed.
 * Change its content to specialize the simulator.
 */
void SyncOperation(int stype) {
}


/**
 * Function use for AMOs instructions
 */
void aquirement(){
}

void release(){
}

void notReserve(){
	hasLr = 0;
}

void reserve(int memoryWord){
		hasLr = 1;
		lrAddr = memoryWord;
}

uint32_t reserved(int memoryWord){
	if(hasLr == 1 && memoryWord == lrAddr){
		hasLr = 0;
		return 1;
	}
	else{
		return 0;
	}
}

void idle_While_No_Interrupts_Pending(){
}
