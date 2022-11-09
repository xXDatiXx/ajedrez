#include "ajedrez.h"

ajedrez::ajedrez() { 
	tope = NULL; //Se inicializa la pila
	ficha tablero[8][8];
	for (int i = 0; i < 8; i++) { //se pone el ajedrez en su posici�n inicial
		for (int j = 0; j < 8; j++) {
			if (i == 0) {
				tablero[i][j].color = "Negro";
				if (j == 0 || j == 7)
					tablero[i][j].pieza = "Torre";
				if (j == 1 || j == 6)
					tablero[i][j].pieza = "Caballo";
				if (j == 2 || j == 5)
					tablero[i][j].pieza = "Alfil";
				if (j == 3)
					tablero[i][j].pieza = "Reina";
				if (j == 4)
					tablero[i][j].pieza = "Rey";
			}
			if (i == 1) {
				tablero[i][j].pieza = "Peon";
				tablero[i][j].color = "Negro";
			}
			if (i == 6) {
				tablero[i][j].pieza = "Peon";
				tablero[i][j].color = "Blanco";
			}
			if (i == 7) {
				tablero[i][j].color = "Blanco";
				if (j == 0 || j == 7)
					tablero[i][j].pieza = "Torre";
				if (j == 1 || j == 6)
					tablero[i][j].pieza = "Caballo";
				if (j == 2 || j == 5)
					tablero[i][j].pieza = "Alfil";
				if (j == 3)
					tablero[i][j].pieza = "Reina";
				if (j == 4)
					tablero[i][j].pieza = "Rey";
			}
		}
	}
	Insertar(tablero); //Inserta el tablero inicial (el que se acaba de crear) en la pila
}


void ajedrez::Insertar(ficha t[8][8]) { //Inserta en la pila la matriz que se le pasa como par�metro
	nuevo = new tabl;
	for (int i = 0; i < 8; i++) { //agregando datos
		for (int j = 0; j < 8; j++)
			nuevo->tablero[i][j] = t[i][j];
	}
	nuevo->ante = tope;
	tope = nuevo;
}

void ajedrez::Extraer() { //Extrae el ultimo movimiento de la pila
	if (tope->ante != NULL) { //Si no es el tablero inicial
		tabl* aux = tope;
		tope = tope->ante;
		delete aux;
	}
	else
		cout << "No hay movimientos que regresar" << endl;
}

void ajedrez::Mostrar() { //Puede que lo quitemos, es para mostrar los elementos de la pila
	if (tope == NULL)
		cout << "No hay movimientos anteriores" << endl;
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

tabl ajedrez::Consultar() { //Regresa el tablero que esta en el tope
	if (tope != NULL) {
		tabl aux = *tope;
		return aux;
	}
	else
		cout << "No hay movimientos anteriores" << endl;

}

void ajedrez::Mostrar_tablero(tabl t) {
	cout << "\n\t    1         2      3       4       5       6       7       8    " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "  \t_________________________________________________________________" << endl;
		if ((i == 0) || (i == 7))
			cout << i + 1 << "\t|   ♖    |    ♘   |   ♗  |   ♕    |  ♔   |   ♗   |   ♘   |   ♖   |" << endl;
		else if ((i == 1) || (i == 6))
			cout << i + 1 << "\t|   ♙    |    ♙   |   ♙  |   ♙    |  ♙   |   ♙   |   ♙   |   ♙   |" << endl;
		else
			cout << i + 1 << "\t|\t |\t |\t |\t |\t |\t |\t |\t |" << endl;
	}
	cout << "  \t_________________________________________________________________" << endl;
	cout << "\n\t    1         2      3       4       5       6       7       8    \n" << endl;
	/*
	cout << "\t1\t2\t3\t4\t5\t6\t7\t8" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << "\t";
		for (int j = 0; j < 8; j++) {
			cout << t.tablero[i][j].pieza << " ";
		}
		cout << endl;
	}
	*/
}

void ajedrez::JugarBlancas() {
	int x, y, x1, y1;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	//Validacion que esa ficha sea blanca si no vuelve a pedir
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1; //Pide las coordenadas a las que quiere mover la ficha
	//Validacion que esa ficha se pueda mover ahi, segun los movimentos de la ficha
	//Aqui faltan las condiciones para que se pueda mover la pieza
	//Al final se inserta la nueva tabla (t)
}

void ajedrez::JugarNegras() {
	int x, y, x1, y1;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	//Validacion que esa ficha sea blanca si no vuelve a pedir
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1;//Pide las coordenadas a las que quiere mover la ficha
	//Validacion que esa ficha se pueda mover ahi, segun los movimentos de la ficha
	//Aqui faltan las condiciones para que se pueda mover la pieza
	//Al final se inserta la nueva tabla (t)
}