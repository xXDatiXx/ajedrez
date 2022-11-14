#include "ajedrez.h"

ajedrez::ajedrez() {
	tope = NULL; //Se inicializa la pila
	ficha tablero[8][8];
	for (int i = 0; i < 8; i++) { //se pone el ajedrez en su posici�n inicial
		for (int j = 0; j < 8; j++) {
			if (i == 0) {
				tablero[i][j].color = "Negro";
				if (j == 0 || j == 7)
				{
					tablero[i][j].pieza = "♖";
					tablero[i][j].nombre = "TORRE";
				}
				if (j == 1 || j == 6)
				{
					tablero[i][j].pieza = "♘";
					tablero[i][j].nombre = "CABALLO";
				}
				if (j == 2 || j == 5)
				{
					tablero[i][j].pieza = "♗";
					tablero[i][j].nombre = "ALFIL";
				}
				if (j == 3)
				{
					tablero[i][j].pieza = "♔";
					tablero[i][j].nombre = "REINA";
				}
				if (j == 4)
				{
					tablero[i][j].pieza = "♕";
					tablero[i][j].nombre = "REY";
				}
			}
			else if (i == 1) {
				tablero[i][j].pieza = "♙";
				tablero[i][j].color = "Negro";
				tablero[i][j].nombre = "PEON";
			}
			else if (i == 6) {
				tablero[i][j].pieza = "♙";
				tablero[i][j].color = "Blanco";
				tablero[i][j].nombre = "PEON";
			}
			else if (i == 7) {
				tablero[i][j].color = "Blanco";
				if (j == 0 || j == 7)
				{
					tablero[i][j].pieza = "♖";
					tablero[i][j].nombre = "TORRE";
				}
				if (j == 1 || j == 6)
				{
					tablero[i][j].pieza = "♘";
					tablero[i][j].nombre = "CABALLO";
				}
				if (j == 2 || j == 5)
				{
					tablero[i][j].pieza = "♗";
					tablero[i][j].nombre = "ALFIL";
				}
				if (j == 3)
				{
					tablero[i][j].pieza = "♔";
					tablero[i][j].nombre = "REINA";
				}
				if (j == 4)
				{
					tablero[i][j].pieza = "♕";
					tablero[i][j].nombre = "REY";
				}
			}
			else
			{
				tablero[i][j].pieza = " ";
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

int ajedrez::Extraer() { //Extrae el ultimo movimiento de la pila
	if (tope->ante != NULL) { //Si no es el tablero inicial
		tabl* aux = tope;
		tope = tope->ante;
		delete aux;
		return 1;
	}
	else {
		return -1;
	}
}

tabl ajedrez::Consultar() { //Regresa el tablero que esta en el tope
	tabl aux;
	if (tope != NULL) {
		aux = *tope;
		return aux;
	}
	else{
		cout << "\v\t**No hay movimientos anteriores" << endl;
		return aux;
	}
}

void ajedrez::Mostrar_tablero(tabl t) {


	cout << "\t\t\t\t\t\t  JUGADOR 2 (NEGROS)" << endl;
	cout << "\n\t\t         1        2       3        4        5        6        7        8    " << endl;
	for (int i = 0; i < 8; i++) {
		cout << "\t\t    _________________________________________________________________________" << endl;
		cout << "\t\t" << i + 1 << "";
		for (int j = 0; j < 8; j++)
			cout << "   |   " << t.tablero[i][j].pieza << " ";
		cout << "   |  " << i + 1 << endl;
	}
	cout << "\t\t    _________________________________________________________________________" << endl;
	cout << "\n\t\t         1        2       3        4        5        6        7        8    " << endl;
	cout << "\n\t\t\t\t\t\t  JUGADOR 1 (BLANCOS)" << endl;
}

void ajedrez::Jugar(string color) {
	int x, y, x1, y1;
	bool move = false;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	x--; y--;
	if (t.tablero[x][y].color != color)
	{
		cout << "\n\t**Casilla seleccionada incorrecta" << endl;
		Jugar(color);
		return;
	}

	cout << "\nHas seleccionado " << t.tablero[x][y].nombre << " en la posicion " << x+1 << "," << y+1 << endl;
	
	cout << "\nIngrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1; //Pide las coordenadas a las que quiere mover la ficha
	x1--; y1--;
	
	if (t.tablero[x1][y1].color == color) { //Validacion para mover ficha
		move = false;
		cout << "\n\t**En el lugar que deseas moverte hay una ficha aliada" << endl;
		Jugar(color);
		return;
	}

	//Validacion ppr tipo de ficha para moverla:
	if (t.tablero[x][y].nombre == "PEON")
	{
		if (color == "Blanco")
		{
			if (x1 == x - 1 && y1 == y)
			{
				move = true;
			}
			else if (x1 == x - 2 && y1 == y && x == 6)
			{
				move = true;
			}
			else if (x1 == x - 1 && y1 == y - 1)
			{
				move = true;
			}
			else if (x1 == x - 1 && y1 == y + 1)
			{
				move = true;
			}
			else
			{
				move = false;
				cout << "\n\t**Movimiento no valido para el peon" << endl;
				Jugar(color);
				return;
			}
		}
		else {
			if (x1 == x + 1 && y1 == y)
			{
				move = true;
			}
			else if (x1 == x + 2 && y1 == y && x == 1)
			{
				move = true;
			}
			else if (x1 == x + 1 && y1 == y - 1)
			{
				move = true;
			}
			else if (x1 == x + 1 && y1 == y + 1)
			{
				move = true;
			}
			else
			{
				move = false;
				cout << "\n\t**Movimiento no valido para el peon" << endl;
				Jugar(color);
				return;
			}
		}
		move = true;
	}

	if (t.tablero[x][y].nombre == "TORRE")
	{
		move = false;
		if (x1 == x && y1 != y) { //Si se mueve horizontal
			if (x1 < x) { //Si se mueve hacia la izquierda
				for (int i = x - 1; i > x1; i--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].nombre != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == color) { //Si la ficha es del color
							x1 = i - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es del otro color
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia la derecha
				for (int i = x + 1; i < x1; i++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == color) { //Si la ficha es del color
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
		else if (y1 == y && x1 != x) { //Si se mueve verical
			if (y1 < y) { //Si se mueve hacia abajo
				for (int i = y - 1; i > y1; i--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == color) { //Si la ficha del color
							y1 = i - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia arriba
				for (int i = y + 1; i < y1; i++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == color) { //Si la ficha es del color
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
	}
	if (t.tablero[x][y].nombre == "ALFIL")
	{
		move = false;
		if (x1 != x && y1 != y) { //Si se mueve diagonal
			if (x1 < x&& y1 < y) { //Si se mueve hacia abajo a la izquierda
				for (int i = x - 1, j = y - 1; i > x1 && j > y1; i--, j--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es del color
							x1 = i - 1; //La posicion final es la anterior a la ficha
							y1 = j - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 < x && y1 > y) { //Si se mueve hacia abajo a la derecha
				for (int i = x - 1, j = y + 1; i > x1 && j < y1; i--, j++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es del color
							x1 = i - 1; //La posicion final es la anterior a la ficha
							y1 = j + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 > x && y1 < y) { //Si se mueve hacia arriba a la izquierda
				for (int i = x + 1, j = y - 1; i < x1 && j > y1; i++, j--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es del color
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							y1 = j - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia arriba a la derecha
				for (int i = x + 1, j = y + 1; i < x1 && j < y1; i++, j++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es del color
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							y1 = j + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
	}
	if (t.tablero[x][y].nombre == "REY")
	{
		move = true;
		if (x == x1)
		{
			if (y1 > y + 1 || y1 < y - 1 || (t.tablero[x][y1].pieza != " " && t.tablero[x][y1].color == color))
				move = false;
		}
		else if (y == y1)
		{
			if (x1 > x + 1 || x1 < x - 1 || (t.tablero[x1][y].pieza != " " && t.tablero[x1][y].color == color))
				move = false;
		}
		else
			move = false;
	}
	if (t.tablero[x][y].nombre == "REINA")
	{
		move = false;
		if (x1 == x && y1 != y) { //Si se mueve horizontal
			if (x1 < x) { //Si se mueve hacia la izquierda
				for (int i = x - 1; i > x1; i--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == color) { //Si la ficha es del color
							x1 = i - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia la derecha
				for (int i = x + 1; i < x1; i++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == color) { //Si la ficha es del color
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
		else if (y1 == y && x1 != x) { //Si se mueve verical
			if (y1 < y) { //Si se mueve hacia abajo
				for (int i = y - 1; i > y1; i--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == color) { //Si la ficha es del color
							y1 = i - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia arriba
				for (int i = y + 1; i < y1; i++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == color) { //Si la ficha es del color
							y1 = i + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}

		else if (x1 != x && y1 != y) { //Si se mueve diagonal
			if (x1 < x&& y1 < y) { //Si se mueve hacia abajo a la izquierda
				for (int i = x - 1, j = y - 1; i > x1 && j > y1; i--, j--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es blanca
							x1 = i - 1; //La posicion final es la anterior a la ficha
							y1 = j - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 < x && y1 > y) { //Si se mueve hacia abajo a la derecha
				for (int i = x - 1, j = y + 1; i > x1 && j < y1; i--, j++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es blanca
							x1 = i - 1; //La posicion final es la anterior a la ficha
							y1 = j + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 > x && y1 < y) { //Si se mueve hacia arriba a la izquierda
				for (int i = x + 1, j = y - 1; i < x1 && j > y1; i++, j--) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es blanca
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							y1 = j - 1; //La posicion final es la anterior a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else { //Si se mueve hacia arriba a la derecha
				for (int i = x + 1, j = y + 1; i < x1 && j < y1; i++, j++) { //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " ") { //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == color) { //Si la ficha es blanca
							x1 = i + 1; //La posicion final es la siguiente a la ficha
							y1 = j + 1; //La posicion final es la siguiente a la ficha
							break;
						}
						else { //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
	}

	if (t.tablero[x][y].nombre == "CABALLO")
	{
		move = false;
		if (x1 == x + 2 && y1 == y + 1) { //Si se mueve hacia arriba a la derecha
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //come
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x + 2 && y1 == y - 1) { //Si se mueve hacia arriba a la izquierda
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
			
		}
		else if (x1 == x - 2 && y1 == y + 1) { //Si se mueve hacia abajo a la derecha
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x - 2 && y1 == y - 1) { //Si se mueve hacia abajo a la izquierda
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x + 1 && y1 == y + 2) { //Si se mueve hacia arriba a la derecha
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x + 1 && y1 == y - 2) { //Si se mueve hacia arriba a la izquierda
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x - 1 && y1 == y + 2) { //Si se mueve hacia abajo a la derecha
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
		else if (x1 == x - 1 && y1 == y - 2) { //Si se mueve hacia abajo a la izquierda
			if (t.tablero[x1][y1].color == color) { //No se mueve porque hay una blanca
				move = false;
			}
			else if (t.tablero[x1][y1].color != color) { //se come a la negra
				cout << "Te has comido " << t.tablero[x1][y1].nombre << endl;
				move = true;
			}
			else {
				move = true;
			}
		}
	}

	if (move == true)
	{
		t.tablero[x1][y1] = t.tablero[x][y]; //mover ficha al lugar deseado
		t.tablero[x][y] = {}; //Borrar lugar anterior de la ficha
		t.tablero[x][y].pieza = " ";
		Insertar(t.tablero); //Insertar tablero nuevo en la pila
		Mostrar_tablero(Consultar()); //Mostrar ultimo tablero en la pila
	}
	else
	{
		cout << "La pieza " << t.tablero[x][y].nombre << " NO puede moverse de esa forma" << endl;
		Jugar(color);
		return;
	}
}