/*
 * Calificador de tareas (suma de vectores)
 *
 * Se da el numero de problemas
 * por cada problema se da
 * x1, y1, x2, y y2
 * despues se dan 4 respuestas (A, B, C y D)
 *
 * Se debe dar output de la cadena
 * de respuestas, ej:
 * respuesta 1: A
 * respuesta 2: B
 *
 * input: 
 * 2
 * 2 3 1 8
 * 1 1
 * 1 3
 * 3 4
 * 3 11
 * 1 1 1 1
 * 2 2
 * 0 0
 * 0 1
 * 1 0
 * Output: AB
 */

#include <iostream>

int main() {
  int n_problemas;
  std::cin >> n_problemas;
  std::string cadena_respuestas;
  for (int i = 0; i < n_problemas; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    // Iterar sobre las posibles respuestas
    for (int j = 0; j < 4; j++) {
      int respuesta_x, respuesta_y;
      std::cin >> respuesta_x >> respuesta_y;

      // Evaluar suma de vectores
      if (respuesta_x == x1 + x2 && respuesta_y == y1 + y2) {
        switch (j) {
          case 0:
            cadena_respuestas += "A";
            break;
          case 1:
            cadena_respuestas += "B";
            break;
          case 2:
            cadena_respuestas += "C";
            break;
          case 3:
            cadena_respuestas += "D";
            break;
        }
      }
    }
  }

  std::cout << cadena_respuestas << '\n';
  return 0;
}
