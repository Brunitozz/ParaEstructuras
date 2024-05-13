#include <iostream>

using namespace std;

struct nodo{
	int nro;
	int tipo;
	struct nodo *sgte; 	
};

typedef struct nodo *TpLista;// crear tipo de dato struct nodo

// Función para crear Nodo
TpLista crearNodo(){
	int n, t;
	TpLista q = new struct nodo;
	cout<<"\nIngresar numero--> ";
	cin>>n;
	cout<<"\nIngresar Tipo--> ";
	cin>>t;
	q->nro = n;
	q->tipo = t;
	q->sgte = NULL;
	return q;
}

void eliminarValor(TpLista &lista, int num){
    if(lista != NULL){
        TpLista t = lista, w = NULL, anterior = NULL; 
        while(t != NULL){
            if(t->nro == num){
                if (anterior == NULL) { 
                    lista = t->sgte;
                } else { 
                    anterior->sgte = t->sgte;
                }
                delete t; 
                cout << "Nodo eliminado correctamente." << endl;
                return;
            }
            anterior = t;
            t = t->sgte;
        }
        
        cout << "El valor " << num << " no se encontró en la lista." << endl;
    } else {
        cout << "Lista vacía. No se puede realizar el procedimiento." << endl;
    }
}

void mostrarLista(TpLista lista){
	TpLista t = lista;
	while(t != NULL){
		cout<<"nr = "<<t->nro<<" tipo = "<<t->tipo<<" --> ";
		t = t->sgte;
	}
	cout<<" NULL"<<endl;
}

void insertarInicio(TpLista &lista){
	TpLista w = crearNodo();
	w->sgte = lista;
	lista = w;
}

void insertarFinal(TpLista &lista){
	TpLista w = crearNodo(), t = lista;
	if(lista == NULL){
		lista = w;
	}
	else{
		while(t->sgte != NULL)
			t = t->sgte;
		t->sgte = w;
	}
}

void insertarPosicion(TpLista &lista, int pos){
	TpLista w = crearNodo(), t = lista, s = NULL;
	int x = 1;
	bool flag = false;
	if(pos == 1){
		insertarInicio(lista);
		return;
	}
	while(x != pos && t != NULL){
		s = t;
		t = t->sgte;
		x++;
		if(x == pos)
			flag = true;
	}
	if(flag == false){
		cout<<" Error, posicion ingresada no existe..."<<endl;
	}
	else{
		s->sgte = w;
		w->sgte = t;
	}
}

void eliminarInicio(TpLista &lista){
	if(lista != NULL){
		TpLista w = lista;
		lista = lista->sgte;
		delete w;
	}
}

void eliminarFinal(TpLista &lista){
	TpLista t = lista, s = NULL;
	while(t != NULL && t->sgte != NULL){
		s = t;
		t = t->sgte;
	}
	if(s != NULL){
		s->sgte = NULL;
		delete t;
	}
	else if(lista != NULL){
		delete lista;
		lista = NULL;
	}
}

void eliminarPosicion(TpLista &lista, int pos){
	if(lista != NULL){
		TpLista t = lista, s = NULL;
		int x = 1;
		bool flag = false;
		if(pos == 1){
			eliminarInicio(lista);
			return;
		}
		while(x != pos && t != NULL){
			s = t;
			t = t->sgte;
			x++;
			if(x == pos)
				flag = true;
		}
		if(flag == false){
			cout<<"Error, Posicion ingresada NO EXISTE.."<<endl;
		}
		else{
			s->sgte = t->sgte;
			delete t;
		}
	}
}

void menu(){
	cout<<"\n\t LISTA ENLAZADA SIMPLE\n\n";
	cout<<"1.- Insertar al Inicio "<<endl;
	cout<<"2.- Insertar al Final "<<endl;	
	cout<<"3.- Insertar por Posicion "<<endl;	
	cout<<"4.- Mostrar Lista"<<endl;
	cout<<"5.- Eliminar primer Nodo"<<endl;	
	cout<<"6.- Eliminar ultimo Nodo"<<endl;	
	cout<<"7.- Eliminar por Posicion "<<endl;	
	cout<<"8.- Buscar y Reemplazar "<<endl;	
	cout<<"0.- Salir "<<endl<<endl;	
	cout<<"Ingresar Opcion--->  "<<endl;
}

int main() {
	int posicion, opc;
	TpLista lista = NULL;// variable guardada el inicio de la lista

	do{
		system("CLS");
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				insertarInicio(lista);
				system("pause");
				break;
			}
				
			case 2:{
				insertarFinal(lista);
				system("pause");
				break;
			}
				
			case 3:{
				cout<<"Ingresar posicion del nodo--> ";
				cin>>posicion;
				insertarPosicion(lista, posicion);
				system("pause");
				break;
			}	
				
			case 4:{
				mostrarLista(lista);
				system("pause");
				break;
			}
				
			case 5:{
				eliminarInicio(lista);
				system("pause");
				break;
			}
				
			case 6:{
				eliminarFinal(lista);
				system("pause");
				break;
			}	
				
			case 7:{
				cout<<"Ingresar posicion del nodo a eliminar--> ";
				cin>>posicion;
				eliminarPosicion(lista, posicion);
				system("pause");
				break;
			}
				
			case 8:{
				system("pause");
				break;
			}
		}	
	}while(opc != 0);
	
	return 0;
}

