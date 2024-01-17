#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

class RegistroBitacora {
public:
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razonFalla;

    RegistroBitacora(const string& m, int d, const string& h, const string& ip, const string& r)
        : mes(m), dia(d), hora(h), direccionIP(ip), razonFalla(r) {}

    bool operator<(const RegistroBitacora& otro) const {
        string fechaCompleta1 = mes + " " + to_string(dia) + " " + hora;
        string fechaCompleta2 = otro.mes + " " + to_string(otro.dia) + " " + otro.hora;

        return fechaCompleta1 < fechaCompleta2;
    }

    void imprimir() const {
        cout << mes << " " << dia << " " << hora << " " << direccionIP << " " << razonFalla << endl;
    }
};

vector<RegistroBitacora> readBitacora(string filename) {
    vector<RegistroBitacora> bitacora;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string mes, hora, direccionIP, razonFalla;
        int dia;

        iss >> mes >> dia >> hora >> direccionIP >> razonFalla;
        bitacora.emplace_back(mes, dia, hora, direccionIP, razonFalla);
    }
    return bitacora;
}

vector<RegistroBitacora> sortBitacora(const vector<RegistroBitacora>& bitacora) {
    vector<RegistroBitacora> bitacoraOrdenada = bitacora;
    sort(bitacoraOrdenada.begin(), bitacoraOrdenada.end());
    return bitacoraOrdenada;
}

void buscarYDesplegarRegistros(const vector<RegistroBitacora>& bitacora, const string& fechaInicio, const string& fechaFin) {
    auto inicio = find_if(bitacora.begin(), bitacora.end(), [fechaInicio](const RegistroBitacora& registro) {
        return registro.mes + " " + to_string(registro.dia) + " " + registro.hora >= fechaInicio;
    });

    auto fin = find_if(bitacora.rbegin(), bitacora.rend(), [fechaFin](const RegistroBitacora& registro) {
        return registro.mes + " " + to_string(registro.dia) + " " + registro.hora <= fechaFin;
    });

    // Corregir la comparación usando != en lugar de la función member
    if (inicio != bitacora.end() && fin != bitacora.rend().base() && inicio != fin.base()) {
        for (auto it = inicio; it != fin.base(); ++it) {
            it->imprimir();
        }
    } else {
        cout << "Al menos una de las fechas no se encuentra en la bitácora." << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input file>" << endl;
        return -1;
    }

    vector<RegistroBitacora> bitacora = readBitacora(argv[1]);

    vector<RegistroBitacora> bitacoraOrdenada = sortBitacora(bitacora);
    ofstream archivoOrdenado("bitacora_ordenada.txt");

    for (const RegistroBitacora& registro : bitacoraOrdenada) {
        registro.imprimir();
        archivoOrdenado << registro.mes << " " << registro.dia << " " << registro.hora
                        << " " << registro.direccionIP << " " << registro.razonFalla << endl;
    }

    string fechaInicio, fechaFin;
    cout << "Ingrese la fecha de inicio (mes dia hora:minutos:segundos): ";
    getline(cin, fechaInicio);

    cout << "Ingrese la fecha de fin (mes dia hora:minutos:segundos): ";
    getline(cin, fechaFin);

    buscarYDesplegarRegistros(bitacoraOrdenada, fechaInicio, fechaFin);

    return 0;
}
