#include "StrList.h"


StrList* StrList_alloc() {
    // Allocate memory for a new StrList structure
    StrList* newList = (StrList*)malloc(sizeof(*newList));
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


void StrList_free(StrList* StrList) {
    StrList* current = StrList;
    while (current != NULL) {
        StrList* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

size_t StrList_size(const StrList* StrList) {
    size_t size = 0;
    const StrList* current = StrList;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void StrList_insertLast(StrList** StrList, const char* data) {
    StrList* newNode = (StrList*)malloc(sizeof(*newNode));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*StrList == NULL) {
        *StrList = newNode;
        return;
    }

    StrList* current = *StrList;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void StrList_insertAt(StrList** StrList, const char* data, int index) {
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

    if (*StrList == NULL) {
        *StrList = newNode;
        return;
    }

    if (index == 0) {
        newNode->next = *StrList;
        *StrList = newNode;
        return;
    }

    StrList* current = *StrList;
    int i;
    for (i = 0; i < index - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

char* StrList_firstData(const StrList* StrList) {
    if (StrList == NULL) {
        return NULL;
    }
    return StrList->data;
}

void StrList_print(const StrList* StrList) {
    const StrList* current = StrList;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* StrList, int index) {
    const StrList* current = StrList;
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

int StrList_printLen(const StrList* StrList) {
    int len = 0;
    const StrList* current = StrList;
    while (current != NULL) {
        len += strlen(current->data);
        current = current->next;
    }
    return len;
}

int StrList_count(StrList* StrList, const char* data) {
    int count = 0;
    StrList* current = StrList;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void StrList_remove(StrList** StrList, const char* data) {
    StrList* current = *StrList;
    StrList* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            if (prev == NULL) {
                *StrList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void StrList_removeAt(StrList** StrList, int index) {
    if (index < 0) {
        printf("Index cannot be negative.\n");
        return;
    }

    StrList* current = *StrList;
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
        *StrList = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    const StrList* current1 = StrList1;
    const StrList* current2 = StrList2;

    while (current1 != NULL && current2 != NULL) {
        if (strcmp(current1->data, current2->data) != 0) {
            return 0;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return current1 == NULL && current2 == NULL;
}

StrList* StrList_clone(const StrList* StrList) {
    if (StrList == NULL) {
        return NULL;
    }

    StrList* clone = NULL;
    const StrList* current = StrList;

    while (current != NULL) {
        StrList_insertLast(&clone, current->data);
        current = current->next;
    }

    return clone;
}

void StrList_reverse(StrList** StrList) {
    StrList* prev = NULL;
    StrList* current = *StrList;
    StrList* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *StrList = prev;
}

void StrList_sort(StrList** StrList) {
    int swapped;
    StrList *ptr1;
    StrList *lptr = NULL;

    if (*StrList == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *StrList;

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

int StrList_isSorted(StrList* StrList) {
    while (StrList != NULL && StrList->next != NULL) {
        if (strcmp(StrList->data, StrList->next->data) > 0) {
            return 0;
        }
        StrList = StrList->next;
    }
    return 1;
}
