#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList* ll_create(void) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void ll_destroy(LinkedList* list) {
    if (list == NULL) {
        return;
    }
    
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int ll_insert(LinkedList* list, int data) {
    if (list == NULL) {
        return -1;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1;
    }
    
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    
    return 0;
}

int ll_delete(LinkedList* list, int data) {
    if (list == NULL || list->head == NULL) {
        return -1;
    }
    
    /* Check if head contains the data */
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return 0;
    }
    
    /* Search for the node in the rest of the list */
    Node* current = list->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        return -1;
    }
    
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
    
    return 0;
}

Node* ll_find(LinkedList* list, int data) {
    if (list == NULL) {
        return NULL;
    }
    
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

void ll_print(LinkedList* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    
    Node* current = list->head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]\n");
}
