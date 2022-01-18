#pragma once
#include "state_list.h"

#define STATE_HASH_TABLE_SIZE (11)

struct _stateHashTable;
typedef struct _stateHashTable *StateHashTableP;
typedef struct _stateHashTable
{
    StateList table[STATE_HASH_TABLE_SIZE];
} StateHashTable;

/**
 * Kreiraj hash tablicu država
 * 
 * @return alociranu hash tablicu
 */
StateHashTableP stateHashTable_create();

/**
 * Unesi čvor države u neku od vezanih lista unutar hash tablice 
 * 
 * @param stateHashTable hash tablica
 * @param stateNode čvor države 
 * @return EXIT_SUCCESS 
 */
int stateHashTable_insertStateNode(StateHashTableP stateHashTable, StateListP stateNode);

/**
 * Isprintaj sve države i gradove iz hash tablice 
 * 
 * @param stateHashTable hash tablica
 * @return EXIT_SUCCESS 
 */
int stateHashTable_print(StateHashTableP stateHashTable);

/**
 * Pronađi državu unutar hash tablice 
 * 
 * @param stateHashTable hash tablica
 * @param stateToFind drzava za pronac
 * @return cvor države iz neke od vezanih lista ako postoji, u suprotnom NULL 
 */
StateListP stateHashTable_findStateNode(StateHashTableP stateHashTable, char *stateToFind);

/**
 * Pobriši cijelu hash tablicu, uključujući sve vezane liste država i stabala gradova unutar njih  
 * 
 * @param stateHashTable hash tablica
 * @return EXIT_SUCCESS
 */
int stateHashTable_delete(StateHashTableP stateHashTable);
