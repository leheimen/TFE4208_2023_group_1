#ifndef TYPES_H
#define TYPES_H

typedef enum {MAIN_MENU, PLAY, SETTINGS, HIGHSCORES} STATE;
typedef enum {BTN_WHITE_UP = 1, BTN_YELLOW_DOWN, BTN_RED_BACK, BTN_GREEN_ENTER} USERINPUT;

typedef struct {
  char name[16];
  void (*function)();
  STATE exit_state;
  STATE enter_state;
} page_item;

typedef struct {
  const int item_cnt;
  page_item *items;
  int lcd_line0_index;
  int lcd_line1_index;
} page;

#endif /* TYPES_H */