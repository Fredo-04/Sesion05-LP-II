#ifndef farmacia_h
#define farmacia_h
#include <iostream>
#include <vector>
using namespace std;
class Medicamento {
private:
    string nombre;
    int cantidad;
public:
    Medicamento(const string& _nombre, int _cantidad) : nombre(_nombre), cantidad(_cantidad) {
        cout << "Se ha creado el medicamento " << nombre << " con una cantidad inicial de " << cantidad << endl;
    }
    ~Medicamento() {
        cout << "Se ha eliminado el medicamento " << nombre << endl;
    }
    Medicamento& vender(int cantidadVendida) {
        if (cantidad >= cantidadVendida) {
            cantidad -= cantidadVendida;
            cout << "Se ha vendido " << cantidadVendida << " unidades del medicamento " << nombre << endl;
        } else {
            cout << "No hay suficiente stock del medicamento " << nombre << endl;
        }
        return *this;
    }
    Medicamento& comprar(int cantidadComprada) {
        cantidad += cantidadComprada;
        cout << "Se ha comprado " << cantidadComprada << " unidades del medicamento " << nombre << endl;
        return *this;
    }
    string getNombre() const {
        return nombre;
    }
};

class Farmacia {
private:
    vector<Medicamento> inventario;
public:
    Farmacia() {
        cout << "Se ha creado la farmacia" << endl;
    }
    ~Farmacia() {
        cout << "Se ha cerrado la farmacia" << endl;
    }
    void agregarMedicamento(const string& nombre, int cantidad) {
        Medicamento nuevoMedicamento(nombre, cantidad);
        inventario.push_back(nuevoMedicamento);
    }
    void venderMedicamento(const string& nombre, int cantidadVendida) {
        int noencuentro=0;
        for (Medicamento& medicamento : inventario) {
            if (medicamento.getNombre() == nombre) {
                medicamento.vender(cantidadVendida);
                noencuentro=1;
            }
        }
        if (noencuentro==0){
            cout << "El medicamento " << nombre << " no se encuentra en el inventario" << endl;
        }
    }
    void comprarMedicamento(const string& nombre, int cantidadComprada) {
        int noencuentro=0;
        for (Medicamento& medicamento : inventario) {
            if (medicamento.getNombre() == nombre) {
                medicamento.comprar(cantidadComprada);
                noencuentro=1;
            }
        }
        if (noencuentro==0){
            cout << "El medicamento " << nombre << " no se encuentra en el inventario" << endl;
        }
    }
};

#endif
