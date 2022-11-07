//Ajedrez con pila de movimientos, se puede regresar un movimiento, 
//pero no se puede regresar un movimiento que se haya regresado

#include "ajedrez.h"

int main() {
	ajedrez juego;
	int opc;
	ficha tablero[8][8] = { };
	bool turno = true;
	do {
		system("cls");
		juego.Mostrar_tablero(juego.Consultar());
		cout << endl << endl;
		cout << "1. Mover fichas" << endl;
		cout << "2. Regresar movimiento" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		switch (opc) {
		case 1:
			system("cls");
			if (turno) {
				cout << "Turno de las blancas" << endl;
				juego.JugarBlancas();
				juego.Mostrar_tablero(juego.Consultar());
				turno = false;
			}
			else {
				cout << "Turno de las negras" << endl;
				juego.JugarNegras();
				juego.Mostrar_tablero(juego.Consultar());
				turno = true;
			}
			break;
		case 2:
			system("cls");
			juego.Extraer();
			juego.Mostrar_tablero(juego.Consultar());
			break;
		case 0:
			system("cls");
			cout << "Saliendo..." << endl;
			break;
		default:
			system("cls");
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (opc != 0);
}