/*
 * Dado una letra y un numero,
 * determinar si la casilla
 * correspondiente es negra
 * o blanca
 */

#include <iostream>
int main() {
  char columna;
  int renglon;
  std::cin >> columna >> renglon;
  if (columna % 2 == renglon % 2) {
    std::cout << "NEGRO";
  } else {
    std::cout << "BLANCO";
  }
}
