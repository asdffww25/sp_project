#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 8

int startx = 0;
int starty = 0;

char *choices[] = { 
			"Tetris",
			"Snake",
			"2048",
			"Exit",
		  };
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

int main()
{	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;
	char num[8];
	initscr();
	start_color();

	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);

	//M
	for(int i=3; i<8; i++) {
                mvprintw(i, 16 , "@");
		mvprintw(i, 20 , "@");
        }
	mvprintw(4, 17, "@");
	mvprintw(5, 18, "@");
	mvprintw(4, 19, "@");

	//I
	for(int i=3, j = 22; i<8; i+=4){
		mvprintw(i, j, "@");
		mvprintw(i, j+2, "@");
	}
	for(int i=3; i<8; i++) {
                mvprintw(i, 23 , "@");
        }
	//N
	for(int i=3; i<8; i++) {
                mvprintw(i, 26 , "@");
        }
	for(int i=4; i<7; i++){
		mvprintw(i, i+23, "@");
	}
	for(int i=3; i<8; i++) {
                mvprintw(i, 30, "@");
        }
	//I
	for(int i=3, j = 32; i<8; i+=4){
                mvprintw(i, j, "@");
                mvprintw(i, j+2, "@");
        }
        for(int i=3; i<8; i++) {
                mvprintw(i, 33 , "@");
        }

	//G
	for(int i=4; i<7; i++) {
                mvprintw(i, 38 , "@");
        }
	for(int i=39; i<42; i++) {
         	mvprintw(7, i , "@");
		mvprintw(3, i , "@");
        }
	for(int i=5; i<7; i++) {
                mvprintw(i, 42 , "@");
        }
	mvprintw(5, 41, "@");

	//A
	for(int i=4; i<8; i++) {
                mvprintw(i, 44 , "@");
		mvprintw(i, 48, "@");
        }
	for(int i=45; i<48; i++) {
		mvprintw(3, i, "@");
		mvprintw(5, i, "@");
	}
	
	//M
	for(int i=3; i<8; i++) {
                mvprintw(i, 50 , "@");
		mvprintw(i, 54, "@");
        }
        mvprintw(4, 51, "@");
        mvprintw(5, 52, "@");
        mvprintw(4, 53, "@");
        for(int i=3; i<8; i++) {
                mvprintw(i, 54, "@");
        }

	//E
	
	for(int i=3; i<8; i++) {
                mvprintw(i, 56 , "@");
        }
	for(int i=57; i<60; i++) {
		mvprintw(3, i, "@");
		mvprintw(5, i, "@");
		mvprintw(7, i, "@");
	}
	

	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case KEY_ENTER: // enter key at the key pad
			case 10: // enter key
				choice = highlight;
				break;
			default:
	
				refresh();
				break;
		}
		if(choice ==1){
			endwin();
			system("./tetris");
			choice = 0;
		}
		else if(choice == 2){
			endwin();
			system("./snake");
			choice = 0;
		}
		else if(choice == 3){
			endwin();
			system("./2048");
			choice = 0;
		}
		print_menu(menu_win, highlight);
		if(choice == 4)	/* User did a choice come out of the infinite loop */
			break;
	}	
	clrtoeol();
	refresh();
	endwin();
	printf("You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
		
	box(menu_win, 0, 0);

	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
