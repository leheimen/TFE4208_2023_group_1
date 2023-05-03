#ifndef LCD_H
#define LCD_H

#include <stdio.h>

/* With hardware devices present, use these definitions */
#define LCD_CLOSE(x) fclose((x))
#define LCD_OPEN() fopen("/dev/lcd_display", "w")
#define LCD_PRINTF fprintf

/* Cursor movement on the LCD */
/* Clear */
#define ESC 27
/* Position cursor at row 1, column 1 of LCD. */
#define ESC_CLEAR "K"
/* Clear whole screen. */
#define ESC_CLEAR_ALL "[2J"
/* Position cursor at row1, column 5 of LCD. */
#define ESC_ROW1_COL5 "[1;5H"
/* Position cursor at row2, column 5 of LCD. */
#define ESC_ROW2_COL5 "[2;5H"
/* Position cursor at row1, column 1 of LCD. */
#define ESC_ROW1_COL1 "[1;1H"
/* Position cursor at row2, column 1 of LCD. */
#define ESC_ROW2_COL1 "[2;1H"
/* Position cursor at row1, column 1 of LCD. */
#define ESC_ROW1_COL13 "[1;13H"
/* Position cursor at row2, column 1 of LCD. */
#define ESC_ROW2_COL13 "[2;13H"
/* Integer ASCII value of the ESC character. */
#define ESC_TOP_LEFT "[1;0H"

FILE *lcd;

#endif /* LCD_H */
