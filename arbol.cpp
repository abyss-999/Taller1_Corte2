#include <iostream>
#include <conio.h>

using namespace std;

struct nodo
{
    int valor;
    nodo* NodoIzquierda;
    nodo* NodoDerecha;
};

nodo* insertar(nodo* arbol, int valor) {
    if (arbol == nullptr) {
        nodo* nuevo = new nodo;
        nuevo->valor = valor;
        nuevo->NodoIzquierda = nullptr;
        nuevo->NodoDerecha = nullptr;
        return nuevo;
    }

    if (valor < arbol->valor) {
        arbol->NodoIzquierda = insertar(arbol->NodoIzquierda, valor);
    } else if (valor > arbol->valor) {
        arbol->NodoDerecha = insertar(arbol->NodoDerecha, valor);
    }

    return arbol;
}

void mostrarArbol(nodo* arbol) {
    if (arbol != nullptr) {
        mostrarArbol(arbol->NodoIzquierda);
        cout << arbol->valor << " ";
        mostrarArbol(arbol->NodoDerecha);
    }
}

int main() {
    int valor;
    char respuesta;
    nodo* arbol = nullptr;

    do {
        cout << "Ingresar nodo al arbol: ";
        cin >> valor;
        arbol = insertar(arbol, valor);
        cout << "Deseas seguir ingresando nodos al arbol? (s/n): ";
        respuesta = getch();
        cout << endl;
    } while (respuesta == 's');

    cout << "\nElementos del arbol: ";
    mostrarArbol(arbol);
    
    return 0;
}
