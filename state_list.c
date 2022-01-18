#include "state_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Kreiraj čvor prema argumentima
 * 
 * @param stateName naziv drzave
 * @param stateFileName naziv datoteke drzave
 * @return alociran čvor
 */
StateListP stateList_createNodeWithArgs(char *stateName, char *stateFileName) {
    State *state = NULL;
    StateListP stateNode = NULL;

    state = state_create(stateName, stateFileName);
    if (!state) {
        return NULL;
    }

    return stateList_create(state);
}

/**
 * Kreiraj čvor
 * 
 * @param state informacije o državi 
 * @return čvor države
 */
StateListP stateList_create(State *state) {
    StateListP stateNode = NULL;

    stateNode = malloc(sizeof(StateList));
    if (!stateNode) {
        perror("State node not allocated!\r\n");
        free(state);
        return NULL;
    }

    stateList_initializeNode(stateNode, state);

    return stateNode;
}

/**
 * Inicijaliziraj čvor
 * 
 * @param stateNode čvor kojeg treba inicijalizirat
 * @param state informacije o državi
 * @return EXIT_SUCCESS
 */
int stateList_initializeNode(StateListP stateNode, State *state) {
    stateNode->state = state;
    stateNode->cityRoot = NULL;
    stateNode->next = NULL;

    return EXIT_SUCCESS;
}

/**
 * Uveži čvor nakon čvora
 * 
 * @param position pozicija nakon koje uvezujemo čvor
 * @param stateNode čvor kojeg treba uvezati
 * @return EXIT_SUCCESS
 */
int stateList_insertAfter(StateListP position, StateListP stateNode) {
    stateNode->next = position->next;
    position->next = stateNode;

    return EXIT_SUCCESS;
}

/**
 * Uveži čvor unutar vezane liste
 * 
 * @param head glava vezane liste
 * @param stateNode čvor kojeg treba uvezat
 * @return EXIT_SUCCESS
 */
int stateList_insertSorted(StateListP head, StateListP stateNode) {
    StateListP temp = NULL;

    for (temp = head; 
         temp->next != NULL && strcmp(temp->next->state->name, stateNode->state->name) < 0; 
         temp = temp->next);

    return stateList_insertAfter(temp, stateNode);
}

/**
 * Pobriši čvor i sve gradove unutar njega
 * 
 * @param stateNode čvor kojeg treba pobrisat
 * @return EXIT_SUCCESS
 */
int stateList_freeNode(StateListP stateNode) {
    if (!stateNode) {
        return EXIT_SUCCESS;
    }

    if (stateNode->state) {
        free(stateNode->state);
        stateNode->state = NULL;
    }

    stateNode->cityRoot = cityTree_delete(stateNode->cityRoot);
    stateNode->next = NULL;
    free(stateNode);

    return EXIT_SUCCESS;
}

/**
 * Pobriši čvor nakon čvora i sve gradove unutar tog čvora
 * 
 * @param position pozicija čvor prije onog kojeg želimo pobrisat
 * @return EXIT_SUCCESS
 */
int stateList_deleteNodeAfter(StateListP position) {
    StateListP state = NULL;

    state = position->next;

    if (!state) {
        return EXIT_SUCCESS;
    }

    position->next = state->next;
    return stateList_freeNode(state);
}

/**
 * Pobriši cijelu listu i sve gradove u njima
 * 
 * @param head glava vezane liste
 * @return EXIT_SUCCESS
 */
int stateList_deleteAll(StateListP head) {
    while (head->next) {
        stateList_deleteNodeAfter(head);
    }
     
    return EXIT_SUCCESS;
}

/**
 * Ispiši iz liste sve države i njegove gradove
 * 
 * @param head glava vezane liste
 * @return EXIT_SUCCESS
 */
int stateList_print(StateListP head) {
    StateListP current = NULL;

    for (current = head->next; current != NULL; current = current->next) {
        printf("State %s from file %s;\r\n", current->state->name, current->state->fileName);
        cityTree_print(current->cityRoot);
    }

    return EXIT_SUCCESS;
}

/**
 * Pronađi državu iz liste po imenu
 * 
 * @param head glava vezane liste
 * @param name ime države koju tražimo
 * @return adresu čvora ako je pronađen, u suprotnom NULL
 */
StateListP stateList_findByName(StateListP head, char *name) {
    StateListP current = NULL;

    for (current = head->next; current != NULL; current = current->next) {
        if (strcmp(current->state->name, name) == 0) {
            return current;
        }
    }

    return NULL;
}