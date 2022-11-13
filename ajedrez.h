#include <iostream>

using namespace std;

struct ficha {
    string pieza; //Nombre de la pieza
    string color; //Color de la pieza --y si ponemos color con una bandera
    string nombre;
};

struct tabl {
    ficha tablero[8][8] = {};
    tabl* ante; //para guardar los movimientos en una pila
};

class ajedrez {
public:
    ajedrez();
    int Extraer(); //Regresar movimientos
    void Mostrar_tablero(tabl); //Muestra la matriz de fichas
    void Jugar(string); //Juega
    tabl Consultar(); //Devuelve el tablero actual
    //Hara falta una funcion para comer pieza?
private:
    void Insertar(ficha t[8][8]);
    tabl* tope, * nuevo;
};