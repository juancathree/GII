/*

 ______                    __                      __
/\__  _\                  /\ \                    /\ \__
\/_/\ \/   ___     ___ ___\ \ \____  __  __    ___\ \ ,_\  __  __
   \ \ \  / __`\ /' __` __`\ \ '__`\/\ \/\ \  /'___\ \ \/ /\ \/\ \
    \ \ \/\ \L\ \/\ \/\ \/\ \ \ \L\ \ \ \_\ \/\ \__/\ \ \_\ \ \_\ \
     \ \_\ \____/\ \_\ \_\ \_\ \_,__/\ \____/\ \____\\ \__\\ \____/
      \/_/\/___/  \/_/\/_/\/_/\/___/  \/___/  \/____/ \/__/ \/___/


*/

#include "../Includes/grafoPMC.h"
#include "../Includes/grafoMA.h"
#include "../Includes/alg_grafoMA.h"
#include "../Includes/alg_grafoPMC.h"
#include "../Includes/alg_grafo_E-S.h"
#include "../Includes/listaenla.h"
#include "../Includes/particion.h"
#include <cmath>
#include <iostream>

struct ciudad{
    double x, y;
    ciudad(double x = 0.0, double y = 0.0) : x(x), y(y) {} 
};

double distancia(unsigned i, unsigned j, const std::vector<ciudad>& ciudades){
    const ciudad& a = ciudades[i];
    const ciudad& b = ciudades[j];
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

std::pair<Particion, matriz<double>> distribucionTombuctiana(const std::vector<ciudad>& ciudades, const Grafo& carreteras){
    const unsigned n = carreteras.numVert();
    Particion p(n);
    GrafoP<double> costes(n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (carreteras[i][j] && p.encontrar(i) != p.encontrar(j)){
                p.unir(p.encontrar(i), p.encontrar(j));
            }
            if (carreteras[i][j]) {
                costes[i][j] = distancia(i, j, ciudades);
            }
        }
    }
    matriz<GrafoP<double>::vertice> P;
    return std::make_pair(p, Floyd(costes, P));
}

int main() {
    std::vector<ciudad> ciudades(5);
    ciudades[0] = (ciudad{0, 0});
    ciudades[1] = (ciudad{1, 1});
    ciudades[2] = (ciudad{1, 2});
    ciudades[3] = (ciudad{5, 4});
    ciudades[4] = (ciudad{6, 6});

    Grafo carreteras{5};

    carreteras[1][2] = carreteras[2][1] = true;
    carreteras[3][4] = carreteras[4][3] = true;

    Particion P{5};
    matriz<double> mapa{5};

    mapa = distribucionTombuctiana(ciudades, carreteras).second;
    
    std::cout << mapa;
}