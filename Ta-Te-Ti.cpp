#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "rlutil.h"

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13

using namespace rlutil;
using namespace std;

void borrarCursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void dibujoMarco() {
	for (int i = 2; i < 120; i++) {
		gotoxy(i, 1); printf("%c", 205);
		gotoxy(i, 30); printf("%c", 205);
	};
	for (int i = 2; i < 30; i++) {
		gotoxy(1, i); printf("%c", 186);
		gotoxy(120, i); printf("%c", 186);
	};
	gotoxy(1, 1); printf("%c", 201);
	gotoxy(1, 30); printf("%c", 200);
	gotoxy(120, 1); printf("%c", 187);
	gotoxy(120, 30); printf("%c", 188);
}

void dibujoTablero() {
	for (int i = 40; i < 70; i++) {
		gotoxy(i, 10); printf("%c", 205);
		gotoxy(i, 15); printf("%c", 205);
	};
	for (int i = 7; i < 19; i++) {
		gotoxy(48, i); printf("%c", 186);
		gotoxy(61, i); printf("%c", 186);
	};
}

int funcion(char tablero[3][3]) {

	return 0;
}

int main(){
	setBackgroundColor(GREY);
	int x = 55; int y = 12;
	bool juegoTerminado = false; bool jugador1Movimiento = false; bool jugador2Movimiento = false;
	int numeroRandomX; int numeroRandomY; int numeroJugadas = 0;
	cls(); borrarCursor(); setColor(LIGHTBLUE); dibujoMarco(); setColor(WHITE);	dibujoTablero(); gotoxy(1, 35); 
	while (juegoTerminado==false) {
		dibujoTablero(); Sleep(20); // Intervalo para que no se vaya volando
		gotoxy(1, 35);
		bool jugador1Movimiento = false; 
		bool jugador2Movimiento = false;
			while(jugador1Movimiento==false){
				//Movimiento Jugador 1
				dibujoTablero();
				setColor(BLACK);
				gotoxy(1, 35); cout << "Turno del primer jugador: " << endl;
				if (kbhit()) {
					setColor(LIGHTBLUE);
					if (numeroJugadas > 8) {
						juegoTerminado = true;
						break;
					}
					char tecla = getch();
					if (tecla == LEFT) {
						gotoxy(x, y); printf(" ");
						x--; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == RIGHT) {
						gotoxy(x, y); printf(" ");
						x++; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == UP) {
						gotoxy(x, y); printf(" ");
						y--; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == DOWN) {
						gotoxy(x, y); printf(" ");
						y++; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == ENTER){
						gotoxy(x - 1, y + 1); printf("%c", 88);
						numeroJugadas++;
						jugador1Movimiento = true;
					}
				}
			}
			while(jugador2Movimiento==false){
				setColor(BLACK);
				if (numeroJugadas > 8) {
					juegoTerminado = true;
					break;
				}
				dibujoTablero();
				gotoxy(1, 35); cout << "Turno del segundo jugador: " << endl;
				setColor(YELLOW);
				if (kbhit()) {
					char tecla = getch();
					if (tecla == LEFT) {
						gotoxy(x, y); printf(" ");
						x--; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == RIGHT) {
						gotoxy(x, y); printf(" ");
						x++; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == UP) {
						gotoxy(x, y); printf(" ");
						y--; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == DOWN) {
						gotoxy(x, y); printf(" ");
						y++; gotoxy(x, y); printf("%c", 176);
					}
					else if (tecla == ENTER) {
						gotoxy(x - 1, y + 1); printf("%c", 79);
						numeroJugadas++;
						jugador2Movimiento = true;
					}
				}
			}
	}
	setColor(BLACK);
	gotoxy(1, 35);
	while (juegoTerminado == true) {
	gotoxy(1, 35);
	setColor(LIGHTRED);
	cout << "Juego terminado!                   " << endl;
	gotoxy(1, 35);
	setColor(YELLOW);
	cout << "Juego terminado!                   " << endl;
	}
	system("pause");
	return 0;
}
