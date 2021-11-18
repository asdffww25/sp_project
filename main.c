#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>


int main(void) {
	int col = 10;
	int row = 10;
	curs_set(FALSE);
	initscr();
	mvprintw(5,8,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-");
	mvprintw(19,8,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-");
	mvprintw(8,21, "|");
	mvprintw(8,43, "|");
	mvprintw(7,21,"+---------------------+");
	mvprintw(9,21,"+---------------------+");

	mvprintw(8,27, "SNAKE GAME");
	mvprintw(11, 24, "<- -> : Move");
	mvprintw(12, 24, "P : Pause");
	mvprintw(13, 24, "EXC : Quit");

	for(int i = 5; i<20; i++) {
		mvprintw(i, 8, "@");
		mvprintw(i, 57, "@");
	}
	noecho();
	keypad(stdscr, TRUE);
	int input = getch();
	while(1){
		mvprintw(5,8,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-");
      		mvprintw(19,8,"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-");
		mvprintw(20, 9, "YOUR SCORE:");
		for(int i = 5; i<20; i++) {
                mvprintw(i, 8, "@");
                mvprintw(i, 57, "@");
        	}
	
        	int input = getch();
        	clear();
        	switch(input){
           		case KEY_UP:
           			mvprintw(--row, col, "@@@@8"); 
        	   		 continue;
            		case KEY_DOWN:
            			mvprintw(++row, col, "@@@@8");
            			continue;
            		case KEY_LEFT:
            			mvprintw(row, --col, "@@@@8");
           			 continue;
            		case KEY_RIGHT:
           			 mvprintw(row, ++col, "@@@@8");
           			 continue;
			

       	 		}
        if(input == 'q') break;
    }

	
	refresh();
	getch();
	endwin();
	return 0;
}
