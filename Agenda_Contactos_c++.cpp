#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct agenda{
    string nombre;
    string direccion;
    string ciudad;
    int codigo_postal;
    string telefono;
    int edad;
};

int main()  {
    fstream archivo;
    archivo.open("agenda.txt", ios::out | ios::app);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    agenda persona;

    int totalperson;
    cout << "ingrese el total de personas a guardar: \n";
    cin >> totalperson;
    cin.ignore();

    for (int i = 0; i < totalperson; i++)   {
        cout << "\nIngrese el nombre: ";
        getline(cin, persona.nombre);

        cout << "Ingrese la direccion: ";
        getline(cin, persona.direccion);

        cout << "Ingrese la ciudad: ";
        getline(cin, persona.ciudad);

        cout << "Ingrese el codigo postal: ";
        cin >> persona.codigo_postal;
        cin.ignore(); // limpiar salto de línea

        cout << "Ingrese el telefono: ";
        getline(cin, persona.telefono);

        cout << "Ingrese la edad: ";
        cin >> persona.edad;
        cin.ignore();
        cout << "-----------------------------" << endl;

         archivo << "Nombre: " << persona.nombre << endl;
        archivo << "Direccion: " << persona.direccion << endl;
        archivo << "Ciudad: " << persona.ciudad << endl;
        archivo << "Codigo Postal: " << persona.codigo_postal << endl;
        archivo << "Telefono: " << persona.telefono << endl;
        archivo << "Edad: " << persona.edad << endl;
        archivo << "-----------------------------" << endl;
        
    }

    archivo.close();
    
    fstream archivoLectura;
    archivoLectura.open("agenda.txt", ios::in);
    if (!archivoLectura.is_open()) {
        cout << "Error al abrir el archivo para lectura." << endl;
        return 1;
    }

    string linea;
    cout << "Contenido del archivo agenda.txt:" << endl;
    while(getline(archivoLectura, linea)) {
        cout << linea << endl;
    }

    archivoLectura.close();

    fstream archivoOrigen;
    archivoOrigen.open("agenda.txt", ios::in);
    if (!archivoOrigen.is_open()) {
        cout << "Error al abrir el archivo de origen." << endl;
        return 1;
    }

    fstream archivoDestino;
    archivoDestino.open("copia_agenda.txt", ios::out);
    if (!archivoDestino.is_open()) {
        cout << "Error al abrir el archivo de destino." << endl;
        return 1;
    }

    string c;

    while(getline(archivoOrigen, c)) {
        archivoDestino << c << endl;
    }

    archivoOrigen.close();
    archivoDestino.close();

    return 0;
}
