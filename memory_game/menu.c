#include "menu.h"

#define ITEM_CNT_MAIN_PAGE 3
#define ITEM_CNT_HIGHSCORES_PAGE 5
#define ITEM_CNT_SETTINGS_PAGE 3
#define ITEM_CNT_ABOUT_PAGE 7

void menu_about();

page_item main_page_items[] = {
   {"Play game",  NULL, MAIN_MENU, PLAY},
   {"Settings",   NULL, MAIN_MENU, SETTINGS},
   {"Highscores", NULL, MAIN_MENU, HIGHSCORES}
};

page_item highscores_page_items[] = {
   {"Place 1: ", NULL, MAIN_MENU, HIGHSCORES},
   {"Place 2: ", NULL, MAIN_MENU, HIGHSCORES},
   {"Place 3: ", NULL, MAIN_MENU, HIGHSCORES},
   {"Place 4: ", NULL, MAIN_MENU, HIGHSCORES},
   {"Place 5: ", NULL, MAIN_MENU, HIGHSCORES}
};

page_item settings_page_items[] = {
   {"Difficulty",      NULL,            MAIN_MENU, SETTINGS},
   {"Reset highscore", highscore_reset, MAIN_MENU, SETTINGS},
   {"About",           menu_about,      MAIN_MENU, SETTINGS}
};

page_item about_page_items[] = {
  {"This game is ",    NULL, SETTINGS, SETTINGS},
  {"the best game",    NULL, SETTINGS, SETTINGS},
  {"ever, and it's",   NULL, SETTINGS, SETTINGS},
  {"made by Jenny, ",  NULL, SETTINGS, SETTINGS},
  {"Ingrid, Lars ",    NULL, SETTINGS, SETTINGS},
  {"Erik and Mia",     NULL, SETTINGS, SETTINGS},
  {"  ;o}  ",          NULL, SETTINGS, SETTINGS},
};

page main_page       = {ITEM_CNT_MAIN_PAGE,       main_page_items,       0, 1};
page highscores_page = {ITEM_CNT_HIGHSCORES_PAGE, highscores_page_items, 0, 1};
page settings_page   = {ITEM_CNT_SETTINGS_PAGE,   settings_page_items,   0, 1};
page about_page      = {ITEM_CNT_ABOUT_PAGE,      about_page_items,      0, 1};

void menu_displayPage(page p) {
	LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
	LCD_PRINTF(lcd, "%c%s>%s\n", ESC, ESC_ROW1_COL1, p.items[p.lcd_line0_index].name);
	LCD_PRINTF(lcd, " %s\n", p.items[p.lcd_line1_index].name);
}

void menu_scrollPage(page *p, USERINPUT up_down) {
  if (up_down == BTN_WHITE_UP) {
    p->lcd_line0_index = ((p->lcd_line0_index - 1) + p->item_cnt) % p->item_cnt;
    p->lcd_line1_index = ((p->lcd_line1_index - 1) + p->item_cnt) % p->item_cnt;
  } else if (up_down == BTN_YELLOW_DOWN) {
    p->lcd_line0_index = (p->lcd_line0_index + 1) % p->item_cnt;
    p->lcd_line1_index = (p->lcd_line1_index + 1) % p->item_cnt;
  }
}

void menu_about() {
  USERINPUT input = 0;
  while (input != BTN_RED_BACK) {
    menu_displayPage(about_page);
    input = game_getUserInput();
    switch(input) {
      case BTN_WHITE_UP:
        menu_scrollPage(&about_page, BTN_WHITE_UP);
        break;
      case BTN_YELLOW_DOWN:
        menu_scrollPage(&about_page, BTN_YELLOW_DOWN);
        break;
      default:
        break;
    }
  }
  
}
