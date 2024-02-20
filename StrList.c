#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

StrList* StrList_alloc() {
    // Allocate memory for a new StrList structure
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList == NULL) {
        // Handle memory allocation failure
        // For example, you can print an error message and exit the program
        fprintf(stderr, "Memory allocation failed in StrList_alloc()\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the newly allocated StrList structure as needed
    newList->data = NULL;
    newList->next = NULL;
    return newList;
}

void StrList_free(StrList* list) {
    StrList* current = list->next; // Skip the sentinel node
    while (current != NULL) {
        StrList* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->next = NULL; // Reset the list after freeing all nodes
}



size_t StrList_size(const StrList* list) {
    size_t size = 0;
    const StrList* current = list->next;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void StrList_insertLast(StrList* list, const char* data) {
    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed in StrList_insertLast()\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;

    // Traverse the list to find the last node
    StrList* current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
}


void StrList_insertAt(StrList* list, const char* data, int index) {
    if (index < 0) {
        printf("Index cannot be negative.\n");
        return;
    }

    StrList* newNode = (StrList*)malloc(sizeof(StrList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed in StrList_insertAt()\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data);
    newNode->next = NULL;

    StrList* current = list; // Start from the sentinel node
    int i;
    for (i = 0; i < index && current->next != NULL; i++) {
        current = current->next;
    }

    // Handle insertion at index 0
    if (i == 0) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}



char* StrList_firstData(const StrList* list) {
    if (list == NULL) {
        return NULL;
    }
    return list->data;
}

void StrList_print(const StrList* list) {
    const StrList* current = list->next; // Start from the first actual node
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}


void StrList_printAt(const StrList* list, int index) {
    const StrList* current = list->next;
    int i;
    for (i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        printf("%s\n", current->data);
    } else {
        printf("Index out of bounds.\n");
    }
}

int StrList_printLen(const StrList* list) {
    int len = 0;
    const StrList* current = list->next;
    while (current != NULL) {
        len += strlen(current->data);
        current = current->next;
    }
    return len;
}

int StrList_count(StrList* list, const char* data) {
    int count = 0;
    StrList* current = list->next;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void StrList_remove(StrList* list, const char* data) {
    StrList* current = list->next; // Start from the first actual node
    StrList* prev = list; // Keep track of the previous node

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            prev->next = current->next; // Update the link of the previous node
            free(current->data); // Free the data of the current node
            free(current); // Free the current node
            current = prev->next; // Move to the next node
        } else {
            prev = current; // Move to the next node
            current = current->next;
        }
    }
}



void StrList_removeAt(StrList* list, int index) {
    if (index < 0) {
        printf("Index cannot be negative.\n");
        return;
    }

    StrList* current = list->next;
    StrList* prev = NULL;
    int i;
    for (i = 0; current != NULL && i < index; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    if (prev == NULL) {
        list = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);
}

int StrList_isEqual(const StrList* list1, const StrList* list2) {
    const StrList* current1 = list1;
    const StrList* current2 = list2;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1 == NULL && current2 == NULL;
}

StrList* StrList_clone(const StrList* list) {
    if (list == NULL) {
        return NULL;
    }

    StrList* clone = NULL;
    const StrList* current = list;

    while (current != NULL) {
        StrList_insertLast(clone, current->data);
        current = current->next;
    }

    return clone;
}

void StrList_reverse(StrList* list) {
    StrList* prev = NULL;
    StrList* current = list->next; // Skip the sentinel node
    StrList* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Update the link of the sentinel node to point to the new first node
    list->next = prev;
}




void StrList_sort(StrList* list) {
    StrList *ptr1;
    StrList *lptr = NULL;
    int swapped;

    if (list == NULL || list->next == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = list->next; // Start from the first node after the sentinel

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->data, ptr1->next->data) > 0) {
                char* temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int StrList_isSorted(StrList* list) {
    const StrList* current = list->next; // Start from the first node after the sentinel

    while (current != NULL && current->next != NULL) {
        if (strcmp(current->data, current->next->data) > 0) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}
