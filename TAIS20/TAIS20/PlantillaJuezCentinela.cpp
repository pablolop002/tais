// Nombre del alumno Pablo Lopez Veleiro
// Usuario del Juez TAIS07


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"


// función que resuelve el problema
long long int resolver(PriorityQueue<long long int> & datos) {
	if (datos.size() == 1)
		return 0;

	long long int acu = 0, sum = 0, aux;

	while (datos.size() > 1) {
		datos.pop(sum);
		datos.pop(aux);
		sum += aux;
		acu += sum;
		datos.push(sum);
	}

	return acu;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, aux;
	std::cin >> n;

	if (n == 0)
		return false;

	PriorityQueue<long long int> datos;

	for (int i = 0; i < n; i++) {
		std::cin >> aux;
		datos.push(aux);
	}

	long long int sol = resolver(datos);

	std::cout << sol << '\n';

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