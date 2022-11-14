//Ajedrez con pila de movimientos, se puede regresar un movimiento, 
//pero no se puede regresar un movimiento que se haya regresado

#include "ajedrez.h"

int main() {
	ajedrez juego;
	int opc, aux;
	bool turno = true; //Para que sea true el turno de las blancas o negras
	do {
		system("clear");
		setlocale(LC_ALL, "");
		juego.Mostrar_tablero(juego.Consultar()); //Muestra el tablero inicial
		cout << endl << endl;
		cout << "1. Mover fichas" << endl;
		cout << "2. Regresar movimiento" << endl;
		cout << "0. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		switch (opc) {
		case 1:
			system("clear");
			if (turno) {
				cout << "--Turno de las BLANCAS--" << endl;
				juego.Jugar("Blanco"); //Jugar con las fichas blancas
				turno = false; //Pone turno en false para que la siguiente juagda sea de las negras
			}
			else {
				cout << "--Turno de las NEGRAS--" << endl;
				juego.Jugar("Negro"); //Jugar con las fichas negras
				turno = true; //Pone turno en true para que la siguiente juagda sea de las blancas
			}
			break;
		case 2:
			system("clear");
			aux = juego.Extraer(); //Regresa el movimiento
			if (aux == -1) {
				cout << "No hay movimientos que regresar" << endl;
				system("pause");
			}
			else {
				cout << "Movimiento regresado" << endl;
				if (turno)
					turno = false; //Pone turno en false para que la siguiente juagda sea de las negras
				else
					turno = true; //Pone turno en true para que la siguiente juagda sea de las blancas
				system("pause");
			}
			break;
		case 0:
			system("clear");
			cout << "Saliendo..." << endl;
			break;
		default:
			system("clear");
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (opc != 0);
}