#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <stack>
#include <algorithm>

using namespace std;

struct Producto {
    int id;
    string nombre;
    float precio;
    int stock;
};

class Tienda {
private:
    vector<Producto> productos;
    stack<Producto> historialModificaciones; // Stack para productos modificados

public:
    void registrarProducto() {
        try {
            Producto nuevoProducto;
            cout << "Ingrese el ID del producto: ";
            cin >> nuevoProducto.id;

            // Validar que el ID sea único
            for (const auto& producto : productos) {
                if (producto.id == nuevoProducto.id) {
                    throw runtime_error("El ID ya está en uso. Intente con otro.");
                }
            }

            cin.ignore(); // Limpiar buffer
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nuevoProducto.nombre);

            cout << "Ingrese el precio del producto: ";
            cin >> nuevoProducto.precio;

            if (nuevoProducto.precio < 0) {
                throw invalid_argument("El precio no puede ser negativo.");
            }

            cout << "Ingrese la cantidad en stock: ";
            cin >> nuevoProducto.stock;

            if (nuevoProducto.stock < 0) {
                throw invalid_argument("El stock no puede ser negativo.");
            }

            productos.push_back(nuevoProducto);
            cout << "Producto registrado exitosamente.\n";
        } catch (const exception& e) {
            cerr << "Registro Inexistente: " << e.what() << "\n";
        }
    }

    void buscarProducto() {
        try {
            int id;
            cout << "Ingrese el ID del producto a buscar: ";
            cin >> id;

            for (const auto& producto : productos) {
                if (producto.id == id) {
                    cout << "Producto encontrado:\n";
                    cout << "ID: " << producto.id << ", Nombre: " << producto.nombre
                         << ", Precio: $" << producto.precio << ", Stock: " << producto.stock << "\n";
                    return;
                }
            }

            throw runtime_error("Producto no encontrado.");
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }

    void modificarProducto() {
        try {
            int id;
            cout << "Ingrese el ID del producto a modificar: ";
            cin >> id;

            for (auto& producto : productos) {
                if (producto.id == id) {
                    cout << "Producto encontrado. Ingrese los nuevos datos:\n";

                    historialModificaciones.push(producto); // Guardar el producto antes de modificarlo

                    cin.ignore(); // Limpiar buffer
                    cout << "Nuevo nombre (actual: " << producto.nombre << "): ";
                    getline(cin, producto.nombre);

                    cout << "Nuevo precio (actual: $" << producto.precio << "): ";
                    cin >> producto.precio;

                    if (producto.precio < 0) {
                        throw invalid_argument("El precio no puede ser negativo.");
                    }

                    cout << "Nuevo stock (actual: " << producto.stock << "): ";
                    cin >> producto.stock;

                    if (producto.stock < 0) {
                        throw invalid_argument("El stock no puede ser negativo.");
                    }

                    cout << "Producto modificado exitosamente.\n";
                    return;
                }
            }

            throw runtime_error("Producto no encontrado.");
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }

    void deshacerModificacion() {
        if (historialModificaciones.empty()) {
            cout << "No hay modificaciones para deshacer.\n";
            return;
        }

        Producto ultimoProducto = historialModificaciones.top();
        historialModificaciones.pop();

        // Restaurar el producto en el vector de productos
        for (auto& producto : productos) {
            if (producto.id == ultimoProducto.id) {
                producto = ultimoProducto;
                cout << "Modificación deshecha exitosamente.\n";
                return;
            }
        }
    }

    void listarProductos() const {
        if (productos.empty()) {
            cout << "No hay productos registrados.\n";
            return;
        }

        cout << "Lista de productos:\n";
        for (const auto& producto : productos) {
            cout << "ID: " << producto.id << ", Nombre: " << producto.nombre
                 << ", Precio: $" << producto.precio << ", Stock: " << producto.stock << "\n";
        }
    }

    void ordenarProductos() {
        int criterio;
        cout << "Seleccione el criterio de ordenamiento:\n";
        cout << "1. Precio\n";
        cout << "2. Stock\n";
        cout << "3. Nombre\n";
        cout << "Seleccione una opcion: ";
        cin >> criterio;

        switch (criterio) {
            case 1:
                sort(productos.begin(), productos.end(), [](const Producto& a, const Producto& b) {
                    return a.precio < b.precio;
                });
                cout << "Productos ordenados por precio.\n";
                break;

            case 2:
                sort(productos.begin(), productos.end(), [](const Producto& a, const Producto& b) {
                    return a.stock < b.stock;
                });
                cout << "Productos ordenados por stock.\n";
                break;

            case 3:
                sort(productos.begin(), productos.end(), [](const Producto& a, const Producto& b) {
                    return a.nombre < b.nombre;
                });
                cout << "Productos ordenados por nombre.\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }
    }
};

int main() {
    Tienda tienda;
    int opcion;

    do {
        cout << "\n*** MENU TIENDA ***\n";
        cout << "1. Registrar producto\n";
        cout << "2. Buscar producto\n";
        cout << "3. Modificar producto\n";
        cout << "4. Listar productos\n";
        cout << "5. Ordenar productos\n";
        cout << "6. Deshacer modificación\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                tienda.registrarProducto();
                break;
            case 2:
                tienda.buscarProducto();
                break;
            case 3:
                tienda.modificarProducto();
                break;
            case 4:
                tienda.listarProductos();
                break;
            case 5:
                tienda.ordenarProductos();
                break;
            case 6:
                tienda.deshacerModificacion();
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);

    return 0;
}