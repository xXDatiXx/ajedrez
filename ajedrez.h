#include <iostream>

using namespace std;

struct ficha {
    string pieza; //Cabballo, rey, etc
    string color; //negro o blanco
	bool turno; //true si es el turno del jugador que tiene la ficha
};

struct tabl {
	ficha tablero[8][8] = { 0 };
    tabl* ante; //para guardar los movimientos en una pila
};

class ajedrez {
public:
    ajedrez();
    void actualizar_tablero();
	void Insertar(ficha t[8][8]);
    void Extraer(); //regresar movimientos
    void Mostrar();
    tabl Consultar();
private:
    tabl* tope, * nuevo;
};