#include <ncurses.h>
#include <stdio.h>


#define DX 3


int main(int argc, char* argv[]) 
{
	char* name;

	if (argc > 1) {
        	name = argv[1];
	} else {
		printf("Please enter file name\n");
		return 1;
	}
	
	FILE *fp;
	if ((fp = fopen(name, "r")) == NULL) {
		printf("Incorrect file\n");
		return 2;
	}

  	initscr();
        noecho();
        printw("%s\n", name);
	refresh();

	WINDOW *win;
	int c = 0;
	int win_w = COLS - 2*DX - 1;
	int win_h = LINES - 2*DX - 1;

	win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);

	keypad(win, TRUE);
	scrollok (win, TRUE);
	box(win, 0, 0); 
	wmove(win, 1, 0);

	char * ret;
	char line[win_w];
	int curr_line = 0;

	ret = fgets(line, win_w, fp);
        while((ret != NULL) && (curr_line < win_h)) {
		wprintw(win, "%s", line);
		curr_line += 1;
		if (curr_line == win_h) {
			break;
		}
	        ret = fgets(line, win_w, fp);
        };
	
	box(win, 0, 0);
        wrefresh(win);

	c = wgetch(win);

	while(c != 27) {
		if (c != ' ') {
			c = wgetch(win);
			continue;
		}
		if (ret != NULL) { 
			ret = fgets(line, win_w, fp);
		}
		if (ret != NULL) { 
			wprintw(win, "%s", line);
		}
		box(win, 0, 0);
		wrefresh(win);
		c = wgetch(win);
	}
	fclose(fp);
	endwin();
	return 0;
}
