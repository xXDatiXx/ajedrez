#include "ajedrez.h"

ajedrez::ajedrez() { //se pone el ajedrez en su posición inicial
    ficha peonesB[8];
    ficha peonesN[8];
    ficha torre1b, caballo1b, alfil1b, reyb, reinab, torre2b, caballo2b, alfil2b;
    ficha torre1n, caballo1n, alfil1n, reyn, reinan, torre2n, caballo2n, alfil2n;
	//inicializar lugares de fichas
	for (int i = 0; i < 8; i++) {
		peonesB[i].fila = 2;
		peonesB[i].columna = 'a' + i;
		peonesB[i].pieza = "Peon";
		peonesB[i].color = "Blanco";
		peonesN[i].fila = 7;
		peonesN[i].columna = 'a' + i;
		peonesN[i].pieza = "Peon";
		peonesN[i].color = "Negro";
	}
	tope = NULL;
}

void ajedrez::actualizar_tablero() {}

void ajedrez::Insertar(movi m) {
	movi* nuevo = new movi;
	nuevo->p = m.p;
	nuevo->ante = tope;
	tope = nuevo;
}

void ajedrez::Extraer() {
	if (tope != NULL) {
		movi* aux = tope;
		tope = tope->ante;
		delete aux;
	}
}

void ajedrez::Mostrar() {
	if (tope == NULL) {
		cout << "No hay movimientos anteriores" << endl;
	}
	else {
		movi* aux = tope;
		while (aux != NULL) {
			cout << aux->p.pieza << " " << aux->p.color << " " << aux->p.columna << aux->p.fila << endl;
			aux = aux->ante;
		}
	}
}