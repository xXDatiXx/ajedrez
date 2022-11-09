#include <iostream>

using namespace std;

struct ficha {
	string pieza; //Nombrede la pieza
    string color; //Color de la pieza --y si ponemos color con una bandera
	bool turno; //Turno de la pieza
};

struct tabl {
	ficha tablero[8][8] = {};
    tabl* ante; //para guardar los movimientos en una pila
};

class ajedrez {
public:
    ajedrez();
    void actualizar_tablero();
	void Insertar(ficha t[8][8]);
    void Extraer(); //Regresar movimientos
    void Mostrar();
	void Mostrar_tablero(tabl);
    void JugarBlancas();
	void JugarNegras();
    tabl Consultar();
private:
    tabl* tope, * nuevo;
};
