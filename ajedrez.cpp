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
	
	
	cout<<"\t\t\t\t\t\t  JUGADOR 2 (NEGROS)"<<endl;
	cout << "\n\t\t         1        2       3        4        5        6        7        8    " << endl;
	for (int i = 0; i < 8; i++) {
		cout << "\t\t    _________________________________________________________________________" << endl;
		cout <<"\t\t"<<i + 1<<"";
		for (int j = 0; j < 8; j++)
			cout << "   |   "<< t.tablero[i][j].pieza << " ";
		cout << "   |  "<<i+1<<endl;
	}
	cout << "\t\t    _________________________________________________________________________" << endl;
	cout << "\n\t\t         1        2       3        4        5        6        7        8    " << endl;
	cout<<"\n\t\t\t\t\t\t  JUGADOR 1 (BLANCOS)"<<endl;
}

void ajedrez::JugarBlancas() {
	int x, y, x1, y1;
	bool move = false;
	tabl t = Consultar();
	Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	if(t.tablero[x][y].color == "Negro")
	{
		cout<<"\n\t**No es turno de esta ficha"<<endl;
		JugarBlancas();
	}
	else if (t.tablero[x][y].color != "Blanco"){
		cout << "\n\t**No hay ninguna ficha en esa posicion" << endl;
		JugarBlancas();
	}
	
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1; //Pide las coordenadas a las que quiere mover la ficha

	if (t.tablero[x1][y1].color == "Blanco"){ //Validacion para mover ficha
		move = false;
		cout << "\n\t**En el lugar que deseas moverte hay una ficha blanca" << endl;
		JugarBlancas();
	}

	//Validacion ppr tipo de ficha para moverla:
	if(t.tablero[x][y].nombre == "PEON")
	{
		move = true;
		if(x != x1 || y1>y+1)
			move = false;
		if(t.tablero[x][y1].pieza != " " && t.tablero[x][y1].color == "Blanco")
			move = false;
	}

	if(t.tablero[x][y].nombre == "TORRE")
	{
		move = false;
		if (x1 == x && y1 != y){ //Si se mueve horizontal
			if (x1 < x){ //Si se mueve hacia la izquierda
				for (int i = x - 1; i > x1; i--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][y]= {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia la derecha
				for (int i = x + 1; i < x1; i++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
		else if (y1 == y && x1 != x){ //Si se mueve verical
			if (y1 < y){ //Si se mueve hacia abajo
				for (int i = y - 1; i > y1; i--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == "Blanco"){ //Si la ficha es blanca
							y1 = i-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia arriba
				for (int i = y + 1; i < y1; i++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == "Blanco"){ //Si la ficha es blanca
							y1 = i+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
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
	if(t.tablero[x][y].nombre == "ALFIL") 
	{
		move = false;
		if (x1 != x && y1 != y){ //Si se mueve diagonal
			if (x1 < x && y1 < y){ //Si se mueve hacia abajo a la izquierda
				for (int i = x - 1, j = y - 1; i > x1 && j > y1; i--, j--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							y1 = j-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 < x && y1 > y){ //Si se mueve hacia abajo a la derecha
				for (int i = x - 1, j = y + 1; i > x1 && j < y1; i--, j++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							y1 = j+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 > x && y1 < y){ //Si se mueve hacia arriba a la izquierda
				for (int i = x + 1, j = y - 1; i < x1 && j > y1; i++, j--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							y1 = j-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia arriba a la derecha
				for (int i = x + 1, j = y + 1; i < x1 && j < y1; i++, j++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							y1 = j+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
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
	if(t.tablero[x][y].nombre == "REY")
	{
		move = true;
		
		if(x==x1)
		{
			if(y1>y+1 || y1<y-1 || (t.tablero[x][y1].pieza != " " && t.tablero[x][y1].color == "Blanco"))
				move = false;
		}
		else if (y==y1)
		{
			if(x1>x+1 || x1<x-1 || (t.tablero[x1][y].pieza != " " && t.tablero[x1][y].color == "Blanco"))
				move = false;
		}
		else 
			move = false;
	}
	if(t.tablero[x][y].nombre == "REINA")
	{
		move = false;
		if (x1 == x && y1 != y){ //Si se mueve horizontal
			if (x1 < x){ //Si se mueve hacia la izquierda
				for (int i = x - 1; i > x1; i--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia la derecha
				for (int i = x + 1; i < x1; i++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][y].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][y].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][y] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}
		else if (y1 == y && x1 != x){ //Si se mueve verical
			if (y1 < y){ //Si se mueve hacia abajo
				for (int i = y - 1; i > y1; i--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == "Blanco"){ //Si la ficha es blanca
							y1 = i-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia arriba
				for (int i = y + 1; i < y1; i++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[x][i].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[x][i].color == "Blanco"){ //Si la ficha es blanca
							y1 = i+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[x][i] = {}; //Elimina la ficha
							y1 = i; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			move = true;
		}

		else if (x1 != x && y1 != y){ //Si se mueve diagonal
			if (x1 < x && y1 < y){ //Si se mueve hacia abajo a la izquierda
				for (int i = x - 1, j = y - 1; i > x1 && j > y1; i--, j--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							y1 = j-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 < x && y1 > y){ //Si se mueve hacia abajo a la derecha
				for (int i = x - 1, j = y + 1; i > x1 && j < y1; i--, j++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i-1; //La posicion final es la anterior a la ficha
							y1 = j+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else if (x1 > x && y1 < y){ //Si se mueve hacia arriba a la izquierda
				for (int i = x + 1, j = y - 1; i < x1 && j > y1; i++, j--){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							y1 = j-1; //La posicion final es la anterior a la ficha
							break;
						}
						else{ //Si la ficha es negra
							t.tablero[i][j] = {}; //Elimina la ficha
							x1 = i; //La posicion final es la ficha
							y1 = j; //La posicion final es la ficha
							break;
						}
					}
				}
			}
			else{ //Si se mueve hacia arriba a la derecha
				for (int i = x + 1, j = y + 1; i < x1 && j < y1; i++, j++){ //Recorre las posiciones entre la posicion inicial y la final
					if (t.tablero[i][j].pieza != " "){ //Si encuentra una ficha en el camino
						if (t.tablero[i][j].color == "Blanco"){ //Si la ficha es blanca
							x1 = i+1; //La posicion final es la siguiente a la ficha
							y1 = j+1; //La posicion final es la siguiente a la ficha
							break;
						}
						else{ //Si la ficha es negra
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
	
	if(t.tablero[x][y].nombre == "CABALLO")
	{
		move = false;
		if (x1 == x + 2 && y1 == y + 1){ //Si se mueve hacia arriba a la derecha
			move = true;
		}
		else if (x1 == x + 2 && y1 == y - 1){ //Si se mueve hacia arriba a la izquierda
			move = true;
		}
		else if (x1 == x - 2 && y1 == y + 1){ //Si se mueve hacia abajo a la derecha
			move = true;
		}
		else if (x1 == x - 2 && y1 == y - 1){ //Si se mueve hacia abajo a la izquierda
			move = true;
		}
		else if (x1 == x + 1 && y1 == y + 2){ //Si se mueve hacia arriba a la derecha
			move = true;
		}
		else if (x1 == x + 1 && y1 == y - 2){ //Si se mueve hacia arriba a la izquierda
			move = true;
		}
		else if (x1 == x - 1 && y1 == y + 2){ //Si se mueve hacia abajo a la derecha
			move = true;
		}
		else if (x1 == x - 1 && y1 == y - 2){ //Si se mueve hacia abajo a la izquierda
			move = true;
		}
	}

	if(move == true)
	{
		t.tablero[x1][y1] = t.tablero[x][y]; //mover ficha al lugar deseado
		t.tablero[x][y] = {}; //Borrar lugar anterior de la ficha
		t.tablero[x][y].pieza = " ";
		Insertar(t.tablero); //Insertar tablero nuevo en la pila
		Mostrar_tablero(Consultar()); //Mostrar ultimo tablero en la pila
	}
	else
	{
		cout<<"La pieza "<<t.tablero[x][y].nombre<<" NO puede moverse de esa forma"<<endl;
		JugarBlancas();
	}
	
	if (t.tablero[x1][y1].color == "Negro"){ //Validacion para comer ficha
		cout << "\n\t¡Comiste " << t.tablero[x1][y1].nombre << " negro!" << endl;
	}
}

void ajedrez::JugarNegras() {
	int x, y, x1, y1;
	tabl t = Consultar();
	//Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	//Validacion que esa ficha sea blanca si no vuelve a pedir
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1;//Pide las coordenadas a las que quiere mover la ficha
	if(t.tablero[x][y].color == "Blanco")
	{
		cout<<"\n\tNO ES TU TURNO"<<endl;
		JugarNegras();
	}
	else{
		t.tablero[x1][y1] = t.tablero[x][y];
		t.tablero[x][y].pieza = " ";
	}
	//Validacion que esa ficha se pueda mover ahi, segun los movimentos de la ficha
	//Aqui faltan las condiciones para que se pueda mover la pieza
	//Al final se inserta la nueva tabla (t)
}