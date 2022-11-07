#include "ajedrez.h"

ajedrez::ajedrez() { //se pone el ajedrez en su posici�n inicial
	tope = NULL;
	ficha tablero[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0) {
				if (j == 0 || j == 7) {
					tablero[i][j].pieza = "Torre";
					tablero[i][j].color = "Negro";
					tablero[i][j].turno = false;
				}
				if (j == 1 || j == 6) {
					tablero[i][j].pieza = "Caballo";
					tablero[i][j].color = "Negro";
					tablero[i][j].turno = false;
				}
				if (j == 2 || j == 5) {
					tablero[i][j].pieza = "Alfil";
					tablero[i][j].color = "Negro";
					tablero[i][j].turno = false;
				}
				if (j == 3) {
					tablero[i][j].pieza = "Reina";
					tablero[i][j].color = "Negro";
					tablero[i][j].turno = false;
				}
				if (j == 4) {
					tablero[i][j].pieza = "Rey";
					tablero[i][j].color = "Negro";
					tablero[i][j].turno = false;
				}
			}
			if (i == 1) {
				tablero[i][j].pieza = "Peon";
				tablero[i][j].color = "Negro";
				tablero[i][j].turno = false;
			}
			if (i == 6) {
				tablero[i][j].pieza = "Peon";
				tablero[i][j].color = "Blanco";
				tablero[i][j].turno = true;
			}
			if (i == 7) {
				if (j == 0 || j == 7) {
					tablero[i][j].pieza = "Torre";
					tablero[i][j].color = "Blanco";
					tablero[i][j].turno = true;
				}
				if (j == 1 || j == 6) {
					tablero[i][j].pieza = "Caballo";
					tablero[i][j].color = "Blanco";
					tablero[i][j].turno = true;
				}
				if (j == 2 || j == 5) {
					tablero[i][j].pieza = "Alfil";
					tablero[i][j].color = "Blanco";
					tablero[i][j].turno = true;
				}
				if (j == 3) {
					tablero[i][j].pieza = "Reina";
					tablero[i][j].color = "Blanco";
					tablero[i][j].turno = true;
				}
				if (j == 4) {
					tablero[i][j].pieza = "Rey";
					tablero[i][j].color = "Blanco";
					tablero[i][j].turno = true;
				}
			}
		}
	}
	Insertar(tablero);
}

void ajedrez::actualizar_tablero() {}

void ajedrez::Insertar(ficha t[8][8]) {
	nuevo = new tabl;
	//agregar datos
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			nuevo->tablero[i][j] = t[i][j];
		}
	}
	nuevo->ante = tope;
	tope = nuevo;
}


void ajedrez::Extraer() {
	if (tope->ante != NULL) { //Si no es el primer movimiento
		tabl* aux = tope;
		tope = tope->ante;
		delete aux;
	}
	else {
		cout << "No hay movimientos que regresar" << endl;
	}
}

void ajedrez::Mostrar() {
	if (tope == NULL) {
		cout << "No hay movimientos anteriores" << endl;
	}
	else {
		tabl* aux = tope;
		while (aux != NULL) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					cout << aux->tablero[i][j].pieza << " ";
				}
				cout << endl;
			}
			aux = aux->ante;
		}
	}
}

tabl ajedrez::Consultar() {
	if (tope != NULL) {
		tabl aux = *tope;
		return aux;
	}
	else {
		cout << "No hay movimientos anteriores" << endl;
	}

}

void ajedrez::Mostrar_tablero(tabl t) {
	cout << "\t1\t2\t3\t4\t5\t6\t7\t8" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << "\t";
		for (int j = 0; j < 8; j++) {
			cout << t.tablero[i][j].pieza << " ";
		}
		cout << endl;
	}
}

void ajedrez::JugarBlancas() {
	int x, y, x1, y1;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y;
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1;
}

void ajedrez::JugarNegras() {
	int x, y, x1, y1;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y;
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1;
}
		