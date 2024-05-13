#include <iostream>
using namespace std;

struct nodo {
	int nro;
	struct nodo *sgte;
};

typedef struct nodo *TpLista; // Crear un nuevo tipo de dato de forma puntero

TpLista crearNodo() {
	TpLista nuevo = NULL;
	nuevo = new struct nodo;
	cout << "Ingresar numero ---> ";
	cin >> nuevo->nro;
	cout << endl;
	nuevo->sgte = NULL;
	return nuevo;
}

void verLista(TpLista p) {
	int i = 0;
	while(p != NULL) {
		cout << " " << i + 1 << ") " << p->nro << endl;
		p = p->sgte;
		i++;
	}
}

// Funcion Insertar al Inicio (PUSH de Pila)
void push(TpLista &pila) {
	TpLista n = NULL;
	n = crearNodo();
	if(pila != NULL)
		n->sgte = pila;
	pila = n;
}

// Funcion Eliminar al Inicio (POP de Pila)
void pop(TpLista &pila) {
	TpLista t = pila;
	pila = pila->sgte;
	cout << "\nNodo eliminado es " << t->nro << endl << endl;
	delete(t);
}

// Funcion Insertar al Final (ENCOLAR)
void encolar(TpLista &cola) {
	TpLista nuevo = NULL, p = cola;
	nuevo = crearNodo();
	// ir al final de la lista
	if(cola == NULL)
		cola = nuevo;
	else {
		while(p->sgte != NULL)
			p = p->sgte;
		p->sgte = nuevo;
	}
}

// Funcion Desencolar elimina el primer elemento
void desencolar(TpLista &cola) {
	TpLista t = cola;
	cola = cola->sgte;
	cout << "\nNodo eliminado es " << t->nro << endl << endl;
	delete(t);
}

void menu() {
	system("cls");
	cout << "\n\t OPERACIONES CON PILAS\n\n";
	cout << "1.- Funcion PUSH (apilar)" << endl;
	cout << "2.- Funcion POP (eliminar)" << endl;
	cout << "3.- Mostrar PILA" << endl;
	cout << "\n\t OPERACIONES CON COLAS\n\n";
	cout << "4.- Funcion Encolar" << endl;
	cout << "5.- Funcion Desencolar" << endl;
	cout << "6.- Mostrar Cola" << endl;
	cout << "0.- Salir" << endl << endl;
	cout << "Ingrese Opcion---> ";
}

int main() {
	TpLista pila = NULL, cola = NULL;
	int opc;
	do {
		menu();
		cin >> opc;
		switch(opc) {
			case 1:
				push(pila);
				break;
			case 2:
				if(pila == NULL)
					cout << "\nERROR.. La pila esta vacia.. no permite esta opcion " << endl;
				else
					pop(pila);
				system("pause");
				break;
			case 3:
				verLista(pila);
				system("pause");
				break;
			case 4:
				encolar(cola);
				system("pause");
				break;
			case 5:
				if(cola == NULL)
					cout << "\nERROR.. La cola esta vacia.. no permite esta opcion " << endl;
				else
					desencolar(cola);
				system("pause");
				break;
			case 6:
				verLista(cola);
				system("pause");
				break;
		}
	} while(opc != 0);
	return 0;
}

