#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

#define BUFFER_SIZE 100000 

int main() {
    StrList head; // Define a sentinel node
    head.next = NULL;

    int option;
    int index;
    char *buffer; // Pointer to dynamically allocated buffer
    int numWords;

    while (1) {
        scanf("%d", &option); // Read the option
        getchar(); // Consume newline character after reading integer

        switch (option) {
            case 1: // Insert strings into the list
                scanf("%d", &numWords); // Read the number of words
                getchar(); // Consume newline character
                
                for (int i = 0; i < numWords; i++) {
                    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE); // Allocate memory for the word
                    int length = 0; // Initialize the length of the word
                    int capacity = BUFFER_SIZE; // Initialize the capacity of the buffer
                    int c;

                    while ((c = getchar()) != '\n' && c != EOF && c != ' ') {
                        buffer[length++] = c; // Add character to the word

                        // Reallocate memory for the word to accommodate the next character
                        buffer = (char *)realloc(buffer, sizeof(char) * (++capacity));
                    }

                    buffer[length] = '\0'; // Null-terminate the string
                    StrList_insertLast(&head, buffer); // Insert the word into the list
                }
                break;

            case 2: // Insert a string at a certain index
                scanf("%d", &index); // Read the index
                getchar(); // Consume newline character after reading integer
                buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE); // Allocate memory for the string
                //printf("Enter the string to insert: ");
                fgets(buffer, BUFFER_SIZE, stdin); // Read the entire line
                strtok(buffer, "\n"); // Remove the newline character
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
                buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE); // Allocate memory for the string
                //printf("Enter the string to count: ");
                fgets(buffer, BUFFER_SIZE, stdin); // Read the entire line
                strtok(buffer, "\n"); // Remove the newline character
                printf("%d\n", StrList_count(&head, buffer)); // Print the count of occurrences
                break;

            case 8: // Receive a string and delete all occurrences from the list
                buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE); // Allocate memory for the string
                //printf("Enter the string to remove: ");
                fgets(buffer, BUFFER_SIZE, stdin); // Read the entire line
                strtok(buffer, "\n"); // Remove the newline character
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
