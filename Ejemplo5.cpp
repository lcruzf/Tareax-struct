// Created by PC on 5/05/2026.
// Tarea struct
#include <iostream>
#include <fstream>
using namespace std;

struct Mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};

Mascota registrarMascota() {
    Mascota m;

    cin.ignore();

    cout << "Ingrese nombre de la mascota: ";
    getline(cin, m.nombre);

    cout << "Ingrese la especie: ";
    getline(cin, m.especie);

    cout << "Ingrese la raza: ";
    getline(cin, m.raza);

    cout << "Ingrese edad: ";
    cin >> m.edad;

    cout << "Ingrese peso: ";
    cin >> m.peso;

    return m;
}

void mostrarMascota(Mascota m) {

    cout << "\nRegistro de mascota" << endl;
    cout << "Nombre: " << m.nombre << endl;
    cout << "Especie: " << m.especie << endl;
    cout << "Raza: " << m.raza << endl;
    cout << "Edad: " << m.edad << " aneos" << endl;
    cout << "Peso: " << m.peso << " kg" << endl;
}

int calcularedad(Mascota m) {

    return m.edad * 7;
}

string clasificarPeso(Mascota m) {

    if (m.peso < 5) {
        return "Mascota pequena";
    }
    else if (m.peso >= 5 && m.peso <= 20) {
        return "Mascota mediana";
    }
    else {
        return "Mascota grande";
    }
}

void modificarMascota(Mascota &m) {
    int opcion;

    cout << "\nQUE DATO DESEA MODIFICAR?\n";
    cout << "1. Nombre\n";
    cout << "2. Especie\n";
    cout << "3. Raza\n";
    cout << "4. Edad\n";
    cout << "5. Peso\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    cin.ignore();

    if (opcion == 1) {
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, m.nombre);
    }
    else if (opcion == 2) {
        cout << "Ingrese la nueva especie: ";
        getline(cin, m.especie);
    }
    else if (opcion == 3) {
        cout << "Ingrese la nueva raza: ";
        getline(cin, m.raza);
    }
    else if (opcion == 4) {
        cout << "Ingrese la nueva edad: ";
        cin >> m.edad;
    }
    else if (opcion == 5) {
        cout << "Ingrese el nuevo peso: ";
        cin >> m.peso;
    }
    else {
        cout << "Opcion invalida\n";
    }
}

int main() {
    Mascota m;
    int opcion;
    bool registro = false;

    do {

        cout << "\n----Registro Mascotas----" << endl;
        cout << "1. Registrar mascota" << endl;
        cout << "2. Mostrar mascota" << endl;
        cout << "3. Calcular edad equivalente" << endl;
        cout << "4. Clasificar por peso" << endl;
        cout << "5. Modificar datos" << endl;
        cout << "6. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 6) {
            cout << "Opcion invalida\n";
            continue;
        }
        switch (opcion) {
            case 1:
                m = registrarMascota();
                registro = true;
                break;
            case 2:
                if (registro) {
                    mostrarMascota(m);
                } else {
                    cout << "Primero registre una mascota\n";
                }
                break;
            case 3:
                if (registro) {
                    cout << "Edad equivalente: "
                         << calcularedad(m) << endl;
                } else {
                    cout << "Primero registre una mascota\n";
                }
                break;
            case 4:
                if (registro) {
                    cout << clasificarPeso(m) << endl;
                } else {
                    cout << "Primero registre una mascota\n";
                }
                break;
            case 5:
                if (registro) {
                    modificarMascota(m);
                } else {
                    cout << "Primero registre una mascota\n";
                }
                break;
            case 6:

                cout << "Saliendo del sistema...\n";
                cout << "Programa realizado por:\n";
                cout << "Luis Fernando Cruz Franco";
                break;
        }
    } while (opcion != 6);

    return 0;
}