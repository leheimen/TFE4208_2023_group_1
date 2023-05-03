#include "game.h"


static TASK correct_sequence[100]; // Assume that user will not manage >100 tasks
static int correct_sequence_len;
static int user_sequence_len;
//static int difficulty = EASY;
//static int number_of_tasks = TASK_CNT_EASY;

difficulty_t easy = {EASY, TASK_CNT_EASY};
difficulty_t hard = {HARD, TASK_CNT_HARD};

difficulty_t difficulty;

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
  bool isCorrect = false;
  if (difficulty.difficulty == HARD) {
    if (input == correct_sequence[user_sequence_len-1]) {
      isCorrect = true;
    } 
    if ((input + 4) == correct_sequence[user_sequence_len-1]) {
      isCorrect = true;
    }
  } else if (difficulty.difficulty == EASY) {
    if (input == correct_sequence[user_sequence_len-1]) {
      isCorrect = true;
    }
  }
  return isCorrect;
}

static void game_appendNewTask() {
  correct_sequence_len++;
  TASK task = rand() % difficulty.number_of_tasks + 1;
  printf("Appending new task %d\n", task);
  correct_sequence[correct_sequence_len-1] = task;
}

static void game_displayCorrectSequence() {
  lcd_clear();
  lcd_print(1,1, "Remember the");
  lcd_print(2,1, "sequence: ");
  usleep(1000000);
  lcd_clear();
  for (int i = 0; i < correct_sequence_len; i++) {
    TASK task = correct_sequence[i];
    if (difficulty.difficulty == EASY) {
      switch (task) {
        case WHITE:
          btnLed_set_led(6);
          break;
        case YELLOW:
          btnLed_set_led(4);
          break;
        case RED:
          btnLed_set_led(2);
          break;
        case GREEN:
          btnLed_set_led(0);
          break;
        default:
          break;
      }
    } else if (difficulty.difficulty == HARD) {
      switch (task) {
        case WHITE:
          lcd_print(1,1, "White");
          break;
        case YELLOW:
          lcd_print(1,1, "Yellow");
          break;
        case RED:
          lcd_print(1,1, "Red");
          break;
        case GREEN:
          lcd_print(1,1, "Green");
          break;
        case UP:
          lcd_print(1,1, "Up");
        break;
        case DOWN:
          lcd_print(1,1, "Down");
          break;
        case LEFT:
          lcd_print(1,1, "Left");
          break;
        case RIGHT:
          lcd_print(1,1, "Right");
          break;
      }
      usleep(500000);
    }
    usleep(500000);
    btnLed_clear_all_leds();
  }
  lcd_print(1,1, "Enter the");
  lcd_print(2,1, "sequence:");
}

static void game_displayGameStart() {
  lcd_clear();
  lcd_print(1,1, "**Memory Game**");
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
  lcd_print(1,1, "Pay attention!");
  usleep(1000000);
}

static void game_displayGameOver(int new_highscore_entry) {
  lcd_clear();
  lcd_print(1,1, "Game Over :(");
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

void game_set_easy_difficulty() {
  difficulty = easy;
}

void game_set_hard_difficulty() {
  difficulty = hard;
}
