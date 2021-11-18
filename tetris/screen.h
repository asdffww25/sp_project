#ifndef SCREEN_H
#define SCREEN_H

enum {
	Y = 22,
	X = 10,
};

extern char screen[Y][X];

void prompt_new_game(void);

#endif /* SCREEN_H */
