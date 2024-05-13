#include <iostream>

using namespace std;

struct nodo {
	int nro;
	struct nodo *sgte;
};

typedef struct nodo *TpLista;

TpLista crearNodo() {
	TpLista nuevo = NULL;
	nuevo = new struct nodo;
	cout << "Ingresar dato --> ";
	cin >> nuevo->nro;
	cout << endl;
	nuevo->sgte = NULL;
	return nuevo;
}

// PUSH Permite insertar un nodo al inicio de una Pila
void push(TpLista &lista) {
	TpLista q = crearNodo();
	if(lista != NULL)
		q->sgte = lista;
	lista = q;
}

void verPila(TpLista lista) {
	int i = 0;
	while(lista != NULL) {
		cout << " " << i+1 << ") " << lista->nro << endl;
		lista = lista->sgte;
		i++;
	}
}

void menu() {
	system("CLS");
	cout << "\n\t Operaciones de PILA HANOI\n\n";
	cout << "1.- Insertar elementos en Pila A" << endl;
	cout << "2.- Extraer de Pila A y Cargar en Pila C" << endl;
	cout << "3.- Mostrar Pila" << endl;
	cout << "0.- Salir" << endl << endl;
	cout << "Ingresar Opcion---> " << endl;
}

// POP extrae un nodo desde el inicio de una PILA
TpLista pop(TpLista &lista) {
	TpLista t = lista;
	if(lista == NULL) {
		cout << "ERROR: Lista vacia.. no permite esta opcion" << endl;
		system("pause");
		return t;
	}
	lista = lista->sgte;
	t->sgte = NULL;
	return t;
}

void pushTraslada(TpLista &lista, TpLista q) {
	if(lista != NULL) {
		q->sgte = lista;
	}
	lista = q;
}

int main() {
	TpLista pilaA = NULL, pilaB = NULL, pilaC = NULL, temp = NULL;
	int opc;
	do {
		menu();
		cin >> opc;
		
		switch(opc) {
			case 1: {
				push(pilaA);
				system("pause");
				break;
			}
			case 2: {
				temp = pop(pilaA);
				pushTraslada(pilaC, temp);
				system("pause");
				break;
			}
			case 3: {
				cout << "*******PILA A **********" << endl << endl;
				verPila(pilaA);
				cout << "*******PILA C **********" << endl << endl;
				verPila(pilaC);
				system("pause");
				break;
			}
		}
	} while(opc != 0);
	return 0;
}

