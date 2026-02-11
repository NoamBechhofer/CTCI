#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

/**
 * @brief Node structure for singly linked list
 */
typedef struct Node {
    int data;           /**< Data stored in the node */
    struct Node* next;  /**< Pointer to the next node */
} Node;

/**
 * @brief Linked list structure
 */
typedef struct LinkedList {
    Node* head;    /**< Pointer to the first node */
    size_t size;   /**< Number of nodes in the list */
} LinkedList;

/**
 * @brief Create a new empty linked list
 * @return Pointer to the newly created list, or NULL if allocation fails
 */
LinkedList* ll_create(void);

/**
 * @brief Destroy a linked list and free all memory
 * @param list The list to destroy
 */
void ll_destroy(LinkedList* list);

/**
 * @brief Insert a new element at the head of the list
 * @param list The list to insert into
 * @param data The data value to insert
 * @return 0 on success, -1 on failure
 */
int ll_insert(LinkedList* list, int data);

/**
 * @brief Delete the first occurrence of a value from the list
 * @param list The list to delete from
 * @param data The data value to delete
 * @return 0 on success, -1 if not found or list is invalid
 */
int ll_delete(LinkedList* list, int data);

/**
 * @brief Find the first node with the specified value
 * @param list The list to search
 * @param data The data value to find
 * @return Pointer to the node if found, NULL otherwise
 */
Node* ll_find(LinkedList* list, int data);

/**
 * @brief Print the contents of the list to stdout
 * @param list The list to print
 */
void ll_print(LinkedList* list);

#endif /* LINKEDLIST_H */
