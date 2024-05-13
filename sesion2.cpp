#include <iostream>

using namespace std;

struct nodo {
    int nro;
    int tipo;
    struct nodo *sgte;
};

typedef struct nodo *TpLista; // crear tipo de dato struct nodo

TpLista dir = NULL;

void InsertarInicio(TpLista &lista, int a, int b) {
    TpLista q = NULL;
    q = new struct nodo;
    q->nro = a;
    q->tipo = b;
    q->sgte = lista;
    lista = q;
}

void InsertarFinal(TpLista &lista, int a, int b) {
    TpLista q = NULL, p = lista;
    // crear nodo
    q = new struct nodo;
    q->nro = a;
    q->tipo = b;
    q->sgte = NULL;
    // Insertarlo

    if (lista == NULL) {
        lista = q;
        return;
    }

    while (p->sgte != NULL)
        p = p->sgte;
    p->sgte = q;
}

void VerLista(TpLista lista) {
    int i = 0;
    while (lista != NULL) {
        cout << " " << i + 1 << ")  " << lista->nro << " -> " << lista->tipo << " -> ";
        lista = lista->sgte;
        i++;
    }
    cout<<"NULL"<<endl;
}

void menu() {
    cout << "\n\t LISTA ENLAZADA SIMPLE\n\n";
    cout << "1.- Insertar al Inicio " << endl;
    cout << "2.- Insertar al Final " << endl;
    cout << "3.- Mostrar Lista" << endl;
    cout << "0.- Salir " << endl
         << endl;

    cout << "Ingresar Opcion--->  " << endl;
}

int main() {

    int n, t;
    TpLista lista = NULL; // variable guardada el inicio de la lista
    int opc;
    do {
    	system("CLS");
        menu();
        cin >> opc;
        switch (opc) {
        case 1: {
            cout << "Ingresar numero ---> ";
            cin >> n;
            cout << "\nIngresar Tipo -----> ";
            cin >> t;
            cout << endl;
            InsertarInicio(lista, n, t);
            system("pause");
            break;
        }

        case 2: {
            cout << "Ingresar numero ---> ";
            cin >> n;
            cout << "\nIngresar Tipo -----> ";
            cin >> t;
            cout << endl;
            InsertarFinal(lista, n, t);
            system("pause");
            break;
        }

        case 3: {
            VerLista(lista);
            system("pause");
            break;
        }
        }

    } while (opc != 0);
    system("pause");

    return 0;
}


