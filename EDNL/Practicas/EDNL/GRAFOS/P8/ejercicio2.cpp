/*

 ______                    __                      __
/\__  _\                  /\ \                    /\ \__
\/_/\ \/   ___     ___ ___\ \ \____  __  __    ___\ \ ,_\  __  __
   \ \ \  / __`\ /' __` __`\ \ '__`\/\ \/\ \  /'___\ \ \/ /\ \/\ \
    \ \ \/\ \L\ \/\ \/\ \/\ \ \ \L\ \ \ \_\ \/\ \__/\ \ \_\ \ \_\ \ 2
     \ \_\ \____/\ \_\ \_\ \_\ \_,__/\ \____/\ \____\\ \__\\ \____/
      \/_/\/___/  \/_/\/_/\/_/\/___/  \/___/  \/____/ \/__/ \/___/


*/

#include "../Includes/grafoPMC.h"
#include "../Includes/grafoMA.h"
#include "../Includes/particion.h"
#include <cmath>
#include <iostream>
#include <algorithm>

struct ciudad{
    double x, y;
    ciudad(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

double distancia(const ciudad& a, const ciudad& b){
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

struct lineaAerea{
    int c1, c2;
    lineaAerea(int c1 = 0, int c2 = 0) : c1(c1), c2(c2) {}
};

struct lineaEntreIslas {
    int rep1, rep2;
    double distancia;
    lineaAerea linea;
    lineaEntreIslas(int rep1 = 0, int rep2 = 0, double d = 0.0, lineaAerea l = lineaAerea())
        : rep1(rep1), rep2(rep2), distancia(d), linea(l) {}
};

// devuelve el indice del vector donde se encuentra una linea aerea entre las
// islas, si no hay ninguna devuelve -1
int buscaLineaEntreIslas(int i1, int i2, const std::vector<lineaEntreIslas>& lineas){
    for (int i = 0; i < lineas.size(); ++i)    {
        const lineaEntreIslas& l = lineas[i];
        if ((l.rep1 == i1 && l.rep2 == i2) || (l.rep2 == i1 && l.rep1 == i2)){
            return i;
        }
    }
    return -1;
}

std::vector<lineaAerea> aerolineacionTombuctiana(const std::vector<ciudad>& ciudades, const Grafo& carreteras){
    const unsigned N = carreteras.numVert();
    Particion p(N);
    // "separo" las ciudades en islas
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (carreteras[i][j] && p.encontrar(i) != p.encontrar(j)){
                p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    }
    std::vector<lineaEntreIslas> lineas;
    // para cada par de ciudades
    for (int i = 0; i < N; ++i){
        int repI = p.encontrar(i);
        for (int j = 0; j < N; ++j){
            int repJ = p.encontrar(j);
            if (repI != repJ){ // si estan en distinta isla
                int pos = buscaLineaEntreIslas(repI, repJ, lineas);
                double dis = distancia(ciudades[i], ciudades[j]);
                if (pos != -1){ // si existe una linea ya entre las dos ciudades
                    lineaEntreIslas& l = lineas[pos];
                    if (dis < l.distancia){ // y la distancia es menor
                        // actualizo la linea a entre esas dos ciudades
                        l.distancia = dis;
                        l.linea = lineaAerea(i, j);
                    }
                }
                else{ // si no hay ninguna linea entre las islas
                    lineaEntreIslas l(repI, repJ, dis, lineaAerea(i, j));
                    lineas.push_back(l); // añado una nueva
                }
            }
        }
    }
    std::vector<lineaAerea> resultado(lineas.size());
    for (int i = 0; i < lineas.size(); ++i){
        resultado[i] = lineas[i].linea;
    }
    return resultado;
}

int main()
{
    std::vector<ciudad> ciudades(5);
    ciudades[0] = (ciudad{0.0, 0.0});
    ciudades[1] = (ciudad{1.0, 1.0});
    ciudades[2] = (ciudad{1.0, 2.0});
    ciudades[3] = (ciudad{5.0, 4.0});
    ciudades[4] = (ciudad{6.0, 6.0});

    Grafo carreteras{5};

    carreteras[0][1] = carreteras[1][0] = true;
    carreteras[1][2] = carreteras[2][1] = true;
    carreteras[3][4] = carreteras[4][3] = true;

    for (lineaAerea& l : aerolineacionTombuctiana(ciudades, carreteras))
    {
        std::cout << "Aerolinea entre: " << l.c1 << " y " << l.c2 << "." << std::endl;
    }
}
