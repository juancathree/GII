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

Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){ return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); }

bool factibilidad(Defense* defense, std::list<Object*> obstacles, std::list<Defense*> defensesPlaced){
    bool factible = true;
    List<Object*>::iterator currentObstacle = obstacles.begin();
    List<Defense*>::iterator currentDefense = defensesPlaced.begin();

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

float cellValue(int row, int col, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, Defense* base = NULL) {
    int value = 0;
    float distance;
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    List<Object*>::iterator currentObstacle = obstacles.begin();
    if(base == NULL){
        bool choca = false;
        while(currentObstacle != obstacles.end() && !choca){
            distance = _distance(base->position, (*currentObstacle)->position) - (base->radio + (*currentObstacle)->radio);
            if((distance < 2*cellWidth || distance < 2*cellHeight) && distance > 0 ){
                value++;
            }
            else if(distance < 0){
                value = 0;
                choca = true;
            }
        }
    }
    else{
        Vector3 defense = cellCenterToPosition(row, col, cellWidth, cellHeight);
        distance = _distance(defense, base->position) ;
        bool tieneValor = false;
        int i=1;
        while(!tieneValor){
            if(distance < i*cellWidth || distance < i*cellHeight){
                value = 100-i;
                tieneValor = true;
            }
            i++;
        }
    }
	return value; // implemente aqui la funci�n que asigna valores a las celdas
}

void DEF_LIB_EXPORTED placeDefenses(bool** freeCells, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight
              , std::list<Object*> obstacles, std::list<Defense*> defenses) {

    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight; 

    std::list<Defense*> defensesPlaced;
    List<Defense*>::iterator currentDefense = defenses.begin();

    // int maxAttemps = 1000;
    int max = 0;
    int baseRow = 0, baseCol = 0;
    float** cellValues = new float*[nCellsHeight];
    for(int i=0; i<nCellsHeight; i++){
        cellValues[i] = new float[nCellsWidth];
        for(int j=0; j<nCellsWidth; j++){
            cellValues[i][j] = cellValue(i,j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles);
            max = (max > cellValues[i][j]) ? max : cellValues[i][j];
            baseRow = i; baseCol = j;
        }
    }
    
    Vector3 basePosition = cellCenterToPosition(baseRow, baseCol, cellWidth, cellHeight);
    
    (*currentDefense)->position.x = basePosition.x;
    (*currentDefense)->position.y = basePosition.y;
    (*currentDefense)->position.z = basePosition.z;
    currentDefense++;
    
    for(int i=0; i<nCellsHeight; i++){
        for(int j=0; j<nCellsWidth; j++){
            cellValues[i][j] = cellValue(i,j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, (*currentDefense));
        }
    }

    while(currentDefense != defenses.end()) {

        do{
            
            (*currentDefense)->position.x = ((int)(_RAND2(nCellsWidth))) * cellWidth + cellWidth * 0.5f;
            (*currentDefense)->position.y = ((int)(_RAND2(nCellsHeight))) * cellHeight + cellHeight * 0.5f;
            (*currentDefense)->position.z = 0; 
        
        }while(!factibilidad((*currentDefense), obstacles, defensesPlaced));
        
        defensesPlaced.push_back((*currentDefense));
        currentDefense++;
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
