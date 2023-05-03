#ifndef MENU_H
#define MENU_H

#include <stddef.h>
#include "lcd.h"
#include "types.h"
#include "highscore.h"

extern page_item main_page_items[];
extern page_item highscores_page_items[];
extern page_item settings_page_items[];

extern page main_page;
extern page highscores_page;
extern page settings_page;

void menu_displayPage(page p);

void menu_scrollPage(page *p, USERINPUT up_down);



#endif /* MENU_H */
