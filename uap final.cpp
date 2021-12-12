#include <string.h>
#include <windows.h>
#include <ncurses.h>

using namespace std;

//kecepatan kotak, semakin kecil nilainya semakin cepat
int time;

void warna();
void menu_utama_play();
void menu_utama_exit();
void mode();
void play();
void exit();

int main(){
	
	char ch;
	int select;
	
	initscr();

	warna();//memanggil fungsi warna
	
	curs_set(0);//menghilangkan cursor
	
	noecho();
	
	start_color();
	
	menu_utama_play();select=1;
	
	while(true){
		for(int i=0;;){
		noecho();
		ch = getch();
			if(ch==72){//tampilan selection play
				clear();
		        menu_utama_play();select=1;
			}
			else if(ch == 80){//tampilan selection exit
				clear();
		        menu_utama_exit();select=2;
			}
			
			if(ch == '\n'){
				
				if(select == 1){//select play
					mode();
				}
				if(select == 2){// exit
					exit(0);
				}
			}
		}	
	}

	getch();
	refresh();
	endwin();
	
}

void warna(){
	start_color();
	init_pair(1,COLOR_BLACK,COLOR_WHITE);
}

void menu_utama_play(){
	mvprintw (8,51, "MENU UTAMA");refresh();
	mvprintw (9,42, "(Tekan enter untuk memilih!)");refresh();
	attron(COLOR_PAIR(1));
	mvprintw (12,53, "PLAY :)");refresh();
	attroff(COLOR_PAIR(1));
	mvprintw (14,53, "EXIT");refresh();
}

void menu_utama_exit(){
	mvprintw (8,51, "MENU UTAMA");refresh();
	mvprintw (9,42, "(Tekan enter untuk memilih!)");refresh();
	mvprintw (12,53, "PLAY");refresh();
	attron(COLOR_PAIR(1));
	mvprintw (14,53, "EXIT :(");refresh();attroff(COLOR_PAIR(1));refresh();
}

void mode(){
	clear();
	char md;
	mvprintw (9,43, "Masukan tingkat kesulitan!");refresh();
	mvprintw (11,50, "1. Easy");refresh();
	mvprintw (12,50, "2. Normal");refresh();
	mvprintw (13,50, "3. Hard");refresh();
	mvprintw (16,47, "Pilihan anda : ");
	
	echo();
	
	md = getch();//input tingkat kesulitan
	
	if(md == '1'){
		time=100;play();
	}
	else if(md == '2'){
		time=50;play();
	}
	else if(md == '3'){
		time=15;play();
	}
}

void play(){
	
	nodelay(stdscr, TRUE);
	
	//inisiasi warna
	init_pair(1,COLOR_RED,COLOR_RED);
	init_pair(2,COLOR_WHITE,COLOR_WHITE);
	init_pair(3,COLOR_YELLOW,COLOR_YELLOW);
	
	//sumbu y = 7 dan 9
	//sumbu x = 60 sampai dengan 116
	
	//kordinat rintangan y,x (kotak merah)
	int a=7;
	int b=100;
	int c=9;
	int d=111;
	int e=7;
	int f=122;
	int g=9;
	int h=133;
	int j=7;
	int k=144;
	int l=9;
	int m=155;
	int n=7;
	int o=166;
	int skors = 0;
	
	int y= 7; //y=a
	int x= 2; //x=b
	
	//kotak kuning
	int tombol;
	char kotak[100] = "<>";
	
	//looping utama
	while(true){
	for(int i = 0;i<170;i++){

		noecho();
		tombol=getch();//menangkap input tombol
		clear();

		//membuat garis lurus
		attron(COLOR_PAIR(2));
		mvprintw(8,0,"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		
		//menampilkan dan membuat kotak merah agar dapat bergerak
		mvprintw(a,b-i,kotak);
		mvprintw(c,d-i,kotak);
		mvprintw(e,f-i,kotak);
		mvprintw(g,h-i,kotak);
		mvprintw(j,k-i,kotak);
		mvprintw(l,m-i,kotak);
		mvprintw(n,o-i,kotak);
		
		attroff(COLOR_PAIR(1));
		Sleep(time);
		
		//kondisi naik turun kotak kuning
		if(tombol==72){
			y=7;
		}
		else if(tombol==80){
			y=9;
		}
		attroff(COLOR_PAIR(1));refresh();
		
		//membuat kotak kuning naik dan turun
		attron(COLOR_PAIR(3));
		mvprintw(y,x, kotak);
		attroff(COLOR_PAIR(3));
		
		//kondisi manual jika kotak kuning menabrak kotak merah
		if(y==a && x==b-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==c && x==d-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==e && x==f-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==g && x==h-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==j && x==k-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==l && x==m-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		else if(y==n && x==o-i){
			clear();
			printw("kamu kalah\ndengan skor: %d",skors);
			getch();
			Sleep(5000);
			refresh();
			exit(0);
		}
		skors++;//syarat score agar nilainya bertambah
		mvprintw(20,11, "Score = ");
		mvprintw(20,20,"%d", skors);
		refresh();
		}
	}
}

