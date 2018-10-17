
// NOMBRE Y APELLIDOS
// Jose Maria Gomez-Trabadela Garcia
// Pablo Lopez Veleiro

// Explicación de la solución y su coste

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

struct caja {
	int numCaja;
	int tiempoCliente;
};

bool operator<(caja const& a, caja const& b) {
	return a.tiempoCliente < b.tiempoCliente || (a.tiempoCliente == b.tiempoCliente && a.numCaja < b.numCaja);
}

/*
Primero creamos una cola de prioridad con las cajas (estructura caja). Añadimos clientes a las cajas hasta quedarnos sin
clientes o cajas.
Tras esto, nos quedan 3 posibilidades:
- No tenemos clientes ni cajas, por tanto, Ismael va a la primera caja que quede libre
- No tenemos clientes pero si quedan cajas libres: Ismael va a la primera caja libre.
- Hemos llenado todas las cajas pero nos quedan clientes: Vamos añadiendo esos clientes en las cajas que se van quedando
libres (sumando el tiempo de espera que ya ha pasado para no tener que modificar el tiempo de espera de la cola constantemente)
hasta llegar a Ismael, que va a la caja que se quede libre.

Coste lineal respecto a N siendo N el numero de clientes de la cola.
*/

bool resuelveCaso() {
	int N, C;
	cin >> N >> C;

	if (N == 0)
		return false;

	// completa para terminar de leer y resolver un caso
	vector<int> v;
	int valor, acu = 0;
	for (int i = 0; i < C; i++) {
		cin >> valor;
		v.push_back(valor);
	}

	PriorityQueue<caja> cajas;
	for (int i = 0; i < N; i++) {
		cajas.push({ i + 1, 0 });
	}

	int i = 0, j = 0;
	while (i < N && j < v.size()) {
		caja aux;
		cajas.pop(aux);
		aux.tiempoCliente = v[j];
		cajas.push(aux);
		i++;
		j++;
	}

	if (j < v.size()) {
		for (i; i < N; i++) {
			//hay clientes pero no cajas
			caja aux;
			cajas.pop(aux);
			acu += aux.tiempoCliente;
			aux.tiempoCliente = acu + v[i];
			cajas.push(aux);
			i++;
		}
	}
	cout << cajas.top().numCaja << '\n';

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
