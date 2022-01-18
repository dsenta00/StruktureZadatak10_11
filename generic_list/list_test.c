#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_SIZE (128)

int stringToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
    
    return EXIT_SUCCESS;
}

int main(void) {
    char command[MAX_COMMAND_SIZE] = { 0 };
    int *number = NULL;
    List *list = NULL;
    
    list = list_create("brojevi");

    printf(" > ('help' for commands)\r\n");

    while (true) {
        printf(" > ");
        scanf(" %s", command);
        
        if (strcmp("append", command) == 0) {
            number = listNode_allocate(sizeof(int));
            scanf(" %d", number);
            list_append(list, number);
        } else if (strcmp("prepend", command) == 0) {
            number = listNode_allocate(sizeof(int));
            scanf(" %d", number);
            list_prepend(list, number);
        } else if (strcmp("remove", command) == 0) {
            scanf(" %s", command);
            if (strcmp("front", command) == 0) {
                list_deleteFirst(list);
            } else if (strcmp("back", command) == 0) {
                list_deleteLast(list);
            } else {
                printf(" UNCRECOGNIZED COMMAND!\r\n");
            }
        } else if (strcmp("clear", command) == 0) {
            list_clear(list);
        } else if (strcmp("print", command) == 0) {
            list_foreach(number, list) {
                printf(" %d", *number);
            }
            printf("\r\n");
        } else if (strcmp("exit", command) == 0) {
            break;
        } else if (strcmp("help", command) == 0) {
            printf(" ***       MENU        ***\r\n");
            printf("    append <number>\r\n");
            printf("    prepend <number>\r\n");
            printf("    remove front|back\r\n");
            printf("    clear\r\n");
            printf("    print\r\n");
            printf("    exit\r\n"); 
        } else {
            printf(" UNCRECOGNIZED COMMAND!\r\n");
        }
    }
    
    list_delete(list);
    return EXIT_SUCCESS;
}