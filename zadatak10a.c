#include "state_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_MAX (1024)

// ********************** Privatne funkcije, vidljive samo unutar ove datoteke, zato ih označavamo sa 'static'

/**
 * Pročitaj gradove iz datoteke
 * 
 * @param stateFile datoteka s gradovima
 * @return root stabla 
 */
static CityTreeP readCitiesFromFile(char *stateFile);

/**
 * Pročitaj države skupa s gradovima iz datoteke
 * 
 * @param head vezana lista u koju se učitavaju države
 * @param statesFile datoteka s državama
 * @return EXIT_SUCCESS ako je sve ok, u suprotnom EXIT_FAILURE
 */
static int readStatesFromFile(StateListP head, char *statesFile);

/**
 * Izvrši upit nad vezanom listom
 * 
 * @param states vezana lista nad kojom se vrši upit
 * @return EXIT_SUCCESS
 */
static int stateQuery(StateListP states);

/**
 * Zadatak 10 pod a)
 * 
 * @return EXIT_SUCCESS ako je uspilo, u suprotnom EXIT_FAILURE
 */
int zadatak10a() {
	StateList states;
	FILE *fp = NULL;
	int status = 0;
	char fileName[FILENAME_MAX] = { 0 };

	stateList_initializeNode(&states, NULL);

	printf("Please, insert filename -> ");
	scanf(" %s", fileName);
	status = readStatesFromFile(&states, fileName);

	if (status != EXIT_SUCCESS) {
		printf("Failed to read file %s!\r\n", fileName);
		return EXIT_FAILURE;
	}

	stateList_print(&states);
	stateQuery(&states);
	stateList_deleteAll(&states);	

	return EXIT_SUCCESS;
}

/**
 * Pročitaj gradove iz datoteke
 * 
 * @param stateFile datoteka s gradovima
 * @return root stabla 
 */
static CityTreeP readCitiesFromFile(char *stateFile) {
	CityTreeP root = NULL;
	FILE *fp = NULL;
    char cityName[MAX_CITY_NAME] = { 0 };
    int cityPopulation = 0;

	fp = fopen(stateFile, "r");

	if (!fp) {
		perror("File not opened!\r\n");
		return NULL;
	}

	while (!feof(fp)) {
		CityTreeP city = NULL;
		fscanf(fp, " %s %d", cityName, &cityPopulation);
		city = cityTree_createNode(cityName,cityPopulation);

		if (!city) {
			root = cityTree_delete(root);
			return NULL;
		}

		root = cityTree_insert(root, city);
	}
	
	fclose(fp);
	return root;
}

/**
 * Pročitaj države skupa s gradovima iz datoteke
 * 
 * @param head vezana lista u koju se učitavaju države
 * @param statesFile datoteka s državama
 * @return EXIT_SUCCESS ako je sve ok, u suprotnom EXIT_FAILURE
 */
static int readStatesFromFile(StateListP head, char *statesFile) {
	FILE *fp = NULL;
	char statesName[MAX_STATE_NAME] = { 0 };   
    char statesFileName[FILENAME_MAX] = { 0 }; 

	fp = fopen(statesFile, "r");

	if (!fp) {
		perror("File not opened!\r\n");
		return EXIT_FAILURE;
	}

	while (!feof(fp)) {
		StateListP stateNode = NULL;
		fscanf(fp, " %s %s", statesName, statesFileName);
		stateNode = stateList_createNodeWithArgs(statesName, statesFileName);

		if (!stateNode) {
			stateList_deleteAll(head);
			return EXIT_FAILURE;
		}

		stateNode->cityRoot = readCitiesFromFile(stateNode->state->fileName);
		stateList_insertSorted(head, stateNode);
	}
	
	fclose(fp);
	return EXIT_SUCCESS;
}

/**
 * Izvrši upit nad vezanom listom
 * 
 * @param states vezana lista nad kojom se vrši upit
 * @return EXIT_SUCCESS
 */
static int stateQuery(StateListP states) {
	char stateToFind[MAX_STATE_NAME] = { 0 };
	int populationMin = 0;
	StateListP state = NULL;

	while (true) {
		printf("Insert state to find -> ");
		scanf(" %s", stateToFind);

		state = stateList_findByName(states, stateToFind);

		if (!state) {
			printf("State %s not found, please try again!\r\n", stateToFind);
		} else {
			break;
		}
	}
	
	printf("Insert minimal city population to print -> ");
	scanf(" %d", &populationMin);

	cityTree_printBiggerThan(state->cityRoot, populationMin);
	return EXIT_SUCCESS;
}