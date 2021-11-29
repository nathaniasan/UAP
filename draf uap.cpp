#include <ncurses.h>
#include <windows.h>
using namespace std;



//void menu(){
//	int pilihan;
//	 printw ("=======Selamat Datang Di game Ular===========\n");
//	 printw ("1. Play\n2. Exit\n ");
//	 printw ("Masukkan pilihan kamu:  ");
//	 scanw ("%d",pilihan);
//	 if (pilihan==1){
//	
//	 }else {
//	 	
//	 }
//}






int main(){
	int x = 1, y = 1;
	initscr();
	
//	menu();
//	
	clear();
	
	//newwin(height, width, start_y, start_x)
	WINDOW * wina = newwin(20, 120, 1, 10);
	refresh();
	
	
	box(wina, 0, 0);

	wmove(wina, y, x);
	wprintw(wina, "|±±|");
	wrefresh(wina);
	
	keypad(wina, TRUE);
	
	while(true){
		
		wclear(wina);
		wmove(wina, y, x);
		wprintw(wina, "|±±|");
		wrefresh(wina);
		int movement;
//		movement = wgetch(win);
		x++;
		Sleep(2000);
				if(x == 120){
					x = 1;
				}else{
					x++;
				}
		
		
	}
	
	getch();
	endwin();
}



// tampilan berjalan obje
