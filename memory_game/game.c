#include "game.h"


static int correct_sequence[100]; // Assume that user will not manage >100 tasks
static int correct_sequence_len;
static int user_sequence_len;

USERINPUT game_getUserInput() {
  btnLed_reset_edge_capture();
  while (!btnLed_get_edge_capture()) {}
  USERINPUT user_input;
  switch (btnLed_get_edge_capture()) {
	  case 0x1:
		  user_input = BTN_GREEN_ENTER;
		  break;
	  case 0x2:
		  user_input = BTN_RED_BACK;
		  break;
	  case 0x4:
		  user_input = BTN_YELLOW_DOWN;
		  break;
	  case 0x8:
		  user_input = BTN_WHITE_UP;
		  break;
	  default:
		  printf( "Error: Button press UNKNOWN!!\n");
  }
  btnLed_reset_edge_capture();
  printf("New user input: %d\n", user_input);
  return user_input;
}

static bool game_isEndOfSequence() {
  if (user_sequence_len == correct_sequence_len) {
    //tone(PIN_BUZZER, 1000, 100);
    user_sequence_len = 0;
    return true;
  } else {
    return false;
  }
}

static bool game_isCorrectInput(USERINPUT input) {
  return (input == correct_sequence[user_sequence_len-1]);
}

static void game_appendNewTask() {
  correct_sequence_len++;
  int task = rand() % 4 + 1;
  printf("Appending new task %d\n", task);
  correct_sequence[correct_sequence_len-1] = task;
}

static void game_displayCorrectSequence() {
  LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
  LCD_PRINTF(lcd, "%c%sRemember the\n", ESC, ESC_ROW1_COL1);
  LCD_PRINTF(lcd, "sequence:\n");
  for (int i = 0; i < correct_sequence_len; i++) {
     int task = correct_sequence[i];
     usleep(500000);
     switch (task) {
      case BTN_WHITE_UP:
        btnLed_set_led(6);
    	break;
      case BTN_YELLOW_DOWN:
        btnLed_set_led(4);
        break;
      case BTN_RED_BACK:
        btnLed_set_led(2);
        break;
      case BTN_GREEN_ENTER:
        btnLed_set_led(0);
        break;
     }
     usleep(500000);
     btnLed_clear_all_leds();
  }
  LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
  LCD_PRINTF(lcd, "%c%sEnter the\n", ESC, ESC_ROW1_COL1);
  LCD_PRINTF(lcd, "sequence:\n");
}

static void game_displayGameStart() {
	LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
	LCD_PRINTF(lcd, "%c%s**Memory Game**\n", ESC, ESC_ROW1_COL1);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 8; j++) {
        btnLed_clear_all_leds();
        btnLed_set_led(j);
        usleep(50000);
      }
      for (int j = 6; j > 0; j--) {
        btnLed_clear_all_leds();
        btnLed_set_led(j);
        usleep(50000);
      }
  }
  btnLed_clear_all_leds();
  LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
  LCD_PRINTF(lcd, "%c%sPay attention!\n", ESC, ESC_ROW1_COL1);
  usleep(1000000);
}

static void game_displayGameOver(int new_highscore_entry) {
  LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
  LCD_PRINTF(lcd, "%c%sGame Over :(\n", ESC, ESC_ROW1_COL1);
  for (int i = 0; i < 6; i++) {
	  btnLed_set_all_red_leds();
	  usleep(200000);
	  btnLed_clear_all_leds();    
    usleep(200000);
  }
  LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
  LCD_PRINTF(lcd, "%c%sScore: %d\n", ESC, ESC_ROW1_COL1, correct_sequence_len-1);
  usleep(3000000);
  if (new_highscore_entry) {
    LCD_PRINTF(lcd, "%c%s\n", ESC, ESC_CLEAR_ALL);
    LCD_PRINTF(lcd, "%c%sNew highscore \n", ESC, ESC_ROW1_COL1);
    LCD_PRINTF(lcd, "entry: %d\n", new_highscore_entry);
  }
}

static void game_init() {
  correct_sequence_len = 0;
  user_sequence_len = 0;
  game_displayGameStart();
}

static void game_over() {
  int new_highscore_entry = highscore_update(correct_sequence_len-1);
  game_displayGameOver(new_highscore_entry);
  game_getUserInput(); // push any button to continue
  btnLed_set_sevenseg(0);
}

void game_play() {
  game_init();
  bool game_over_flag = false;
  while (!game_over_flag) {
    btnLed_set_sevenseg(correct_sequence_len);
    game_appendNewTask();
    game_displayCorrectSequence();
    while (!game_isEndOfSequence()) {
      USERINPUT new_input = game_getUserInput();
      user_sequence_len++;
      if (!game_isCorrectInput(new_input)) {
        game_over_flag = true;
        break;
      }
    }
  }
  game_over();
}