#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
using std::cout;
using std::endl;
using std::setprecision;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;
std::vector<double> distacia_euclidiana(std::vector<std::vector<double>>&vec) {
    std::vector<double> resul;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            double distancia_total = 0;
            //{9,6}
            //{5,3}
            //{2,1}
            //{4,8}
            for (int k = 0; k < vec[i].size(); k++) {
                double v1 = vec[i][k];
                double v2 = vec[j][k];
                double distance = pow(v1 - v2, 2);
                distancia_total += distance;
            }

            distancia_total = sqrt(distancia_total); 
            resul.push_back(distancia_total);
        }
    }

    return resul;
}
void guardarResultadosEnArchivo(const std::vector<double>& resultados, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const double& resultado : resultados) {
            archivo << resultado << std::endl;
        }
        archivo.close();
        std::cout << "Resultados guardados en " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}
int main()
{
    std::vector<std::vector<double>> vec;
    std::vector<double> aux;
    float dist;
    int dimension;
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<> distr(FLOAT_MIN, FLOAT_MAX);
    std::cout << "dame la dimension " << std::endl;
    std::cin >> dimension;
    for (int n = 0; n <100; n++) {
        for (int j = 0; j <dimension;j++) {
            aux.push_back(distr(eng));
        }
        vec.push_back(aux);
        aux.clear();
    }
    auto re=distacia_euclidiana(vec);

    std::string name= "dim2";
    guardarResultadosEnArchivo(re, name);

    return 0;
}