#include "problem.h"
#include <stddef.h>

int ll_sum(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        return 0;
    }
    
    int sum = 0;
    Node* current = list->head;
    
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    
    return sum;
}
