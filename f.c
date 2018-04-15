// Exercise 1.
// FIFO (First in - first out) queue in C.
#include <stdio.h>
#include <stdlib.h>

// Defines a structure which holds the value of an element of the FIFO queue and the reference to the next element in the queue.
typedef struct node {
    int value;
    struct node *next;
} node_t;

// Prints out the entire FIFO queue's contents to the stdout.
void print_list(node_t *first_node) {
    node_t *current_node = first_node;

    while (current_node != NULL) {
        printf("%d  ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

// Adds the new element to the end of the queue.
void push(node_t *first_node, int value) {
    node_t *current_node = first_node;

    // Goes through the queue until the last elements is found.
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    // Adds the reference to the new element and its' value to the queue.
    current_node->next = malloc(sizeof(node_t));
    current_node->next->value = value;
    current_node->next->next = NULL;
}

// Returns the first element from the queue.
int pop(node_t **first_node) {      // **first_node, because we want to modify it inside a function.
    int retval = -1;                // We pass the pointer to the first_node pointer, basically.
    node_t *next_node = NULL;

    // Checks if the queue is not empty.
    if (*first_node == NULL) {
        printf("error: fifo queue empty.\n");
        return -1;
    }

    // Gets the contents of the next element.
    next_node = (*first_node)->next;
    retval = (*first_node)->value;

    free(*first_node);

    // Makes the next_node the first_node of the queue.
    *first_node = next_node;

    return retval;
}

int main() {

    node_t *test_list = malloc(sizeof(node_t));
    test_list->value = 0;
    test_list->next = NULL;

    for (int i = 1; i <= 10; i++) {
        push(test_list, i);
    }

    printf("-> The contents of the queue is as follows:\n");
    print_list(test_list);

    int first_element = pop(&test_list);

    printf("-> Poped the first element: %d.\nThe contents of the queue afterwards is:\n", first_element);
    print_list(test_list);


    return 0;
}
