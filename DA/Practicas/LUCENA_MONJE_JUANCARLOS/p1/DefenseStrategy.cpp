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

struct Cells{
    int row=0, col=0;
    float value=0;
};

void ordenar(List<Cells> &celdas){
    List<Cells>::iterator currentCell;
    List<Cells>::iterator nextCell;
    Cells aux;
    int i=0;
    while(i < celdas.size()-1){
        i = 0;
        currentCell = celdas.begin();
        while(currentCell != celdas.end()){
            nextCell = currentCell;
            nextCell++;
            if((*currentCell).value < (*nextCell).value){
                aux.row = (*currentCell).row;
                aux.col = (*currentCell).col;
                aux.value = (*currentCell).value;
                (*currentCell).row = (*nextCell).row;
                (*currentCell).col = (*nextCell).col;
                (*currentCell).value = (*nextCell).value;
                (*nextCell).row = aux.row;
                (*nextCell).col = aux.col;
                (*nextCell).value = aux.value;                             
            }
            else i++;
            currentCell++;
        }
    }
}

Vector3 cellCenterToPosition(int i, int j, float cellWidth, float cellHeight){ return Vector3((j * cellWidth) + cellWidth * 0.5f, (i * cellHeight) + cellHeight * 0.5f, 0); }

float cellValue(int row, int col, int nCellsWidth, int nCellsHeight, float mapWidth, float mapHeight, List<Object*> obstacles, Defense* base, bool first) {
    float value = 0;
    float distance;
    float cellWidth = mapWidth / nCellsWidth;
    float cellHeight = mapHeight / nCellsHeight;
    List<Object*>::iterator currentObstacle = obstacles.begin();

    if(first){
        Vector3 positionTmp = cellCenterToPosition(row, col, cellWidth, cellHeight);
        base->position.x = positionTmp.x;
        base->position.y = positionTmp.y;
        bool posUp = false, posDown = false, posLeft = false, posRight = false;
        while(currentObstacle != obstacles.end()){
            distance = _distance(base->position, (*currentObstacle)->position) - (base->radio + (*currentObstacle)->radio);
            if(distance > 4 && distance < 10){
                value++;
                if(base->position.x < (*currentObstacle)->position.x){
                    if(posUp || posLeft || posRight) value++;
                    posDown = true;
                    value++;
                }
                if(base->position.x > (*currentObstacle)->position.x){
                    if(posDown || posLeft || posRight) value++;
                    posUp = true;
                    value++;
                }
                if(base->position.y > (*currentObstacle)->position.y){
                    if(posUp || posDown || posRight) value++;
                    posLeft = true;
                    value++;
                }
                if(base->position.x < (*currentObstacle)->position.x){
                    if(posUp || posLeft || posDown) value++;
                    posRight = true;
                    value++;
                }
            }
            currentObstacle++;
        }
    }

    else{
        Vector3 defense = cellCenterToPosition(row, col, cellWidth, cellHeight);
        distance = _distance(defense, base->position) ;
        bool tieneValor = false;
        float i=1;
        while(!tieneValor){
            if(distance < i*cellWidth || distance < i*cellHeight){
                value = 100-i;
                tieneValor = true;
            }
            i++;
        }
        while(currentObstacle != obstacles.end()){
            Vector3 positionTmp = cellCenterToPosition(row, col, cellWidth, cellHeight);
            distance = _distance(positionTmp, (*currentObstacle)->position);
            if(distance > 29 && distance < 33){
                value++;
            }
            currentObstacle++;
        }
    }
	return value; // implemente aqui la funci�n que asigna valores a las celdas
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
    List<Defense*> defensesPlaced;
    List<Defense*>::iterator currentDefense = defenses.begin();

    // Asignacion valores para la base
    List<Cells> cells;
    Cells aux;
    for(int i=0; i < nCellsHeight; i++){
        for(int j=0; j < nCellsWidth; j++){ 
            aux.row = i;
            aux.col = j;
            aux.value = cellValue(i,j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, (*currentDefense), true); 
            cells.push_back(aux);
        }
    }

    // Ordenar la lista para la base
    ordenar(cells);

    List<Cells>::iterator currentCell = cells.begin();
    (*currentDefense)->position.x=0;
    
    // algoritmo voraz base
    while((*currentDefense)->position.x ==0 && currentCell != cells.end()){
        Vector3 currentPosition = cellCenterToPosition((*currentCell).row, (*currentCell).col, cellWidth, cellHeight);
        (*currentDefense)->position.x = currentPosition.x;
        (*currentDefense)->position.y = currentPosition.y;
        if(!factibilidad((*currentDefense), obstacles, defensesPlaced, mapWidth, mapHeight)){
            (*currentDefense)->position.x = 0;
        }
        currentCell++;
    }
    defensesPlaced.push_back((*currentDefense));
    
    // Asignacion valores para las demas
    List<Cells> cells2;
    for(int i=0; i < nCellsHeight; i++){
        for(int j=0; j < nCellsWidth; j++){ 
            aux.row = i;
            aux.col = j;
            aux.value = cellValue(i,j, nCellsWidth, nCellsHeight, mapWidth, mapHeight, obstacles, (*currentDefense), false); 
            cells2.push_back(aux);
        }
    }
    currentDefense++;
        
    // Ordenar la lista para las demas
    ordenar(cells2);

    List<Cells>::iterator currentCell2 = cells2.begin();

    // algoritmo voraz demas
    while(currentDefense != defenses.end()){
        (*currentDefense)->position.x = 0;
        while((*currentDefense)->position.x == 0 && currentCell2 != cells2.end()){
            Vector3 currentPosition = cellCenterToPosition((*currentCell2).row, (*currentCell2).col, cellWidth, cellHeight);
            (*currentDefense)->position.x = currentPosition.x;
            (*currentDefense)->position.y = currentPosition.y;
            if(!factibilidad((*currentDefense), obstacles, defensesPlaced, mapWidth, mapHeight)){
                (*currentDefense)->position.x = 0;
            }
            currentCell2++;
        }
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
