/*Este programa contiene un menu con 4 opciones:
1- Calculo de Subsidio
2- Coparacion de vectores
3- Estadistica descriptiva
4- Generacion de cuadrado
Se utilizan estructuras de control anidadas y funciones.
Este programa es propiedad de Nelson Santos*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int calcularSubsidio(int n_hijos, int h_Escolar, bool m_viuda) {
    int base = 0;
    if (n_hijos > 0 && n_hijos < 3) {
        base = 70;
    } else if (n_hijos > 2 && n_hijos < 6) {
        base = 90;
    } else if (n_hijos > 5) {
        base = 120;
    }
    int H_adicional = h_Escolar * 10;
    int V_adicional = m_viuda ? 20 : 0;
    int total = base + H_adicional + V_adicional;
    return total;
}
int main() {
    int menu;
    cout << "Ingrese el numero del ejercicio que desea visualizar (del 1 al 4): ";
    cin >> menu;
    if (menu == 1) {
        cout << "Ingresando calculo de subsidio... " << endl;
        int n_hijos;
        cout << "Ingrese el numero de hijos: ";
        cin >> n_hijos;
        int h_Escolar = 0;
        for (int i = 0; i < n_hijos; ++i) {
            int edad;
            cout << "Ingrese edad del hijo No. " << (i + 1) << ": ";
            cin >> edad;
            if (edad > 5 && edad < 19) {
                h_Escolar += 1;
            }
        }
        int viuda;
        cout << "La madre es viuda? (Ingrese 1 para decir que si y 0 para decir que no): ";
        cin >> viuda;
        bool m_viuda = (viuda == 1);
        int subsidio = calcularSubsidio(n_hijos, h_Escolar, m_viuda);
        cout << "El monto mensual que debe recibir la familia es de: " << subsidio << endl;
    } else if (menu == 2) {
        cout << "Ingresando comparacion de dos vectores... " << endl;
        vector<int> ListaA, ListaB;
        int sumaA = 0, sumaB = 0;
        srand(time(0));
        int Vector1, Vector2;
        cout << "Ingrese la longitud del vector 1: ";
        cin >> Vector1;
        cout << "Ingrese la longitud del vector 2: ";
        cin >> Vector2;
        for (int i = 0; i < Vector1; ++i) {
            int VectorA = rand() % 101;
            ListaA.push_back(VectorA);
            sumaA += VectorA;
        }
        for (int j = 0; j < Vector2; ++j) {
            int VectorB = rand() % 101;
            ListaB.push_back(VectorB);
            sumaB += VectorB;
        }
        if (sumaA == sumaB) {
            cout << "Los vectores A y B son iguales. Vector A: " << endl;
        } else if (sumaA < sumaB) {
            cout << "El Vector B es mayor que el Vector A. " << endl;
        } else {
            cout << "El Vector A es mayor que el Vector B. " << endl;
        }
        cout << "Vector A: ";
        for (int i = 0; i < ListaA.size(); ++i) {
            cout << ListaA[i] << " ";
        }
        cout << "= " << sumaA << endl;
        cout << "Vector B: ";
        for (int i = 0; i < ListaB.size(); ++i) {
            cout << ListaB[i] << " ";
        }
        cout << "= " << sumaB << endl;
    } else if (menu == 3) {
        cout << "Ingresando a la estadistica descriptiva... " << endl;
        int n_Datos;
        cout << "Cuantos datos desea ingresar? ";
        cin >> n_Datos;
        vector<double> Lista;
        double mayor = 0, menor = 0;
        for (int i = 0; i < n_Datos; ++i) {
            double d_real;
            cout << "Ingrese numero real: ";
            cin >> d_real;
            Lista.push_back(d_real);
            if (i == 0) {
                mayor = d_real;
                menor = d_real;
            } else {
                if (d_real > mayor) {
                    mayor = d_real;
                } else {
                    if (d_real < menor) {
                        menor = d_real;
                    }
                }
            }
        }
        cout << "Los numeros ingresados son: ";
        for (int i = 0; i < Lista.size(); ++i) {
            cout << Lista[i] << " ";
        }
        cout << endl;
        cout << "El rango de la lista anterior es de: " << mayor << " - " << menor << " = " << (mayor - menor) << endl;
    } else if (menu == 4) {
        cout << "Ingresando a generacion de cuadrado... " << endl;
        int numero;
        cout << "Ingrese numero: ";
        cin >> numero;
        char caracter;
        cout << "Ingrese el caracter: ";
        cin >> caracter;
        for (int i = 0; i < numero; ++i) {
            for (int j = 0; j < numero; ++j) {
                if (i == 0 || i == (numero - 1) || j == 0 || j == (numero - 1)) {
                    cout << caracter << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Opcion no valida" << endl;
    }
    return 0;
}
