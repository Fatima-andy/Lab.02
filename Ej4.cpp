#include <iostream>

using namespace std;

int cont = 0;
struct nodo{
int dato;
nodo *sig;

};
nodo *pInicio = NULL;

void fillList(int cant){
nodo *next, *s;
int data;

cout<<"Ingresa tus datos:"<<endl;
if(pInicio == NULL){
    next = new nodo;
    pInicio = next;
    cin>>data;
    next -> dato = data;
    next ->sig = NULL;
}
s = pInicio;

for(int i =0; i <(cant - 1); i++){
    next = new nodo;
    pInicio = next;
    next-> sig = NULL;
    cin>>data;
    next -> dato = data;
    s = s-> sig;
}

s = pInicio;

cout<<"Tu lista:"<<endl;
while(s != NULL){
    cout<<s->dato<<" ";
    s = s->sig;
}
}

void SumPar(void){
nodo *s = pInicio;
while(s != NULL){
    if(s->dato % 2 == 0)
        cont = cont + s -> dato;
    s = s->sig;
}
cout<<"La suma de los pares: "<<cont<<endl;
}

void SumImp(){
nodo *s = pInicio;
while(s != NULL){
    if (s->dato% 2 != 0)
        cont = cont + s->dato;
    s = s-> sig;
}
cout<<"La suma de los impares: " <<cont<<endl;
}
int main(){

int cant;

cout<<"Cuantos numeros quieres ingrsar?"<<endl;
cin>>cant;

fillList(cant);
SumPar();
SumImp();

return 0;
}
