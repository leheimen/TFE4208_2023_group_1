#include "highscore.h"

#define HIGHSCORES_CNT 5

static int highscore_list[HIGHSCORES_CNT] = {0,0,0,0,0};

/* Check if new score is new highscore, and update highscore list */
int highscore_update(int new_score) {
	int new_highscore_entry = 0;
	for (int i = 0; i < HIGHSCORES_CNT; i++) {
		if (new_score > highscore_list[i]) {
			for (int j = HIGHSCORES_CNT-1; j > i; j--) {
				highscore_list[j] = highscore_list[j-1];
			}
			highscore_list[i] = new_score;
			new_highscore_entry = i+1;
			break;
		}
	}
	return new_highscore_entry;
}

void highscore_display(page p) {
	//LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
	LCD_PRINTF(lcd, "%c%s%d\n", ESC, ESC_ROW1_COL13, highscore_list[p.lcd_line0_index]);
	LCD_PRINTF(lcd, "%c%s%d\n", ESC, ESC_ROW2_COL13, highscore_list[p.lcd_line1_index]);
}

void highscore_reset() {
	for (int i = 0; i < HIGHSCORES_CNT; i++) {
		highscore_list[i] = 0;
	}
	LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
	LCD_PRINTF(lcd, "%c%sHighscore is \n", ESC, ESC_ROW1_COL1);
  	LCD_PRINTF(lcd, "reset\n");
	usleep(3000000);
}
