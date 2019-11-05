#include <iostream>
using namespace std;

struct nodo {
    int num;
    nodo* izq;
    nodo* der;
};

int sumI = 0, sumD = 0;
int lvl = 0, numnod = 0, sumNod = 0;

typedef struct nodo Nodo;
typedef struct nodo* Arbol;

Arbol makeTree(int num) {
    Arbol p = new Nodo;
    p->num = num;
    p->izq = NULL;
    p->der = NULL;

    return p;
}

void asI(Arbol, int);
void asD(Arbol, int);
void AddNod(Arbol);
void inNiveles(Arbol);
void numNod(Arbol);
void SumNod(Arbol);
void Print(Arbol);

int main() {

    int vari = 0;
    cout << "Inicializando arbol.. \nValor de la raiz:" << endl;
    cin >> vari;

    Arbol arbol = makeTree(vari);
    Arbol a = arbol;

    bool continuar = true;
    do {
        int op = 0;
        cout << "Menu: \n1) Agregar \n2) Imprimir todas las operaciones \n3) Salir" << endl;
        cout << "Opcion elegida: ";
        cin >> op;
        switch (op) {
        case 1:  AddNod(arbol);
            break;
        case 2:
            cout << "Num de niveles del arbol: "; inNiveles(a); cout << lvl << endl;
            cout << "Num de nodos: "; numNod(a); cout << numnod << endl;
            cout << "Suma de los nodos: "; SumNod(a); cout << sumNod << endl;
            break;
        case 3:   continuar = false;
            break;
        default: cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar);


    return 0;
}

void asI(Arbol a, int num) {
    if (a == NULL) {
        cout << "Error, el sub arbol Izq no existe" << endl;
    }
    else if (a->izq != NULL) {
        cout << "Error, el subarbol Izq ya existe" << endl;
    }
    else
        a->izq = makeTree(num);
}
void asD(Arbol a, int num) {
    if (a == NULL) {
        cout << "Error, el sub arbol Izq no existe" << endl;
    }
    else if (a->der != NULL) {
        cout << "Error, el subarbol Izq ya existe" << endl;
    }
    else
        a->der = makeTree(num);
}
void AddNod(Arbol a) {
    int num = 0;
    cout << "Num a agregar:" << endl;
    cin >> num;

    Arbol p = a;

    while (true) {
        if (num == p->num) {
            cout << "Error " << num << " ya existe" << endl;
            return;
        }
        else if (num < p->num) {
            if (p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else {
            if (p->der == NULL)
                break;
            else
                p = p->der;
        }
    }

    if (num < p->num)
        asI(p, num);
    else
        asD(p, num);
}
void inNiveles(Arbol a) {
    if (a != NULL) {
        lvl++;
        inNiveles(a->izq);
        //cout << lvl;
    }
}
void numNod(Arbol a) {
    if (a != NULL) {
        numNod(a->izq);
        numnod++;
        numNod(a->der);
    }
    //cout << numnod;
}
void SumNod(Arbol a) {
    if (a != NULL) {
        SumNod(a->izq);
        sumNod = sumNod + a->num;
        SumNod(a->der);
        //sumNod = sumNod + a->num;
    }
    //cout << sumNod;
}
void Print(Arbol a) {
    cout << "Num de niveles del arbol: "; inNiveles(a); cout << endl;
    cout << "Num de nodos: "; numNod(a); cout << endl;
    cout << "Suma de los nodos: "; SumNod(a); cout << endl;
}
