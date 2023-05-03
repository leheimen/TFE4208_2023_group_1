#include "lcd.h"

void lcd_print(int row, int col, char str[]) {
    LCD_PRINTF(lcd, "%c[%d;%dH%c%s\b%s\n", ESC, row, col+1, ESC, ESC_CLEAR, str);
}

void lcd_clear() {
    LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
}