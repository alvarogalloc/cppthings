/*
  Programa que hace citas y las guarda en memoria dinamica.
  Estas Citas se pueden:
  - Acceder por un numero de cita
  - Modificar
  - Eliminar
  - Listar
*/

#include <iomanip>
#include <iostream>
#include <vector>

struct Fecha
{
  Fecha(int d, int m, int a) : dia(d), mes(m), anio(a)
  {
  }
  bool esValida()
  {
    return dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1000 && anio <= 9999;
  }
  int dia;
  int mes;
  int anio;
};

struct Hora
{
  Hora(int h, int m, int s) : hora(h), minuto(m), segundo(s)
  {
  }
  bool esValida()
  {
    return hora >= 0 && hora <= 23 && minuto >= 0 && minuto <= 59 && segundo >= 0 && segundo <= 59;
  }
  int hora;
  int minuto;
  int segundo;
};

struct Cita
{
  Cita(int numCita, Fecha f, Hora h) : id(numCita), fecha(f), hora(h)
  {
  }

  int id;
  Fecha fecha;
  Hora hora;
};

class Citas
{
private:
  std::vector<Cita> citas;

public:
  Citas();
  ~Citas();
  bool existeCita(int id);
  void agregarCita(Cita cita);
  Cita &obtenerCita(int id);
  void modificarCita(int id);
  void eliminarCita(int id);
  void mostrarCitas();
  void mostrarCita(int id);
};
Citas::Citas()
{
}
Citas::~Citas()
{
}

bool Citas::existeCita(int id)
{
  for (auto cita : citas)
  {
    if (cita.id == id)
    {
      return true;
    }
  }
  return false;
}
void Citas::agregarCita(Cita cita)
{
  // Checar si la cita ya existe
  for (int i = 0; i < citas.size(); i++)
  {
    if (citas[i].id == cita.id)
    {
      std::cout << "La cita ya existe" << std::endl;
      return;
    }
  }
  // Si la cita no existe, la agregamos
  // Pero checamos que la cita sea valida
  if (cita.fecha.esValida() && cita.hora.esValida())
    this->citas.push_back(cita);
  else
    std::cout << "La cita no es valida" << std::endl;
}
Cita &Citas::obtenerCita(int id)
{
  for (int i = 0; i < citas.size(); i++)
  {
    if (citas[i].id == id)
    {
      return citas[i];
    }
  }
  std::cout << "La cita no existe" << std::endl;
  return citas[0];
}

void Citas::modificarCita(int id)
{
  if (existeCita(id))
  {
    bool seguirCambios = true;
    do
    {
      std::cout << "Que desea modificar?" << std::endl;
      std::cout << "1. Fecha" << std::endl;
      std::cout << "2. Hora" << std::endl;
      int opcion;
      std::cin >> opcion;
      switch (opcion)
      {
      case 1: {

        bool fechaValida = false;
        int dia, mes, anio;
        do
        {
          std::cout << "Ingrese la nueva fecha" << std::endl;
          std::cin >> dia >> mes >> anio;
          fechaValida = Fecha(dia, mes, anio).esValida();
          if (!fechaValida)
          {
            std::cout << "La fecha no es valida" << std::endl;
          }
        } while (!fechaValida);
        obtenerCita(id).fecha = Fecha(dia, mes, anio);
        break;
      }
      case 2: {

        bool horaValida = false;
        int hora, minuto, segundo;
        do
        {
          std::cout << "Ingrese la nueva hora" << std::endl;
          std::cin >> hora >> minuto >> segundo;
          horaValida = Hora(hora, minuto, segundo).esValida();
          if (!horaValida)
          {
            std::cout << "La hora no es valida" << std::endl;
          }
        } while (!horaValida);
        obtenerCita(id).hora = Hora(hora, minuto, segundo);
        break;
      }
      }
      std::cout << "Desea seguir modificando? (1: si 2: no)" << std::endl;
      int respuesta;
      std::cin >> respuesta;
      if (respuesta == 2)
      {
        seguirCambios = false;
      }
    } while (seguirCambios);
  }
}

void Citas::eliminarCita(int id)
{
  if (existeCita(id))
  {
    std::cout << "Desea eliminar esta cita? (1: si 2: no)" << std::endl;
    int respuesta;
    std::cin >> respuesta;

    if (respuesta == 1)
    {
      citas.erase(citas.begin() + id);
    }
  }
}

void Citas::mostrarCitas()
{
  for (auto cita : citas)
  {
    mostrarCita(cita.id);
  }
}
void Citas::mostrarCita(int id)
{
  if (existeCita(id))
  {
    auto cita = obtenerCita(id);
    std::cout << "Cita ID: " << cita.id << std::endl;
    std::cout << std::setfill('0') << "Fecha: " << std::setw(2) << cita.fecha.dia << "/" << std::setw(2)
              << cita.fecha.mes << "/" << std::setw(4) << cita.fecha.anio << std::endl;
    std::cout << "Hora:  " << std::setw(2) << cita.hora.hora << ":" << std::setw(2) << cita.hora.minuto << ":"
              << std::setw(2) << cita.hora.segundo << std::endl;
    std::cout << std::string(20, '-') << std::endl;
  }
}

int main()
{
  Citas citas;
  bool salir = false;
  while (!salir)
  {
    std::cout << "Que quieres Haces???" << std::endl;
    std::cout << "1. Agregar cita" << std::endl;
    std::cout << "2. Modificar cita" << std::endl;
    std::cout << "3. Eliminar cita" << std::endl;
    std::cout << "4. Mostrar citas" << std::endl;
    std::cout << "5. Salir" << std::endl;
    int opcion;
    std::cin >> opcion;
    switch (opcion)
    {
    case 1: {
      std::cout << "Ingrese la cita" << std::endl;
      int id;
      std::cout << "ID: ";
      std::cin >> id;
      std::cout << "Fecha: ";
      int dia, mes, anio;
      std::cin >> dia >> mes >> anio;
      std::cout << "Hora: ";
      int hora, minuto, segundo;
      std::cin >> hora >> minuto >> segundo;
      citas.agregarCita(Cita(id, Fecha(dia, mes, anio), Hora(hora, minuto, segundo)));
      break;
    }
    case 2: {
      std::cout << "Ingrese el ID de la cita a modificar" << std::endl;
      int id;
      std::cin >> id;
      citas.modificarCita(id);
      break;
    }
    case 3: {
      std::cout << "Ingrese el ID de la cita a eliminar" << std::endl;
      int id;
      std::cin >> id;
      citas.eliminarCita(id);
      break;
    }
    case 4: {
      citas.mostrarCitas();
      break;
    }
    case 5: {
      salir = true;
      break;
    }
    }
  }
}