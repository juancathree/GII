// ###### Config options ################


// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

int defenseValue(Defense* defense){
    return defense->range*0.1+defense->damage*0.3+defense->attacksPerSecond*0.3+defense->health*0.1-defense->cost*0.2;
}

void nDefensas(std::list<Defense*> defenses, int &nDefenses){
    std::list<Defense*>::iterator it = defenses.begin();
    while(it != defenses.end()){
        nDefenses++;
        it++;
    }
}

void tablaSubproblema(int **f, std::list<Defense*> defenses, unsigned int ases, int nDefenses){
    std::list<Defense*>::iterator it = defenses.begin();
    for(int j=0; j < ases; j++){
        if(j < (*it)->cost)
            f[0][j] = 0;
        else
            f[0][j] = defenseValue((*it));
    }
    for(int i=1; i < nDefenses; i++){
        it++;
        for(int j=0; j < ases; j++){
            if(j < (*it)->cost)
                f[i][j] = f[i-1][j];
            else    
                f[i][j] = std::max(f[i-1][j], f[i-1][j-(*it)->cost] + defenseValue((*it)));
        }
    }
}

void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses, unsigned int ases, std::list<int> &selectedIDs
            , float mapWidth, float mapHeight, std::list<Object*> obstacles) {

    unsigned int cost = 0;

    int nDefenses = 0;
    nDefensas(defenses, nDefenses);
    
    int** f = new int*[nDefenses];
    for(int i=0; i<nDefenses; i++)
        f[i] = new int[ases]; 
    
    tablaSubproblema(f, defenses, ases, nDefenses);

    std::list<Defense*>::iterator it = defenses.end();
    it--;
    for(int i = nDefenses-1; i >= 0; i--){
        if(i == 0 && f[i][ases-1] != 0){
            selectedIDs.push_back(i);
        }
        else{
            if(f[i][ases-1] != f[i-1][ases-1]){
                selectedIDs.push_back(i);
            }
        }
        it--;
    }    
    
}
