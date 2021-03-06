#include <stdlib.h> /* for rand() */

#include "pieces.h"

const char tetris[7][4][4][4] = {
	{ /* I */
		{{1},{1},{1},{1}},
		{{1,1,1,1}},
		{{1},{1},{1},{1}},
		{{1,1,1,1}},
	},
	{ /* O */
		{{1,1},{1,1},{0},{0}},
		{{1,1},{1,1},{0},{0}},
		{{1,1},{1,1},{0},{0}},
		{{1,1},{1,1},{0},{0}},
	},
	{ /* L */
		{{1,1},{1},{1},{0}},
		{{1,1,1},{0,0,1},{0},{0}},
		{{0,1},{0,1},{1,1},{0}},
		{{1},{1,1,1},{0},{0}},
	},
	{ /* J */
		{{1,1},{0,1},{0,1},{0}},
		{{0,0,1},{1,1,1},{0},{0}},
		{{1},{1},{1,1},{0}},
		{{1,1,1},{1},{0},{0}},
	},
	{ /* T */
		{{0,1},{1,1,1},{0},{0}},
		{{1},{1,1},{1},{0}},
		{{1,1,1},{0,1},{0},{0}},
		{{0,1},{1,1},{0,1},{0}},
	},
	{ /* S */
		{{0,1},{1,1},{1},{0}},
		{{1,1},{0,1,1},{0},{0}},
		{{0,1},{1,1},{1},{0}},
		{{1,1},{0,1,1},{0},{0}},
	},
	{ /* Z */
		{{1},{1,1},{0,1},{0}},
		{{0,1,1},{1,1},{0},{0}},
		{{1},{1,1},{0,1},{0}},
		{{0,1,1},{1,1},{0},{0}},
	},
};

struct piece
get_random_piece(void)
{
	struct piece p = {
		.piece = rand() % NUMBER_OF_PIECES,
		.rotation = ROTATION_NORMAL,
		.position = {
			.x = 4,
			.y = 3,
		},
	};

	return p;
}
