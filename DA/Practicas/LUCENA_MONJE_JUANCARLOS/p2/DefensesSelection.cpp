// ###### Config options ################


// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

using namespace Asedio;

int defenseValue(Defense* defense, float radio, float damage, float attacksPerSecond, float health, float cost){
    float value=0;
    if(defense->radio > radio) value++;
    if(defense->damage > damage) value++;
    if(defense->attacksPerSecond < attacksPerSecond) value++;
    if(defense->health > health) value++;
    if(defense->cost < cost) value+2;
    return value;
}

void promedio(std::list<Defense*> defenses, float &radio, float &damage, float &atps, float &health, float &costs, int &nDefenses){
    std::list<Defense*>::iterator it = defenses.begin();
    while(it != defenses.end()){
        nDefenses++;
        radio += (*it)->radio;
        damage += (*it)->damage;
        atps += (*it)->attacksPerSecond;
        health += (*it)->health;
        costs += (*it)->cost;
        it++;
    }
}

void tablaSubproblema(int **f, std::list<Defense*> defenses, unsigned int ases, float radio, float damage, float atps, float health, float costs, int nDefenses){
    std::list<Defense*>::iterator it = defenses.begin();
    for(int j=0; j < ases; j++){
        if(j < (*it)->cost)
            f[0][j] = 0;
        else
            f[0][j] = defenseValue((*it), radio/nDefenses, damage/nDefenses, atps/nDefenses, health/nDefenses, costs/nDefenses);
    }
    for(int i=1; i < nDefenses; i++){
        it++;
        for(int j=0; j < ases; j++){
            if(j < (*it)->cost)
                f[i][j] = f[i-1][j];
            else    
                f[i][j] = std::max(f[i-1][j], f[i-1][j-(*it)->cost] + defenseValue((*it), radio/nDefenses, damage/nDefenses, atps/nDefenses, health/nDefenses, costs/nDefenses));
        }
    }
}

void DEF_LIB_EXPORTED selectDefenses(std::list<Defense*> defenses, unsigned int ases, std::list<int> &selectedIDs
            , float mapWidth, float mapHeight, std::list<Object*> obstacles) {

    unsigned int cost = 0;
    std::list<Defense*>::iterator it = defenses.begin();
    while(it != defenses.end()) {
        if(cost + (*it)->cost <= ases) {
            selectedIDs.push_back((*it)->id);
            cost += (*it)->cost;
        }
        ++it;
    }

    float radio = 0, damage = 0, atps = 0, health = 0, costs=0;
    int nDefenses = 0;
    promedio(defenses, radio, damage, atps, health, costs, nDefenses);
    
    int** f = new int*[nDefenses];
    for(int i=0; i<nDefenses; i++)
        f[i] = new int[ases]; 
    
    tablaSubproblema(f, defenses, ases, radio, damage, atps, health, costs, nDefenses);

    for(int i=0; i<nDefenses; i++){
        for(int j=0; j<ases; j++){
            std::cout << i <<": " <<f[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}
