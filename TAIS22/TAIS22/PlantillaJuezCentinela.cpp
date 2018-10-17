// Nombre del alumno Pablo Lopez Veleiro
// Usuario del Juez TAIS07


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct patient {
	int position;
	char state;
	std::string name;
	int gravity;
};

bool operator<(patient const &a, patient const &b) {
	return a.gravity > b.gravity || (a.gravity == b.gravity && a.position < b.position);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, send;
	PriorityQueue<patient> queue;

	std::cin >> n;

	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		int gravity;
		std::string name;
		char state;
		std::cin >> state;
		if (state != 'A') {
			std::cin >> name >> gravity;
			queue.push({ i, state, name, gravity });
		}
		else {
			patient out;
			queue.pop(out);
			std::cout << out.name << '\n';
		}
	}

	std::cout << "----\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}