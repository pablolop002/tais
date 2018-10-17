
// NOMBRE Y APELLIDOS

// Explicación de la solución y su coste

#include <iostream>
#include <fstream>
using namespace std;


bool resuelveCaso() {
   int N, C;
   cin >> N >> C;
   
   if (N == 0)
      return false;
   
   // completa para terminar de leer y resolver un caso
   
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
