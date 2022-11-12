//Ajedrez con pila de movimientos, se puede regresar un movimiento, 
//pero no se puede regresar un movimiento que se haya regresado

#include "ajedrez.h"

int main() {
	ajedrez juego;
	int opc;
	bool turno = true; //Para que sea true el turno de las blancas o negras
	do {
		system("cls");
		juego.Mostrar_tablero(juego.Consultar()); //Muestra el tablero inicial
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
				juego.JugarBlancas(); //Jugar con las fichas blancas
				//juego.Mostrar_tablero(juego.Consultar()); //Despues del movimiento muestra como quedo el tablero
				turno = false; //Pone turno en false para que la siguiente juagda sea de las negras
			}
			else {
				cout << "Turno de las negras" << endl;
				juego.JugarNegras(); //Jugar con las fichas negras
				//juego.Mostrar_tablero(juego.Consultar()); //Despues del movimiento muestra como quedo el tablero
				turno = true; //Pone turno en true para que la siguiente juagda sea de las blancas
			}
			break;
		case 2:
			system("cls");
			juego.Extraer(); //Regresa el movimiento
			juego.Mostrar_tablero(juego.Consultar()); //Despues de extraer muestra como quedo el tablero
			if (turno) 
				turno = false; //Pone turno en false para que la siguiente juagda sea de las negras
			else
				turno = true; //Pone turno en true para que la siguiente juagda sea de las blancas
		
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