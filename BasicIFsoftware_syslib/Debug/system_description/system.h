/* system.h
 *
 * Machine generated for a CPU named "cpu" as defined in:
 * c:\Lab5\software\BasicIFsoftware_syslib\..\..\wb_NiosProcessor.ptf
 *
 * Generated: 2008-10-26 01:59:05.703
 *
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/*

DO NOT MODIFY THIS FILE

   Changing this file will have subtle consequences
   which will almost certainly lead to a nonfunctioning
   system. If you do modify this file, be aware that your
   changes will be overwritten and lost when this file
   is generated again.

DO NOT MODIFY THIS FILE

*/

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2003 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/

/*
 * system configuration
 *
 */

#define ALT_SYSTEM_NAME "wb_NiosProcessor"
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_ARCHITECTURE "altera_nios2"
#define ALT_DEVICE_FAMILY "CYCLONEII"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN_BASE 0x00021070
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_PRESENT
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT_BASE 0x00021070
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_PRESENT
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDERR_BASE 0x00021070
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_PRESENT
#define ALT_CPU_FREQ 50000000
#define ALT_IRQ_BASE NULL

/*
 * processor configuration
 *
 */

#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_BIG_ENDIAN 0

#define NIOS2_ICACHE_SIZE 2048
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_FLUSHDA_SUPPORTED

#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_RESET_ADDR 0x00010000
#define NIOS2_BREAK_ADDR 0x00020820

#define NIOS2_HAS_DEBUG_STUB

#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0

/*
 * A define for each class of peripheral
 *
 */

#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_SYSID
#define __ALTERA_UP_AVALON_PS2
#define __ALTERA_UP_AVALON_CHARACTER_LCD
#define __ALTERA_AVALON_PIO

/*
 * onchip_mem configuration
 *
 */

#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_BASE 0x00010000
#define ONCHIP_MEM_SPAN 40960
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "M4K"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEM_WRITEABLE 1
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_SIZE_VALUE 40960
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_USE_SHALLOW_MEM_BLOCKS 1
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_IGNORE_AUTO_BLOCK_TYPE_ASSIGNMENT 1
#define ONCHIP_MEM_CONTENTS_INFO ""
#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2

/*
 * jtag_uart configuration
 *
 */

#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_BASE 0x00021070
#define JTAG_UART_SPAN 8
#define JTAG_UART_IRQ 16
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_READ_CHAR_STREAM ""
#define JTAG_UART_SHOWASCII 1
#define JTAG_UART_READ_LE 0
#define JTAG_UART_WRITE_LE 0
#define JTAG_UART_ALTERA_SHOW_UNRELEASED_JTAG_UART_FEATURES 0
#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart

/*
 * sys_clk_timer configuration
 *
 */

#define SYS_CLK_TIMER_NAME "/dev/sys_clk_timer"
#define SYS_CLK_TIMER_TYPE "altera_avalon_timer"
#define SYS_CLK_TIMER_BASE 0x00021000
#define SYS_CLK_TIMER_SPAN 32
#define SYS_CLK_TIMER_IRQ 0
#define SYS_CLK_TIMER_ALWAYS_RUN 0
#define SYS_CLK_TIMER_FIXED_PERIOD 0
#define SYS_CLK_TIMER_SNAPSHOT 1
#define SYS_CLK_TIMER_PERIOD 1.0
#define SYS_CLK_TIMER_PERIOD_UNITS "ms"
#define SYS_CLK_TIMER_RESET_OUTPUT 0
#define SYS_CLK_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYS_CLK_TIMER_LOAD_VALUE 49999
#define SYS_CLK_TIMER_COUNTER_SIZE 32
#define SYS_CLK_TIMER_MULT 0.0010
#define SYS_CLK_TIMER_TICKS_PER_SEC 1000
#define SYS_CLK_TIMER_FREQ 50000000
#define ALT_MODULE_CLASS_sys_clk_timer altera_avalon_timer

/*
 * sysid configuration
 *
 */

#define SYSID_NAME "/dev/sysid"
#define SYSID_TYPE "altera_avalon_sysid"
#define SYSID_BASE 0x00021078
#define SYSID_SPAN 8
#define SYSID_ID 688169549u
#define SYSID_TIMESTAMP 1224971512u
#define SYSID_REGENERATE_VALUES 0
#define ALT_MODULE_CLASS_sysid altera_avalon_sysid

/*
 * ps2_keyboard configuration
 *
 */

#define PS2_KEYBOARD_NAME "/dev/ps2_keyboard"
#define PS2_KEYBOARD_TYPE "altera_up_avalon_ps2"
#define PS2_KEYBOARD_BASE 0x00021080
#define PS2_KEYBOARD_SPAN 8
#define PS2_KEYBOARD_IRQ 8
#define PS2_KEYBOARD_HDL_PARAMETERS ""
#define ALT_MODULE_CLASS_ps2_keyboard altera_up_avalon_ps2

/*
 * character_lcd configuration
 *
 */

#define CHARACTER_LCD_NAME "/dev/character_lcd"
#define CHARACTER_LCD_TYPE "altera_up_avalon_character_lcd"
#define CHARACTER_LCD_BASE 0x00021088
#define CHARACTER_LCD_SPAN 8
#define ALT_MODULE_CLASS_character_lcd altera_up_avalon_character_lcd

/*
 * A_reg_pio configuration
 *
 */

#define A_REG_PIO_NAME "/dev/A_reg_pio"
#define A_REG_PIO_TYPE "altera_avalon_pio"
#define A_REG_PIO_BASE 0x00021020
#define A_REG_PIO_SPAN 16
#define A_REG_PIO_DO_TEST_BENCH_WIRING 0
#define A_REG_PIO_DRIVEN_SIM_VALUE 0
#define A_REG_PIO_HAS_TRI 0
#define A_REG_PIO_HAS_OUT 1
#define A_REG_PIO_HAS_IN 0
#define A_REG_PIO_CAPTURE 0
#define A_REG_PIO_DATA_WIDTH 16
#define A_REG_PIO_RESET_VALUE 0
#define A_REG_PIO_EDGE_TYPE "NONE"
#define A_REG_PIO_IRQ_TYPE "NONE"
#define A_REG_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define A_REG_PIO_FREQ 50000000
#define ALT_MODULE_CLASS_A_reg_pio altera_avalon_pio

/*
 * B_reg_pio configuration
 *
 */

#define B_REG_PIO_NAME "/dev/B_reg_pio"
#define B_REG_PIO_TYPE "altera_avalon_pio"
#define B_REG_PIO_BASE 0x00021030
#define B_REG_PIO_SPAN 16
#define B_REG_PIO_DO_TEST_BENCH_WIRING 0
#define B_REG_PIO_DRIVEN_SIM_VALUE 0
#define B_REG_PIO_HAS_TRI 0
#define B_REG_PIO_HAS_OUT 1
#define B_REG_PIO_HAS_IN 0
#define B_REG_PIO_CAPTURE 0
#define B_REG_PIO_DATA_WIDTH 16
#define B_REG_PIO_RESET_VALUE 0
#define B_REG_PIO_EDGE_TYPE "NONE"
#define B_REG_PIO_IRQ_TYPE "NONE"
#define B_REG_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define B_REG_PIO_FREQ 50000000
#define ALT_MODULE_CLASS_B_reg_pio altera_avalon_pio

/*
 * Dbg_pc configuration
 *
 */

#define DBG_PC_NAME "/dev/Dbg_pc"
#define DBG_PC_TYPE "altera_avalon_pio"
#define DBG_PC_BASE 0x00021040
#define DBG_PC_SPAN 16
#define DBG_PC_DO_TEST_BENCH_WIRING 0
#define DBG_PC_DRIVEN_SIM_VALUE 0
#define DBG_PC_HAS_TRI 0
#define DBG_PC_HAS_OUT 0
#define DBG_PC_HAS_IN 1
#define DBG_PC_CAPTURE 1
#define DBG_PC_DATA_WIDTH 8
#define DBG_PC_RESET_VALUE 0
#define DBG_PC_EDGE_TYPE "RISING"
#define DBG_PC_IRQ_TYPE "NONE"
#define DBG_PC_BIT_CLEARING_EDGE_REGISTER 0
#define DBG_PC_FREQ 50000000
#define ALT_MODULE_CLASS_Dbg_pc altera_avalon_pio

/*
 * Dbg_reg configuration
 *
 */

#define DBG_REG_NAME "/dev/Dbg_reg"
#define DBG_REG_TYPE "altera_avalon_pio"
#define DBG_REG_BASE 0x00021050
#define DBG_REG_SPAN 16
#define DBG_REG_DO_TEST_BENCH_WIRING 0
#define DBG_REG_DRIVEN_SIM_VALUE 0
#define DBG_REG_HAS_TRI 0
#define DBG_REG_HAS_OUT 0
#define DBG_REG_HAS_IN 1
#define DBG_REG_CAPTURE 1
#define DBG_REG_DATA_WIDTH 8
#define DBG_REG_RESET_VALUE 0
#define DBG_REG_EDGE_TYPE "RISING"
#define DBG_REG_IRQ_TYPE "NONE"
#define DBG_REG_BIT_CLEARING_EDGE_REGISTER 0
#define DBG_REG_FREQ 50000000
#define ALT_MODULE_CLASS_Dbg_reg altera_avalon_pio

/*
 * Dbg_reg_set configuration
 *
 */

#define DBG_REG_SET_NAME "/dev/Dbg_reg_set"
#define DBG_REG_SET_TYPE "altera_avalon_pio"
#define DBG_REG_SET_BASE 0x00021060
#define DBG_REG_SET_SPAN 16
#define DBG_REG_SET_DO_TEST_BENCH_WIRING 0
#define DBG_REG_SET_DRIVEN_SIM_VALUE 0
#define DBG_REG_SET_HAS_TRI 0
#define DBG_REG_SET_HAS_OUT 1
#define DBG_REG_SET_HAS_IN 0
#define DBG_REG_SET_CAPTURE 0
#define DBG_REG_SET_DATA_WIDTH 4
#define DBG_REG_SET_RESET_VALUE 0
#define DBG_REG_SET_EDGE_TYPE "NONE"
#define DBG_REG_SET_IRQ_TYPE "NONE"
#define DBG_REG_SET_BIT_CLEARING_EDGE_REGISTER 0
#define DBG_REG_SET_FREQ 50000000
#define ALT_MODULE_CLASS_Dbg_reg_set altera_avalon_pio

/*
 * system library configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYS_CLK_TIMER
#define ALT_TIMESTAMP_CLK none

/*
 * Devices associated with code sections.
 *
 */

#define ALT_TEXT_DEVICE       ONCHIP_MEM
#define ALT_RODATA_DEVICE     ONCHIP_MEM
#define ALT_RWDATA_DEVICE     ONCHIP_MEM
#define ALT_EXCEPTIONS_DEVICE ONCHIP_MEM
#define ALT_RESET_DEVICE      ONCHIP_MEM

/*
 * The text section is initialised so no bootloader will be required.
 * Set a variable to tell crt0.S to provide code at the reset address and
 * to initialise rwdata if appropriate.
 */

#define ALT_NO_BOOTLOADER


#endif /* __SYSTEM_H_ */
