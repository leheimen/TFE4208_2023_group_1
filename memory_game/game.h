#ifndef GAME_H
#define GAME_H


#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#include "system.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "btnLed.h"
#include "lcd.h"
#include "types.h"
#include "highscore.h"
#include "game.h"


USERINPUT game_getUserInput();

void game_play();

#endif /* GAME_H */
