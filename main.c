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

    while (1) {
        scanf("%d", &option); // Read the option
        getchar(); // Consume newline character after reading integer

        switch (option) {
            case 1: // Insert strings into the list
                int numWords;
                scanf("%d", &numWords); // Read the number of words
                getchar(); // Consume newline character
                
                for (int i = 0; i < numWords; i++) {
                    buffer = NULL; // Initialize buffer to NULL
                    int length = 0; // Initialize the length of the word
                    //int capacity = 1; // Initialize the capacity of the buffer
                    
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF && c != ' ') {
                        buffer = realloc(buffer, (length + 1) * sizeof(char)); // Reallocate memory for the word
                        buffer[length++] = c; // Add character to the word
                    }
                    buffer = realloc(buffer, (length + 1) * sizeof(char)); // Allocate one extra byte for the null terminator
                    buffer[length] = '\0'; // Null-terminate the string
                    StrList_insertLast(&head, buffer); // Insert the word into the list
                }
                break;

            case 2: // Insert a string at a certain index
                scanf("%d", &index); // Read the index
                getchar(); // Consume newline character after reading integer
                buffer = NULL; // Initialize buffer to NULL
                int length = 0; // Initialize the length of the string
                //int capacity = 1; // Initialize the capacity of the buffer

                int c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    buffer = realloc(buffer, (length + 1) * sizeof(char)); // Reallocate memory for the string
                    buffer[length++] = c; // Add character to the string
                }
                buffer = realloc(buffer, (length + 1) * sizeof(char)); // Allocate one extra byte for the null terminator
                buffer[length] = '\0'; // Null-terminate the string
                StrList_insertAt(&head, buffer, index); // Insert the string at the specified index
                break;

            case 3: // Print the list
                StrList_print(&head);
                break;

            case 4: // Print the length of the list
                printf("%zu\n", StrList_size(&head));
                break;

            case 5: // Print a string at a certain index
                scanf("%d", &index); // Read the index
                StrList_printAt(&head, index);
                break;

            case 6: // Print the number of characters in the entire list
                printf("%d\n", StrList_printLen(&head));
                break;

            case 7: // Receive a string and print how many times it appears
                buffer = NULL; // Initialize buffer to NULL
                length = 0; // Initialize the length of the string
                //capacity = 1; // Initialize the capacity of the buffer

                while ((c = getchar()) != '\n' && c != EOF) {
                    buffer = realloc(buffer, (length + 1) * sizeof(char)); // Reallocate memory for the string
                    buffer[length++] = c; // Add character to the string
                }
                buffer = realloc(buffer, (length + 1) * sizeof(char)); // Allocate one extra byte for the null terminator
                buffer[length] = '\0'; // Null-terminate the string
                printf("%d\n", StrList_count(&head, buffer)); // Print the count of occurrences
                break;

            case 8: // Receive a string and delete all occurrences from the list
                buffer = NULL; // Initialize buffer to NULL
                length = 0; // Initialize the length of the string
                //capacity = 1; // Initialize the capacity of the buffer

                while ((c = getchar()) != '\n' && c != EOF) {
                    buffer = realloc(buffer, (length + 1) * sizeof(char)); // Reallocate memory for the string
                    buffer[length++] = c; // Add character to the string
                }
                buffer = realloc(buffer, (length + 1) * sizeof(char)); // Allocate one extra byte for the null terminator
                buffer[length] = '\0'; // Null-terminate the string
                StrList_remove(&head, buffer); // Remove all occurrences of the string from the list
                break;

            case 9: // Receive an index and delete the corresponding member
                scanf("%d", &index); // Read the index
                StrList_removeAt(&head, index); // Remove the element at the specified index
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
