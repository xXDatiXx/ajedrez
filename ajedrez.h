#include <iostream>

using namespace std;

struct ficha {
    int fila; //En el tablero
    char columna; //En el tablero
    string pieza; //Cabballo, rey, etc
    string color; //negro o blanco
};

struct movi {
    ficha p;
    movi* ante; //para guardar los movimientos en una pila
};

class ajedrez {
public:
    ajedrez();
    void actualizar_tablero();
    void Insertar(movi); //mover ficha
    void Extraer(); //regresar movimientos
	void Mostrar();
private:
    ficha tablero[8][8];
    movi* tope, * nuevo;
};