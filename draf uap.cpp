#include <ncurses.h>
#include <windows.h>
#include <iostream>
#include "string.h";

using namespace std;


void yay(){
	
	Sleep(10000);
	refresh();
	clear();
	
	
}



//void(){
//	
//	WINDOW * win =newwin( 20,40, 2, 3);
//	refresh();
//	box (win, 0,0);
//	wprintw (win, "");
//	wrefresh ();
//	
//	
//}


int main(){
	
	initscr();

	start_color();
	
	
	WINDOW * win =newwin( 20,40, 2, 3);
	refresh();
	box (win, 0,0);
	wprintw (win, "");
	for(int k=0 ;k<19;k++) {
	init_pair(2, COLOR_YELLOW,COLOR_WHITE);
	attron (COLOR_PAIR(2));			
	wprintw(win,"%s", name[k].c_str());	
	yay();
	wrefresh (win);
	
	
}

	wrefresh(win);
	refresh();
	getch();
	endwin();
	

	
	
}
