#include <stdio.h>
#include <assert.h>
#include "problem.h"

int main(void) {
    printf("Testing Linked List Sum (build system verification)...\n\n");
    
    /* Test 1: Empty list */
    LinkedList* list1 = ll_create();
    assert(ll_sum(list1) == 0);
    printf("Test 1 passed: Empty list sum = 0\n");
    ll_destroy(list1);
    
    /* Test 2: Single element */
    LinkedList* list2 = ll_create();
    ll_insert(list2, 42);
    assert(ll_sum(list2) == 42);
    printf("Test 2 passed: Single element [42] sum = 42\n");
    ll_destroy(list2);
    
    /* Test 3: Multiple positive elements */
    LinkedList* list3 = ll_create();
    ll_insert(list3, 1);
    ll_insert(list3, 2);
    ll_insert(list3, 3);
    ll_insert(list3, 4);
    ll_insert(list3, 5);
    assert(ll_sum(list3) == 15);
    printf("Test 3 passed: List [5, 4, 3, 2, 1] sum = 15\n");
    ll_destroy(list3);
    
    /* Test 4: Mix of positive and negative */
    LinkedList* list4 = ll_create();
    ll_insert(list4, 10);
    ll_insert(list4, -5);
    ll_insert(list4, 3);
    ll_insert(list4, -2);
    assert(ll_sum(list4) == 6);
    printf("Test 4 passed: List [-2, 3, -5, 10] sum = 6\n");
    ll_destroy(list4);
    
    /* Test 5: NULL list */
    assert(ll_sum(NULL) == 0);
    printf("Test 5 passed: NULL list sum = 0\n");
    
    printf("\nAll tests passed! Build system is working correctly.\n");
    
    return 0;
}
