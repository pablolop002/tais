// Nombre del alumno Pablo Lopez Veleiro
// Usuario del Juez TAIS07


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct reg {
	int moment;
	int id;
	int period;
};

bool operator<(reg const &a, reg const &b) {
	return a.moment < b.moment || (a.moment == b.moment && a.id < b.id);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, send;
	PriorityQueue<reg> queue;

	std::cin >> n;

	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		int id_user, period;
		std::cin >> id_user >> period;
		queue.push({ period, id_user, period });
	}

	std::cin >> send;

	while (send--) {
		reg out;
		queue.pop(out);
		std::cout << out.id << '\n';
		out.moment += out.period;
		queue.push(out);
	}

	std::cout << "----\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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