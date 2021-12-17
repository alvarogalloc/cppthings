/*
 * Se dan 6 valores:
 * a1, a2, b1,
 * b2, c1 y c2.
 * Estos se aplican a la ecuación:
 * ax + by = c
 * se sustituyen los valores en un sistema de ecuaciones
 * y se obtiene el valor de x y y.
 */

#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // variables necesarias
  float x, y, a1, a2, b1, b2, c1, c2;

  // recibir los valores
  std::cin >> a1 >> b1 >> c1;
  std::cin >> a2 >> b2 >> c2;

  // despeje de la ecuacion para x & y
  y = ((a1 * c2) - (a2 * c1)) / ((a1 * b2) - (a2 * b1));
  x = ((c1 - (b1 * y)) / a1);

  std::cout << x << ' ' << y << '\n';
  return 0;
}
