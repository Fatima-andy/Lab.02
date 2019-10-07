#include <iostream>
#include <string>
#include <vector>
#include <time.h>


using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

nodo* pInicio = NULL;

void ListRan(int cant){

    srand(time(NULL));
    nodo *next,*s;


    if(pInicio == NULL){
        next = new nodo;
        pInicio = next;
        next -> dato = rand() %100 +1;
        next -> sig = NULL;
    }

     s = pInicio;

    for(int i = 0; i < (cant -1); i ++){
        next = new nodo;
        s -> sig = next;
        next -> sig = NULL;
        next -> dato = rand() %100 +1;
        s = s-> sig;
    }
s = pInicio;
    while ( s != NULL){
        cout<< s-> dato <<" ";
        s = s -> sig;
    }
}
void Inver(nodo *s){
    if ( s != NULL){
        Inver( s-> sig);
        cout<< s-> dato <<" ";
    }
}

void par(void){
    nodo*s = pInicio;

        while ( s != NULL){
            if( s->dato % 2 == 0)
            cout<< s-> dato <<" ";
            s = s -> sig;
        }

}
void impar (void){
    nodo *s = pInicio;
    while (  s != NULL){
        if (s-> dato %2 != 0)
            cout<< s-> dato <<" ";
            s = s -> sig;
    }

}

int main(){


int  cant =0;


cout<<"Cuantos num quieres ingresar? "<<endl;
cin>> cant;
cout<<"Tu lista: "<<endl;
   ListRan( cant);
   cout<<endl;
cout<<"Pares: "<< endl;
   par();
    cout<<endl;
    cout<<"Impares: "<<endl;
impar();
cout<<endl;
cout<<"Inversesa"<<endl;
Inver(pInicio);


return 0;
}
