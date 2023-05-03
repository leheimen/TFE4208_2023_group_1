#include "fsm.h"


STATE state = MAIN_MENU;

static void fsm_mainMenu() {
  menu_displayPage(main_page);
  USERINPUT input = game_getUserInput();
  switch(input) {
    case BTN_WHITE_UP:
      menu_scrollPage(&main_page, BTN_WHITE_UP);
      break;
    case BTN_YELLOW_DOWN:
      menu_scrollPage(&main_page, BTN_YELLOW_DOWN);
      break;
    case BTN_RED_BACK:
      state = main_page.items[main_page.lcd_line0_index].exit_state;
      break;
    case BTN_GREEN_ENTER:
      state = main_page.items[main_page.lcd_line0_index].enter_state;
      break;
  }
}

static void fsm_game() {
  game_play();
  state = MAIN_MENU;
}

static void fsm_settings() {
  menu_displayPage(settings_page);
  USERINPUT input = game_getUserInput();
  switch(input) {
    case BTN_WHITE_UP:
      menu_scrollPage(&settings_page, BTN_WHITE_UP);
      break;
    case BTN_YELLOW_DOWN:
      menu_scrollPage(&settings_page, BTN_YELLOW_DOWN);
      break;
    case BTN_RED_BACK:
      state = settings_page.items[settings_page.lcd_line0_index].exit_state;
      break;
    case BTN_GREEN_ENTER:
      settings_page.items[settings_page.lcd_line0_index].function();
      break;
  }
}

static void fsm_highscores() {
  menu_displayPage(highscores_page);
  highscore_display(highscores_page);
  USERINPUT input = game_getUserInput();
  switch(input) {
    case BTN_WHITE_UP:
      menu_scrollPage(&highscores_page, BTN_WHITE_UP);
      break;
    case BTN_YELLOW_DOWN:
      menu_scrollPage(&highscores_page, BTN_YELLOW_DOWN);
      break;
    case BTN_RED_BACK:
      state = highscores_page.items[highscores_page.lcd_line0_index].exit_state;  
      break;
    case BTN_GREEN_ENTER:
      state = highscores_page.items[highscores_page.lcd_line0_index].enter_state; 
      break;
  }
}

void fsm() {
  switch(state) {
    case MAIN_MENU:
      fsm_mainMenu();
      break;
    case PLAY:
      fsm_game();
      break;
    case SETTINGS:
      fsm_settings();
      break;
    case HIGHSCORES:
      fsm_highscores();
      break;
  }
}