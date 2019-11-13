// ###### Config options ################

//#define PRINT_DEFENSE_STRATEGY 1    // generate map images

// #######################################

#define BUILDING_DEF_STRATEGY_LIB 1

#include "../simulador/Asedio.h"
#include "../simulador/Defense.h"

#ifdef PRINT_DEFENSE_STRATEGY
#include "ppm.h"
#endif

#ifdef CUSTOM_RAND_GENERATOR
RAND_TYPE SimpleRandomGenerator::a;
#endif

using namespace Asedio;

float cellValue(int row, int col, bool** freeCells, int nCellsWidth, int nCellsHeight
	, float mapWidth, float mapHeight, List<Object*> obstacles, List<Defense*> defenses) {
	return 0; // implemente aqui la funci�n que asigna valores a las celdas
}

bool factibilidad(Defense* defense, std::list<Object*> obstacles, std::list<Defense*> defensesPlaced, float mapWidth, float mapHeight){
    bool factible = true;
    List<Object*>::iterator currentObstacle = obstacles.begin();
    List<Defense*>::iterator currentDefense = defensesPlaced.begin();

    if(defense->position.x + defense->radio >= mapWidth || defense->position.x - defense->radio <= 0 || defense->position.y + defense->radio >= mapHeight || defense->position.y - defense->radio <= 0){
        factible = false;
    }

    while(currentObstacle != obstacles.end() && factible){
        if(_distance(defense->position, (*currentObstacle)->position) < (defense->radio + (*currentObstacle)->radio)){
            factible = false;
        }
        currentObstacle++;
    }

    while(currentDefense != defensesPlaced.end() && factible){
        if(_distance(defense->position, (*currentDefense)->position) < (defense->radio + (*currentDefense)->radio)){
            factible = false;
        }
        currentDefense++;
    }
    return factible;
}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight
              , std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 
    std::list<Defense*> defensesPlaced;
    int maxAttemps = 1000;
    List<Defense*>::iterator currentDefense = defenses.begin();
    while(currentDefense != defenses.end() && maxAttemps > 0) {

        do{
            (*currentDefense)->position.x = ((int)(_RAND2(10))) * cellWidth + cellWidth * 0.5f;
            (*currentDefense)->position.y = ((int)(_RAND2(10))) * cellHeight + cellHeight * 0.5f;
            (*currentDefense)->position.z = 0; 
        }while(!factibilidad((*currentDefense), obstacles, defensesPlaced, mapWidth, mapHeight));
        
        defensesPlaced.push_back((*currentDefense));
        ++currentDefense;
    }

#ifdef PRINT_DEFENSE_STRATEGY

    float** cellValues = new float* [nCellsHeight]; 
    for(int i = 0; i < nCellsHeight; ++i) {
       cellValues[i] = new float[nCellsWidth];
       for(int j = 0; j < nCellsWidth; ++j) {
           cellValues[i][j] = ((int)(cellValue(i, j))) % 256;
       }
    }
    dPrintMap("strategy.ppm", nCellsHeight, nCellsWidth, cellHeight, cellWidth, freeCells
                         , cellValues, std::list<Defense*>(), true);

    for(int i = 0; i < nCellsHeight ; ++i)
        delete [] cellValues[i];
	delete [] cellValues;
	cellValues = NULL;

#endif
}
