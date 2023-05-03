/******************************************************************************
 *
 * Description BasicIFsoftware
 * ************* 
 * This program is used in course TFE4105 digital Design and Computer Fundamentals
 * at the Norwegian University of Science and Technology, Trondheim, Norway.
 * It is part of the Altera DE2 card labratorum, where it is run on a NIOS II
 * processor to control the reday made test bench for the student designs.
 * ****************
 * BasicIFsoftware.c ==>  This file.
 *                     main() is contained here, as is the lion's share of the
 *                     functionality.
 * BasicIFsoftware.h ==>  Contains some very simple VT100 ESC sequence defines
 *                     for formatting text to the LCD Display.
 * 
 *
 * Useful Functions
 * *****************
 */

#include "BasicIFsoftware.h"
#include "altera_up_avalon_character_lcd.h"



 /*******************************************************************************
 * int main()                                                                  *
 *                                                                             *
 * 
 ******************************************************************************/

int main(void)
{ 
    char lcd_firstline[64];  // Should be enough. It only supports 16 chars. 
    char lcd_secondline[64]; // This is to ensure that there is enough
    alt_u8 registers[16];    // Enough room for all registers
    alt_u8 pc;               // Holds the program counter
    
    alt_u8 i;

   
    // Start of LCD functionality
    alt_up_character_lcd_dev* lcd = alt_up_character_lcd_open_dev(CHARACTER_LCD_NAME);
    
    // Print a nice debug sentence.
    alt_up_character_lcd_set_cursor_pos(lcd, 0, 0);
    alt_up_character_lcd_write(lcd, "Starting", 8);
 
    while( 1 ) 
    {
        // Read in debug registers
        // Program counter
        pc = IORD_ALTERA_AVALON_PIO_DATA(DBG_PC_BASE);
        
        // General purpose registers
        for (i = 0; i < 16; i++) {
            IOWR_ALTERA_AVALON_PIO_DATA(DBG_REG_SET_BASE,i);
            registers[i] = IORD_ALTERA_AVALON_PIO_DATA(DBG_REG_BASE);
        }
        
        // Set up the display
        sprintf(lcd_firstline, "P:%2X R0:%2X R1:%2X", pc, registers[0], registers[1]);
        sprintf(lcd_secondline, "2:%2X R3:%2X R4:%2X", registers[2], registers[3], registers[4]);
        
        // Put it on the display
        alt_up_character_lcd_set_cursor_pos(lcd, 0, 0);
        alt_up_character_lcd_write(lcd, lcd_firstline,16);
        alt_up_character_lcd_set_cursor_pos(lcd, 0, 2);
        alt_up_character_lcd_write(lcd, lcd_secondline, 16);        

    }
    LCD_CLOSE(lcd);
    return 0;
}
