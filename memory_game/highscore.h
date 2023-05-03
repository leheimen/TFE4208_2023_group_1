#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <stdbool.h>
#include "lcd.h"
#include "types.h"

int highscore_update(int new_score);

void highscore_display(page p);

int* get_highscore_list();

void highscore_reset();

#endif /* HIGHSCORE_H */
