#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList list_sentinel; // Define a sentinel node
    list_sentinel.next = NULL;
    
    int option;
    int index;
    char buffer[100];
    int numWords;
    
    while (1) {
        scanf("%d", &option);
        
        switch(option) {
            case 1: // Insert strings into the list
                scanf("%d", &numWords);
                for (int i = 0; i < numWords; i++) {
                    scanf("%s", buffer);
                    StrList_insertLast(&list_sentinel, buffer);
                }
                break;

            case 3: // Print the list
                StrList_print(&list_sentinel);
                break;

            case 4: // Print the length of the list
                printf("%d\n", (int)StrList_size(&list_sentinel));
                break;

            case 13: // Check whether the list is arranged according to lexicographic order
                if (StrList_isSorted(&list_sentinel)) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;

            case 5: // Print a string at a certain index
                scanf("%d", &index);
                StrList_printAt(&list_sentinel, index);
                break;

            case 6: // Print the number of characters in the entire list
                printf("%d\n", StrList_printLen(&list_sentinel));
                break;

            case 10: // Reverse the list
                StrList_reverse(&list_sentinel);
                break;

            case 0: // Exit the program
                StrList_free(&list_sentinel);
                return 0;

            default:
                break;
        }
    }

    return 0;
}
