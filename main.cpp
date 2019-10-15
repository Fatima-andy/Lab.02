#include <iostream>
#include <time.h>

using namespace std;

struct nodo {
    int valor;
    nodo* sig;
    int dato;
};
nodo *pInicio = NULL;

 ///Ejercicio 5
/*void llenarLista(int);
void mostrarLista(void);
void Listinv(nodo*, nodo*);

nodo * p = NULL;

int main(void) {
    int n;

    cout << "Ingresa la cantidad d numeros q usaras ";
    cin >> n;
    llenarLista(n);

    cout << "Tu lista:" << endl;
    mostrarLista();

    cout << "Lista invertida: " << endl;
    Listinv(pInicio, NULL);

    mostrarLista();

    return 0;
}

void llenarLista(int n) {
    srand(time(NULL));
    nodo* nuevo, * s;

    if (pInicio == NULL) {
        nuevo = new nodo;
        pInicio = nuevo;
        pInicio->valor = rand() % 100 + 1;
        pInicio->sig = NULL;
    }

    s = pInicio;

    for (int i = 0; i < n - 1; i++)
    {
        nuevo = new nodo;
        s->sig = nuevo;
        s = nuevo;
        s->sig = NULL;
        s->valor = rand() % 100 + 1;
    }
}

void mostrarLista(void) {
    nodo* s = pInicio;

    while (s != NULL)
    {
        cout << s->valor << " ";
        s = s->sig;
    }
    cout << endl;
}

void Listinv(nodo* s, nodo* p) {

    if (s != NULL) {
        inversionLista(s->sig, s);
        s->sig = p;
    }
    else
    {
        pInicio = p;
    }
}
*/

///Ej 7

void fillList(int cant) {
    nodo* next, * s;
    int data;

    cout << "Ingresa tus datos:" << endl;
    if (pInicio == NULL) {
        next = new nodo;
        pInicio = next;
        cin >> data;
        next->dato = data;
        next->sig = NULL;
    }
    s = pInicio;

    for (int i = 0; i < (cant - 1); i++) {
        next = new nodo;
        s->sig = next;
        next->sig = NULL;
        cout << "Ingresa un dato: ";
        cin >> data;
        next->dato = data;
        s = next;
    }
}

void mostrar() {
    nodo* s = pInicio;
    cout << "Mostrando lista:" << endl;
    while (s != NULL)
    {
        cout << s->dato << " ";
        s = s->sig;
    }
    cout << endl;
}

void buscar(int numero, nodo* s) {
    nodo* q = NULL;

    while (s != NULL) {
        if (s->dato == numero && s == pInicio) {
            pInicio = s->sig;
            delete s;
            s = pInicio;
            continue;
        }
        q = s;
        s = s->sig;

        if (s != NULL && s->dato == numero) {
            q->sig = s->sig;
            delete s;
            s = q->sig;
        }
    }
}

int main() {

    int cant, bus;

    cout << "Cuantos numeros quieres ingresar? ";
    cin >> cant;

    fillList(cant);
    mostrar();

    cout << "Cual numero quieres eliminar? ";
    cin >> bus;

    buscar(bus, pInicio);
    mostrar();

    return 0;
}
