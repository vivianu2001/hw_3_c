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
        printf("\nOptions:\n");
        printf("1- Insert strings into the list.\n");
        printf("2- Insert a string at a certain index.\n");
        printf("3- Print the list.\n");
        printf("4- Print the length of the list.\n");
        printf("5- Print a string at a certain index.\n");
        printf("6- Print the number of characters in the entire list.\n");
        printf("7- Receive a string and print how many times it appears.\n");
        printf("8- Receive a string and delete all occurrences from the list.\n");
        printf("9- Receive an index and delete the corresponding member.\n");
        printf("10- Reverse the list.\n");
        printf("11- Delete the entire list.\n");
        printf("12- Sort the list in lexicographical order.\n");
        printf("13- Check whether the list is arranged according to lexicographic order.\n");
        printf("0- Exit the program.\n");
        printf("Choose an option: ");
        scanf(" %d", &option);
        switch(option) {
    case 1: // Insert strings into the list
        printf("Press 'A' to enter strings into the list: ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'A') {
            printf("Invalid choice.\n");
            break;
        }
        printf("Enter number of words: ");
        scanf("%d", &numWords);
        printf("Enter strings separated by space:\n");
        for (int i = 0; i < numWords; i++) {
            scanf("%s", buffer);
            StrList_insertLast(&list_sentinel, buffer);
        }
        break;


            case 2: // Insert a string at a certain index
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter string: ");
                scanf("%s", buffer);
                StrList_insertAt(&list_sentinel, buffer, index);
                break;
            case 3: // Print the list
                printf("List: ");
                StrList_print(&list_sentinel);
                break;
            case 4: // Print the length of the list
                printf("Length of the list: %zu\n", StrList_size(&list_sentinel));
                break;
            case 5: // Print a string at a certain index
                printf("Enter index: ");
                scanf("%d", &index);
                printf("String at index %d: ", index);
                StrList_printAt(&list_sentinel, index);
                break;
            case 6: // Print the number of characters in the entire list
                printf("Number of characters in the list: %d\n", StrList_printLen(&list_sentinel));
                break;
            case 7: // Receive a string and print how many times it appears
                printf("Enter string: ");
                scanf("%s", buffer);
                printf("String '%s' appears %d times in the list.\n", buffer, StrList_count(&list_sentinel, buffer));
                break;
            case 8: // Receive a string and delete all occurrences from the list
                printf("Enter string to delete: ");
                scanf("%s", buffer);
                StrList_remove(&list_sentinel,buffer);
                break;
            case 9: // Receive an index and delete the corresponding member
                printf("Enter index to delete: ");
                scanf("%d", &index);
                StrList_removeAt(&list_sentinel, index);
                break;
            case 10: // Reverse the list
                StrList_reverse(&list_sentinel);
                printf("List reversed.\n");
                break;
            case 11: // Delete the entire list
                StrList_free(&list_sentinel);
                printf("List deleted.\n");
                break;
            case 12: // Sort the list in lexicographical order
                StrList_sort(&list_sentinel);
                printf("List sorted.\n");
                break;
            case 13: // Check whether the list is arranged according to lexicographic order
                if (StrList_isSorted(&list_sentinel)) {
                    printf("List is arranged in lexicographic order.\n");
                } else {
                    printf("List is not arranged in lexicographic order.\n");
                }
                break;
            case 0: // Exit the program
                StrList_free(&list_sentinel);
                return 0;
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}
