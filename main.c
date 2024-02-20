#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

int main() {
    StrList head; // Define a sentinel node
    head.next = NULL;
    
    int option;
    int index;
    char *buffer; // Pointer to dynamically allocated buffer
    int numWords;
    
    while (1) {
        scanf(" %d", &option);
        switch(option) {
            case 1: // Insert strings into the list
                scanf("%d\n", &numWords); // Consume newline character after reading integer
                for (int i = 0; i < numWords; i++) {
                    buffer = (char*)malloc(sizeof(char) * 100); // Initial allocation
                    int length = 0;
                    int capacity = 100;
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {
                        if (length + 1 >= capacity) {
                            capacity *= 2; // Double the capacity
                            buffer = (char*)realloc(buffer, sizeof(char) * capacity); // Reallocate with doubled capacity
                        }
                        buffer[length++] = c;
                    }
                    buffer[length] = '\0'; // Null-terminate the string
                    StrList_insertLast(&head, buffer);
                }
                break;

            case 2: // Insert a string at a certain index
                scanf("%d\n", &index); // Consume newline character after reading integer
                buffer = (char*)malloc(sizeof(char) * 100); // Initial allocation
                int length = 0;
                int capacity = 100;
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    if (length + 1 >= capacity) {
                        capacity *= 2; // Double the capacity
                        buffer = (char*)realloc(buffer, sizeof(char) * capacity); // Reallocate with doubled capacity
                    }
                    buffer[length++] = c;
                }
                buffer[length] = '\0'; // Null-terminate the string
                StrList_insertAt(&head, buffer, index);
                break;

            case 3: // Print the list
                StrList_print(&head);
                break;

            case 4: // Print the length of the list
                printf("%zu\n", StrList_size(&head));
                break;

            case 5: // Print a string at a certain index
                scanf("%d\n", &index); // Consume newline character after reading integer
                StrList_printAt(&head, index);
                break;

            case 6: // Print the number of characters in the entire list
                printf("%d\n", StrList_printLen(&head));
                break;

            case 7: // Receive a string and print how many times it appears
                buffer = (char*)malloc(sizeof(char) * 100); // Initial allocation
                length = 0;
                capacity = 100;
                while ((c = getchar()) != '\n' && c != EOF) {
                    if (length + 1 >= capacity) {
                        capacity *= 2; // Double the capacity
                        buffer = (char*)realloc(buffer, sizeof(char) * capacity); // Reallocate with doubled capacity
                    }
                    buffer[length++] = c;
                }
                buffer[length] = '\0'; // Null-terminate the string
                printf("%d\n", StrList_count(&head, buffer));
                free(buffer); // Free dynamically allocated memory
                break;

            case 8: // Receive a string and delete all occurrences from the list
                buffer = (char*)malloc(sizeof(char) * 100); // Initial allocation
                length = 0;
                capacity = 100;
                while ((c = getchar()) != '\n' && c != EOF) {
                    if (length + 1 >= capacity) {
                        capacity *= 2; // Double the capacity
                        buffer = (char*)realloc(buffer, sizeof(char) * capacity); // Reallocate with doubled capacity
                    }
                    buffer[length++] = c;
                }
                buffer[length] = '\0'; // Null-terminate the string
                StrList_remove(&head, buffer);
                free(buffer); // Free dynamically allocated memory
                break;

            case 9: // Receive an index and delete the corresponding member
                scanf("%d\n", &index); // Consume newline character after reading integer
                StrList_removeAt(&head, index);
                break;

            case 10: // Reverse the list
                StrList_reverse(&head);
                break;

            case 11: // Delete the entire list
                StrList_free(&head);
                head.next = NULL;
                break;

            case 12: // Sort the list in lexicographical order
                StrList_sort(&head);
                break;

            case 13: // Check whether the list is arranged according to lexicographic order
                if (StrList_isSorted(&head)) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;

            case 0: // Exit the program
                StrList_free(&head);
                return 0;

            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}
