#include <ncurses.h>
#include <windows.h>
using namespace std;

int main(){
	int x = 1, y = 1;
	initscr();
	
	//newwin(height, width, start_x, start_y)
	WINDOW * wina = newwin(20, 120, 1, 1);
	refresh();
	
	wmove(wina, y, x);
	wprintw(wina, "|±±|");
	wrefresh(wina);
	
	keypad(wina, TRUE);
	
	while(true){
		int movement;
//		movement = wgetch(win);
		x++;
		Sleep(20);
				if(x == 120){
					x = 1;
				}else{
					x++;
				}
		
		wclear(wina);
		wmove(wina, y, x);
		wprintw(wina, "|±±|");
		wrefresh(wina);
	}
	
	getch();
	endwin();
}



// tampilan berjalan objek
