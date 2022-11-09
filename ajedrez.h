#include <iostream>

using namespace std;

struct ficha {
    string pieza; //Nombre de la pieza
    string color; //Color de la pieza --y si ponemos color con una bandera
};

struct tabl {
    ficha tablero[8][8] = {};
    tabl* ante; //para guardar los movimientos en una pila
};

class ajedrez {
public:
    ajedrez();
    void Extraer(); //Regresar movimientos
    void Mostrar(); //Puede que lo quitemos
	void Mostrar_tablero(tabl); //Muestra la matriz de fichas
	void JugarBlancas(); //Juega las blancas
	void JugarNegras(); //Juega las negras
	tabl Consultar(); //Devuelve el tablero actual
    //Hara falta una funcion para comer pieza?
private:
    void Insertar(ficha t[8][8]);
    tabl* tope, * nuevo;
};