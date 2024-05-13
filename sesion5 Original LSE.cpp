#include <iostream>

using namespace std;

struct nodo{
	int nro;
	int tipo;
	struct nodo *sgte; 	
};

typedef struct nodo *TpLista;// crear tipo de dato struct nodo

TpLista CrearNodo(){
	TpLista nuevo = new struct nodo;
	cout<<"Ingresar numero ---> ";
	cin>>nuevo->nro;
	cout<<"Ingresar Tipo -----> ";
	cin>>nuevo->tipo;
	cout<<endl;
	nuevo->sgte = NULL;
	return nuevo;
}

void InsertarInicio(TpLista &lista){
	TpLista q = CrearNodo();
	if(lista != NULL)
		q->sgte = lista;
	lista = q;
}

void InsertarFinal(TpLista &lista){
	TpLista q = CrearNodo(), p = lista;
	if(lista == NULL)
		lista = q;
	else{
		while(p->sgte != NULL)
			p = p->sgte;
		p->sgte = q;
	}	
}

void InsertarPosicion(TpLista &lista, int pos){
	TpLista p = lista, t = NULL, q = NULL;
	int x = 1;
	bool flag = false;
	
	if(pos == 1){
		InsertarInicio(lista);
		return;
	}
	
	q = CrearNodo();
		
	while(p->sgte != NULL && x != pos){
		t = p;
		p = p->sgte;
		x++;
		if(x == pos)
			flag = true;
	}	
	if(flag == true){
		t->sgte = q;
		q->sgte = p;
	}
	else{
		cout<<"ERROR: Posicion No Existe en la Lista"<<endl;
	}	 
	
}

void VerLista(TpLista lista){
	int i = 0;
	while(lista != NULL){
		cout<< " "<<i+1<<")  "<<lista->nro<<" - "<<lista->tipo<< endl;
		lista = lista->sgte;
		i++;	
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

void EliminarInicio(TpLista &lista){
	if(lista == NULL){
		cout<<"\nERROR: Lista vacia, no permite esta opcion"<<endl;
		return;
	}
	TpLista t = lista;
	lista = lista->sgte;
	cout<<"\nNodo eliminado Nr. "<<t->nro<<" tipo: "<<t->tipo<<endl<<endl;
	delete t;
}

void EliminarFinal(TpLista &lista){
	TpLista p = lista, t = NULL;
	if(lista == NULL){
		cout<<"\nERROR: Lista vacia, no permite esta opcion"<<endl;
		return;
	}
	if(lista->sgte == NULL){
		lista = NULL;
		cout<<"\nNodo eliminado Nr. "<<p->nro<<" tipo: "<<p->tipo<<endl<<endl;
		delete p;
		return;
	}
	
	while(p->sgte != NULL){
		t = p;
		p = p->sgte;
	}
	t->sgte = NULL;
	cout<<"\nNodo eliminado Nr. "<<p->nro<<" tipo: "<<p->tipo<<endl<<endl;
	delete p;
}

void EliminarPosicion(TpLista &lista, int pos){
	if(lista == NULL){
		cout<<"\nERROR: Lista vacia, no permite esta opcion"<<endl;
		return;
	}
	TpLista p = lista, t = NULL;
	int x = 1;
	bool flag = false;
	if(pos == 1){
		EliminarInicio(lista);
		return;
	}

	while(p->sgte != NULL && x != pos){
		t = p;
		p = p->sgte;
		x++;
		if(x == pos)
			flag = true;
	}	
	if(flag == true){
		t->sgte = p->sgte;
		cout<<"\nNodo eliminado Nr. "<<p->nro<<" tipo: "<<p->tipo<<endl<<endl;
		delete p;
	}
	else{
		cout<<"ERROR: Posicion No Existe en la Lista"<<endl;
	}	 
}

void BuscaReemplaza(TpLista lista, int b, int r ){
	TpLista p = lista;
	bool flag = false;
	while(p != NULL){
		if(p->nro == b){
			p->nro = r;
			flag = true;
		}
		p = p->sgte;	
	}
	if(flag == false){
		cout<<"Valor buscado "<<b<< " no existe en la lista.."<<endl;
	}
}

int main() {
	int pos, opc, busca, reemp;
	TpLista lista = NULL;// variable guardada el inicio de la lista

	do{
		system("CLS");
		menu();
		cin>>opc;
		switch(opc){
			case 1:{
				InsertarInicio(lista);
				system("pause");
				break;
			}
				
			case 2:{
				InsertarFinal(lista);
				system("pause");
				break;
			}
				
			case 3:{
				if(lista == NULL){
					cout<<"\nERROR: la lista esta vacia, no permite esta opcion"<<endl;
				}
				else {
					cout<<"Insertar Posicion--> ";
					cin>>pos;
					if(pos > 0)
						InsertarPosicion(lista, pos);
					else{
						cout<<"\nERROR: Solo permite valores mayores que cero"<<endl;
					}
				}
				system("pause");
				break;
			}	
				
			case 4:{
				VerLista(lista);
				system("pause");
				break;
			}
				
			case 5:{
				EliminarInicio(lista);
				system("pause");
				break;
			}
				
			case 6:{
				EliminarFinal(lista);
				system("pause");
				break;
			}	
				
			case 7:{
				if(lista == NULL){
					cout<<"\nERROR: la lista esta vacia, no permite esta opcion"<<endl;
				}
				else {
					cout<<"Insertar Posicion--> ";
					cin>>pos;
					if(pos > 0)
						EliminarPosicion(lista, pos);
					else{
						cout<<"\nERROR: Solo permite valores mayores que cero"<<endl;
					}
				}
				system("pause");
				break;
			}
				
			case 8:{
				if(lista == NULL){
					cout<<"\nERROR: la lista esta vacia, no permite esta opcion"<<endl;
				}
				else {
					cout<<"Ingresar el valor a Buscar ------> ";
					cin>>busca;
					cout<<"Ingresar el valor a Reemplazar --> ";
					cin>>reemp;
					if(busca > 0 && reemp > 0)
						BuscaReemplaza(lista, busca, reemp);
					else{
						cout<<"\nERROR: Solo permite valores mayores que cero"<<endl;
					}
				}
				system("pause");
				break;
			}
		}
	
	}while(opc != 0);
	
	return 0;
}

