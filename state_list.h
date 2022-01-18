#pragma once
#include "state.h"
#include "city_tree.h"

struct _stateList;
typedef struct _stateList *StateListP;
typedef struct _stateList
{
    State *state;
    StateListP next;
    CityTreeP cityRoot;
} StateList;

/**
 * Kreiraj čvor prema argumentima
 * 
 * @param stateName naziv drzave
 * @param stateFileName naziv datoteke drzave
 * @return alociran čvor
 */
StateListP stateList_createNodeWithArgs(char *stateName, char *stateFileName);

/**
 * Kreiraj čvor
 * 
 * @param state informacije o državi 
 * @return čvor države
 */
StateListP stateList_create(State *state);

/**
 * Inicijaliziraj čvor
 * 
 * @param stateNode čvor kojeg treba inicijalizirat
 * @param state informacije o državi
 * @return EXIT_SUCCESS
 */
int stateList_initializeNode(StateListP stateNode, State *state);

/**
 * Uveži čvor nakon čvora
 * 
 * @param position pozicija nakon koje uvezujemo čvor
 * @param stateNode čvor kojeg treba uvezati
 * @return EXIT_SUCCESS
 */
int stateList_insertAfter(StateListP position, StateListP stateNode);

/**
 * Uveži čvor unutar vezane liste
 * 
 * @param head glava vezane liste
 * @param stateNode čvor kojeg treba uvezat
 * @return EXIT_SUCCESS
 */
int stateList_insertSorted(StateListP head, StateListP stateNode);

/**
 * Pobriši čvor i sve gradove unutar njega
 * 
 * @param stateNode čvor kojeg treba pobrisat
 * @return EXIT_SUCCESS
 */
int stateList_freeNode(StateListP stateNode);

/**
 * Pobriši čvor nakon čvora i sve gradove unutar tog čvora
 * 
 * @param position pozicija čvor prije onog kojeg želimo pobrisat
 * @return EXIT_SUCCESS
 */
int stateList_deleteNodeAfter(StateListP position);

/**
 * Pobriši cijelu listu i sve gradove u njima
 * 
 * @param head glava vezane liste
 * @return EXIT_SUCCESS
 */
int stateList_deleteAll(StateListP head);

/**
 * Ispiši iz liste sve države i njegove gradove
 * 
 * @param head glava vezane liste
 * @return EXIT_SUCCESS
 */
int stateList_print(StateListP head);

/**
 * Pronađi državu iz liste po imenu
 * 
 * @param head glava vezane liste
 * @param name ime države koju tražimo
 * @return adresu čvora ako je pronađen, u suprotnom NULL
 */
StateListP stateList_findByName(StateListP head, char *name);