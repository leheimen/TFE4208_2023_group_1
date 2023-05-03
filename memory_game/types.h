#ifndef TYPES_H
#define TYPES_H

#define TASK_CNT_EASY 4
#define TASK_CNT_HARD 8

typedef enum {MAIN_MENU, PLAY, SETTINGS, HIGHSCORES} STATE;
typedef enum {EASY, HARD} DIFFICULTY;
typedef enum {BTN_WHITE_UP = 1, BTN_YELLOW_DOWN, BTN_RED_BACK, BTN_GREEN_ENTER} USERINPUT;
typedef enum {WHITE = 1, YELLOW, RED, GREEN, UP, DOWN, LEFT, RIGHT, CLAP} TASK;

typedef struct {
    DIFFICULTY difficulty;
    int number_of_tasks;
} difficulty_t;

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