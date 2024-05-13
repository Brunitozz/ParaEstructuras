#include <iostream>

using namespace std;

struct nodo {
    int nro;
    int tipo;
    struct nodo *ant;
    struct nodo *sgte;
};

typedef struct nodo *TpLista; // crear tipo de dato struct nodo

TpLista CrearNodo() {
    TpLista nuevo = new struct nodo;
    cout << "Ingresar numero ---> ";
    cin >> nuevo->nro;
    cout << "Ingresar Tipo -----> ";
    cin >> nuevo->tipo;
    cout << endl;
    nuevo->sgte = NULL;
    nuevo->ant = NULL;

    return nuevo;
}

void InsertarInicio(TpLista &lista) {
    TpLista q = CrearNodo();
    if (lista == NULL) {
        lista = q;
        lista->sgte = lista;
        lista->ant = lista;
    } else {
        q->sgte = lista;
        q->ant = lista->ant;
        lista->ant->sgte = q;
        lista->ant = q;
        lista = q;
    }
}

void InsertarFinal(TpLista &lista) {
    TpLista q = CrearNodo();
    if (lista == NULL) {
        lista = q;
        lista->sgte = lista;
        lista->ant = lista;
    } else {
        q->sgte = lista;
        q->ant = lista->ant;
        lista->ant->sgte = q;
        lista->ant = q;
    }
}

void InsertarPosicion(TpLista &lista, int pos) {
    if (pos < 1) {
        cout << "\nERROR: La posición debe ser mayor que cero." << endl;
        return;
    }

    if (pos == 1) {
        InsertarInicio(lista);
        return;
    }

    TpLista p = lista;
    int x = 1;
    while (p->sgte != lista && x < pos - 1) {
        p = p->sgte;
        x++;
    }

    if (x != pos - 1) {
        cout << "\nERROR: La posición especificada está fuera de rango." << endl;
        return;
    }

    TpLista q = CrearNodo();
    q->sgte = p->sgte;
    q->ant = p;
    p->sgte->ant = q;
    p->sgte = q;
}

void VerLista(TpLista lista) {
    if (lista == NULL) {
        cout << "Lista vacía." << endl;
        return;
    }

    TpLista p = lista;
    cout << "Lista de IDA:" << endl;
    int i = 1;
    do {
        cout << i << ") " << p->nro << " - " << p->tipo << endl;
        p = p->sgte;
        i++;
    } while (p != lista);

    cout << "Lista de REGRESO:" << endl;
    i = 1;
    do {
        cout << i << ") " << p->nro << " - " << p->tipo << endl;
        p = p->ant;
        i++;
    } while (p != lista->ant);
}

void menu() {
    cout << "\n\t LISTA CIRCULAR DOBLE\n\n";
    cout << "1.- Insertar al Inicio" << endl;
    cout << "2.- Insertar al Final" << endl;
    cout << "3.- Insertar por Posicion" << endl;
    cout << "4.- Mostrar Lista" << endl;
    cout << "0.- Salir" << endl << endl;

    cout << "Ingresar Opcion--->  " << endl;
}

int main() {
    int opc;
    TpLista lista = NULL; // variable guardada el inicio de la lista

    do {
    	system("CLS");
        menu();
        cin >> opc;
        switch (opc) {
            case 1:
                InsertarInicio(lista);
                system("pause");
                break;

            case 2:
                InsertarFinal(lista);
                system("pause");
                break;

            case 3: {
                int pos;
                cout << "Insertar Posicion--> ";
                cin >> pos;
                InsertarPosicion(lista, pos);
                system("pause");
                break;
            }

            case 4:
                VerLista(lista);
                system("pause");
                break;
        }

    } while (opc != 0);

    return 0;
}


