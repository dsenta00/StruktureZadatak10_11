#include "zadatak10a.h"
#include "zadatak11.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

static char userPicksZadatak();

/**
 * Pocetak programa, iskon i kraj
 * 
 * @param argc broj argumenata 
 * @param argv niz argumenata
 * @return EXIT_SUCCESS ako je program uspio s radom, u suprotnom vrati EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	switch (userPicksZadatak())
	{
	case 'A':
		return zadatak10a();
	case 'B':
		return zadatak11();
	default:
		break;
	}

	return EXIT_SUCCESS;
}

static char userPicksZadatak()
{
	char choice = 0;

	while (true)
	{
		printf("Choose zadatak:\r\n");
		printf(" a) ........ Zadatak 10 pod a\r\n");
		printf(" b)  ....... Zadatak 11\r\n");
		printf(" ESC) ...... End\r\n");
		printf("\r\n");
		printf(" Your choice -> ");

		choice = toupper(getchar());

		switch (choice)
		{
		case 'A':
		case 'B':
		case '\e':
			return choice;
		default:
			printf("Wrong choice! Try again!\r\n");
			break;
		}
	}
}