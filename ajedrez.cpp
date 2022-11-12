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
	
	
	cout<<"\t\t\t\t\t\t  JUGADOR 2"<<endl;
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
	cout<<"\n\t\t\t\t\t\t  JUGADOR 1"<<endl;
}

void ajedrez::JugarBlancas() {
	int x, y, x1, y1;
	bool move = false;
	tabl t = Consultar();
	//Mostrar_tablero(t);
	cout << "Ingrese la posicion de la pieza que desea mover" << endl;
	cout << "Ingrese la fila: "; cin >> x;
	cout << "Ingrese la columna: "; cin >> y; //Pide las coordenadas de la ficha que quiere mover
	//Validacion que esa ficha sea blanca si no vuelve a pedir
	cout << "Ingrese la posicion a la que desea mover la pieza" << endl;
	cout << "Ingrese la fila: "; cin >> x1;
	cout << "Ingrese la columna: ";	cin >> y1; //Pide las coordenadas a las que quiere mover la ficha
	if(t.tablero[x][y].color == "Negro")
	{
		cout<<"\n\tNO ES TU TURNO"<<endl;
		JugarBlancas();
	}
	else{
		//Validacion que esa ficha se pueda mover ahi, segun los movimentos de la ficha 
		if(t.tablero[x][y].nombre == "PEON")
		{
			move = true;
			if(x != x1 || y1>y+1)
				move = false;
		}
		if(t.tablero[x][y].nombre == "TORRE")
		{
			move = true;
			if(x1==x && y!=y1)
			{
				for (int i = y+1; i < y1; i++)
				{
					if (t.tablero[x][i].pieza != " ")
						break;
					
				}
			}
			
			
			
		}
		if(move == true)
		{
			t.tablero[x1][y1] = t.tablero[x][y];
			t.tablero[x][y].pieza = " ";
			t.tablero[x][y].nombre = " ";
			Mostrar_tablero(t);
		}
		else
		{
			cout<<"La pieza "<<t.tablero[x][y].nombre<<" NO puede moverse de esa forma"<<endl;
			JugarBlancas();
		}
		
	}
	
	//Aqui faltan las condiciones para que se pueda mover la pieza
	//Al final se inserta la nueva tabla (t)
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