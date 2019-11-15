#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *hI;
    Nodo *hD;
};
struct nodoL{
    int dato;
    nodoL *sig;
};

typedef struct Nodo nodo;
typedef struct Nodo *arbol;
nodo *pArbol = NULL;
nodoL *pInicio = NULL;

arbol maketree(int x){
    arbol p = new nodo;
    p -> dato = x;
    p -> hI = NULL;
    p -> hD = NULL;

    return p;
}

void insIz(arbol,int);
void insDer(arbol, int);
void addNodo(arbol);
void buscar(int,arbol);
void inor(nodo *a){
  if( a != NULL){
      inor(a -> hI);
      cout<<" "<<a -> dato;
      inor( a -> hD);
  }
}
void inFin(int);
void MLista(void);
void ej1(void);
void ej5(void);
void RecLista(void);
void arb5(nodo**,int);

int main(){
    int chose;
    cout<<"Escoja el ejercicio: "<<endl<<"1) Ej 1 \n2)Ej 5"<<endl;
    cin>> chose;
    switch(chose){
        case 1:
            ej1();
            break;
        case 2:
            ej5();
            break;
        default:  cout<<"No vale la opcion"<<endl;
            break;
    }
    return 0;
}

void insIz(arbol a, int dato){
    if ( a == NULL)
        cout<<"Arbol esta vacio"<<endl;
    else if( a -> hI != NULL)
        cout<<"El subarbol ya existe"<<endl;
    else
        a -> hI = maketree(dato);
}
void insDer(arbol a, int dato){if ( a == NULL)
        cout<<"Arbol esta vacio"<<endl;
    else if( a -> hD != NULL)
        cout<<"El subarbol ya existe"<<endl;
    else
        a -> hD = maketree(dato);
}
void addNodo(arbol a){
    int num = 0;
    cout<< "Agregar numero"<<endl;
    cin >> num;

    arbol p = a;

    while(true){
        if( num == p -> dato){
            cout << "Error: "<< num << "Ya existe"<<endl;
            return;
        }else if( num < p-> dato){
            if( p -> hI == NULL){
                break;
            }else{
                p = p -> hI;
            }
        }else{
            if (p -> hD == NULL)
                break;
            else
                p = p -> hD;
        }
    }
    if(num < p -> dato)
        insIz(p, num);
    else
        insDer(p, num);
}
void buscar(int datoA,arbol a){
    if(!a)
        cout<<"No existe"<<endl;
    else {
        inFin(a -> dato);
        if (a->dato == datoA)
            cout << "Si esta" << endl;
        else if (datoA < a->dato)
            buscar(datoA, a->hI);
        else
            buscar(datoA, a->hD);
    }
}
void inFin(int dato){
    nodoL *p, *q;
    nodoL *nuevo = new nodoL;
    nuevo -> dato = dato;
    nuevo -> sig = NULL;
    if(pInicio == NULL){
        pInicio = nuevo;
    }
    else {
        p = pInicio;
        q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}
void MLista(void){
    nodoL *s = pInicio;
    while( s != NULL){
        cout << s -> dato <<" ";
        s = s -> sig;
    }
}
void ej1(void){
    int var = 0;
    cout<<"Valor de la raiz: "<<endl;
    cin>> var;
    int datoB;

    arbol Arbol = maketree(var);
    bool cont = true;
    do{
        int op = 0;
        cout << "Menu: \n1) Agregar \n2)Buscar nodo\n3) Salir"<<endl;
        cout<<"Opcion elegida: ";
        cin>> op;
        switch(op){
            case 1:  addNodo(Arbol);
                break;
            case 2: cout<<"Num q quieres encontrar: "<<endl;
                cin>> datoB;
                buscar(datoB, Arbol);
                MLista();
                cout<<endl;
                break;
            case 3:  cont = false;
                break;
            default:   cout<<"Opcion erronea"<<endl;
                break;
        }
    }while(cont);
}
void ej5(void){
   char ans;
   int dato;
   cout<<"Quireses ingresar un dato s/n?";
   cin>>ans;
   while(ans == 's'){
       cout<<"Digita el dato";
       cin >> dato;
       inFin(dato);
       cout<<"Desea meter otro dato?";
       cin>>ans;
   }
   RecLista();
   MLista();
   cout<<endl;
   inor(pArbol);

}
void RecLista(void){
    nodoL *s = pInicio;
    while( s != NULL){
        arb5(&pArbol,s -> dato);
        s = s -> sig;
    }
}
void arb5(nodo**p, int dato){
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hI = (*p)->hD = NULL;
    }
    else
    if(dato < (*p)->dato){
        arb5(&((*p)->hI), dato);
    }
    else
    if(dato > (*p)->dato){
        arb5(&((*p)->hD), dato);
    }
    else
        cout << "El nodo ya existe\n";
}